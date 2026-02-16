#include <QApplication>
#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include "qt_ros/my_window.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<rclcpp::Node>("qt_node");
        // Start ROS spin in background thread
    std::thread ros_thread([&]() {
        rclcpp::spin(node);
    });
    ros_thread.detach();

    QApplication app(argc, argv);
    MyWindow window(node);
    std::cout<<"window opened"<<std::endl;
    window.show();
    
    int result = app.exec();
    rclcpp::shutdown();

    return result;
}
