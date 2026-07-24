from communication_msgs.srv import GetPose

import rclpy
from rclpy.executors import ExternalShutdownException


def main(args=None):
    try:
        with rclpy.init(args=args):
            node = rclpy.create_node('get_pose_client_async')

            cli = node.create_client(GetPose, 'get_pose')

            req = GetPose.Request()
            while not cli.wait_for_service(timeout_sec=1.0):
                node.get_logger().info('service not available, waiting again...')

            future = cli.call_async(req)
            while rclpy.ok():
                rclpy.spin_once(node)
                if future.done():
                    result = future.result()
                    node.get_logger().info(
                        'Result of get_pose: for %s = %s' %
                        (req.a, req.b, result.sum))
                    break
    except (KeyboardInterrupt, ExternalShutdownException):
        pass


if __name__ == '__main__':
    main()