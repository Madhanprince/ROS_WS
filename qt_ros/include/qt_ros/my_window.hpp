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

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>


class MyWindow : public QWidget
{
public:
    explicit MyWindow(rclcpp::Node::SharedPtr node, QWidget *parent = nullptr);

    ~MyWindow();

private:
    void handleButtonClick_callback();
    void toggle_timer();

    void client_req();
    void service_res(const std::shared_ptr<qt_ros::srv::QtString::Request> request,
          std::shared_ptr<qt_ros::srv::QtString::Response> response );
    
    //action_client
    void send_goal();
    void goal_response_callback(const rclcpp_action::GoalHandleFibonacci::SharedPrt & goalhandle);
    void feedback_callback(rclcpp_action::GoalHandleFibonacci::SharedPrt,
    const srd::shared_prt<const Fibonacci::Feedback> feedback);
    void result_callback(const rclcpp_action::GoalHandleFibonacci::WrappedResult & result);

    // //action_server
    // rclcpp_action::GoalResponse handle_goal(
    // const rclcpp_action::GoalUUID & uuid,std::shared_prt<const Fibonacci::Goal> goal);
    // rclcpp_action::CancelResponse handle_cancel(
    // const std::shared_ptr<GoalHandleFibonacci> goal_handle);
    // rclcpp_action::CancelResponse(const std::shared_ptr<GoalHandleFibonacci> goal_handle);
    void execute(const std::shared_ptr<rclcpp_action::GoalHandleFibonacci> goal_handle);


    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Client<qt_ros::srv::QtString>::SharedPtr qt_client;
    rclcpp::Service<qt_ros::srv::QtString>::SharedPtr qt_service;
    rclcpp_action::Client<Fibonacci>::SharedPtr client_ptr_;
    rclcpp_action::Server<Fibonacci>::SharedPtr action_server_

    rclcpp::TimerBase::SharedPtr timer_;

    QPushButton *button_1; 
    QPushButton *button_2;
    QPushButton *button_3;

    bool publishing_ ;

};

#endif // MY_WINDOW_HPP
