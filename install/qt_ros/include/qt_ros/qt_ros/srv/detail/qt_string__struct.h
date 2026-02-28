// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from qt_ros:srv/QtString.idl
// generated code does not contain a copyright notice

#ifndef QT_ROS__SRV__DETAIL__QT_STRING__STRUCT_H_
#define QT_ROS__SRV__DETAIL__QT_STRING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'req'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/QtString in the package qt_ros.
typedef struct qt_ros__srv__QtString_Request
{
  rosidl_runtime_c__String req;
} qt_ros__srv__QtString_Request;

// Struct for a sequence of qt_ros__srv__QtString_Request.
typedef struct qt_ros__srv__QtString_Request__Sequence
{
  qt_ros__srv__QtString_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qt_ros__srv__QtString_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

/// Struct defined in srv/QtString in the package qt_ros.
typedef struct qt_ros__srv__QtString_Response
{
  rosidl_runtime_c__String message;
} qt_ros__srv__QtString_Response;

// Struct for a sequence of qt_ros__srv__QtString_Response.
typedef struct qt_ros__srv__QtString_Response__Sequence
{
  qt_ros__srv__QtString_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} qt_ros__srv__QtString_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // QT_ROS__SRV__DETAIL__QT_STRING__STRUCT_H_
