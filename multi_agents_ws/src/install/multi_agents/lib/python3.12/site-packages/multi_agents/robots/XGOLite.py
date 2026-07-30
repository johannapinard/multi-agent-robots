import rclpy
# from sensor_msgs.msg import BatteryState
from nav_msgs.srv import GetMap
from xgo2_ros.xgo_bt_node import XGOBTNode
from multi_agents.robots.Robot import Robot


class XGOLite(Robot):
    def __init__(self):
        super().__init__("XGOLite")
        self.actions_list = ["move", "go_to", "pick", "get_map"]
        self._control = XGOBTNode()

        # battery not OK
        # self._battery_subscriber = self.create_subscription(BatteryState, '/xgo/battery', self._check_battery, 10)
        # self.battery_timer = self.create_timer(
        #     1.0, self._check_battery)

        # msg OK
        # self.answer_timer = self.create_timer(
        #     1.0, self._send_answer)
        # self.info_timer = self.create_timer(
        #     1.0, self._send_info)
        # self.introduction_timer = self.create_timer(
        #     1.0, self._send_introduction)

        # functions ok
        # self._move(1, 0, 0.5) # moves continuously
        # time.sleep(1)
        # self._stop()
        # time.sleep(1)
        # self._pick()

    # direction forward 1 backward -1 turn right 1 left -1 speed between 0 and 1
    def _move(self, direction, turn, speed):
        self._control.move(direction, turn, speed)

    # TODO check nav2 / xgo_lite nav
    def _go_to(self, x, y):
        pass

    def _stop(self):
        self._control.stop()

    def _pick(self):
        self._control.pick()

    def _get_map(self):
        # TODO implement and call map service
        pass

    # TODO implement battery -- might not be possible
    # def _check_battery(self):
    #     self.get_logger().info(f'XGO MA: battery: {self._control._battery}')
    #     # self.get_logger().info(msg.percentage)
    #     # self._current_battery = msg.percentage


def main(args=None):
    rclpy.init(args=args)

    xgo_lite = XGOLite()

    rclpy.spin(xgo_lite)

    xgo_lite.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
