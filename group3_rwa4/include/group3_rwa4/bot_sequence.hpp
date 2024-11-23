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

/**
 * @brief 
 * 
 */
class BotSequence : public rclcpp::Node {
    /**
     * @brief 
     * 
     */
public:
/**
 * @brief Construct a new Bot Sequence object
 * 
 */
    BotSequence();
    /**
     * @brief Destroy the Bot Sequence object
     * 
     */
    ~BotSequence() = default;

private:
/**
 * @brief 
 * 
 */
    void timerCallback();
    /**
     * @brief 
     * 
     * @param msg 
     */
    void odometryCallback(const nav_msgs::msg::Odometry::SharedPtr msg);
    /**
     * @brief 
     * 
     * @param distance 
     */
    void moveForward(double distance);
    /**
     * @brief 
     * 
     * @param angle 
     */
    void rotate(double angle);
    /**
     * @brief 
     * 
     */
    void stopRobot();
    /**
     * @brief 
     * 
     * @param x1 
     * @param y1 
     * @param x2 
     * @param y2 
     * @return double 
     */
    double calculateDistance(double x1, double y1, double x2, double y2);
    /**
     * @brief 
     * 
     * @param initial_yaw 
     * @param current_yaw 
     * @return double 
     */
    double calculateAngle(double initial_yaw, double current_yaw);

    /**
     * @brief 
     * 
     */
    enum ActionFlag { MOVE_FORWARD, ROTATE, STOP };
    ActionFlag action_flag_;

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::TimerBase::SharedPtr timer_;

    double start_x_; 
    double start_y_;
    double current_x_;
    double current_y_;
    double start_yaw_;
    double current_yaw_;
    double target_distance_;
    double target_angle_;
    double linear_velocity_;
    double angular_velocity_;
    bool odom_initialized_;
    int current_step_; // Tracks the current step of the sequence
};

#endif // BOT_SEQUENCE_HPP