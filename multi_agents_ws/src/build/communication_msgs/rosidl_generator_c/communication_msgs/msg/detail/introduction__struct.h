// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from communication_msgs:msg/Introduction.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/msg/introduction.h"


#ifndef COMMUNICATION_MSGS__MSG__DETAIL__INTRODUCTION__STRUCT_H_
#define COMMUNICATION_MSGS__MSG__DETAIL__INTRODUCTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'name'
// Member 'available_actions'
// Member 'frame_id'
#include "rosidl_runtime_c/string.h"
// Member 'pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in msg/Introduction in the package communication_msgs.
/**
  * Message sent to all robots
 */
typedef struct communication_msgs__msg__Introduction
{
  rosidl_runtime_c__String name;
  rosidl_runtime_c__String__Sequence available_actions;
  rosidl_runtime_c__String frame_id;
  geometry_msgs__msg__Pose pose;
} communication_msgs__msg__Introduction;

// Struct for a sequence of communication_msgs__msg__Introduction.
typedef struct communication_msgs__msg__Introduction__Sequence
{
  communication_msgs__msg__Introduction * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__msg__Introduction__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMMUNICATION_MSGS__MSG__DETAIL__INTRODUCTION__STRUCT_H_
