// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qt_ros:srv/QtString.idl
// generated code does not contain a copyright notice

#ifndef QT_ROS__SRV__DETAIL__QT_STRING__BUILDER_HPP_
#define QT_ROS__SRV__DETAIL__QT_STRING__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qt_ros/srv/detail/qt_string__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qt_ros
{

namespace srv
{

namespace builder
{

class Init_QtString_Request_req
{
public:
  Init_QtString_Request_req()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qt_ros::srv::QtString_Request req(::qt_ros::srv::QtString_Request::_req_type arg)
  {
    msg_.req = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_ros::srv::QtString_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_ros::srv::QtString_Request>()
{
  return qt_ros::srv::builder::Init_QtString_Request_req();
}

}  // namespace qt_ros


namespace qt_ros
{

namespace srv
{

namespace builder
{

class Init_QtString_Response_message
{
public:
  Init_QtString_Response_message()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qt_ros::srv::QtString_Response message(::qt_ros::srv::QtString_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_ros::srv::QtString_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_ros::srv::QtString_Response>()
{
  return qt_ros::srv::builder::Init_QtString_Response_message();
}

}  // namespace qt_ros

#endif  // QT_ROS__SRV__DETAIL__QT_STRING__BUILDER_HPP_
