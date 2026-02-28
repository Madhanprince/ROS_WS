// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from qt_ros:action/Fibonacci.idl
// generated code does not contain a copyright notice

#ifndef QT_ROS__ACTION__DETAIL__FIBONACCI__BUILDER_HPP_
#define QT_ROS__ACTION__DETAIL__FIBONACCI__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "qt_ros/action/detail/fibonacci__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace qt_ros
{

namespace action
{

namespace builder
{

class Init_Fibonacci_Goal_order
{
public:
  Init_Fibonacci_Goal_order()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qt_ros::action::Fibonacci_Goal order(::qt_ros::action::Fibonacci_Goal::_order_type arg)
  {
    msg_.order = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_ros::action::Fibonacci_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_ros::action::Fibonacci_Goal>()
{
  return qt_ros::action::builder::Init_Fibonacci_Goal_order();
}

}  // namespace qt_ros


namespace qt_ros
{

namespace action
{

namespace builder
{

class Init_Fibonacci_Result_sequence
{
public:
  Init_Fibonacci_Result_sequence()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qt_ros::action::Fibonacci_Result sequence(::qt_ros::action::Fibonacci_Result::_sequence_type arg)
  {
    msg_.sequence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_ros::action::Fibonacci_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_ros::action::Fibonacci_Result>()
{
  return qt_ros::action::builder::Init_Fibonacci_Result_sequence();
}

}  // namespace qt_ros


namespace qt_ros
{

namespace action
{

namespace builder
{

class Init_Fibonacci_Feedback_partial_sequence
{
public:
  Init_Fibonacci_Feedback_partial_sequence()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qt_ros::action::Fibonacci_Feedback partial_sequence(::qt_ros::action::Fibonacci_Feedback::_partial_sequence_type arg)
  {
    msg_.partial_sequence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_ros::action::Fibonacci_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_ros::action::Fibonacci_Feedback>()
{
  return qt_ros::action::builder::Init_Fibonacci_Feedback_partial_sequence();
}

}  // namespace qt_ros


namespace qt_ros
{

namespace action
{

namespace builder
{

class Init_Fibonacci_SendGoal_Request_goal
{
public:
  explicit Init_Fibonacci_SendGoal_Request_goal(::qt_ros::action::Fibonacci_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::qt_ros::action::Fibonacci_SendGoal_Request goal(::qt_ros::action::Fibonacci_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_ros::action::Fibonacci_SendGoal_Request msg_;
};

class Init_Fibonacci_SendGoal_Request_goal_id
{
public:
  Init_Fibonacci_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Fibonacci_SendGoal_Request_goal goal_id(::qt_ros::action::Fibonacci_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Fibonacci_SendGoal_Request_goal(msg_);
  }

private:
  ::qt_ros::action::Fibonacci_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_ros::action::Fibonacci_SendGoal_Request>()
{
  return qt_ros::action::builder::Init_Fibonacci_SendGoal_Request_goal_id();
}

}  // namespace qt_ros


namespace qt_ros
{

namespace action
{

namespace builder
{

class Init_Fibonacci_SendGoal_Response_stamp
{
public:
  explicit Init_Fibonacci_SendGoal_Response_stamp(::qt_ros::action::Fibonacci_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::qt_ros::action::Fibonacci_SendGoal_Response stamp(::qt_ros::action::Fibonacci_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_ros::action::Fibonacci_SendGoal_Response msg_;
};

class Init_Fibonacci_SendGoal_Response_accepted
{
public:
  Init_Fibonacci_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Fibonacci_SendGoal_Response_stamp accepted(::qt_ros::action::Fibonacci_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_Fibonacci_SendGoal_Response_stamp(msg_);
  }

private:
  ::qt_ros::action::Fibonacci_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_ros::action::Fibonacci_SendGoal_Response>()
{
  return qt_ros::action::builder::Init_Fibonacci_SendGoal_Response_accepted();
}

}  // namespace qt_ros


namespace qt_ros
{

namespace action
{

namespace builder
{

class Init_Fibonacci_GetResult_Request_goal_id
{
public:
  Init_Fibonacci_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::qt_ros::action::Fibonacci_GetResult_Request goal_id(::qt_ros::action::Fibonacci_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_ros::action::Fibonacci_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_ros::action::Fibonacci_GetResult_Request>()
{
  return qt_ros::action::builder::Init_Fibonacci_GetResult_Request_goal_id();
}

}  // namespace qt_ros


namespace qt_ros
{

namespace action
{

namespace builder
{

class Init_Fibonacci_GetResult_Response_result
{
public:
  explicit Init_Fibonacci_GetResult_Response_result(::qt_ros::action::Fibonacci_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::qt_ros::action::Fibonacci_GetResult_Response result(::qt_ros::action::Fibonacci_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_ros::action::Fibonacci_GetResult_Response msg_;
};

class Init_Fibonacci_GetResult_Response_status
{
public:
  Init_Fibonacci_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Fibonacci_GetResult_Response_result status(::qt_ros::action::Fibonacci_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_Fibonacci_GetResult_Response_result(msg_);
  }

private:
  ::qt_ros::action::Fibonacci_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_ros::action::Fibonacci_GetResult_Response>()
{
  return qt_ros::action::builder::Init_Fibonacci_GetResult_Response_status();
}

}  // namespace qt_ros


namespace qt_ros
{

namespace action
{

namespace builder
{

class Init_Fibonacci_FeedbackMessage_feedback
{
public:
  explicit Init_Fibonacci_FeedbackMessage_feedback(::qt_ros::action::Fibonacci_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::qt_ros::action::Fibonacci_FeedbackMessage feedback(::qt_ros::action::Fibonacci_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::qt_ros::action::Fibonacci_FeedbackMessage msg_;
};

class Init_Fibonacci_FeedbackMessage_goal_id
{
public:
  Init_Fibonacci_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Fibonacci_FeedbackMessage_feedback goal_id(::qt_ros::action::Fibonacci_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_Fibonacci_FeedbackMessage_feedback(msg_);
  }

private:
  ::qt_ros::action::Fibonacci_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::qt_ros::action::Fibonacci_FeedbackMessage>()
{
  return qt_ros::action::builder::Init_Fibonacci_FeedbackMessage_goal_id();
}

}  // namespace qt_ros

#endif  // QT_ROS__ACTION__DETAIL__FIBONACCI__BUILDER_HPP_
