# Reference: source/standalone_examples/api/isaacsim.robot.wheeled_robots.examples/jetbot_differential_move.py
# Timeline: use app_utils (play/stop/is_playing) instead of omni.timeline. Use app_utils.update_app(steps=N) instead of for-loop simulation_app.update(); same for other mobile_robot_controllers examples.

from isaacsim.core.api.world import World
from isaacsim.robot.experimental.wheeled_robots.controllers import DifferentialController
from isaacsim.robot.experimental.wheeled_robots.robots import WheeledRobot
import omni
import carb
import asyncio
import rclpy
from geometry_msgs.msg import Twist

cmd_vel_node = None
cmd_vel_pub = None

# rclpy.init()

cmd_vel_node = rclpy.create_node("rb3_cmd_vel_publisher")

cmd_vel_pub = cmd_vel_node.create_publisher(Twist, "/cmd_vel_executed", 10)


input_iface = carb.input.acquire_input_interface()
keyboard = omni.appwindow.get_default_app_window().get_keyboard()
rover_rb3_controller = None
robot = None
drive = False

linear_speed = -0.1 # negative forward, positive backward
angular_speed = 0.0 # negative left, positive right

def keyboard_callback(event, *args):
    global drive
    if event.type == carb.input.KeyboardEventType.KEY_PRESS:
        if event.input == carb.input.KeyboardInput.SPACE:
            drive = True

def publish_cmd_vel():
    msg = Twist()

    msg.linear.x = -linear_speed # cheating because it was inverted on Rviz
    msg.linear.y = 0.0
    msg.linear.z = 0.0

    msg.angular.x = 0.0
    msg.angular.y = 0.0
    msg.angular.z = angular_speed

    cmd_vel_pub.publish(msg)

def update(dt):
    global drive
    if drive:
        velocities = rover_rb3_controller.forward([linear_speed, angular_speed])
        left, right = velocities # returns velocities for two-wheeled robots

        four_wheels_velocities = [
            left,   # FL
            right,  # FR
            left,   # RL
            right,  # RR
        ]

        robot.apply_wheel_actions(four_wheels_velocities)

        publish_cmd_vel()

        rclpy.spin_once(cmd_vel_node, timeout_sec=0.0)


async def main():
    print("rover init")
    global robot, rover_rb3_controller

    omni.usd.get_context().get_stage()

    world = World()
    await world.initialize_simulation_context_async()

    robot = WheeledRobot(
        paths="/Environment/_ROBOTS_/rover_rb3",
        wheel_dof_names=["wheel_fl_joint", "wheel_fr_joint", "wheel_rl_joint", "wheel_rr_joint"],
        usd_path="/home/johanna/Workspaces/msc_project_ws/multi-agent-robots/IsaacSim/Robots/rover_rb3/rover_rb3.usda"
    )

    # TODO general config file
    rover_rb3_controller = DifferentialController(wheel_radius=0.038, wheel_base=0.095)

    await world.reset_async()

    #robot.initialize()

    # initial_pose = robot.get_joint_positions()

    input_iface.subscribe_to_keyboard_events(
        keyboard,
        keyboard_callback
    )

    # register physics loop callback -> app running
    world.add_physics_callback("rover_control", update)

asyncio.ensure_future(main())
