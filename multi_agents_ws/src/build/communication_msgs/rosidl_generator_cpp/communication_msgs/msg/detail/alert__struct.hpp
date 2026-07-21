// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from communication_msgs:msg/Alert.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/msg/alert.hpp"


#ifndef COMMUNICATION_MSGS__MSG__DETAIL__ALERT__STRUCT_HPP_
#define COMMUNICATION_MSGS__MSG__DETAIL__ALERT__STRUCT_HPP_

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
# define DEPRECATED__communication_msgs__msg__Alert __attribute__((deprecated))
#else
# define DEPRECATED__communication_msgs__msg__Alert __declspec(deprecated)
#endif

namespace communication_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Alert_
{
  using Type = Alert_<ContainerAllocator>;

  explicit Alert_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->code = 0l;
    }
  }

  explicit Alert_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->code = 0l;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _code_type =
    int32_t;
  _code_type code;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__code(
    const int32_t & _arg)
  {
    this->code = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    communication_msgs::msg::Alert_<ContainerAllocator> *;
  using ConstRawPtr =
    const communication_msgs::msg::Alert_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<communication_msgs::msg::Alert_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<communication_msgs::msg::Alert_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      communication_msgs::msg::Alert_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<communication_msgs::msg::Alert_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      communication_msgs::msg::Alert_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<communication_msgs::msg::Alert_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<communication_msgs::msg::Alert_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<communication_msgs::msg::Alert_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__communication_msgs__msg__Alert
    std::shared_ptr<communication_msgs::msg::Alert_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__communication_msgs__msg__Alert
    std::shared_ptr<communication_msgs::msg::Alert_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Alert_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->code != other.code) {
      return false;
    }
    return true;
  }
  bool operator!=(const Alert_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Alert_

// alias to use template instance with default allocator
using Alert =
  communication_msgs::msg::Alert_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace communication_msgs

#endif  // COMMUNICATION_MSGS__MSG__DETAIL__ALERT__STRUCT_HPP_
