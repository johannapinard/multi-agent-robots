# to use if app is not running
# from isaacsim import SimulationApp

# simulation_app = SimulationApp({"headless": False})

from isaacsim.core.api.world import World
from isaacsim.core.prims import SingleArticulation, XFormPrim # GameObject
from isaacsim.core.utils.stage import add_reference_to_stage
from isaacsim.core.utils.types import ArticulationAction
from pxr import UsdGeom, Usd, UsdPhysics
import omni
import carb
import omni.appwindow
import copy
from quadruped_gait_generator import BezierGait
from quadruped_kinematics import XGOModel
import numpy as np
import asyncio


gait = None
xgo_ik = None
robot = None
orn = None
pos = None
T_bf_init = None
physics_sub = None
FL_offset = np.array([-0.0016, 0.8941, -1.4603])
FR_offset = np.array([0.0047, 0.8955, -1.4624])
BL_offset = np.array([-0.0016, 0.8567, -1.4616])
BR_offset = np.array([-0.0005, 0.8787, -1.4685])
input_iface = carb.input.acquire_input_interface()
keyboard = omni.appwindow.get_default_app_window().get_keyboard()
walk = False

def make_transform_from_target_pos(p):
    T = np.eye(4)
    T[:3, 3] = p
    return T

def keyboard_callback(event, *args):
    global walk
    if event.type == carb.input.KeyboardEventType.KEY_PRESS:
        if event.input == carb.input.KeyboardInput.SPACE:
            walk = True

def update(dt):
    global walk
    if walk:
        T_bf = gait.GenerateTrajectory(
            L=0.05,             # L is half of stride length -> leg movements, negative to go backwards
            LateralFraction=0.0,
            YawRate=0.0,        # positive left negative right
            vel=1.0,            # joint speed
            T_bf_= T_bf_init,
            clearance_height=0.0,
            penetration_depth=0.01 # force applied on the ground to push
        )

        angles = xgo_ik.IK(orn, pos, T_bf)

        '''
        Hip abduction (joint 3)
        0  FL 13
        1  FR 23
        2  BL 33
        3  BR 43
        4  Arm 53

        Hip pitch (joint 2)
        5  FL 12
        6  FR 22
        7  BL 32
        8  BR 42
        9  Arm 52

        Knee (joint 1)
        10 FL 11
        11 FR 21
        12 BL 31
        13 BR 41
        14 Arm 51

        15 Arm joint 50
        16 Gripper 500
        '''

        joint_cmd = robot.get_joint_positions()

        # First leg joint layer
        joint_cmd[0] = angles[0, 0] - FL_offset[0]   # FL
        joint_cmd[1] = angles[1, 0] - FR_offset[0]   # FR
        joint_cmd[2] = angles[3, 0] - BR_offset[0]  # BL
        joint_cmd[3] = angles[2, 0] - BL_offset[0]  # BR

        # Second leg joint layer
        joint_cmd[5] = angles[0, 1] - FL_offset[1]
        joint_cmd[6] = angles[1, 1] - FR_offset[1]
        joint_cmd[7] = angles[3, 1] - BR_offset[1]
        joint_cmd[8] = angles[2, 1] - BL_offset[1]

        # Third leg joint layer
        joint_cmd[10] = angles[0, 2] - FL_offset[2]
        joint_cmd[11] = angles[1, 2] - FR_offset[2]
        joint_cmd[12] = angles[3, 2] - BR_offset[2]
        joint_cmd[13] = angles[2, 2] - BL_offset[2]

        # # First leg joint layer
        # joint_cmd[0] = 0
        # joint_cmd[1] = 0
        # joint_cmd[2] = 0
        # joint_cmd[3] = 0
        # # Second leg joint layer
        # joint_cmd[5] = 0
        # joint_cmd[6] = 0
        # joint_cmd[7] = 0
        # joint_cmd[8] = 0
        # # Third leg joint layer
        # joint_cmd[10] = 0
        # joint_cmd[11] = 0
        # joint_cmd[12] = 0
        # joint_cmd[13] = 0

        print(joint_cmd)

        # robot.set_joint_positions(joint_cmd)

        robot.apply_action(
            ArticulationAction(joint_positions=joint_cmd)
        )

        # walk = False

async def main():
    global gait, xgo_ik, robot, orn, pos, T_bf_init, physics_sub, initial_pose, FL_target, FR_target, RR_target, RL_target

    stage = omni.usd.get_context().get_stage()

    world = World()
    await world.initialize_simulation_context_async()

    robot = SingleArticulation(
        prim_path="/Environment/_ROBOTS_/xgo_lite",
        name="xgo_lite",
    )

    FL_target = stage.GetPrimAtPath("/Environment/_ROBOTS_/xgo_lite/Geometry/world/base_link/FL_foot_target")
    FR_target = stage.GetPrimAtPath("/Environment/_ROBOTS_/xgo_lite/Geometry/world/base_link/FR_foot_target")
    RL_target = stage.GetPrimAtPath("/Environment/_ROBOTS_/xgo_lite/Geometry/world/base_link/RL_foot_target")
    RR_target = stage.GetPrimAtPath("/Environment/_ROBOTS_/xgo_lite/Geometry/world/base_link/RR_foot_target")

    xform_fl = UsdGeom.Xformable(FL_target)
    xform_fr = UsdGeom.Xformable(FR_target)
    xform_rl = UsdGeom.Xformable(RL_target)
    xform_rr = UsdGeom.Xformable(RR_target)

    await world.reset_async()

    robot.initialize()

    # initial_pose = robot.get_joint_positions()

    # retrieve the relative position of each foot (IK targets) to the base_link
    fl_pos = xform_fl.GetLocalTransformation()
    fr_pos = xform_fr.GetLocalTransformation()
    rl_pos = xform_rl.GetLocalTransformation()
    rr_pos = xform_rr.GetLocalTransformation()

    # Move to home pose
    # joint_pos = np.zeros(robot.num_dof)

    # robot.set_joint_positions(joint_pos)

    # Moves one joint
    # idx = robot.get_dof_index("tn__11_Joint_")

    # joint_pos = robot.get_joint_positions()
    # joint_pos[idx] = 0.5

    # robot.set_joint_positions(joint_pos)

    gait = BezierGait()

    orn = np.array([0.0, 0.0, 0.0])      # roll, pitch, yaw
    pos = np.array([0.0, 0.0, 0.0])      # body centered at origin

    xgo_ik = XGOModel()

    T_bf_init = {
    "FL": make_transform_from_target_pos(fl_pos.ExtractTranslation()),
    "FR": make_transform_from_target_pos(fr_pos.ExtractTranslation()),
    "BL": make_transform_from_target_pos(rl_pos.ExtractTranslation()),
    "BR": make_transform_from_target_pos(rr_pos.ExtractTranslation()),
    }

    # robot.set_joint_positions(initial_pose)

    # physics loop

    # if app is not running
    # while simulation_app.is_running():
        # world.step(render=True)

        # await world.play_async()
    
    input_iface.subscribe_to_keyboard_events(
    keyboard,
    keyboard_callback
    )

    # register physics loop callback -> app not running
    world.add_physics_callback("gait", update)

asyncio.ensure_future(main())

# stage_utils.add_reference_to_stage(
#     usd_path="/home/johanna/Workspaces/msc_project_ws/multi-agent-robots/IsaacSim/Robots/mini2_description/mini2_description.usda",
#     path="/Environment/_ROBOTS_/xgo_lite"
# )

# from isaacsim.core.utils.types import ArticulationAction
# import numpy as np

# joint_angles = [
# 13,12,11,
# 23,22,21,
# 33,32,31,
# 43,42,41
# ]

# LEG_JOINTS = [
#     "13_Joint",
#     "12_Joint",
#     "11_Joint",
#     "23_Joint",
#     "22_Joint",
#     "21_Joint",
#     "33_Joint",
#     "32_Joint",
#     "31_Joint",
#     "43_Joint",
#     "42_Joint",
#     "41_Joint",
# ]

# robot = SingleArticulation(
#     prim_path="/Environment/_ROBOTS_/xgo_lite",
#     name="xgo_lite"
# )

# await world.reset_async()

# robot.initialize()

# print(robot.dof_names)

# foot_positions = gait_generator.step(dt)

# joint_angles = legIK.solve(foot_positions)

# q = np.zeros(robot.num_dof)

# q[0] = 0.3

# action = ArticulationAction(
#     joint_positions=q
# )

# robot.apply_action(action)

# joint_index = {
#     name: i
#     for i, name in enumerate(robot.dof_names)
# }

# robot.set_gains(
#     kp=np.ones(12)*60,
#     kd=np.ones(12)*2
# )

# q = robot.get_joint_positions()

# for name, angle in angles.items():
#     q[joint_index[name]] = angle

# robot.apply_action(
#     ArticulationAction(
#         joint_positions=q
#     )
# )