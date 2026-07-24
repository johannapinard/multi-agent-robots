import rclpy
from sensor_msgs.msg import BatteryState
from nav_msgs.srv import GetMap
from xgo_ros.xgo_bt_node import XGOBTNode
from multi_agents.robots.Robot import Robot


class XGOLite(Robot):
    def __init__(self):
        super().__init__("XGOLite")
        self.actions_list = ["move", "go_to", "pick", "get_map", "check_battery"]
        self._control = XGOBTNode()
        self._current_battery = 100

        self._battery_subscriber = self.create_subscription(BatteryState, '/xgo/battery', self._check_battery, 10)

        # msg OK
        # self.answer_timer = self.create_timer(
        #     1.0, self._send_answer)
        # self.info_timer = self.create_timer(
        #     1.0, self._send_info)
        # self.introduction_timer = self.create_timer(
        #     1.0, self._send_introduction)

        # self.move_timer = self.create_timer(
        #     0.01, self._move(1, 0, 0.5))
        self._move(1, 0, 0.5)

    # direction forward 1 backward -1 turn right 1 left -1 speed between 0 and 1
    def _move(self, direction, turn, speed):
        self._control.move(direction, turn, speed)

    # TODO check nav2 / xgo_lite nav
    def _go_to(self, x, y):
        pass

    def _stop(self):
        self._control.stop()

    def _pick(self, obj_x, obj_y, obj_z):
        self._control.pick()

    def _get_map(self):
        # TODO implement and call map service
        pass

    def _check_battery(self, msg):
        self._current_battery = msg.percentage


def main(args=None):
    rclpy.init(args=args)

    xgo_lite = XGOLite()

    rclpy.spin(xgo_lite)

    xgo_lite.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
