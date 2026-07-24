import rclpy
import cv2
from cv_bridge import CvBridge
import numpy as np
from geometry_msgs.msg import Twist, TwistStamped, Pose
from visualization_msgs.msg import Marker
from sensor_msgs.msg import Image
from multi_agents.robots.Robot import Robot


RED_MASK = [[(170,70,50), (180,255,255)], [(0,120,120), (10,255,255)]]
BLUE_MASK = [(90,120,120), (115,255,255)]
CAMERA_FRAME = "camera_link"
CUBE_SIZE = 0.024
CAMERA_MATRIX = np.array([
        [535.9722398656454,   0.7503762811340555, 961.2167788863221],
        [0.0,                 542.8814952634423,  539.8347175243642],
        [0.0,                 0.0,                1.0]
    ], dtype=np.float32)
CAMERA_DIST_COEF = np.array([
        0.6470512552648332, 
        -1.6544240987455412, 
        2.237932646705218, 
        -1.0510577371076386
    ], dtype=np.float32)


class RB3(Robot):
    def __init__(self):
        super().__init__("RB3")
        self.actions_list = ["move", "go_to","scan", "publish_object", "detect_object"]
        self.colors_dict = {"red": RED_MASK, "blue": BLUE_MASK}
        self._bridge = CvBridge()
        self._last_frame = None

        self._image_subscriber = self.create_subscription(Image, '/image', self._camera_callback, 10)

        # check with nav2
        self._object_publisher = self.create_publisher(Marker, '/multi_agents/objects', 10)
        self._twist_publisher = self.create_publisher(TwistStamped, '/RB3/cmd_vel', 10)

        # msg OK
        # self.request_timer = self.create_timer(
        #     1.0, self._send_request)
        # self.request_timer = self.create_timer(
        #     1.0, self._send_alert)
        # self.request_timer = self.create_timer(
        #     1.0, self._publish_object)

        # to test
        self.get_logger().info("Starting to move...")
        timer_period = 0.5  # seconds
        self.timer = self.create_timer(timer_period, self._move)


    def _camera_callback(self, msg):
        self._last_frame = self._bridge.imgmsg_to_cv2(msg)

    def _set_mask(self, src, color):

        hsv = cv2.cvtColor(src, cv2.COLOR_BGR2HSV)

        if type(color[0]) == list:
            # create mask
            mask1 = cv2.inRange(hsv, color[0][0], color[0][1]) # lower color range
            mask2 = cv2.inRange(hsv, color[1][0], color[1][1]) # upper color range

            # apply mask
            mask = mask1 + mask2

        else:
            # create mask
            mask = cv2.inRange(hsv, color[0][0], color[0][1])

        # apply mask
        return cv2.bitwise_and(src, src, mask)

    def _move(self, direction=1, turn=0.0, speed=0.5):
        # from teleop_twist_keyboard.py
        # 'i':(1,0,0,0),
        # 'o':(1,0,0,-1),
        # 'j':(0,0,0,1),
        # 'l':(0,0,0,-1),
        # 'u':(1,0,0,1),
        # ',':(-1,0,0,0),
        # '.':(-1,0,0,1),
        # 'm':(-1,0,0,-1),
        move_cmd = Twist()
        move_cmd.linear.x = speed * direction # forward 1 backward -1
        move_cmd.linear.y = speed * direction
        move_cmd.linear.z = 0.0
        move_cmd.angular.x = 0.0
        move_cmd.angular.y = 0.0
        move_cmd.angular.z = speed * turn # right 1 left -1

        twist = TwistStamped()
        twist.header.stamp = self.get_clock().now().to_msg()
        twist.twist = move_cmd

        self._twist_publisher.publish(twist)

    # TODO nav2
    def _go_to(self, x, y):
        pass

    # bonus
    def _scan(self, map):
        pass

    def _detect_object(self, color, object_type="cube"):

        frame = self._last_frame
        color_mask = self.set_mask(frame, color)
                
        cv2.imshow('Mask', color_mask)
                
        # todo draw contours
        # Find the contours in the image using the cv2.findContours function
        contours, _ = cv2.findContours(color_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE) # retrieve only the external contours and use simple shapes

        '''test'''
        # sort the contours by size using cv2.contourArea
        box_contour = contours[0]

        for c in contours[0:]:
            if len(list(box_contour)) == 0 or cv2.contourArea(c) > cv2.contourArea(box_contour):
                box_contour = c

        # compute the rotated bounding box of the largest contour
        rectangle = cv2.minAreaRect(box_contour)
        box = cv2.boxPoints(rectangle)
        box = np.intp(box)

        # draw a bounding box around the detected barcode and display the
        # image
        box = cv2.drawContours(frame, [box], 0, (0,255,0), 3) 
        ''''''

        c = max(contours, key=cv2.contourArea)

        # find 4 corners
        perimeter = cv2.arcLength(c, True)

        epsilon_max = 0.05
        approx = 0
        eps = 0.02
        while eps <= epsilon_max and (len(approx) < 4 or len(approx) > 4):
            approx = cv2.approxPolyDP(c, eps * perimeter, True)

            eps += 0.01

        if len(approx) == 4:
            raw_corners = approx.reshape(4, 2)
        else:
            print(f"Error: Found {len(approx)} corners instead of 4. Adjust the epsilon value.")

        # Estimate center pose of cube

        box_corners = np.array([
            [0, 0, 0], [CUBE_SIZE, 0, 0], [CUBE_SIZE, CUBE_SIZE, 0], [0, CUBE_SIZE, 0]
        ], dtype=np.float32)

        image_points = np.zeros((4, 2), dtype=np.float32)
        
        # Top-left has the smallest sum (x + y), bottom-right has the largest sum
        s = raw_corners.sum(axis=1)
        image_points[0] = raw_corners[np.argmin(s)] # Top-Left
        image_points[2] = raw_corners[np.argmax(s)] # Bottom-Right
        
        # Top-right has the smallest difference (x - y), bottom-left has the largest difference
        diff = np.diff(raw_corners, axis=1).flatten()
        image_points[1] = raw_corners[np.argmin(diff)] # Top-Right
        image_points[3] = raw_corners[np.argmax(diff)] # Bottom-Left

        # rvec = rotation), tvec = translation
        success, rvec, tvec = cv2.solvePnP(box_corners, image_points, CAMERA_MATRIX, CAMERA_DIST_COEF)

        # result in frame camera_link
        return success, tvec, rvec

    def _publish_object(self, size, pose, type=Marker.CUBE):
        object = Marker()
        object.header.frame_id = CAMERA_FRAME
        object.ns = "cube"
        object.type = type
        object.action = Marker.ADD
        object.pose = pose
        object.scale.x = size
        object.scale.y = size
        object.scale.z = size
        object.color.b = 1.0

        self._object_publisher.publish(object)
        self.get_logger().info('Publishing detected object')


def main(args=None):
    rclpy.init(args=args)

    rb3 = RB3()

    rclpy.spin(rb3)

    rb3.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()