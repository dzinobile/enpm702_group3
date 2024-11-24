/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib
/**
 * @file bot_sequence.cpp
 * @author Pritom Gomes (pgomes10@umd.edu)
 * @author Khuzema Habib (khabib@umd.edu)
 * @author Daniel Zinobile (zinobile@umd.edu)
 * @brief Function Definitions for Bot Sequence Node
 * @version 0.1
 * @date 11-23-2024
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "group3_rwa4/bot_sequence.hpp"

/**
 * @brief Construct a new Bot Sequence:: Bot Sequence object
 * @details Initializing Starting Position Coordinated, Robot Orientation(Yaw), and Target Distance and Angles.
 * 
 */
BotSequence::BotSequence() : Node("bot_sequence"),
                             start_x_(0.0), start_y_(0.0), current_x_(0.0), current_y_(0.0),
                             start_yaw_(0.0), current_yaw_(0.0),
                             target_distance_(0.0), target_angle_(0.0),
                             odom_initialized_(false), current_step_(1)
{
    /**
     * @brief Velocity Publisher Publishes to the /cmd_vel topic to move the robot
     * 
     */
    cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    /**
     * @brief Odometer Subscriber Subscribes to the /odom topic to retrieve the current position and distance travelled by the robot
     * 
     */
    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odom", 10, std::bind(&BotSequence::odometryCallback, this, std::placeholders::_1));
        /**
         * @brief Timer callback function that runs at 50 Hz for better control and faster feedback to ensure precise movement
         * 
         */
    timer_ = this->create_wall_timer(std::chrono::milliseconds(50), std::bind(&BotSequence::timerCallback, this)); // Faster timer for better control
}
/**
 * @brief Odometry Callback function sets variables current_x_, current_y_ and orientation to the respective data from the /odom topic
 * 
 * current yaw angle is given by arctan^2 of siny and cosy to calculate the orientation of the robot
 * 
 * @param msg 
 */
void BotSequence::odometryCallback(const nav_msgs::msg::Odometry::SharedPtr msg)
{
    current_x_ = msg->pose.pose.position.x;
    current_y_ = msg->pose.pose.position.y;

    auto orientation = msg->pose.pose.orientation;
    double siny_cosp = 2.0 * (orientation.w * orientation.z + orientation.x * orientation.y);
    double cosy_cosp = 1.0 - 2.0 * (orientation.y * orientation.y + orientation.z * orientation.z);
    current_yaw_ = std::atan2(siny_cosp, cosy_cosp);

    if (!odom_initialized_) /**< Initialize the starting x and y coordinates and yaw to the current x and y coordinates and current yaw at the start of every path*/
    {
        start_x_ = current_x_;
        start_y_ = current_y_;
        start_yaw_ = current_yaw_;
        odom_initialized_ = true;
    }
}
/**
 * @brief Function to move the robot forwards
 * 
 * @param distance 
 */
void BotSequence::handleMoveForward(double distance)
{
    if (target_distance_ == 0.0) 
    {
        target_distance_ = distance; //initialization
    }

    double traveled_distance = calculateDistance(start_x_, start_y_, current_x_, current_y_);
    RCLCPP_INFO(this->get_logger(), "Step %d: Distance traveled: %.2f m", current_step_, traveled_distance); /**< Publish distance travelled to the terminal*/

    if (traveled_distance >= target_distance_) /**< Output that the target distance has been reached and will reset the target distance to 0 for the next path*/
    {
        RCLCPP_INFO(this->get_logger(), "Step %d: Reached target distance of %.2f m.", current_step_, target_distance_);
        target_distance_ = 0.0;
        odom_initialized_ = false; /**< Runs the initialization loop in Odometry Callback Function*/
        current_step_++;
    }
    else
    {
        auto msg = geometry_msgs::msg::Twist();
        msg.linear.x = LINEAR_VELOCITY;
        cmd_vel_pub_->publish(msg);
    }
}
/**
 * @brief Function to rotate the Robot
 * 
 * @param angle 
 */
void BotSequence::handleRotate(double angle)
{
    if (target_angle_ == 0.0) //initialization
    {
        target_angle_ = angle;
    }

    double rotated_angle = calculateAngle(start_yaw_, current_yaw_); /**< Calculates the rotation of the robot to track the orientation output in the terminal */
    RCLCPP_INFO(this->get_logger(), "Step %d: Angle rotated: %.2f degrees", current_step_, rotated_angle);

    if (std::abs(rotated_angle - target_angle_) <= TOLERANCE) /**< If Rotation has been reached within the tolerance limit Output that the Target angle has been reached and reinitialize variables */
    {
        RCLCPP_INFO(this->get_logger(), "Step %d: Reached target angle of %.2f degrees.", current_step_, target_angle_);
        target_angle_ = 0.0;
        odom_initialized_ = false;
        current_step_++;
    }
    else
    {
        auto msg = geometry_msgs::msg::Twist();
        msg.angular.z = (angle < 0) ? -ANGULAR_VELOCITY : ANGULAR_VELOCITY; /**< Adjustment loop to apply Negative or positive velocity to reach desired orientation */
        cmd_vel_pub_->publish(msg);
    }
}
/**
 * @brief Function to Stop the Robot
 * 
 */
void BotSequence::handleStop()
{
    auto msg = geometry_msgs::msg::Twist();
    cmd_vel_pub_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Step %d: Robot stopped. All steps completed.", current_step_);
    rclcpp::shutdown();
}
/**
 * @brief Main Function to Run Switch Case for each path
 * 
 */
void BotSequence::timerCallback()
{
    switch (current_step_)
    {
    case 1:
        handleMoveForward(10.0); /**< Move Robot by 10 m in a straight line */
        break;
    case 2:
        handleRotate(-90.0); /**< Rotate Robot 90 Degrees Clockwise */
        break;
    case 3:
        handleMoveForward(5.0); /**< Move Robot 5 m in a straight lilne */
        break;
    case 4:
        handleRotate(-45.0); /**< Rotate Robot by 45 Degrees Clockwise */
        break;
    case 5:
        handleMoveForward(10.0); /**< Move Robot by 10 m in a straight line */
        break;
    case 6:
        handleStop(); /**< Stop Robot */
        break;
    default:
        RCLCPP_ERROR(this->get_logger(), "Invalid step encountered!");
        rclcpp::shutdown();
        break;
    }
}
