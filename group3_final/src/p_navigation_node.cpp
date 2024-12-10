#include "p_navigation_node.hpp"

NavigationNode::NavigationNode()
    : Node("navigation_node"), waypoint_reached_(false), current_x_(0), current_y_(0), current_theta_(0) {
    waypoint_subscriber_ = this->create_subscription<mage_msgs::msg::PartPose>(
        "/target_positions", 10, std::bind(&NavigationNode::waypoint_callback, this, std::placeholders::_1));
    odom_subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odom", 10, std::bind(&NavigationNode::odom_callback, this, std::placeholders::_1));
    velocity_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);

    kp_distance_ = 0.5;
    kp_angle_ = 1.0;
    epsilon_ = 0.05;
}

void NavigationNode::waypoint_callback(const mage_msgs::msg::PartPose::SharedPtr msg) {
    waypoints_.push_back(*msg);
    RCLCPP_INFO(this->get_logger(), "New waypoint added. Total waypoints: %lu", waypoints_.size());
}

void NavigationNode::odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg) {
    // Extract current position from odometry message
    current_x_ = msg->pose.pose.position.x;
    current_y_ = msg->pose.pose.position.y;

    // Extract orientation (quaternion) and convert to roll, pitch, yaw
    tf2::Quaternion quaternion;
    tf2::fromMsg(msg->pose.pose.orientation, quaternion);

    // Declare non-const variables for roll, pitch, and yaw
    double roll, pitch, yaw;

    // Convert quaternion to roll, pitch, and yaw
    tf2::Matrix3x3(quaternion).getRPY(roll, pitch, yaw);

    // Use yaw as the robot's current orientation
    current_theta_ = yaw;

    RCLCPP_INFO(this->get_logger(), "Odometry updated: x=%.2f, y=%.2f, theta=%.2f",
                current_x_, current_y_, current_theta_);

    // Call the control loop to update navigation
    control_loop();
}
void NavigationNode::control_loop() {
    if (!waypoints_.empty()) {
        const auto &target = waypoints_.front();

        double distance_error = std::sqrt(std::pow(target.pose.position.x - current_x_, 2) +
                                          std::pow(target.pose.position.y - current_y_, 2));
        double angle_error = normalize_angle(
            std::atan2(target.pose.position.y - current_y_, target.pose.position.x - current_x_) - current_theta_);

        if (distance_error > epsilon_) {
            geometry_msgs::msg::Twist cmd_vel;
            cmd_vel.linear.x = kp_distance_ * distance_error;
            cmd_vel.angular.z = kp_angle_ * angle_error;
            velocity_publisher_->publish(cmd_vel);
        } else {
            waypoints_.erase(waypoints_.begin());
            RCLCPP_INFO(this->get_logger(), "Waypoint reached. Remaining: %lu", waypoints_.size());
        }
    }
}

double NavigationNode::normalize_angle(double angle) {
    while (angle > M_PI) angle -= 2 * M_PI;
    while (angle < -M_PI) angle += 2 * M_PI;
    return angle;
}
