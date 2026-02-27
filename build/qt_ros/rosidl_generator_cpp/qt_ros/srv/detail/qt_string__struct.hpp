// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from qt_ros:srv/QtString.idl
// generated code does not contain a copyright notice

#ifndef QT_ROS__SRV__DETAIL__QT_STRING__STRUCT_HPP_
#define QT_ROS__SRV__DETAIL__QT_STRING__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__qt_ros__srv__QtString_Request __attribute__((deprecated))
#else
# define DEPRECATED__qt_ros__srv__QtString_Request __declspec(deprecated)
#endif

namespace qt_ros
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct QtString_Request_
{
  using Type = QtString_Request_<ContainerAllocator>;

  explicit QtString_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->req = "";
    }
  }

  explicit QtString_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : req(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->req = "";
    }
  }

  // field types and members
  using _req_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _req_type req;

  // setters for named parameter idiom
  Type & set__req(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->req = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qt_ros::srv::QtString_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const qt_ros::srv::QtString_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qt_ros::srv::QtString_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qt_ros::srv::QtString_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qt_ros::srv::QtString_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qt_ros::srv::QtString_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qt_ros::srv::QtString_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qt_ros::srv::QtString_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qt_ros::srv::QtString_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qt_ros::srv::QtString_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qt_ros__srv__QtString_Request
    std::shared_ptr<qt_ros::srv::QtString_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qt_ros__srv__QtString_Request
    std::shared_ptr<qt_ros::srv::QtString_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const QtString_Request_ & other) const
  {
    if (this->req != other.req) {
      return false;
    }
    return true;
  }
  bool operator!=(const QtString_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct QtString_Request_

// alias to use template instance with default allocator
using QtString_Request =
  qt_ros::srv::QtString_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qt_ros


#ifndef _WIN32
# define DEPRECATED__qt_ros__srv__QtString_Response __attribute__((deprecated))
#else
# define DEPRECATED__qt_ros__srv__QtString_Response __declspec(deprecated)
#endif

namespace qt_ros
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct QtString_Response_
{
  using Type = QtString_Response_<ContainerAllocator>;

  explicit QtString_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
    }
  }

  explicit QtString_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->message = "";
    }
  }

  // field types and members
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    qt_ros::srv::QtString_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const qt_ros::srv::QtString_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<qt_ros::srv::QtString_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<qt_ros::srv::QtString_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      qt_ros::srv::QtString_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<qt_ros::srv::QtString_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      qt_ros::srv::QtString_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<qt_ros::srv::QtString_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<qt_ros::srv::QtString_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<qt_ros::srv::QtString_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__qt_ros__srv__QtString_Response
    std::shared_ptr<qt_ros::srv::QtString_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__qt_ros__srv__QtString_Response
    std::shared_ptr<qt_ros::srv::QtString_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const QtString_Response_ & other) const
  {
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const QtString_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct QtString_Response_

// alias to use template instance with default allocator
using QtString_Response =
  qt_ros::srv::QtString_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace qt_ros

namespace qt_ros
{

namespace srv
{

struct QtString
{
  using Request = qt_ros::srv::QtString_Request;
  using Response = qt_ros::srv::QtString_Response;
};

}  // namespace srv

}  // namespace qt_ros

#endif  // QT_ROS__SRV__DETAIL__QT_STRING__STRUCT_HPP_
