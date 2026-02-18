#include "qt_ros/my_window.hpp"
#include <QVBoxLayout>
#include <chrono>
#include "qt_ros/srv/qt_string.hpp"
using namespace std::chrono_literals; 

MyWindow::MyWindow(rclcpp::Node::SharedPtr node, QWidget *parent)
    : QWidget(parent), node_(node),publishing_(false)
{
    setFixedSize(300, 200);

    publisher_ = node_->create_publisher<std_msgs::msg::String>("chatter", 10);
    qt_client = node_->create_client<qt_ros::srv::QtString>("qt_res");
    qt_service =node_->create_service<qt_ros::srv::QtString>("qt_req",std::bind(&MyWindow::service_res,this,std::placeholders::_1,std::placeholders::_2));


    button_1  = new QPushButton("Publish Message", this);
    button_2 = new QPushButton("service_call", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(button_1);
    layout->addWidget(button_2);
    timer_ = node_->create_wall_timer(
        500ms,
        std::bind(&MyWindow::handleButtonClick_callback, this)
    );
    timer_->cancel();

    connect(button_1 , &QPushButton::clicked,
            this, &MyWindow::toggle_timer);

    connect(button_2 , &QPushButton::clicked,
            this, &MyWindow::client_req);
}


MyWindow::~MyWindow() {
    // Implementation
}

//Publisher Button 

void MyWindow::toggle_timer()
{
    if (!publishing_) {
        timer_->reset();                     // start
        button_1 ->setText("Stop Publishing");
        publishing_ = true;

        RCLCPP_INFO(node_->get_logger(), "Publishing started");
    } else {
        timer_->cancel();                    // stop
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

//service Call Button

void MyWindow::client_req()
{
    // if(!qt_client-> wait_for_service(std::chrono::seconds(1)))
    // {
    //     RCLCPP_WARN(node_->get_logger(), "Service not available");
    //     return;
    // }

    auto request = std::make_shared<qt_ros::srv::QtString::Request>();

    request->req ="hay..!buddy";

    auto future = qt_client->async_send_request(request,
            [this](rclcpp::Client<qt_ros::srv::QtString>::SharedFuture result)
            {
                RCLCPP_INFO(node_->get_logger(),"Response from service: %s",result.get()->message.c_str());
            });
}

void MyWindow::service_res(const std::shared_ptr<qt_ros::srv::QtString::Request> request,
          std::shared_ptr<qt_ros::srv::QtString::Response> response )
{
    RCLCPP_INFO(
        node_->get_logger(),
        "Received: %s",
        request->req.c_str());

    response->message = "Hello " + request->req;

    // Print what we are sending back
    RCLCPP_INFO(node_->get_logger(),
                "Sending: %s",
                response->message.c_str());

      // Optional: show in UI
    // label_->setText(QString::number(response->sum));
}