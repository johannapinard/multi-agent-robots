// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from communication_msgs:srv/GetPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/srv/get_pose.hpp"


#ifndef COMMUNICATION_MSGS__SRV__DETAIL__GET_POSE__BUILDER_HPP_
#define COMMUNICATION_MSGS__SRV__DETAIL__GET_POSE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "communication_msgs/srv/detail/get_pose__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace communication_msgs
{

namespace srv
{

namespace builder
{

class Init_GetPose_Request_item
{
public:
  Init_GetPose_Request_item()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::communication_msgs::srv::GetPose_Request item(::communication_msgs::srv::GetPose_Request::_item_type arg)
  {
    msg_.item = std::move(arg);
    return std::move(msg_);
  }

private:
  ::communication_msgs::srv::GetPose_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::communication_msgs::srv::GetPose_Request>()
{
  return communication_msgs::srv::builder::Init_GetPose_Request_item();
}

}  // namespace communication_msgs


namespace communication_msgs
{

namespace srv
{

namespace builder
{

class Init_GetPose_Response_color
{
public:
  Init_GetPose_Response_color()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::communication_msgs::srv::GetPose_Response color(::communication_msgs::srv::GetPose_Response::_color_type arg)
  {
    msg_.color = std::move(arg);
    return std::move(msg_);
  }

private:
  ::communication_msgs::srv::GetPose_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::communication_msgs::srv::GetPose_Response>()
{
  return communication_msgs::srv::builder::Init_GetPose_Response_color();
}

}  // namespace communication_msgs


namespace communication_msgs
{

namespace srv
{

namespace builder
{

class Init_GetPose_Event_response
{
public:
  explicit Init_GetPose_Event_response(::communication_msgs::srv::GetPose_Event & msg)
  : msg_(msg)
  {}
  ::communication_msgs::srv::GetPose_Event response(::communication_msgs::srv::GetPose_Event::_response_type arg)
  {
    msg_.response = std::move(arg);
    return std::move(msg_);
  }

private:
  ::communication_msgs::srv::GetPose_Event msg_;
};

class Init_GetPose_Event_request
{
public:
  explicit Init_GetPose_Event_request(::communication_msgs::srv::GetPose_Event & msg)
  : msg_(msg)
  {}
  Init_GetPose_Event_response request(::communication_msgs::srv::GetPose_Event::_request_type arg)
  {
    msg_.request = std::move(arg);
    return Init_GetPose_Event_response(msg_);
  }

private:
  ::communication_msgs::srv::GetPose_Event msg_;
};

class Init_GetPose_Event_info
{
public:
  Init_GetPose_Event_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_GetPose_Event_request info(::communication_msgs::srv::GetPose_Event::_info_type arg)
  {
    msg_.info = std::move(arg);
    return Init_GetPose_Event_request(msg_);
  }

private:
  ::communication_msgs::srv::GetPose_Event msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::communication_msgs::srv::GetPose_Event>()
{
  return communication_msgs::srv::builder::Init_GetPose_Event_info();
}

}  // namespace communication_msgs

#endif  // COMMUNICATION_MSGS__SRV__DETAIL__GET_POSE__BUILDER_HPP_
