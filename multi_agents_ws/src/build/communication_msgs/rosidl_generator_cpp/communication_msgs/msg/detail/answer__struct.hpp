// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from communication_msgs:msg/Answer.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/msg/answer.hpp"


#ifndef COMMUNICATION_MSGS__MSG__DETAIL__ANSWER__STRUCT_HPP_
#define COMMUNICATION_MSGS__MSG__DETAIL__ANSWER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__communication_msgs__msg__Answer __attribute__((deprecated))
#else
# define DEPRECATED__communication_msgs__msg__Answer __declspec(deprecated)
#endif

namespace communication_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Answer_
{
  using Type = Answer_<ContainerAllocator>;

  explicit Answer_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->to = "";
      this->response_code = 0l;
      this->current_action = "";
      this->details = "";
    }
  }

  explicit Answer_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    to(_alloc),
    current_action(_alloc),
    details(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->to = "";
      this->response_code = 0l;
      this->current_action = "";
      this->details = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _id_type =
    int32_t;
  _id_type id;
  using _to_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _to_type to;
  using _response_code_type =
    int32_t;
  _response_code_type response_code;
  using _current_action_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _current_action_type current_action;
  using _details_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _details_type details;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__to(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->to = _arg;
    return *this;
  }
  Type & set__response_code(
    const int32_t & _arg)
  {
    this->response_code = _arg;
    return *this;
  }
  Type & set__current_action(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->current_action = _arg;
    return *this;
  }
  Type & set__details(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->details = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    communication_msgs::msg::Answer_<ContainerAllocator> *;
  using ConstRawPtr =
    const communication_msgs::msg::Answer_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<communication_msgs::msg::Answer_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<communication_msgs::msg::Answer_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      communication_msgs::msg::Answer_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<communication_msgs::msg::Answer_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      communication_msgs::msg::Answer_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<communication_msgs::msg::Answer_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<communication_msgs::msg::Answer_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<communication_msgs::msg::Answer_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__communication_msgs__msg__Answer
    std::shared_ptr<communication_msgs::msg::Answer_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__communication_msgs__msg__Answer
    std::shared_ptr<communication_msgs::msg::Answer_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Answer_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->id != other.id) {
      return false;
    }
    if (this->to != other.to) {
      return false;
    }
    if (this->response_code != other.response_code) {
      return false;
    }
    if (this->current_action != other.current_action) {
      return false;
    }
    if (this->details != other.details) {
      return false;
    }
    return true;
  }
  bool operator!=(const Answer_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Answer_

// alias to use template instance with default allocator
using Answer =
  communication_msgs::msg::Answer_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace communication_msgs

#endif  // COMMUNICATION_MSGS__MSG__DETAIL__ANSWER__STRUCT_HPP_
