// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from communication_msgs:msg/Answer.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "communication_msgs/msg/answer.hpp"


#ifndef COMMUNICATION_MSGS__MSG__DETAIL__ANSWER__TRAITS_HPP_
#define COMMUNICATION_MSGS__MSG__DETAIL__ANSWER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "communication_msgs/msg/detail/answer__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace communication_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Answer & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: id
  {
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << ", ";
  }

  // member: to
  {
    out << "to: ";
    rosidl_generator_traits::value_to_yaml(msg.to, out);
    out << ", ";
  }

  // member: response_code
  {
    out << "response_code: ";
    rosidl_generator_traits::value_to_yaml(msg.response_code, out);
    out << ", ";
  }

  // member: current_action
  {
    out << "current_action: ";
    rosidl_generator_traits::value_to_yaml(msg.current_action, out);
    out << ", ";
  }

  // member: details
  {
    out << "details: ";
    rosidl_generator_traits::value_to_yaml(msg.details, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Answer & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "id: ";
    rosidl_generator_traits::value_to_yaml(msg.id, out);
    out << "\n";
  }

  // member: to
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "to: ";
    rosidl_generator_traits::value_to_yaml(msg.to, out);
    out << "\n";
  }

  // member: response_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "response_code: ";
    rosidl_generator_traits::value_to_yaml(msg.response_code, out);
    out << "\n";
  }

  // member: current_action
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "current_action: ";
    rosidl_generator_traits::value_to_yaml(msg.current_action, out);
    out << "\n";
  }

  // member: details
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "details: ";
    rosidl_generator_traits::value_to_yaml(msg.details, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Answer & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace communication_msgs

namespace rosidl_generator_traits
{

[[deprecated("use communication_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const communication_msgs::msg::Answer & msg,
  std::ostream & out, size_t indentation = 0)
{
  communication_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use communication_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const communication_msgs::msg::Answer & msg)
{
  return communication_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<communication_msgs::msg::Answer>()
{
  return "communication_msgs::msg::Answer";
}

template<>
inline const char * name<communication_msgs::msg::Answer>()
{
  return "communication_msgs/msg/Answer";
}

template<>
struct has_fixed_size<communication_msgs::msg::Answer>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<communication_msgs::msg::Answer>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<communication_msgs::msg::Answer>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // COMMUNICATION_MSGS__MSG__DETAIL__ANSWER__TRAITS_HPP_
