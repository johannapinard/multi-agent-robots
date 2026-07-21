// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from communication_msgs:msg/Answer.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/msg/answer.hpp"


#ifndef COMMUNICATION_MSGS__MSG__DETAIL__ANSWER__BUILDER_HPP_
#define COMMUNICATION_MSGS__MSG__DETAIL__ANSWER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "communication_msgs/msg/detail/answer__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace communication_msgs
{

namespace msg
{

namespace builder
{

class Init_Answer_details
{
public:
  explicit Init_Answer_details(::communication_msgs::msg::Answer & msg)
  : msg_(msg)
  {}
  ::communication_msgs::msg::Answer details(::communication_msgs::msg::Answer::_details_type arg)
  {
    msg_.details = std::move(arg);
    return std::move(msg_);
  }

private:
  ::communication_msgs::msg::Answer msg_;
};

class Init_Answer_current_action
{
public:
  explicit Init_Answer_current_action(::communication_msgs::msg::Answer & msg)
  : msg_(msg)
  {}
  Init_Answer_details current_action(::communication_msgs::msg::Answer::_current_action_type arg)
  {
    msg_.current_action = std::move(arg);
    return Init_Answer_details(msg_);
  }

private:
  ::communication_msgs::msg::Answer msg_;
};

class Init_Answer_response_code
{
public:
  explicit Init_Answer_response_code(::communication_msgs::msg::Answer & msg)
  : msg_(msg)
  {}
  Init_Answer_current_action response_code(::communication_msgs::msg::Answer::_response_code_type arg)
  {
    msg_.response_code = std::move(arg);
    return Init_Answer_current_action(msg_);
  }

private:
  ::communication_msgs::msg::Answer msg_;
};

class Init_Answer_to
{
public:
  explicit Init_Answer_to(::communication_msgs::msg::Answer & msg)
  : msg_(msg)
  {}
  Init_Answer_response_code to(::communication_msgs::msg::Answer::_to_type arg)
  {
    msg_.to = std::move(arg);
    return Init_Answer_response_code(msg_);
  }

private:
  ::communication_msgs::msg::Answer msg_;
};

class Init_Answer_id
{
public:
  explicit Init_Answer_id(::communication_msgs::msg::Answer & msg)
  : msg_(msg)
  {}
  Init_Answer_to id(::communication_msgs::msg::Answer::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_Answer_to(msg_);
  }

private:
  ::communication_msgs::msg::Answer msg_;
};

class Init_Answer_header
{
public:
  Init_Answer_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Answer_id header(::communication_msgs::msg::Answer::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Answer_id(msg_);
  }

private:
  ::communication_msgs::msg::Answer msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::communication_msgs::msg::Answer>()
{
  return communication_msgs::msg::builder::Init_Answer_header();
}

}  // namespace communication_msgs

#endif  // COMMUNICATION_MSGS__MSG__DETAIL__ANSWER__BUILDER_HPP_
