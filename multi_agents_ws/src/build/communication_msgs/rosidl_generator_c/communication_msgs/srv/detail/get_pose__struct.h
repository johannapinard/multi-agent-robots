// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from communication_msgs:srv/GetPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/srv/get_pose.h"


#ifndef COMMUNICATION_MSGS__SRV__DETAIL__GET_POSE__STRUCT_H_
#define COMMUNICATION_MSGS__SRV__DETAIL__GET_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'item'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetPose in the package communication_msgs.
typedef struct communication_msgs__srv__GetPose_Request
{
  rosidl_runtime_c__String item;
} communication_msgs__srv__GetPose_Request;

// Struct for a sequence of communication_msgs__srv__GetPose_Request.
typedef struct communication_msgs__srv__GetPose_Request__Sequence
{
  communication_msgs__srv__GetPose_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__srv__GetPose_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'color'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/GetPose in the package communication_msgs.
typedef struct communication_msgs__srv__GetPose_Response
{
  rosidl_runtime_c__String color;
} communication_msgs__srv__GetPose_Response;

// Struct for a sequence of communication_msgs__srv__GetPose_Response.
typedef struct communication_msgs__srv__GetPose_Response__Sequence
{
  communication_msgs__srv__GetPose_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__srv__GetPose_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  communication_msgs__srv__GetPose_Event__request__MAX_SIZE = 1
};
// response
enum
{
  communication_msgs__srv__GetPose_Event__response__MAX_SIZE = 1
};

/// Struct defined in srv/GetPose in the package communication_msgs.
typedef struct communication_msgs__srv__GetPose_Event
{
  service_msgs__msg__ServiceEventInfo info;
  communication_msgs__srv__GetPose_Request__Sequence request;
  communication_msgs__srv__GetPose_Response__Sequence response;
} communication_msgs__srv__GetPose_Event;

// Struct for a sequence of communication_msgs__srv__GetPose_Event.
typedef struct communication_msgs__srv__GetPose_Event__Sequence
{
  communication_msgs__srv__GetPose_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__srv__GetPose_Event__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMMUNICATION_MSGS__SRV__DETAIL__GET_POSE__STRUCT_H_
