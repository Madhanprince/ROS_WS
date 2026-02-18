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

    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Client<qt_ros::srv::QtString>::SharedPtr qt_client;
    rclcpp::Service<qt_ros::srv::QtString>::SharedPtr qt_service;
    QPushButton *button_1; 
    QPushButton *button_2;
    QPushButton *button_3;

    rclcpp::TimerBase::SharedPtr timer_;

    bool publishing_ ;

};

#endif // MY_WINDOW_HPP
