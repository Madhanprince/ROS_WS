#ifndef MY_WINDOW_HPP
#define MY_WINDOW_HPP

#include <QWidget>
#include <QPushButton>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

class MyWindow : public QWidget
{
public:
    explicit MyWindow(rclcpp::Node::SharedPtr node, QWidget *parent = nullptr);

    /// @brief 
    ~MyWindow();


private:
    void handleButtonClick();

    rclcpp::Node::SharedPtr node_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    QPushButton *button_;
    rclcpp::TimerBase::SharedPtr timer_;
};

#endif // MY_WINDOW_HPP
