#ifndef MY_WINDOW_HPP
#define MY_WINDOW_HPP

#include <memory>
#include <string>
#include <thread>

#include <QWidget>
#include <QPushButton>

#include <rclcpp/rclcpp.hpp>
#include "qt_ros/srv/qt_string.hpp"
#include <rclcpp_action/rclcpp_action.hpp>
#include "qt_ros/action/fibonacci.hpp"
#include <std_msgs/msg/string.hpp>

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>


class MyWindow : public QWidget
{
public:
    explicit MyWindow(rclcpp::Node::SharedPtr node, QWidget *parent = nullptr);

    ~MyWindow();

    void handleButtonClick_callback();
    void toggle_timer();

    void client_req();
    void service_res(const std::shared_ptr<qt_ros::srv::QtString::Request> request,
          std::shared_ptr<qt_ros::srv::QtString::Response> response );
    
    //action_client
    void send_goal();
    void goal_response_callback(const rclcpp_action::ClientGoalHandle<qt_ros::action::Fibonacci>::SharedPtr & goalhandle);
    void feedback_callback(rclcpp_action::ClientGoalHandle<qt_ros::action::Fibonacci>::SharedPtr,
        const std::shared_ptr<const qt_ros::action::Fibonacci::Feedback> feedback);
    void result_callback(const rclcpp_action::ClientGoalHandle<qt_ros::action::Fibonacci>::WrappedResult & result);
    
    // //action_server
    
    rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID & uuid,std::shared_ptr<const qt_ros::action::Fibonacci::Goal> goal);
    rclcpp_action::CancelResponse handle_cancel(
        const std::shared_ptr<rclcpp_action::ServerGoalHandle<qt_ros::action::Fibonacci>> & goal_handle);
    void handle_accepted(const std::shared_ptr<rclcpp_action::ServerGoalHandle<qt_ros::action::Fibonacci>> & goal_handle);
    void execute(const std::shared_ptr<rclcpp_action::ServerGoalHandle<qt_ros::action::Fibonacci>> goal_handle);

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Client<qt_ros::srv::QtString>::SharedPtr qt_client;
    rclcpp::Service<qt_ros::srv::QtString>::SharedPtr qt_service;
    rclcpp_action::Client<qt_ros::action::Fibonacci>::SharedPtr client_ptr_;
    rclcpp_action::Server<qt_ros::action::Fibonacci>::SharedPtr action_server_;

    rclcpp::TimerBase::SharedPtr timer_;

    QPushButton *button_1; 
    QPushButton *button_2;
    QPushButton *button_3;

    bool publishing_ ;

private:
    rclcpp::Node::SharedPtr node_;
};

#endif // MY_WINDOW_HPP
