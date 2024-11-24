cmake_minimum_required(VERSION 3.8)
project(group3_rwa4)



# If using GCC or Clang, enable some extra warnings
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(gazebo_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

# Add include directories
include_directories(include/group3_rwa4)

# Add executable for your project
add_executable(bot_sequence src/main.cpp src/bot_sequence.cpp)

# Link dependencies to the target executable
ament_target_dependencies(bot_sequence rclcpp nav_msgs geometry_msgs tf2_geometry_msgs gazebo_ros)

# Install the executable
install(TARGETS bot_sequence DESTINATION lib/${PROJECT_NAME})

# Optionally add testing dependencies and linting
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # The following line skips the linter which checks for copyrights
  # Uncomment the line when a copyright and license is not present in all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # Skip cpplint if not in a git repository
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
