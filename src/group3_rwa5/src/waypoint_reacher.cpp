/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "waypoint_reacher.hpp"
#include <cmath>
#include <std_msgs/msg/bool.hpp>

WaypointReacher::WaypointReacher()
    : Node("waypoint_reacher_node"), waypoint_reached_(false) {
    // QoS settings for reliable and transient local communication
    rclcpp::QoS sub_qos(10);
    sub_qos.reliable();
    sub_qos.transient_local();

    // Subscriber for receiving waypoints
    subscriber_ = this->create_subscription<bot_waypoint_msgs::msg::BotWaypoint>(
        "bot_waypoint", sub_qos, std::bind(&WaypointReacher::receive_int, this, std::placeholders::_1));

    // Publisher for velocity commands
    velocity_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);

    // Publisher for next waypoint signals
    next_waypoint_publisher_ = this->create_publisher<std_msgs::msg::Bool>("next_waypoint", 10);

    RCLCPP_INFO(this->get_logger(), "WaypointReacher node started.");
}

void WaypointReacher::receive_int(const bot_waypoint_msgs::msg::BotWaypoint::SharedPtr msg) {
    // Update the current waypoint with the received data
    current_waypoint_ = *msg;
    waypoint_reached_ = false;

    RCLCPP_INFO_STREAM(this->get_logger(), "Received waypoint: [" 
        << current_waypoint_.pose.x << ", " << current_waypoint_.pose.y << ", " 
        << current_waypoint_.pose.theta << "] with tolerance " 
        << static_cast<int>(current_waypoint_.tolerance));

    // Start moving toward the new waypoint
    move_toward_waypoint();
}

void WaypointReacher::move_toward_waypoint() {
    double dx = current_waypoint_.pose.x - 0.0; // Replace 0.0 with actual robot's x position
    double dy = current_waypoint_.pose.y - 0.0; // Replace 0.0 with actual robot's y position
    double distance = std::sqrt(dx * dx + dy * dy);

    if (distance <= current_waypoint_.tolerance / 10.0) {
        waypoint_reached_ = true;

        // Stop the robot
        auto stop_msg = geometry_msgs::msg::Twist();
        velocity_publisher_->publish(stop_msg);

        RCLCPP_INFO_STREAM(this->get_logger(), "Waypoint reached: [" 
            << current_waypoint_.pose.x << ", " << current_waypoint_.pose.y << ", " 
            << current_waypoint_.pose.theta << "]");

        // Signal readiness for the next waypoint
        publish_next_waypoint_signal();
        return;
    }

    // Proportional control for movement
    auto cmd_msg = geometry_msgs::msg::Twist();
    cmd_msg.linear.x = 0.5 * distance; // Adjust linear velocity
    cmd_msg.angular.z = 0.1 * (current_waypoint_.pose.theta - 0.0); // Adjust angular velocity

    velocity_publisher_->publish(cmd_msg);

    RCLCPP_INFO_STREAM(this->get_logger(), "Moving toward waypoint: linear.x=" 
        << cmd_msg.linear.x << ", angular.z=" << cmd_msg.angular.z);
}

void WaypointReacher::publish_next_waypoint_signal() {
    auto signal_msg = std_msgs::msg::Bool();
    signal_msg.data = true;

    next_waypoint_publisher_->publish(signal_msg);

    RCLCPP_INFO(this->get_logger(), "Published signal to request the next waypoint.");
}
