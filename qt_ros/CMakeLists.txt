cmake_minimum_required(VERSION 3.8)
project(qt_ros)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(qt_node
  src/main.cpp
  src/my_window.cpp
)
include_directories(
  include)

target_link_libraries(qt_node Qt5::Widgets)
ament_target_dependencies(qt_node rclcpp std_msgs)

install(TARGETS qt_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()