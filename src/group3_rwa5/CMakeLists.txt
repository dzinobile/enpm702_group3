cmake_minimum_required(VERSION 3.8)
project(group3_rwa5)

# Enable strict compiler warnings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find required dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(bot_waypoint_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(std_msgs REQUIRED)

# Specify include directories
include_directories(include/group3_rwa5)

# Add the executable target for the project
add_executable(project_5
  src/main.cpp
  src/waypoint_publisher.cpp
  src/waypoint_reacher.cpp
)

# Correct usage of ament_target_dependencies with the target name
ament_target_dependencies(project_5
  rclcpp
  bot_waypoint_msgs
  geometry_msgs
  std_msgs
)

# Install the executable
install(TARGETS project_5
  DESTINATION lib/${PROJECT_NAME}
)

# Generate the ament package
ament_package()
