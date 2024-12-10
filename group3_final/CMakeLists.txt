cmake_minimum_required(VERSION 3.8)
project(group3_final)

# Enable strict compiler warnings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(gazebo REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(std_msgs REQUIRED)
find_package(camera_info_manager REQUIRED)
find_package(gazebo_msgs REQUIRED)
find_package(image_transport REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(orocos_kdl REQUIRED)
find_package(mage_msgs REQUIRED)
find_package(nav_msgs REQUIRED)

# Ensure Gazebo libraries are linked correctly
link_directories(${gazebo_LIBRARY_DIRS})
include_directories(${gazebo_INCLUDE_DIRS})

# Ensure proper include paths for the package
include_directories(include/group3_final)

# Add the executable for the package
add_executable(final_project
  src/main.cpp
  src/parts_subscriber_node.cpp
  src/camera_subscriber_node.cpp
  src/transformation_node.cpp
  src/p_navigation_node.cpp
)

# Specify dependencies for the target
ament_target_dependencies(final_project
  rclcpp
  mage_msgs
  sensor_msgs
  tf2
  tf2_geometry_msgs
  tf2_ros
  geometry_msgs
  nav_msgs
  std_msgs
)

# Link necessary libraries
target_link_libraries(final_project ${gazebo_LIBRARIES})

# Install the target
install(TARGETS final_project
  DESTINATION lib/${PROJECT_NAME}
)

# Add tests if enabled
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # Skip the linter checks as needed
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# Export the package
ament_package()
