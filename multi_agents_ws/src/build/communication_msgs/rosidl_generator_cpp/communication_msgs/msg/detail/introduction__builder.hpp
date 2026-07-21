// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from communication_msgs:msg/Introduction.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/msg/introduction.hpp"


#ifndef COMMUNICATION_MSGS__MSG__DETAIL__INTRODUCTION__BUILDER_HPP_
#define COMMUNICATION_MSGS__MSG__DETAIL__INTRODUCTION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "communication_msgs/msg/detail/introduction__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace communication_msgs
{

namespace msg
{

namespace builder
{

class Init_Introduction_pose
{
public:
  explicit Init_Introduction_pose(::communication_msgs::msg::Introduction & msg)
  : msg_(msg)
  {}
  ::communication_msgs::msg::Introduction pose(::communication_msgs::msg::Introduction::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::communication_msgs::msg::Introduction msg_;
};

class Init_Introduction_frame_id
{
public:
  explicit Init_Introduction_frame_id(::communication_msgs::msg::Introduction & msg)
  : msg_(msg)
  {}
  Init_Introduction_pose frame_id(::communication_msgs::msg::Introduction::_frame_id_type arg)
  {
    msg_.frame_id = std::move(arg);
    return Init_Introduction_pose(msg_);
  }

private:
  ::communication_msgs::msg::Introduction msg_;
};

class Init_Introduction_available_actions
{
public:
  explicit Init_Introduction_available_actions(::communication_msgs::msg::Introduction & msg)
  : msg_(msg)
  {}
  Init_Introduction_frame_id available_actions(::communication_msgs::msg::Introduction::_available_actions_type arg)
  {
    msg_.available_actions = std::move(arg);
    return Init_Introduction_frame_id(msg_);
  }

private:
  ::communication_msgs::msg::Introduction msg_;
};

class Init_Introduction_name
{
public:
  Init_Introduction_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Introduction_available_actions name(::communication_msgs::msg::Introduction::_name_type arg)
  {
    msg_.name = std::move(arg);
    return Init_Introduction_available_actions(msg_);
  }

private:
  ::communication_msgs::msg::Introduction msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::communication_msgs::msg::Introduction>()
{
  return communication_msgs::msg::builder::Init_Introduction_name();
}

}  // namespace communication_msgs

#endif  // COMMUNICATION_MSGS__MSG__DETAIL__INTRODUCTION__BUILDER_HPP_
