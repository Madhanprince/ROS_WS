#include "qt_ros/my_window.hpp"
#include <QVBoxLayout>
#include <chrono>

MyWindow::MyWindow(rclcpp::Node::SharedPtr node, QWidget *parent)
    : QWidget(parent), node_(node)
{
    setFixedSize(300, 200);

    publisher_ = node_->create_publisher<std_msgs::msg::String>("chatter", 10);

    button_ = new QPushButton("Publish Message", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(button_);

    timer_ = this->create_wall_timer(
            500ms, std::bind(&MyWindow::handleButtonClick_calback(), this));

    connect(button_, &QPushButton::clicked,
            this, &MyWindow::handleButtonClick_callback);
        
     
}

MyWindow::~MyWindow() {
    // Implementation
}

void MyWindow::handleButtonClick_callback()
{
    std_msgs::msg::String message;
    message.data = "Hello from Qt Button!";

    publisher_->publish(message);

    RCLCPP_INFO(node_->get_logger(), "Message Published!");
}