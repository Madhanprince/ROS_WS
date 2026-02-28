// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from qt_ros:srv/QtString.idl
// generated code does not contain a copyright notice

#ifndef QT_ROS__SRV__DETAIL__QT_STRING__TRAITS_HPP_
#define QT_ROS__SRV__DETAIL__QT_STRING__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "qt_ros/srv/detail/qt_string__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace qt_ros
{

namespace srv
{

inline void to_flow_style_yaml(
  const QtString_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: req
  {
    out << "req: ";
    rosidl_generator_traits::value_to_yaml(msg.req, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const QtString_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: req
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "req: ";
    rosidl_generator_traits::value_to_yaml(msg.req, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const QtString_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace qt_ros

namespace rosidl_generator_traits
{

[[deprecated("use qt_ros::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qt_ros::srv::QtString_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  qt_ros::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qt_ros::srv::to_yaml() instead")]]
inline std::string to_yaml(const qt_ros::srv::QtString_Request & msg)
{
  return qt_ros::srv::to_yaml(msg);
}

template<>
inline const char * data_type<qt_ros::srv::QtString_Request>()
{
  return "qt_ros::srv::QtString_Request";
}

template<>
inline const char * name<qt_ros::srv::QtString_Request>()
{
  return "qt_ros/srv/QtString_Request";
}

template<>
struct has_fixed_size<qt_ros::srv::QtString_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<qt_ros::srv::QtString_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<qt_ros::srv::QtString_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace qt_ros
{

namespace srv
{

inline void to_flow_style_yaml(
  const QtString_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const QtString_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const QtString_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace qt_ros

namespace rosidl_generator_traits
{

[[deprecated("use qt_ros::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const qt_ros::srv::QtString_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  qt_ros::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use qt_ros::srv::to_yaml() instead")]]
inline std::string to_yaml(const qt_ros::srv::QtString_Response & msg)
{
  return qt_ros::srv::to_yaml(msg);
}

template<>
inline const char * data_type<qt_ros::srv::QtString_Response>()
{
  return "qt_ros::srv::QtString_Response";
}

template<>
inline const char * name<qt_ros::srv::QtString_Response>()
{
  return "qt_ros/srv/QtString_Response";
}

template<>
struct has_fixed_size<qt_ros::srv::QtString_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<qt_ros::srv::QtString_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<qt_ros::srv::QtString_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<qt_ros::srv::QtString>()
{
  return "qt_ros::srv::QtString";
}

template<>
inline const char * name<qt_ros::srv::QtString>()
{
  return "qt_ros/srv/QtString";
}

template<>
struct has_fixed_size<qt_ros::srv::QtString>
  : std::integral_constant<
    bool,
    has_fixed_size<qt_ros::srv::QtString_Request>::value &&
    has_fixed_size<qt_ros::srv::QtString_Response>::value
  >
{
};

template<>
struct has_bounded_size<qt_ros::srv::QtString>
  : std::integral_constant<
    bool,
    has_bounded_size<qt_ros::srv::QtString_Request>::value &&
    has_bounded_size<qt_ros::srv::QtString_Response>::value
  >
{
};

template<>
struct is_service<qt_ros::srv::QtString>
  : std::true_type
{
};

template<>
struct is_service_request<qt_ros::srv::QtString_Request>
  : std::true_type
{
};

template<>
struct is_service_response<qt_ros::srv::QtString_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // QT_ROS__SRV__DETAIL__QT_STRING__TRAITS_HPP_
