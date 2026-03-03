#include <iostream>
#include "qt_ros/my_window.hpp"
#include <QVBoxLayout>
#include <chrono>
#include "qt_ros/srv/qt_string.hpp"

#include <rclcpp_action/rclcpp_action.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sstream>


using namespace std::chrono_literals; 
using namespace std::placeholders;

MyWindow::MyWindow(rclcpp::Node::SharedPtr node, QWidget *parent)
    : QWidget(parent), node_(node),publishing_(false)
{
    setFixedSize(300, 200);

    publisher_ = node_->create_publisher<std_msgs::msg::String>("chatter", 10);
    qt_client = node_->create_client<qt_ros::srv::QtString>("qt_string");
    qt_service =node_->create_service<qt_ros::srv::QtString>("qt_string",
        std::bind(&MyWindow::service_res,this,std::placeholders::_1,std::placeholders::_2));
    client_ptr_ =rclcpp_action::create_client<qt_ros::action::Fibonacci>(this,"qt_fibonacci");
    action_server =rclcpp_action::create_server<qt_ros::action::Fibonacci>(
      this,
      "qt_fibonacci",
      std::bind(&MyWindow::handle_goal, this, _1, _2),
      std::bind(&MyWindow::handle_cancel, this, _1),
      std::bind(&MyWindow::handle_accepted, this, _1));

    button_1 = new QPushButton("Publish Message", this);
    button_2 = new QPushButton("Service_call", this);
    button_3 = new QPushButton("Action_client",this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(button_1);
    layout->addWidget(button_2);
    layout->addWidget(button_3);

    timer_ = node_->create_wall_timer(
        500ms,
        std::bind(&MyWindow::handleButtonClick_callback, this)
    );
    timer_->cancel();

    timer_ = node->create_wall_timer(
        std::chrono::milliseconds(500),
        std::bind(&MyWindow::send_goal, this));
    timer_->cancel();

    connect(button_1 , &QPushButton::clicked,
            this, &MyWindow::toggle_timer);

    connect(button_2 , &QPushButton::clicked,
            this, &MyWindow::client_req);

    connect(button_3 , &QPushButton::clicked,
            this, &MyWindow::send_goal);
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
    if (!qt_client->wait_for_service(std::chrono::seconds(1)))
    {
        RCLCPP_WARN(node_->get_logger(), "Service not available");
        return;
    }

    auto request =
      std::make_shared<qt_ros::srv::QtString::Request>();

    request->req = "hay..!buddy";

    RCLCPP_INFO(node_->get_logger(),
                "Client sending: %s",
                request->req.c_str());

    qt_client->async_send_request(
        request,
        [this](rclcpp::Client<qt_ros::srv::QtString>::SharedFuture result)
        {
            RCLCPP_INFO(node_->get_logger(),
                        "Response from service: %s",
                        result.get()->message.c_str());
        });
}

void MyWindow::service_res(
    const std::shared_ptr<qt_ros::srv::QtString::Request> request,
    std::shared_ptr<qt_ros::srv::QtString::Response> response)
{
    // RCLCPP_INFO(node_->get_logger(),
    //             "Service received: %s",
    //             request->req.c_str());

    response->message = "Hello " + request->req;

    // RCLCPP_INFO(node_->get_logger(),
    //             "Service sending: %s",
    //             response->message.c_str());

      // Optional: show in UI
    // label_->setText(QString::number(response->sum));
}

void MyWindow::send_goal()
{
    using namespace std::placeholders;
    this->timer_->cancel();
    if (MyWindow::client_ptr_->wait_for_action_server()){
        RCLCPP_ERROR(this->get_logger(),"Action server not available after waiting");
        rclcpp::shutdown();
    } 

    qt_ros::action::Fibonacci::Goal goal_msg ;
    goal_msg.order =10 ;

    RCLCPP_INFO(this->get_logger(),"sending goal");

    rclcpp_action::Client<qt_ros::action::Fibonacci>::SendGoalOptions send_goal_options ;
    send_goal_options.goal_response_callback= 
        std::bind(&MyWindow::goal_response_callback,this,_1);
    send_goal_options.feedback_callback = 
        std::bind(&MyWindow::feedback_callback,this,_1,_2);
    send_goal_options.result_callback =
        std::bind(&MyWindow::result_callback,this,_1);
    MyWindow::client_ptr_->async_send_goal(goal_msg,send_goal_options);

}
void MyWindow::goal_response_callback(const rclcpp_action::ClientGoalHandle<qt_ros::action::Fibonacci>::SharedPtr & goal_handle)
{
    if(!goal_handle){
        RCLCPP_ERROR(this->get_logger(),"Goal was rejected by server");
    }else{
        RCLCPP_INFO(this->get_logger(),"Goal accepted by server,wating for the result");
    }
}

void MyWindow::feedback_callback(rclcpp_action::ClientGoalHandle<qt_ros::action::Fibonacci>::SharedPtr,
    const std::shared_ptr<const qt_ros::action::Fibonacci::Feedback> feedback)
{
    std::stringstream ss;
    ss<<"Next Number in sequence received: ";
    for(auto number : feedback->partial_sequence)
    {
        ss << number <<" ";
    }
    RCLCPP_INFO(this->get_logger(), ss.str().c_str());
}

void MyWindow::result_callback(const rclcpp_action::ClientGoalHandle<qt_ros::action::Fibonacci>::WrappedResult & result)
{
    switch (result.code) {
      case rclcpp_action::ResultCode::SUCCEEDED:
      break;
    case rclcpp_action::ResultCode::ABORTED:
      RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
      return;
    case rclcpp_action::ResultCode::CANCELED:
      RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
      return;
    default:
      RCLCPP_ERROR(this->get_logger(), "Unknown result code");
      return;
    }
}

//Action Server

rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID & uuid,std::shared_ptr<const qt_ros::action::Fibonacci> & goal)
{
    RCLCPP_INFO(this->get_logger(),"received goal request with order %d",goal-> order);
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
}

rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<rclcpp_action::ServerGoalHandle<qt_ros::action::Fibonacci>> & goal_handle)
{
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    (void)goal_handle;
    return rclcpp_action::CancelResponse::ACCEPT;
}

void MyWindow::handle_accepted(const std::shared_ptr<qt_ros::action::Fibonacci> & goal_handle)
{
    using namespace std::placeholders;
    std::thread{std::bind(&MyWindow::execute, this, goal_handle)}.detach();
}

void MyWindow::execute(const std::shared_ptr<rclcpp_action::ServerGoalHandle<qt_ros::action::Fibonacci>> goal_handle)
{
    RCLCPP_INFO(this->get_logger(),"Executing goal");
    rclcpp::Rate loop_rate(1);
    const auto goal= goal_handle->get_goal();
    auto feedback = std::make_shared<qt_ros::action::Fibonacci::Feedback>();
    auto &sequence = feedback->partial_sequence;
    sequence.push_back(1);
    sequence.push_back(2);
    auto result = std::make_shared<qt_ros::action::Fibonacci::Result>();

    for (int i=1; (i< goal->order) && rclcpp::ok(); ++i)
    {
        if(goal_handle->is_canceling())
        {
            result->sequence =sequence;
            goal_handle->canceled(result)
            RCLCPP_INFO(this->get _logger(),"Goal Canceled");
            return ;
        }

        sequence.push_back(sequence[i] + sequence[i-1]);
        goal_handle->publish_feedback(feedback);
        RCLCPP_INFO(this->get_logger(), "Publish feedback");
        loop_rate.sleep();
    }

      //check if the goal is done 
      if(rclcpp::ok)
      {
        result->sequence = sequence ;
        goal_handle->succeed(result);
        RCLCPP_INFO(this->get_logger(), "Goal succeeded");
      }
}