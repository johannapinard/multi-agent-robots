import rclpy
import cv2
import numpy as np
from geometry_msgs.msg import Twist, TwistStamped, Pose
from visualization_msgs.msg import Marker
from multi_agents.robots.Robot import Robot


RED_MASK = [[(170,70,50), (180,255,255)], [(0,120,120), (10,255,255)]]
BLUE_MASK = [(90,120,120), (115,255,255)]
CAMERA_FRAME = "camera_link"
CUBE_SIZE = 0.024
CAMERA_MATRIX = [535.9722398656454, 0.7503762811340555, 961.2167788863221,
                 0.0, 542.8814952634423, 539.8347175243642, 
                 0.0, 0.0, 1.0]
CAMERA_DIST_COEF = [0.6470512552648332, -1.6544240987455412, 2.237932646705218, -1.0510577371076386]


class RB3(Robot):
    def __init__(self):
        super().__init__("RB3")
        self.actions_list = ["move", "go_to","scan", "publish_collision_object", "detect_object"]
        self.colors_dict = {"red": self._set_red_mask(), "blue": BLUE_MASK}

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


    def set_mask(self, src, color):

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

    # todo nav2
    def _go_to(self, x, y):
        pass

    # bonus
    def _scan(self, map):
        pass

    def _detect_object(self, color, object_type="cube"):
        # todo get one frame
        frame = None
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

        # Compute center pose of cube

        # camera_matrix = np.array([[650, 0, 320],
        # ,
        #                         [0, 0, 1]], dtype=np.float32)
        # dist_coeffs = np.zeros((4, 1)) # Assuming no lens distortion for placeholder


        box_corners = np.array([
            [0, 0, 0], [CUBE_SIZE, 0, 0], [CUBE_SIZE, CUBE_SIZE, 0], [0, CUBE_SIZE, 0]
            [0, 0, -CUBE_SIZE], [CUBE_SIZE, 0, -CUBE_SIZE], [CUBE_SIZE, CUBE_SIZE, -CUBE_SIZE], [0, CUBE_SIZE, -CUBE_SIZE]
        ], dtype=np.float32)

        camera_matrix = CAMERA_MATRIX

        # Define 4 corners of a single square face in 3D space (Z = 0)
        # object_points = np.array([,
        #     [cube_size, 0, 0],
        #     [cube_size, cube_size, 0],
        #     [0, cube_size, 0]
        # ], dtype=np.float32)

        # Corresponding 2D points of these corners from your image
        # (You will extract these via corner detection, ArUco markers, or manual clicks)
        # image_points = np.array([
        #     [x0, y0], [x1, y1], [x2, y2], [x3, y3],
        #     [x4, y4], [x5, y5], [x6, y6], [x7, y7]
        # ], dtype="float32")

        # # success, rvec (rotation), tvec (translation)
        # success, rvec, tvec = cv2.solvePnP(cube_corners_3d, image_points, camera_matrix, dist_coeffs)

        # Translation vector 'tvec' gives the (X, Y, Z) position of the cube's origin (0,0,0) in the camera's coordinate frame.

        # if cv2.contourArea(largest_contour) > 500:  # Filter out tiny noise blobs
        # # Approximate the contour to a polygon to find the 4 sharp corners
        # epsilon = 0.02 * cv2.arcLength(largest_contour, True)
        # approx = cv2.approxPolyDP(largest_contour, epsilon, True)

        # # Ensure the color mask detected exactly a 4-sided shape (the square face)
        # if len(approx) == 4:
        #     # Reshape to a clean list of 2D image points
        #     image_points = approx.reshape(4, 2).astype(np.float32)

        #     # Sort the 4 corners so they match the order of 'object_points'
        #     # (Top-Left, Top-Right, Bottom-Right, Bottom-Left)
        #     sum_pts = image_points.sum(axis=1)
        #     diff_pts = np.diff(image_points, axis=1)

        #     sorted_image_points = np.zeros((4, 2), dtype=np.float32)
        #     sorted_image_points[0] = image_points[np.argmin(sum_pts)]   # Top-Left
        #     sorted_image_points[2] = image_points[np.argmax(sum_pts)]   # Bottom-Right
        #     sorted_image_points[1] = image_points[np.argmin(diff_pts)]  # Top-Right
        #     sorted_image_points[3] = image_points[np.argmax(diff_pts)]  # Bottom-Left

        #     # 4. COMPUTE POSITION (solvePnP)
        #     success, rvec, tvec = cv2.solvePnP(
        #         object_points, sorted_image_points, camera_matrix, dist_coeffs
        #     )

        #     if success:
        #         # Extract positions in centimeters
        #         x_pos = tvec[0][0]
        #         y_pos = tvec[1][0]
        #         z_pos = tvec[2][0]

        #         # Draw the detected outline and print 3D coordinates on screen
        #         cv2.drawContours(frame, [approx], -1, (0, 255, 0), 2)
        #         text = f"X: {x_pos:.1f}cm  Y: {y_pos:.1f}cm  Z: {z_pos:.1f}cm"
        #         cv2.putText(frame, text, (20, 40), cv2.FONT_HERSHEY_SIMPLEX, 0.7, (0, 0, 255), 2)

        # result in frame camera_link

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