# from __future__ import annotations 

# import argparse
# from isaaclab.app import AppLauncher

# parser = argparse.ArgumentParser(description="Collision Avoidance Environment")
# AppLauncher.add_app_launcher_args(parser)
# args_cli = parser.parse_args()

# app_launcher = AppLauncher(args_cli)
# simulation_app = app_launcher.app


from __future__ import annotations 

import isaacsim 
from isaacsim import SimulationApp 

simulation_app = SimulationApp({"headless": False})

# from isaacsim.robot.experimental.wheeled_robots.controllers import DifferentialController
import omni.physics.tensors
from omni.physx import get_physx_scene_query_interface
import omni.usd
import math
from collections.abc import Sequence
import torch
import isaaclab
import isaaclab_physx
import isaaclab.sim as sim_utils
from isaaclab.assets import Articulation, ArticulationCfg, AssetBaseCfg
from isaaclab.envs import DirectRLEnv, DirectRLEnvCfg
from isaaclab.scene import InteractiveSceneCfg
from isaaclab.actuators import ImplicitActuatorCfg
from isaaclab.sim import SimulationCfg
from isaaclab.utils.configclass import configclass
from isaaclab.sim.schemas import ArticulationRootPropertiesCfg
from isaaclab.sensors import ContactSensor, ContactSensorCfg, RayCaster, RayCasterCfg, patterns, Camera, CameraCfg
from isaaclab.utils.math import sample_uniform
import warp as wp
from pxr import UsdGeom, Usd, PhysxSchema, UsdPhysics, Gf
import carb
from omni.physx.scripts import physicsUtils
import time
import gymnasium as gym


WALL_MARGIN = 0.20
ROVER_PATH = "_ROBOTS_/rover_rb3/Geometry/world/base_link"


# -----------------------------------------------------------------------------
# Scene Configuration
# -----------------------------------------------------------------------------

@configclass
class CollisionEnvSceneCfg(InteractiveSceneCfg):

    scene_cfg = AssetBaseCfg(
        prim_path="{ENV_REGEX_NS}/scene", 
        spawn=sim_utils.UsdFileCfg(
            usd_path="/home/johanna/Workspaces/msc_project_ws/multi-agent-robots/IsaacSim/multi_agent_robots.usd",
            # articulation_props=ArticulationRootPropertiesCfg(fix_root_link=False),
        ),
    )
        
    rover_rb3: ArticulationCfg = ArticulationCfg(
        prim_path="{ENV_REGEX_NS}/scene/" + ROVER_PATH,
        spawn=None, 
        init_state=ArticulationCfg.InitialStateCfg(
            pos=(-1.274781178649809, 0.39281118685148864, 0.05064811513781181),
            rot=(0.0, 0.0, 0.0, 1.0), 
        ),
        actuators={
            "wheels": ImplicitActuatorCfg(
                joint_names_expr=["wheel_fl_joint", "wheel_fr_joint", "wheel_rl_joint", "wheel_rr_joint"],
                stiffness=0.0,
                damping=10.0,
            ),
        },
    )

    maze: AssetBaseCfg = AssetBaseCfg(prim_path="{ENV_REGEX_NS}/scene/_MAZE_")

# -----------------------------------------------------------------------------
# Environment Configuration
# -----------------------------------------------------------------------------

@configclass
class CollisionEnvRB3Cfg(DirectRLEnvCfg):
    decimation = 4 # nb of physics simulation steps for each RL action
    episode_length_s = 18.0
    action_space = 2 # linear and angular velocity
    observation_space = 258 # [lidar lasers, linear_velocity, angular_velocity]
    state_space = 0

    linear_scale = 0.25   # m/s
    angular_scale = 0.5   # rad/s

    sim = SimulationCfg(
        device="cuda:0",
        dt=1.0 / 120.0,
        render_interval=decimation,
    )

    scene: CollisionEnvSceneCfg = CollisionEnvSceneCfg(
        num_envs=4,
        env_spacing=12.0,
        replicate_physics=True,
        clone_in_fabric=True,
    )

    rew_gets_closer_to_goal = 0.1
    rew_reach_goal = 10.0
    rew_step = -0.01
    rew_robot_proximity_penalty = -2.0
    rew_wall_collision = -100.0
    # rew_robot_collision = -100.0


# -----------------------------------------------------------------------------
# Environment Creation
# -----------------------------------------------------------------------------

class CollisionAvoidanceEnv(DirectRLEnv):

    cfg: CollisionEnvRB3Cfg

    def __init__(self, cfg: CollisionEnvRB3Cfg, render_mode: str | None = None, **kwargs):
        print("Collision env init")
        super().__init__(cfg, render_mode, **kwargs)

        # continues after setup_scene()

        print("Scene entities: ")
        print(self.scene.keys())

        self.spawn_points = torch.stack(self._get_spawn_points()).to(self.device)
        print(f"spawned: {self.spawn_points[0]}")

        print("========== AFTER CLONING ==========")

        print("ENV REGEX:", self.scene.env_regex_ns)

        print("Contact sensor:")
        print("  prim_path:", self.contact_sensor.cfg.prim_path)
        print("  num_instances:", self.contact_sensor.num_instances)
        print("  body_physx_view:", self.contact_sensor.body_physx_view)

        stage = omni.usd.get_context().get_stage()

        for i in range(self.cfg.scene.num_envs):
            p = f"/World/envs/env_{i}/scene/{ROVER_PATH}"
            prim = stage.GetPrimAtPath(p)
            print(f"env_{i}: {p} -> valid={prim.IsValid()}")

        print("===================================")

        print("CONTACT DEVICE NUM:", self.contact_sensor.num_instances)
        print("CONTACT PRIM PATH:", self.contact_sensor.cfg.prim_path)

        print("LIDAR DEVICE:", self.lidar.device)
        print("LIDAR PRIM PATH:", self.lidar.cfg.prim_path)

        self.goal_pos = torch.zeros((self.num_envs, 2), device=self.device)
        self.previous_distance = torch.zeros(self.num_envs, device=self.device)
        self.wall_collision = torch.zeros(self.num_envs, dtype=torch.bool, device=self.device)
        self.robot_collision = torch.zeros(self.num_envs, dtype=torch.bool, device=self.device)

        self.rb3_linear_velocity = 0.0
        self.rb3_angular_velocity = 0.0
        # self.rover_rb3_controller = DifferentialController(wheel_radius=0.038, wheel_base=0.095) # apparently uses CPU and not GPU
        self.wheel_radius = 0.038
        self.wheel_base = 0.095

        self.actions[0] = self.cfg.linear_scale
        self.actions[1] = self.cfg.angular_scale

        self.current_actions = torch.zeros(
            (self.num_envs, self.cfg.action_space),
            device=self.device,
            dtype=torch.float32,
        )

        self.goal_distance = torch.zeros(self.num_envs, device=self.device)
        self.collisions_array = torch.zeros(self.num_envs, dtype=torch.bool, device=self.device)
        self.is_too_close = torch.zeros(self.num_envs, dtype=torch.bool, device=self.device)

        self._debug_action_counter = 0

        print("Collision env init done")


    def _get_spawn_points(self):
        spawn_points = []
        stage = omni.usd.get_context().get_stage()

        # for prim in stage.Traverse():
        #     if "_MAZE_" in str(prim.GetPath()):
        #         print(prim.GetPath())

        prim = stage.GetPrimAtPath("/World/envs/env_0/scene/_MAZE_")
        print(prim)

        # compute maze bounding box
        bbox_cache = UsdGeom.BBoxCache(
            Usd.TimeCode.Default(),
            includedPurposes=["default", "render", "proxy"],
        )

        bbox = bbox_cache.ComputeWorldBound(prim)
        bbox = bbox.ComputeAlignedBox()

        # get lowest and highest points to detect borders
        min_point = bbox.GetMin()
        max_point = bbox.GetMax()

        print(f"min: {min_point}, max: {max_point}")

        num_candidates = 10000

        x = torch.rand(num_candidates, device=self.device) * (max_point[0] - min_point[0]) + min_point[0]
        y = torch.rand(num_candidates, device=self.device) * (max_point[1] - min_point[1]) + min_point[1]

        # reshape in one array
        candidates_xy = torch.stack((x, y), dim=1)

        query_interface = get_physx_scene_query_interface()

        # origin = carb.Float3(x[0].item(), y[0].item(), 10.0)
        # direction = carb.Float3(0.0, 0.0, -1.0)
        distance = WALL_MARGIN

        # h = query_interface.raycast_closest(origin, direction, distance)
        # print(h)

        for c in candidates_xy:
            origin = carb.Float3(c[0].item(), c[1].item(), 10.0)
            direction = carb.Float3(0.0, 0.0, -1.0)

            hit = query_interface.raycast_closest(origin, direction, distance)

            if hit:
                spawn_points.append(c)

        return spawn_points


    # -------------------------------------------------------------------------
    # Scene setup
    # -------------------------------------------------------------------------

    def _setup_scene(self):
        print("Starting scene setup")

        env_regex = self.scene.env_regex_ns

        stage = omni.usd.get_context().get_stage()

        xgo_prim_path = "{ENV_REGEX_NS}/_ROBOTS_/xgo_lite"

        xgo_prim = stage.GetPrimAtPath(xgo_prim_path)

        if xgo_prim.IsValid():
            xgo_prim.SetActive(False)
            print(f"[INFO] Disabled XGO: {xgo_prim_path}")

        # source_robot_path = f"{prim_path}/{ROVER_PATH}"
        # robot_prim = stage.GetPrimAtPath(source_robot_path)

        contact_cfg = ContactSensorCfg(
            prim_path=f"{env_regex}/scene/{ROVER_PATH}",
            update_period=0.0,
            history_length=6,
            track_pose=False
            # filter_prim_paths_expr=["/World"] # detect contacts with everything that is under _MAZE_ (leave .*)
        )
        self.contact_sensor = ContactSensor(contact_cfg)

        contact_prim_path = "{ENV_REGEX_NS}/" + ROVER_PATH

        contact_prim = stage.GetPrimAtPath(contact_prim_path)

        print("CONTACT REPORT PRIM:", contact_prim_path)
        print("VALID:", contact_prim.IsValid())

        if contact_prim.IsValid():
            PhysxSchema.PhysxContactReportAPI.Apply(contact_prim)
            print("[INFO] ContactReport API applied")

        self.scene.sensors["contact_forces"] = self.contact_sensor

        # self.scene.clone_environments(copy_from_source=False)

        lidar_cfg = RayCasterCfg(
            prim_path=f"{env_regex}/scene/{ROVER_PATH}/lidar_link",
            mesh_prim_paths=["/World"],
            update_period=0.0,
            offset=RayCasterCfg.OffsetCfg(pos=(0.0, 0.0, 0.21)),
            pattern_cfg=patterns.LidarPatternCfg(
                channels=16,
                vertical_fov_range=(0.0, 0.0),
                horizontal_fov_range=(-180.0, 180.0),
                horizontal_res=22.5,
            ),
            max_distance=10.0,
        )
        self.lidar = RayCaster(lidar_cfg)
        self.scene.sensors["lidar"] = self.lidar

        env_regex = self.scene.env_regex_ns
        self.cfg.scene.rover_rb3.prim_path = f"{env_regex}/scene/{ROVER_PATH}"

        self.rover_rb3 = Articulation(self.cfg.scene.rover_rb3)
        self.scene.articulations["rover_rb3"] = self.rover_rb3

        print(f"Spawned {self.cfg.scene.num_envs} envs.")
    
        print("ENV REGEX:", self.scene.env_regex_ns)
        print("CONTACT PRIM:", contact_cfg.prim_path)


    # -------------------------------------------------------------------------
    # Physics
    # -------------------------------------------------------------------------

    def _pre_physics_step(self, actions: torch.Tensor) -> None:
        self.current_actions = actions.to(device=self.device, dtype=torch.float32).clone()

        # print("PRE PHYSICS ACTIONS:")
        # print(self.current_actions)


    def _apply_action(self):

        linear_speed = self.actions[:, 0]
        angular_speed = self.actions[:, 1]

        print(self.actions)

        left_velocity = (linear_speed - angular_speed * self.wheel_base / 2.0)
        right_velocity = (linear_speed + angular_speed * self.wheel_base / 2.0)

        left_angular = left_velocity / self.wheel_radius
        right_angular = right_velocity / self.wheel_radius

        # velocities = self.rover_rb3_controller.forward([linear_speed, angular_speed])
        # left_velocity, right_velocity = velocities

        wheel_velocities = torch.stack(
            [
                left_angular,
                right_angular,
                left_angular,
                right_angular,
            ],
            dim=-1,
        )

        print("========== APPLY ACTION ==========")
        print("actions:")
        print(self.actions)
        print("wheel velocities:")
        print(wheel_velocities)
        print("==================================")

        # wheel_velocities = torch.full(
        #     (self.num_envs, 4),
        #     5.0,
        #     device=self.device,
        #     dtype=torch.float32,
        # )

        # print("DIRECT WHEEL COMMAND:")
        # print(wheel_velocities)

        self.rover_rb3.write_joint_velocity_to_sim(wheel_velocities) # ignore warning as the proposed function uses Warp

        self._debug_action_counter += 1

    # -------------------------------------------------------------------------
    # Observations
    # -------------------------------------------------------------------------

    def _get_observations(self) -> dict:
        
        # get tag pose in isaac sim + noise

        # wp.to_torch avoids compatibility problems
        robot_pos = wp.to_torch(self.rover_rb3.data.root_pos_w)[:, :2] # world frame position, exclude z

        # TODO measure proximity using Lidar

        # TODO check collisions
        contact_forces = wp.to_torch(self.contact_sensor.data.net_forces_w)

        contact_magnitude = torch.linalg.vector_norm(
            contact_forces,
            dim=-1,
        )

        self.collisions_array = (contact_magnitude > 1.0).any(dim=1)

        # compute distance to goal for reward
        goal_relative = (self.goal_pos - robot_pos)
        self.goal_distance = torch.linalg.vector_norm(goal_relative, dim=-1).unsqueeze(-1)

        linear_velocity = (wp.to_torch(self.rover_rb3.data.root_lin_vel_w)[:, 0])
        angular_velocity = (wp.to_torch(self.rover_rb3.data.root_ang_vel_w)[:, 2])

        # check the distances for wall proximity reward
        lidar_origin = torch.as_tensor(self.scene["lidar"].data.pos_w, device=self.device)

        lidar_output = torch.as_tensor(self.scene["lidar"].data.ray_hits_w, device=self.device)

        # print("origin torch:", lidar_origin.shape)
        # print("output torch:", lidar_output.shape)

        lidar_distances = torch.linalg.vector_norm(lidar_output - lidar_origin.unsqueeze(1), dim=-1)

        # print("========== LIDAR DATA ==========")
        # print("origin type:", type(lidar_origin))
        # print("origin:", lidar_origin)
        # print("output type:", type(lidar_output))
        # print("output:", lidar_output)

        # try:
        #     print("origin shape:", lidar_origin.shape)
        # except Exception as e:
        #     print("origin shape ERROR:", e)

        # try:
        #     print("output shape:", lidar_output.shape)
        # except Exception as e:
        #     print("output shape ERROR:", e)

        # print("===============================")

        lidar_distances = torch.linalg.vector_norm(lidar_output - lidar_origin.unsqueeze(1), dim=-1)

        self.is_too_close = (lidar_distances < 0.20).any(dim=1)

        # pass the raw lidar output to the policy
        obs = torch.cat(
            (
                lidar_output.reshape(self.num_envs, -1),
                linear_velocity.unsqueeze(-1),
                angular_velocity.unsqueeze(-1),
            ),
            dim=-1,
        )

        return { "policy": obs }

    # -------------------------------------------------------------------------
    # Rewards
    # -------------------------------------------------------------------------

    def _get_rewards(self) -> torch.Tensor:

        robot_pos = wp.to_torch(self.rover_rb3.data.root_pos_w)[:, :2]

        current_distance = torch.linalg.vector_norm(self.goal_pos - robot_pos, dim=-1)

        collision_rew = (
            self.collisions_array.float()
            * self.cfg.rew_wall_collision
        )

        proximity_rew = (
            self.is_too_close.float()
            * self.cfg.rew_robot_proximity_penalty
        )

        progress = self.previous_distance - current_distance
        # TODO global variable
        goal_reached = current_distance < 0.15

        progress_rew = self.cfg.rew_gets_closer_to_goal * progress
        goal_rew = goal_reached.float() * self.cfg.rew_reach_goal
        collision_rew = self.collisions_array.float() * self.cfg.rew_wall_collision
        proximity_rew = self.is_too_close.float() * self.cfg.rew_robot_proximity_penalty
        step_rew = torch.full((self.num_envs,), self.cfg.rew_step, device=self.device)

        total_reward = goal_rew + progress_rew + collision_rew + proximity_rew + step_rew
        self.previous_distance = current_distance

        return total_reward

    # -------------------------------------------------------------------------
    # Termination
    # -------------------------------------------------------------------------

    def _get_dones(self):

        robot_pos = wp.to_torch(self.rover_rb3.data.root_pos_w)[:, :2]

        current_distance = torch.linalg.vector_norm(self.goal_pos - robot_pos, dim=-1)
        goal_reached = current_distance < 0.15

        has_collided = self.collisions_array

        terminated = (has_collided | goal_reached)
        time_out = (self.episode_length_buf >= self.max_episode_length - 1)

        return terminated, time_out

    # -------------------------------------------------------------------------
    # Reset
    # -------------------------------------------------------------------------

    def _reset_idx(self, env_ids: Sequence[int] | None):
        if env_ids is None:
            env_ids = self.rover_rb3._ALL_INDICES

        env_ids = torch.as_tensor(
            env_ids,
            device=self.device,
            dtype=torch.long,
        )

        super()._reset_idx(env_ids)

        # choose a random position from the list of precomputed valid positions for each env
        indices = torch.randint(
            0,
            self.spawn_points.shape[0],
            (len(env_ids),),
            device=self.device,
        )

        next_spawn_positions = self.spawn_points[indices]

        # random robot orientation
        yaw = torch.rand(len(env_ids), device=self.device) * 2.0 * math.pi 

        root_pose = torch.zeros((len(env_ids), 7), device=self.device, dtype=torch.float32)

        init_rb3 = self.cfg.scene.rover_rb3.init_state.pos[2]
        root_pose[:, 0:2] = next_spawn_positions[:, 0:2]
        root_pose[:, 2] = init_rb3

        root_pose[:, 3] = torch.cos(yaw / 2.0)  # W
        root_pose[:, 4] = 0.0                   # X
        root_pose[:, 5] = 0.0                   # Y
        root_pose[:, 6] = torch.sin(yaw / 2.0)  # Z

        root_vel = torch.zeros((len(env_ids), 6), device=self.device, dtype=torch.float32)

        self.rover_rb3.write_root_pose_to_sim(root_pose, env_ids)        
        self.rover_rb3.write_root_velocity_to_sim(root_vel, env_ids)

        zero_joint_vel = torch.zeros((len(env_ids), self.rover_rb3.num_joints), device=self.device)
        self.rover_rb3.write_joint_velocity_to_sim_index(velocity=zero_joint_vel, joint_ids=None, env_ids=env_ids)

        self.rover_rb3.write_data_to_sim()

        rand_x = torch.rand(len(env_ids), device=self.device) * (4.0 - 2.0 * WALL_MARGIN) + WALL_MARGIN
        rand_y = torch.rand(len(env_ids), device=self.device) * (4.0 - 2.0 * WALL_MARGIN) + WALL_MARGIN

        self.goal_pos[env_ids, 0] = self.scene.env_origins[env_ids, 0] + rand_x
        self.goal_pos[env_ids, 1] = self.scene.env_origins[env_ids, 1] + rand_y

        self.previous_distance[env_ids] = torch.linalg.vector_norm(self.goal_pos[env_ids] - next_spawn_positions[:, :2], dim=-1)

        self.collisions_array[env_ids] = False
        self.is_too_close[env_ids] = False
        # self.robot_collision[env_ids] = False


if __name__ == "__main__":

    env_cfg = CollisionEnvRB3Cfg()

    print("Creating environment...")

    base_env = CollisionAvoidanceEnv(
        cfg=env_cfg,
        render_mode=None, # for videos
    )

    print("Environment created.")

    print("BEFORE RESET")

    obs, info = base_env.reset()
    
    print("AFTER RESET")

    num_steps = 2000 # 50 000

    start_time = time.perf_counter()

    print("training...")
    steps_done = 0

    for step in range(100000):

        actions = torch.zeros(
            (base_env.num_envs, base_env.cfg.action_space),
            device=base_env.device,
        )

        obs, rewards, terminated, truncated, info = base_env.step(actions)
        simulation_app.update()

        steps_done += 1

    elapsed = (time.perf_counter() - start_time)

    simulated_seconds = (num_steps * base_env.cfg.decimation * base_env.cfg.sim.dt)

    print()
    print("========== BENCHMARK ==========")
    print(f"Environments:       {base_env.num_envs}")
    print(f"Steps:              {num_steps}")
    print(f"Steps executed      {steps_done}")
    print(f"Simulated time:     {simulated_seconds:.2f} s")
    print(f"Real time:    {elapsed:.2f} s")
    print(f"Steps/sec:          {num_steps / elapsed:.2f}")
    print(
        f"Simulation speed:   "
        f"{simulated_seconds / elapsed:.2f}x real-time"
    )
    print("================================")

    base_env.close()
    simulation_app.close()
