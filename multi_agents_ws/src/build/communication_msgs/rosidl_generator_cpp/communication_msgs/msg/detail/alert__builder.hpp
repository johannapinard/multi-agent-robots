// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from communication_msgs:msg/Alert.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/msg/alert.hpp"


#ifndef COMMUNICATION_MSGS__MSG__DETAIL__ALERT__BUILDER_HPP_
#define COMMUNICATION_MSGS__MSG__DETAIL__ALERT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "communication_msgs/msg/detail/alert__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace communication_msgs
{

namespace msg
{

namespace builder
{

class Init_Alert_code
{
public:
  explicit Init_Alert_code(::communication_msgs::msg::Alert & msg)
  : msg_(msg)
  {}
  ::communication_msgs::msg::Alert code(::communication_msgs::msg::Alert::_code_type arg)
  {
    msg_.code = std::move(arg);
    return std::move(msg_);
  }

private:
  ::communication_msgs::msg::Alert msg_;
};

class Init_Alert_header
{
public:
  Init_Alert_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Alert_code header(::communication_msgs::msg::Alert::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Alert_code(msg_);
  }

private:
  ::communication_msgs::msg::Alert msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::communication_msgs::msg::Alert>()
{
  return communication_msgs::msg::builder::Init_Alert_header();
}

}  // namespace communication_msgs

#endif  // COMMUNICATION_MSGS__MSG__DETAIL__ALERT__BUILDER_HPP_
