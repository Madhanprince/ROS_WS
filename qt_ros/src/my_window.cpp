#include "qt_ros/my_window.hpp"
#include <QVBoxLayout>
#include <chrono>
#include <std_srvs/srv/qt_ros.hpp>
using namespace std::chrono_literals; 

MyWindow::MyWindow(rclcpp::Node::SharedPtr node, QWidget *parent)
    : QWidget(parent), node_(node),publishing_(false)
{
    setFixedSize(300, 200);

    publisher_ = node_->create_publisher<std_msgs::msg::String>("chatter", 10);
    qt_service = node_->create_client<std_srvs::srv::qt_string>("qt_response");

    button_1  = new QPushButton("Publish Message", this);
    button_2 = new QPushButton("Publish Message", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(button_1);
    timer_ = node_->create_wall_timer(
        500ms,
        std::bind(&MyWindow::handleButtonClick_callback, this)
    );

     timer_ = node_->create_wall_timer(
        500ms,
        std::bind(&MyWindow::handleButtonClick_callback, this)
    );


    timer_->cancel();

    connect(button_1 , &QPushButton::clicked,
            this, &MyWindow::toggle_timer);

    connect(button_2 , &QPushButton::clicked,
            this, &MyWindow::toggle_timer);
}


MyWindow::~MyWindow() {
    // Implementation
}
void MyWindow::toggle_timer()
{
    if (!publishing_) {
        timer_->reset();                     // ▶ start
        button_1 ->setText("Stop Publishing");
        publishing_ = true;

        RCLCPP_INFO(node_->get_logger(), "Publishing started");
    } else {
        timer_->cancel();                    // ⏹ stop
        button_1 ->setText("Start Publishing");
        publishing_ = false;

        RCLCPP_INFO(node_->get_logger(), "Publishing stopped");
    }
}
void MyWindow::handleButtonClick_callback()
{
    timer_->reset();
    button_1->setText("stop publishing"); 
    std_msgs::msg::String message;
    message.data = "Hello from Qt Button!"; 

    publisher_->publish(message);

    RCLCPP_INFO(node_->get_logger(), "Message Published!");
}

void MyWindow:: req_res()
{
    auto request = std::make_shared<::srv::::Request>();
}