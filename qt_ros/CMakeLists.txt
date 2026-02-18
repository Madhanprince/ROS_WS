cmake_minimum_required(VERSION 3.8)
project(qt_ros)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Generate service
rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/QtString.srv"
)

ament_export_dependencies(rosidl_default_runtime)

add_executable(qt_node
  src/main.cpp
  src/my_window.cpp
)

target_include_directories(qt_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

target_link_libraries(qt_node Qt5::Widgets)
ament_target_dependencies(qt_node rclcpp std_msgs)

# IMPORTANT: link service interfaces
rosidl_target_interfaces(qt_node
  ${PROJECT_NAME} "rosidl_typesupport_cpp"
)

install(TARGETS qt_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
