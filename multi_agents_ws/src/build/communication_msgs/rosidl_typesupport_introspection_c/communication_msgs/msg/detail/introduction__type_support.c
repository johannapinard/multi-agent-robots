// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from communication_msgs:msg/Introduction.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "communication_msgs/msg/detail/introduction__rosidl_typesupport_introspection_c.h"
#include "communication_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "communication_msgs/msg/detail/introduction__functions.h"
#include "communication_msgs/msg/detail/introduction__struct.h"


// Include directives for member types
// Member `name`
// Member `available_actions`
// Member `frame_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose`
#include "geometry_msgs/msg/pose.h"
// Member `pose`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__Introduction_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  communication_msgs__msg__Introduction__init(message_memory);
}

void communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__Introduction_fini_function(void * message_memory)
{
  communication_msgs__msg__Introduction__fini(message_memory);
}

size_t communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__size_function__Introduction__available_actions(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__get_const_function__Introduction__available_actions(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__get_function__Introduction__available_actions(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__fetch_function__Introduction__available_actions(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__get_const_function__Introduction__available_actions(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__assign_function__Introduction__available_actions(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__get_function__Introduction__available_actions(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__resize_function__Introduction__available_actions(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__Introduction_message_member_array[4] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(communication_msgs__msg__Introduction, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "available_actions",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(communication_msgs__msg__Introduction, available_actions),  // bytes offset in struct
    NULL,  // default value
    communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__size_function__Introduction__available_actions,  // size() function pointer
    communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__get_const_function__Introduction__available_actions,  // get_const(index) function pointer
    communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__get_function__Introduction__available_actions,  // get(index) function pointer
    communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__fetch_function__Introduction__available_actions,  // fetch(index, &value) function pointer
    communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__assign_function__Introduction__available_actions,  // assign(index, value) function pointer
    communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__resize_function__Introduction__available_actions  // resize(index) function pointer
  },
  {
    "frame_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(communication_msgs__msg__Introduction, frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(communication_msgs__msg__Introduction, pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__Introduction_message_members = {
  "communication_msgs__msg",  // message namespace
  "Introduction",  // message name
  4,  // number of fields
  sizeof(communication_msgs__msg__Introduction),
  false,  // has_any_key_member_
  communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__Introduction_message_member_array,  // message members
  communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__Introduction_init_function,  // function to initialize message memory (memory has to be allocated)
  communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__Introduction_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__Introduction_message_type_support_handle = {
  0,
  &communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__Introduction_message_members,
  get_message_typesupport_handle_function,
  &communication_msgs__msg__Introduction__get_type_hash,
  &communication_msgs__msg__Introduction__get_type_description,
  &communication_msgs__msg__Introduction__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_communication_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, communication_msgs, msg, Introduction)() {
  communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__Introduction_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__Introduction_message_type_support_handle.typesupport_identifier) {
    communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__Introduction_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &communication_msgs__msg__Introduction__rosidl_typesupport_introspection_c__Introduction_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
