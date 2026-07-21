// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from communication_msgs:msg/Request.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/msg/request.h"


#ifndef COMMUNICATION_MSGS__MSG__DETAIL__REQUEST__STRUCT_H_
#define COMMUNICATION_MSGS__MSG__DETAIL__REQUEST__STRUCT_H_

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
// Member 'to'
// Member 'action_name'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Request in the package communication_msgs.
typedef struct communication_msgs__msg__Request
{
  std_msgs__msg__Header header;
  int32_t id;
  /// all, robot_name
  rosidl_runtime_c__String to;
  rosidl_runtime_c__String action_name;
} communication_msgs__msg__Request;

// Struct for a sequence of communication_msgs__msg__Request.
typedef struct communication_msgs__msg__Request__Sequence
{
  communication_msgs__msg__Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__msg__Request__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMMUNICATION_MSGS__MSG__DETAIL__REQUEST__STRUCT_H_
