from __future__ import annotations 

import isaacsim 
from isaacsim import SimulationApp 

simulation_app = SimulationApp({"headless": False})

# -----------------------------------------------------------------------------
# Imports after launching Isaac Sim
# -----------------------------------------------------------------------------

import isaaclab.sim as sim_utils
from isaacsim.robot.experimental.wheeled_robots.controllers import DifferentialController
from isaaclab.assets import Articulation, ArticulationCfg, AssetBaseCfg
from isaaclab.envs import DirectRLEnv, DirectRLEnvCfg
from isaaclab.scene import InteractiveSceneCfg
from isaaclab.sim import SimulationCfg
from isaaclab.utils.configclass import configclass
from isaaclab.assets import RigidObject, RigidObjectCfg
from isaaclab.actuators import ImplicitActuatorCfg
import torch


ROVER_PATH = "_ROBOTS_/rover_rb3/Geometry/world/base_link"

# -----------------------------------------------------------------------------
# Scene
# -----------------------------------------------------------------------------

@configclass
class TestSceneCfg(InteractiveSceneCfg):

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

    # ground = AssetBaseCfg(
    #     prim_path="/World/ground",
    #     spawn=sim_utils.GroundPlaneCfg(),
    # )

    # light = AssetBaseCfg(
    #     prim_path="/World/DomeLight",
    #     spawn=sim_utils.DomeLightCfg(
    #         intensity=3000.0,
    #         color=(1.0, 1.0, 1.0),
    #     ),
    # )

    # cube = AssetBaseCfg(
    #     prim_path="{ENV_REGEX_NS}/Cube",
    #     spawn=sim_utils.CuboidCfg(
    #         size=(0.5, 0.5, 0.5),
    #         rigid_props=sim_utils.RigidBodyPropertiesCfg(
    #             kinematic_enabled=False,
    #         ),
    #         mass_props=sim_utils.MassPropertiesCfg(
    #             mass=1.0,
    #         ),
    #         collision_props=sim_utils.CollisionPropertiesCfg(),
    #     ),
    #     init_state=AssetBaseCfg.InitialStateCfg(
    #         pos=(0.0, 0.0, 3.0),
    #     ),
    # )

    # robot = AssetBaseCfg(
    #     prim_path="{ENV_REGEX_NS}/Robot",
    #     spawn=sim_utils.UsdFileCfg(
    #         usd_path="/home/johanna/Workspaces/msc_project_ws/multi-agent-robots/IsaacSim/Robots/rover_rb3/rover_rb3.usda",
    #     ),
    #     init_state=AssetBaseCfg.InitialStateCfg(
    #         pos=(0.0, 0.0, 3.0),
    #     ),
    # )


# -----------------------------------------------------------------------------
# Environment configuration
# -----------------------------------------------------------------------------

@configclass
class TestEnvCfg(DirectRLEnvCfg):

    decimation = 1
    episode_length_s = 10.0

    action_space = 2
    observation_space = 1
    state_space = 0

    linear_scale = 0.25   # m/s
    angular_scale = 0.5   # rad/s

    sim = SimulationCfg(
        device="cuda:0",
        dt=1.0 / 60.0,
        render_interval=1,
    )

    scene = TestSceneCfg(
        num_envs=1,
        env_spacing=2.0,
        replicate_physics=True,
        clone_in_fabric=True,
    )


# -----------------------------------------------------------------------------
# Environment
# -----------------------------------------------------------------------------

class TestDirectEnv(DirectRLEnv):

    cfg: TestEnvCfg

    def __init__(
        self,
        cfg: TestEnvCfg,
        render_mode: str | None = None,
        **kwargs,
    ):
        super().__init__(cfg, render_mode, **kwargs)

        self.wheel_radius = 0.038
        self.wheel_base = 0.095
        self.rover_rb3_controller = DifferentialController(wheel_radius=0.038, wheel_base=0.095)

        print("===================================")
        print("Minimal DirectRL environment ready")
        print("Scene:", self.scene.keys())
        print("===================================")

    # -------------------------------------------------------------------------
    # Scene
    # -------------------------------------------------------------------------

    def _setup_scene(self):

        self.scene.clone_environments(copy_from_source=False)

        # Ground is global, so don't replicate it.
        self.scene.filter_collisions(
            global_prim_paths=["/World/ground"]
        )

        print("Scene setup complete.")

    # -------------------------------------------------------------------------
    # Actions
    # -------------------------------------------------------------------------

    def _pre_physics_step(self, actions: torch.Tensor):
        self.actions = actions.clone()

    def _apply_action(self):

        linear_speed = self.actions[:, 0]
        angular_speed = self.actions[:, 1]

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

        self.scene["rover_rb3"].write_joint_velocity_to_sim(wheel_velocities) # ignore warning as the proposed function uses Warp


    # -------------------------------------------------------------------------
    # Observations
    # -------------------------------------------------------------------------

    def _get_observations(self):

        # Dummy observation.
        obs = torch.zeros(
            (self.num_envs, 1),
            device=self.device,
        )

        return {"policy": obs}

    # -------------------------------------------------------------------------
    # Rewards
    # -------------------------------------------------------------------------

    def _get_rewards(self):

        return torch.zeros(
            self.num_envs,
            device=self.device,
        )

    # -------------------------------------------------------------------------
    # Termination
    # -------------------------------------------------------------------------

    def _get_dones(self):

        terminated = torch.zeros(
            self.num_envs,
            dtype=torch.bool,
            device=self.device,
        )

        time_out = (
            self.episode_length_buf
            >= self.max_episode_length - 1
        )

        return terminated, time_out

    # -------------------------------------------------------------------------
    # Reset
    # -------------------------------------------------------------------------

    def _reset_idx(self, env_ids):

        if env_ids is None:
            env_ids = self.scene["rover_rb3"]._ALL_INDICES

        super()._reset_idx(env_ids)


# -----------------------------------------------------------------------------
# Main
# -----------------------------------------------------------------------------

if __name__ == "__main__":

    env_cfg = TestEnvCfg()

    print("Creating environment...")

    env = TestDirectEnv(
        cfg=env_cfg,
        render_mode="human",
    )

    print("Environment created.")

    obs, info = env.reset()

    rover_rb3 = env.scene["rover_rb3"]

    print("Environment reset.")

    print("INITIAL VELOCITY:")
    print(rover_rb3.data.root_lin_vel_w)

    # -------------------------------------------------------------------------
    # Training / simulation loop
    # -------------------------------------------------------------------------

    for episodes in range(30):
        for step in range(100):

            actions = (
                torch.rand(
                    (env.num_envs, env.cfg.action_space),
                    device=env.device,
                )
                * 2.0
                - 1.0
            )

            obs, rewards, terminated, truncated, info = env.step(actions)
            simulation_app.update()

            if step % 10 == 0:
                print(f"\nSTEP {step}")
                print("JOINT VEL:", rover_rb3.data.joint_vel)
                print("JOINT POS:", rover_rb3.data.joint_pos)
                print("ROOT VEL:", rover_rb3.data.root_lin_vel_w)
                print(
                    f"STEP {step:03d} | "
                    f"root velocity = {rover_rb3.data.root_lin_vel_w}"
                )

                # if torch.any(terminated) or torch.any(truncated):
                #     break

            simulation_app.update()

    print("FINAL VELOCITY:")
    print(rover_rb3.data.root_lin_vel_w)

    # -------------------------------------------------------------------------
    # Shutdown
    # -------------------------------------------------------------------------

    env.close()
    simulation_app.close()