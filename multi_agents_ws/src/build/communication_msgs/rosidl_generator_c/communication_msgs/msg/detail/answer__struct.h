// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from communication_msgs:msg/Answer.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/msg/answer.h"


#ifndef COMMUNICATION_MSGS__MSG__DETAIL__ANSWER__STRUCT_H_
#define COMMUNICATION_MSGS__MSG__DETAIL__ANSWER__STRUCT_H_

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
// Member 'current_action'
// Member 'details'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Answer in the package communication_msgs.
typedef struct communication_msgs__msg__Answer
{
  std_msgs__msg__Header header;
  /// should be the same as request id
  int32_t id;
  rosidl_runtime_c__String to;
  /// 0 error, 1 success, 2 ongoing
  int32_t response_code;
  /// move, scan etc
  rosidl_runtime_c__String current_action;
  /// human-readable log message
  rosidl_runtime_c__String details;
} communication_msgs__msg__Answer;

// Struct for a sequence of communication_msgs__msg__Answer.
typedef struct communication_msgs__msg__Answer__Sequence
{
  communication_msgs__msg__Answer * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__msg__Answer__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMMUNICATION_MSGS__MSG__DETAIL__ANSWER__STRUCT_H_
