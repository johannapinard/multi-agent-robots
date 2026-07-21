import rclpy
from multi_agents.robots.Robot import Robot


class XGOLite(Robot):
    def __init__(self):
        super().__init__("XGOLite")
        self.actions_list = ["move", "go_to", "pick", "get_map", "check_battery"]

        # msg OK
        # self.answer_timer = self.create_timer(
        #     1.0, self._send_answer)
        # self.info_timer = self.create_timer(
        #     1.0, self._send_info)
        # self.introduction_timer = self.create_timer(
        #     1.0, self._send_introduction)


    def _move(self, direction, speed):
        pass

    def _go_to(self, x, y):
        pass

    def _pick(self, obj_x, obj_y, obj_z):
        pass

    def _get_map(self):
        pass

    def _check_battery(self):
        pass


def main(args=None):
    rclpy.init(args=args)

    xgo_lite = XGOLite()

    rclpy.spin(xgo_lite)

    xgo_lite.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
