// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from communication_msgs:msg/Request.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/msg/request.hpp"


#ifndef COMMUNICATION_MSGS__MSG__DETAIL__REQUEST__BUILDER_HPP_
#define COMMUNICATION_MSGS__MSG__DETAIL__REQUEST__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "communication_msgs/msg/detail/request__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace communication_msgs
{

namespace msg
{

namespace builder
{

class Init_Request_action_name
{
public:
  explicit Init_Request_action_name(::communication_msgs::msg::Request & msg)
  : msg_(msg)
  {}
  ::communication_msgs::msg::Request action_name(::communication_msgs::msg::Request::_action_name_type arg)
  {
    msg_.action_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::communication_msgs::msg::Request msg_;
};

class Init_Request_to
{
public:
  explicit Init_Request_to(::communication_msgs::msg::Request & msg)
  : msg_(msg)
  {}
  Init_Request_action_name to(::communication_msgs::msg::Request::_to_type arg)
  {
    msg_.to = std::move(arg);
    return Init_Request_action_name(msg_);
  }

private:
  ::communication_msgs::msg::Request msg_;
};

class Init_Request_id
{
public:
  explicit Init_Request_id(::communication_msgs::msg::Request & msg)
  : msg_(msg)
  {}
  Init_Request_to id(::communication_msgs::msg::Request::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Request_to(msg_);
  }

private:
  ::communication_msgs::msg::Request msg_;
};

class Init_Request_header
{
public:
  Init_Request_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Request_id header(::communication_msgs::msg::Request::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Request_id(msg_);
  }

private:
  ::communication_msgs::msg::Request msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::communication_msgs::msg::Request>()
{
  return communication_msgs::msg::builder::Init_Request_header();
}

}  // namespace communication_msgs

#endif  // COMMUNICATION_MSGS__MSG__DETAIL__REQUEST__BUILDER_HPP_
