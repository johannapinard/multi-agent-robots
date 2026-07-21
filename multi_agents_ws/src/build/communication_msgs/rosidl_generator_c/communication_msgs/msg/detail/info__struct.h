// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from communication_msgs:msg/Info.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/msg/info.h"


#ifndef COMMUNICATION_MSGS__MSG__DETAIL__INFO__STRUCT_H_
#define COMMUNICATION_MSGS__MSG__DETAIL__INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'subject'
// Member 'type'
// Member 'content'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/Info in the package communication_msgs.
/**
  * TODO custom description
 */
typedef struct communication_msgs__msg__Info
{
  /// This is a message that holds data to describe the state of a set of torque controlled joints.
  ///
  /// The state of each joint (revolute or prismatic) is defined by:
  ///  * the position of the joint (rad or m),
  ///  * the velocity of the joint (rad/s or m/s) and
  ///  * the effort that is applied in the joint (Nm or N).
  ///
  /// Each joint is uniquely identified by its name
  /// The header specifies the time at which the joint states were recorded. All the joint states
  /// in one message have to be recorded at the same time.
  ///
  /// This message consists of a multiple arrays, one for each part of the joint state.
  /// The goal is to make each of the fields optional. When e.g. your joints have no
  /// effort associated with them, you can leave the effort array empty.
  ///
  /// All arrays in this message should have the same size, or be empty.
  /// This is the only way to uniquely associate the joint name with the correct
  /// states.
  std_msgs__msg__Header header;
  /// robot, human, object
  rosidl_runtime_c__String subject;
  /// text, pose
  rosidl_runtime_c__String type;
  /// data
  rosidl_runtime_c__String content;
  geometry_msgs__msg__Pose pose;
} communication_msgs__msg__Info;

// Struct for a sequence of communication_msgs__msg__Info.
typedef struct communication_msgs__msg__Info__Sequence
{
  communication_msgs__msg__Info * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__msg__Info__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMMUNICATION_MSGS__MSG__DETAIL__INFO__STRUCT_H_
