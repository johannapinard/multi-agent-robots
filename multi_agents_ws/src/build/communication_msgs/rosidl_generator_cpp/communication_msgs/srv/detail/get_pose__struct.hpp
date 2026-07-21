// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from communication_msgs:srv/GetPose.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/srv/get_pose.hpp"


#ifndef COMMUNICATION_MSGS__SRV__DETAIL__GET_POSE__STRUCT_HPP_
#define COMMUNICATION_MSGS__SRV__DETAIL__GET_POSE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__communication_msgs__srv__GetPose_Request __attribute__((deprecated))
#else
# define DEPRECATED__communication_msgs__srv__GetPose_Request __declspec(deprecated)
#endif

namespace communication_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetPose_Request_
{
  using Type = GetPose_Request_<ContainerAllocator>;

  explicit GetPose_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->item = "";
    }
  }

  explicit GetPose_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : item(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->item = "";
    }
  }

  // field types and members
  using _item_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _item_type item;

  // setters for named parameter idiom
  Type & set__item(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->item = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    communication_msgs::srv::GetPose_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const communication_msgs::srv::GetPose_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<communication_msgs::srv::GetPose_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<communication_msgs::srv::GetPose_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      communication_msgs::srv::GetPose_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<communication_msgs::srv::GetPose_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      communication_msgs::srv::GetPose_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<communication_msgs::srv::GetPose_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<communication_msgs::srv::GetPose_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<communication_msgs::srv::GetPose_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__communication_msgs__srv__GetPose_Request
    std::shared_ptr<communication_msgs::srv::GetPose_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__communication_msgs__srv__GetPose_Request
    std::shared_ptr<communication_msgs::srv::GetPose_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetPose_Request_ & other) const
  {
    if (this->item != other.item) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetPose_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetPose_Request_

// alias to use template instance with default allocator
using GetPose_Request =
  communication_msgs::srv::GetPose_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace communication_msgs


#ifndef _WIN32
# define DEPRECATED__communication_msgs__srv__GetPose_Response __attribute__((deprecated))
#else
# define DEPRECATED__communication_msgs__srv__GetPose_Response __declspec(deprecated)
#endif

namespace communication_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetPose_Response_
{
  using Type = GetPose_Response_<ContainerAllocator>;

  explicit GetPose_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->color = "";
    }
  }

  explicit GetPose_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : color(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->color = "";
    }
  }

  // field types and members
  using _color_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _color_type color;

  // setters for named parameter idiom
  Type & set__color(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->color = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    communication_msgs::srv::GetPose_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const communication_msgs::srv::GetPose_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<communication_msgs::srv::GetPose_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<communication_msgs::srv::GetPose_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      communication_msgs::srv::GetPose_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<communication_msgs::srv::GetPose_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      communication_msgs::srv::GetPose_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<communication_msgs::srv::GetPose_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<communication_msgs::srv::GetPose_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<communication_msgs::srv::GetPose_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__communication_msgs__srv__GetPose_Response
    std::shared_ptr<communication_msgs::srv::GetPose_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__communication_msgs__srv__GetPose_Response
    std::shared_ptr<communication_msgs::srv::GetPose_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetPose_Response_ & other) const
  {
    if (this->color != other.color) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetPose_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetPose_Response_

// alias to use template instance with default allocator
using GetPose_Response =
  communication_msgs::srv::GetPose_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace communication_msgs


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__communication_msgs__srv__GetPose_Event __attribute__((deprecated))
#else
# define DEPRECATED__communication_msgs__srv__GetPose_Event __declspec(deprecated)
#endif

namespace communication_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetPose_Event_
{
  using Type = GetPose_Event_<ContainerAllocator>;

  explicit GetPose_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit GetPose_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<communication_msgs::srv::GetPose_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<communication_msgs::srv::GetPose_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<communication_msgs::srv::GetPose_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<communication_msgs::srv::GetPose_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<communication_msgs::srv::GetPose_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<communication_msgs::srv::GetPose_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<communication_msgs::srv::GetPose_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<communication_msgs::srv::GetPose_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    communication_msgs::srv::GetPose_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const communication_msgs::srv::GetPose_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<communication_msgs::srv::GetPose_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<communication_msgs::srv::GetPose_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      communication_msgs::srv::GetPose_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<communication_msgs::srv::GetPose_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      communication_msgs::srv::GetPose_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<communication_msgs::srv::GetPose_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<communication_msgs::srv::GetPose_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<communication_msgs::srv::GetPose_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__communication_msgs__srv__GetPose_Event
    std::shared_ptr<communication_msgs::srv::GetPose_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__communication_msgs__srv__GetPose_Event
    std::shared_ptr<communication_msgs::srv::GetPose_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetPose_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetPose_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetPose_Event_

// alias to use template instance with default allocator
using GetPose_Event =
  communication_msgs::srv::GetPose_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace communication_msgs

namespace communication_msgs
{

namespace srv
{

struct GetPose
{
  using Request = communication_msgs::srv::GetPose_Request;
  using Response = communication_msgs::srv::GetPose_Response;
  using Event = communication_msgs::srv::GetPose_Event;
};

}  // namespace srv

}  // namespace communication_msgs

#endif  // COMMUNICATION_MSGS__SRV__DETAIL__GET_POSE__STRUCT_HPP_
