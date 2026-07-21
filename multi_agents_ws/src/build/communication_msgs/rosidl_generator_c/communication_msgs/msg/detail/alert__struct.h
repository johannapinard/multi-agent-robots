// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from communication_msgs:msg/Alert.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/msg/alert.h"


#ifndef COMMUNICATION_MSGS__MSG__DETAIL__ALERT__STRUCT_H_
#define COMMUNICATION_MSGS__MSG__DETAIL__ALERT__STRUCT_H_

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

/// Struct defined in msg/Alert in the package communication_msgs.
/**
  * Message sent to all robots
 */
typedef struct communication_msgs__msg__Alert
{
  std_msgs__msg__Header header;
  /// 1: battery below 20%, 2: sensor not available
  int32_t code;
} communication_msgs__msg__Alert;

// Struct for a sequence of communication_msgs__msg__Alert.
typedef struct communication_msgs__msg__Alert__Sequence
{
  communication_msgs__msg__Alert * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__msg__Alert__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMMUNICATION_MSGS__MSG__DETAIL__ALERT__STRUCT_H_
