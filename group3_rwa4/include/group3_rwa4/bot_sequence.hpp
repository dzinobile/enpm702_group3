/// ENPM702 Assignment - 4
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

// /**
//  * @file bot_sequence.hpp
//  * @brief Header file for BotSequence class with modularized steps
//  * @version 0.2
//  * @date 2024-11-19
//  */

#ifndef BOT_SEQUENCE_HPP
#define BOT_SEQUENCE_HPP

#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include <cmath>

/**
 * @brief BotSequence Class Extends Node
 *
 */
class BotSequence : public rclcpp::Node
{
public:
    /**
     * @brief Construct a new Bot Sequence object
     *
     */
    BotSequence();

private:
    // Constants
    /**
     * @brief Setting Constant Values for Linear Velocity at 1 m/s and Angular Velocity at 0.2 m/s. Also, Tolerance for Angular error is set to 1 deg
     *
     */
    static constexpr double LINEAR_VELOCITY = 1.0;
    static constexpr double ANGULAR_VELOCITY = 0.2; // Reduced for finer control
    static constexpr double TOLERANCE = 1.0;        // Tolerance for angular error (in degrees)

    // State Management
    /**
     * @brief Create Action Flags to call based on the state of the Robot
     *
     */
    enum ActionFlag
    {
        MOVE_FORWARD,
        ROTATE,
        STOP
    };

    // Helper Methods
    /**
     * @brief Distance Calculation Method
     *
     * @param x1
     * @param y1
     * @param x2
     * @param y2
     * @return constexpr double
     */
    static constexpr double calculateDistance(double x1, double y1, double x2, double y2)
    {
        return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    }
    /**
     * @brief Angle Calculation Method
     *
     * @param initial_yaw
     * @param current_yaw
     * @return constexpr double
     */
    static constexpr double calculateAngle(double initial_yaw, double current_yaw)
    {
        double delta_angle = current_yaw - initial_yaw;
        if (delta_angle > M_PI)
            delta_angle -= 2 * M_PI;
        if (delta_angle < -M_PI)
            delta_angle += 2 * M_PI;
        return delta_angle * (180.0 / M_PI); // Convert radians to degrees
    }

    // Methods for each action
    /**
     * @brief Function Declations for Moving Forward, Rotation, Stopping and Timer Callback method
     *
     * @param distance,angle
     */
    void handleMoveForward(double distance);
    void handleRotate(double angle);
    void handleStop();
    void timerCallback();

    // Callback
    /**
     * @brief Odometry Callback function to subscribe to /odom topic to initialize and update values 
     *
     * @param msg
     */
    void odometryCallback(const nav_msgs::msg::Odometry::SharedPtr msg);

    // ROS2 Components
    /**
     * @brief Publisher to /cmd_vel, Subscription to /odom topic, and timer 
     *
     */
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::TimerBase::SharedPtr timer_;

    // Attributes
    double start_x_;         /**<Starting X Position*/
    double start_y_;         /**<Starting Y Position  */
    double current_x_;       /**<Current X Position(/odom subscription)  */
    double current_y_;       /**<Current Y Position (/odom subscription) */
    double start_yaw_;       /**<Starting Yaw Value */
    double current_yaw_;     /**<Current Yaw Value (Calculated)  */
    double target_distance_; /**<Target Distance for each path */
    double target_angle_;    /**< Target Angle for each path */
    bool odom_initialized_;  /**<State of Odom initialization to reset variables after completion of each path  */
    int current_step_;       /**< Current timestep  */
};

#endif // BOT_SEQUENCE_HPP
