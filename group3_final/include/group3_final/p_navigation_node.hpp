#pragma once

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <mage_msgs/msg/part_pose.hpp>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2/LinearMath/Matrix3x3.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>
#include <vector>
#include <cmath>

class NavigationNode : public rclcpp::Node {
public:
    NavigationNode();

private:
    // Callbacks
    void waypoint_callback(const mage_msgs::msg::PartPose::SharedPtr msg);
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg);
    
    // Control loop
    void control_loop();

    // Utility function
    double normalize_angle(double angle);

    // Publishers and subscribers
    rclcpp::Subscription<mage_msgs::msg::PartPose>::SharedPtr waypoint_subscriber_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscription_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;

    // Variables for state
    std::vector<mage_msgs::msg::PartPose> waypoints_;
    bool waypoint_reached_;
    double current_x_;
    double current_y_;
    double current_theta_;

    // Control gains and threshold
    double kp_distance_;
    double kp_angle_;
    double epsilon_;
};
