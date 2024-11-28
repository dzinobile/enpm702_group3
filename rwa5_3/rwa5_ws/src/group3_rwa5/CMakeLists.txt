cmake_minimum_required(VERSION 3.8)
project(group3_rwa5)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(bot_waypoint_msgs REQUIRED)

include_directories(include/group3_rwa5)

add_executable(executable src/main.cpp src/waypoint_publisher.cpp src/waypoint_reacher.cpp)

ament_target_dependencies(rclcpp bot_waypoint_msgs)

install(TARGETS executable DESTINATION lib/${PROJECT_NAME})

ament_package()
