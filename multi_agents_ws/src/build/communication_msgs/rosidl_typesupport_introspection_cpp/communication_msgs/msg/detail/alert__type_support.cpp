// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from communication_msgs:msg/Alert.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "communication_msgs/msg/detail/alert__functions.h"
#include "communication_msgs/msg/detail/alert__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace communication_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void Alert_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) communication_msgs::msg::Alert(_init);
}

void Alert_fini_function(void * message_memory)
{
  auto typed_message = static_cast<communication_msgs::msg::Alert *>(message_memory);
  typed_message->~Alert();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember Alert_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(communication_msgs::msg::Alert, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "code",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(communication_msgs::msg::Alert, code),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers Alert_message_members = {
  "communication_msgs::msg",  // message namespace
  "Alert",  // message name
  2,  // number of fields
  sizeof(communication_msgs::msg::Alert),
  false,  // has_any_key_member_
  Alert_message_member_array,  // message members
  Alert_init_function,  // function to initialize message memory (memory has to be allocated)
  Alert_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t Alert_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &Alert_message_members,
  get_message_typesupport_handle_function,
  &communication_msgs__msg__Alert__get_type_hash,
  &communication_msgs__msg__Alert__get_type_description,
  &communication_msgs__msg__Alert__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace communication_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<communication_msgs::msg::Alert>()
{
  return &::communication_msgs::msg::rosidl_typesupport_introspection_cpp::Alert_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, communication_msgs, msg, Alert)() {
  return &::communication_msgs::msg::rosidl_typesupport_introspection_cpp::Alert_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
