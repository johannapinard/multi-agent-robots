// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from communication_msgs:action/Action.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/action/action.h"


#ifndef COMMUNICATION_MSGS__ACTION__DETAIL__ACTION__STRUCT_H_
#define COMMUNICATION_MSGS__ACTION__DETAIL__ACTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'type'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Action in the package communication_msgs.
typedef struct communication_msgs__action__Action_Goal
{
  /// communication_msg/Search, communication_msg/Pick
  rosidl_runtime_c__String type;
} communication_msgs__action__Action_Goal;

// Struct for a sequence of communication_msgs__action__Action_Goal.
typedef struct communication_msgs__action__Action_Goal__Sequence
{
  communication_msgs__action__Action_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__action__Action_Goal__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'color'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in action/Action in the package communication_msgs.
typedef struct communication_msgs__action__Action_Result
{
  rosidl_runtime_c__String color;
} communication_msgs__action__Action_Result;

// Struct for a sequence of communication_msgs__action__Action_Result.
typedef struct communication_msgs__action__Action_Result__Sequence
{
  communication_msgs__action__Action_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__action__Action_Result__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'requested_pose'
#include "geometry_msgs/msg/detail/pose__struct.h"

/// Struct defined in action/Action in the package communication_msgs.
typedef struct communication_msgs__action__Action_Feedback
{
  geometry_msgs__msg__Pose requested_pose;
} communication_msgs__action__Action_Feedback;

// Struct for a sequence of communication_msgs__action__Action_Feedback.
typedef struct communication_msgs__action__Action_Feedback__Sequence
{
  communication_msgs__action__Action_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__action__Action_Feedback__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "communication_msgs/action/detail/action__struct.h"

/// Struct defined in action/Action in the package communication_msgs.
typedef struct communication_msgs__action__Action_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  communication_msgs__action__Action_Goal goal;
} communication_msgs__action__Action_SendGoal_Request;

// Struct for a sequence of communication_msgs__action__Action_SendGoal_Request.
typedef struct communication_msgs__action__Action_SendGoal_Request__Sequence
{
  communication_msgs__action__Action_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__action__Action_SendGoal_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Action in the package communication_msgs.
typedef struct communication_msgs__action__Action_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} communication_msgs__action__Action_SendGoal_Response;

// Struct for a sequence of communication_msgs__action__Action_SendGoal_Response.
typedef struct communication_msgs__action__Action_SendGoal_Response__Sequence
{
  communication_msgs__action__Action_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__action__Action_SendGoal_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  communication_msgs__action__Action_SendGoal_Event__request__MAX_SIZE = 1
};
// response
enum
{
  communication_msgs__action__Action_SendGoal_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Action in the package communication_msgs.
typedef struct communication_msgs__action__Action_SendGoal_Event
{
  service_msgs__msg__ServiceEventInfo info;
  communication_msgs__action__Action_SendGoal_Request__Sequence request;
  communication_msgs__action__Action_SendGoal_Response__Sequence response;
} communication_msgs__action__Action_SendGoal_Event;

// Struct for a sequence of communication_msgs__action__Action_SendGoal_Event.
typedef struct communication_msgs__action__Action_SendGoal_Event__Sequence
{
  communication_msgs__action__Action_SendGoal_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__action__Action_SendGoal_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Action in the package communication_msgs.
typedef struct communication_msgs__action__Action_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} communication_msgs__action__Action_GetResult_Request;

// Struct for a sequence of communication_msgs__action__Action_GetResult_Request.
typedef struct communication_msgs__action__Action_GetResult_Request__Sequence
{
  communication_msgs__action__Action_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__action__Action_GetResult_Request__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "communication_msgs/action/detail/action__struct.h"

/// Struct defined in action/Action in the package communication_msgs.
typedef struct communication_msgs__action__Action_GetResult_Response
{
  int8_t status;
  communication_msgs__action__Action_Result result;
} communication_msgs__action__Action_GetResult_Response;

// Struct for a sequence of communication_msgs__action__Action_GetResult_Response.
typedef struct communication_msgs__action__Action_GetResult_Response__Sequence
{
  communication_msgs__action__Action_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__action__Action_GetResult_Response__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'info'
// already included above
// #include "service_msgs/msg/detail/service_event_info__struct.h"

// constants for array fields with an upper bound
// request
enum
{
  communication_msgs__action__Action_GetResult_Event__request__MAX_SIZE = 1
};
// response
enum
{
  communication_msgs__action__Action_GetResult_Event__response__MAX_SIZE = 1
};

/// Struct defined in action/Action in the package communication_msgs.
typedef struct communication_msgs__action__Action_GetResult_Event
{
  service_msgs__msg__ServiceEventInfo info;
  communication_msgs__action__Action_GetResult_Request__Sequence request;
  communication_msgs__action__Action_GetResult_Response__Sequence response;
} communication_msgs__action__Action_GetResult_Event;

// Struct for a sequence of communication_msgs__action__Action_GetResult_Event.
typedef struct communication_msgs__action__Action_GetResult_Event__Sequence
{
  communication_msgs__action__Action_GetResult_Event * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__action__Action_GetResult_Event__Sequence;

// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "communication_msgs/action/detail/action__struct.h"

/// Struct defined in action/Action in the package communication_msgs.
typedef struct communication_msgs__action__Action_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  communication_msgs__action__Action_Feedback feedback;
} communication_msgs__action__Action_FeedbackMessage;

// Struct for a sequence of communication_msgs__action__Action_FeedbackMessage.
typedef struct communication_msgs__action__Action_FeedbackMessage__Sequence
{
  communication_msgs__action__Action_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} communication_msgs__action__Action_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMMUNICATION_MSGS__ACTION__DETAIL__ACTION__STRUCT_H_
