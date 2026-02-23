#ifndef MY_WINDOW_HPP
#define MY_WINDOW_HPP

#include <QWidget>
#include <QPushButton>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include "qt_ros/srv/qt_string.hpp"

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
    void send_goal();

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
