/// ENPM702 Assignment - 4
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

// /**
//  * @file bot_sequence.hpp
//  * @brief Header file for BotSequence class with modularized steps
//  * @version 0.2
//  * @date 2024-11-19
//  */
// #ifndef BOT_SEQUENCE_HPP
// #define BOT_SEQUENCE_HPP

// #include <rclcpp/rclcpp.hpp>
// #include <geometry_msgs/msg/twist.hpp>
// #include <nav_msgs/msg/odometry.hpp>
// #include <cmath>

// class BotSequence : public rclcpp::Node {
// public:
//     BotSequence();
//     ~BotSequence() = default;

// private:
//     void timerCallback();
//     void odometryCallback(const nav_msgs::msg::Odometry::SharedPtr msg);
//     void handleMoveForward(double distance);
//     void handleRotate(double angle);
//     void handleStop();
//     double calculateDistance(double x1, double y1, double x2, double y2);
//     double calculateAngle(double initial_yaw, double current_yaw);

//     rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
//     rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
//     rclcpp::TimerBase::SharedPtr timer_;

//     double start_x_, start_y_, current_x_, current_y_;
//     double start_yaw_, current_yaw_;
//     double target_distance_, target_angle_;
//     double linear_velocity_, angular_velocity_;
//     bool odom_initialized_;
//     int current_step_;
// };

// #endif // BOT_SEQUENCE_HPP


// #ifndef BOT_SEQUENCE_HPP
// #define BOT_SEQUENCE_HPP

// #include "rclcpp/rclcpp.hpp"
// #include "geometry_msgs/msg/twist.hpp"
// #include "nav_msgs/msg/odometry.hpp"
// #include <cmath>

// class BotSequence : public rclcpp::Node {
// public:
//     BotSequence();

// private:
//     // Constants
//     static constexpr double LINEAR_VELOCITY = 1.0;
//     static constexpr double ANGULAR_VELOCITY = 0.3;

//     // State Management
//     enum ActionFlag { MOVE_FORWARD, ROTATE, STOP };

//     // Helper Methods
//     static constexpr double calculateDistance(double x1, double y1, double x2, double y2) {
//         return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
//     }

//     static constexpr double calculateAngle(double initial_yaw, double current_yaw) {
//         double delta_angle = current_yaw - initial_yaw;
//         if (delta_angle > M_PI) delta_angle -= 2 * M_PI;
//         if (delta_angle < -M_PI) delta_angle += 2 * M_PI;
//         return delta_angle * (180.0 / M_PI); // Convert radians to degrees
//     }

//     // Methods for each action
//     void handleMoveForward(double distance);
//     void handleRotate(double angle);
//     void handleStop();
//     void timerCallback();

//     // Callback
//     void odometryCallback(const nav_msgs::msg::Odometry::SharedPtr msg);

//     // ROS2 Components
//     rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
//     rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
//     rclcpp::TimerBase::SharedPtr timer_;

//     // Attributes
//     double start_x_;
//     double start_y_;
//     double current_x_;
//     double current_y_;
//     double start_yaw_;
//     double current_yaw_;
//     double target_distance_;
//     double target_angle_;
//     bool odom_initialized_;
//     int current_step_;
// };

// #endif // BOT_SEQUENCE_HPP

#ifndef BOT_SEQUENCE_HPP
#define BOT_SEQUENCE_HPP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <cmath>

class BotSequence : public rclcpp::Node {
public:
    BotSequence();

private:
    // Constants
    static constexpr double LINEAR_VELOCITY = 1.0;
    static constexpr double ANGULAR_VELOCITY = 0.2; // Reduced for finer control
    static constexpr double TOLERANCE = 1.0;        // Tolerance for angular error (in degrees)

    // State Management
    enum ActionFlag { MOVE_FORWARD, ROTATE, STOP };

    // Helper Methods
    static constexpr double calculateDistance(double x1, double y1, double x2, double y2) {
        return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    }

    static constexpr double calculateAngle(double initial_yaw, double current_yaw) {
        double delta_angle = current_yaw - initial_yaw;
        if (delta_angle > M_PI) delta_angle -= 2 * M_PI;
        if (delta_angle < -M_PI) delta_angle += 2 * M_PI;
        return delta_angle * (180.0 / M_PI); // Convert radians to degrees
    }

    // Methods for each action
    void handleMoveForward(double distance);
    void handleRotate(double angle);
    void handleStop();
    void timerCallback();

    // Callback
    void odometryCallback(const nav_msgs::msg::Odometry::SharedPtr msg);

    // ROS2 Components
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::TimerBase::SharedPtr timer_;

    // Attributes
    double start_x_;
    double start_y_;
    double current_x_;
    double current_y_;
    double start_yaw_;
    double current_yaw_;
    double target_distance_;
    double target_angle_;
    bool odom_initialized_;
    int current_step_;
};

#endif // BOT_SEQUENCE_HPP
