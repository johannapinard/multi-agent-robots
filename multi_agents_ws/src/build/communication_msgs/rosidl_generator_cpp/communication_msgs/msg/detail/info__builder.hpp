// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from communication_msgs:msg/Info.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/msg/info.hpp"


#ifndef COMMUNICATION_MSGS__MSG__DETAIL__INFO__BUILDER_HPP_
#define COMMUNICATION_MSGS__MSG__DETAIL__INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "communication_msgs/msg/detail/info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace communication_msgs
{

namespace msg
{

namespace builder
{

class Init_Info_pose
{
public:
  explicit Init_Info_pose(::communication_msgs::msg::Info & msg)
  : msg_(msg)
  {}
  ::communication_msgs::msg::Info pose(::communication_msgs::msg::Info::_pose_type arg)
  {
    msg_.pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::communication_msgs::msg::Info msg_;
};

class Init_Info_content
{
public:
  explicit Init_Info_content(::communication_msgs::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_pose content(::communication_msgs::msg::Info::_content_type arg)
  {
    msg_.content = std::move(arg);
    return Init_Info_pose(msg_);
  }

private:
  ::communication_msgs::msg::Info msg_;
};

class Init_Info_type
{
public:
  explicit Init_Info_type(::communication_msgs::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_content type(::communication_msgs::msg::Info::_type_type arg)
  {
    msg_.type = std::move(arg);
    return Init_Info_content(msg_);
  }

private:
  ::communication_msgs::msg::Info msg_;
};

class Init_Info_subject
{
public:
  explicit Init_Info_subject(::communication_msgs::msg::Info & msg)
  : msg_(msg)
  {}
  Init_Info_type subject(::communication_msgs::msg::Info::_subject_type arg)
  {
    msg_.subject = std::move(arg);
    return Init_Info_type(msg_);
  }

private:
  ::communication_msgs::msg::Info msg_;
};

class Init_Info_header
{
public:
  Init_Info_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Info_subject header(::communication_msgs::msg::Info::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Info_subject(msg_);
  }

private:
  ::communication_msgs::msg::Info msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::communication_msgs::msg::Info>()
{
  return communication_msgs::msg::builder::Init_Info_header();
}

}  // namespace communication_msgs

#endif  // COMMUNICATION_MSGS__MSG__DETAIL__INFO__BUILDER_HPP_
