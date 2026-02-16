#ifndef MY_WINDOW_HPP
#define MY_WINDOW_HPP

#include <QWidget>
#include <QPushButton>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <std_srvs/srv/

class MyWindow : public QWidget
{
public:
    explicit MyWindow(rclcpp::Node::SharedPtr node, QWidget *parent = nullptr);

    /// @brief 
    ~MyWindow();



private:
    void handleButtonClick_callback();
    void toggle_timer();

    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Service<std::srv::qt_string>::SharedPtr qt_service;
    QPushButton *button_1; 
    QPushButton *button_2;
    QPushButton *button_3;

    rclcpp::TimerBase::SharedPtr timer_;

    bool publishing_ ;
};

#endif // MY_WINDOW_HPP
