# Parent class for all robots. Provides common MAR communication publishers and subscribers.

from rclpy.node import Node
from std_msgs.msg import Header
from moveit_msgs.msg import CollisionObject
from communication_msgs.msg import Request, Alert, Answer, Info, Introduction
from communication_msgs.action import Action


class Robot(Node):

    def __init__(self, name):
        super().__init__(name + "_node")
        self._name = name
        self.global_actions_list = ["send_request", "send_alert", "send_answer", "send_info", "send_introduction"]

        self._request_subscriber = self.create_subscription(Request, 'multi_agents/request', self._request_callback, 10)
        self._alert_subscriber = self.create_subscription(Alert, 'multi_agents/alert', self._alert_callback, 10)
        self._answer_subscriber = self.create_subscription(Answer, 'multi_agents/answer', self._answer_callback, 10)
        self._info_subscriber = self.create_subscription(Info, 'multi_agents/info', self._info_callback, 10)
        self._introduction_subscriber = self.create_subscription(Introduction, 'multi_agents/introduction', self._introduction_callback, 10)
        self._collision_object_subscriber = self.create_subscription(CollisionObject, '/collision_object', self._collision_object_callback, 10)

        self._request_publisher = self.create_publisher(Request, 'multi_agents/request', 10)
        self._alert_publisher = self.create_publisher(Alert, 'multi_agents/alert', 10)
        self._answer_publisher = self.create_publisher(Answer, 'multi_agents/answer', 10)
        self._info_publisher = self.create_publisher(Info, 'multi_agents/info', 10)
        self._introduction_publisher = self.create_publisher(Introduction, 'multi_agents/introduction', 10)


    ''' CALLBACKS '''


    def _request_callback(self, msg):
        self.get_logger().info(f'Received request id {msg.id} from {msg.header.frame_id} to {msg.to} - action: {msg.action_name}')

    def _alert_callback(self, msg):
        self.get_logger().info(f'Received alert from {msg.header.frame_id} with code: {msg.code}')

    def _answer_callback(self, msg):
        self.get_logger().info(f'Received answer for request {msg.id} from {msg.header.frame_id} to {msg.to} - action: {msg.current_action} and code: {msg.response_code}')

    def _info_callback(self, msg):
        self.get_logger().info(f'Received info from {msg.header.frame_id} - type: {msg.type}')

    def _introduction_callback(self, msg):
        self.get_logger().info(f'Received introduction from {msg.name} with actions: {msg.available_actions}')

    def _collision_object_callback(self, msg):
        self.get_logger().info(f'Received collision object: {msg.id} with size: {msg.primitives[0].dimensions}')


    ''' ACTIONS '''


    def _send_request(self):#, msg, target="all"):
        msg = Request()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "test"
        msg.to = "xgo"
        msg.id = 1
        msg.action_name = "scan"

        self._request_publisher.publish(msg)

    def _send_alert(self):#, msg, target="all"):
        msg = Alert()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "RB3"
        msg.code = 2   

        self._alert_publisher.publish(msg)

    def _send_answer(self):#, msg, target="all"):
        msg = Answer()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "xgo"
        msg.to = "RB3"
        msg.id = 1
        msg.current_action = "move"
        msg.response_code = 0

        self._answer_publisher.publish(msg)

    def _send_info(self):#, msg, target="all"):
        msg = Info()
        msg.header = Header()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.subject = "human"
        msg.type = "text"
        msg.content = "Hello, world!"

        self._info_publisher.publish(msg)

    def _send_introduction(self):#, msg, target="all"):
        msg = Introduction()
        msg.name = "RB3"
        msg.available_actions = ["move", "scan", "detect_object"]

        self._introduction_publisher.publish(msg)

    def _get_pose(self, tf, frame="map"):
        pass

    def _move(self, direction, speed):
        pass

    def _go_to(self, x, y):
        pass

    def log(self, msg):
        pass  
    