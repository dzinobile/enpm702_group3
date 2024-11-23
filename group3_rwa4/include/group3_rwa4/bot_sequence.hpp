/**
 * @file bot_sequence.hpp
 * @author ...
 * @brief Header file for BotSequence class with odometry integration and task sequencing
 * @version 0.1
 * @date 2024-11-19
 * 
 * @copyright Copyright (c) 2024
 */
#ifndef BOT_SEQUENCE_HPP
#define BOT_SEQUENCE_HPP

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <cmath>

class BotSequence : public rclcpp::Node {
public:
    BotSequence();
    ~BotSequence() = default;

private:
    void timerCallback();
    void odometryCallback(const nav_msgs::msg::Odometry::SharedPtr msg);
    void moveForward(double distance);
    void rotate(double angle);
    void stopRobot();
    double calculateDistance(double x1, double y1, double x2, double y2);
    double calculateAngle(double initial_yaw, double current_yaw);

    enum ActionFlag { MOVE_FORWARD, ROTATE, STOP };
    ActionFlag action_flag_;

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::TimerBase::SharedPtr timer_;

    double start_x_, start_y_, current_x_, current_y_;
    double start_yaw_, current_yaw_;
    double target_distance_, target_angle_;
    double linear_velocity_, angular_velocity_;
    bool odom_initialized_;
    int current_step_; // Tracks the current step of the sequence
};

#endif // BOT_SEQUENCE_HPP
