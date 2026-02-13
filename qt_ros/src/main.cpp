#include <QApplication>
#include <rclcpp/rclcpp.hpp>
#include "qt_ros/my_window.hpp"

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<rclcpp::Node>("qt_node");

    QApplication app(argc, argv);

    MyWindow window(node);
    rclcpp::spin(node);
    window.show();
    
    int result = app.exec();
    rclcpp::shutdown();
    return result;
}
