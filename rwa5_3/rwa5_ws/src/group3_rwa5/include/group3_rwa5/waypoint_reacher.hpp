#pragma once

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <bot_waypoint_msgs/msg/bot_waypoint.hpp>
#include <std_msgs/msg/bool.hpp>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>


/**
 * @class WaypointReacher
 * @brief A ROS 2 node for reaching the published waypoints
 *
 * The WaypointReacher class commands the robot to reach the desired waypoint and angle using a proportional controller, 
 * then signals when it is ready to recieve the next waypoint.
 */
class WaypointReacher : public rclcpp::Node {
public:
    /**
     * @brief Constructor for the WaypointReacher class.
     *
     * Initializes the waypoint reacher.
     */
    WaypointReacher();

private:
    /**
     * @brief Recieves the current waypoint from the bot_waypoint topic.
     *
     * Receives the current waypoint from the array and sets as current waypoint
     * Return type: void
     * @param msg A shared pointer to the bot waypoint
     *
     */
    void receive_int(const bot_waypoint_msgs::msg::BotWaypoint::SharedPtr msg);


    /**
     * @brief Publishes signal to request the next waypoint.
     *
     * When previous waypoint is achieved, publishes signal to request the next waypoint
     * 
     */
    void publish_next_waypoint_signal();

    /**
     * @brief Feeds current position to control loop
     *
     * Takes current position from odometry and feeds  into the control loop 
     * @param msg shared pointer to odometry message
     * 
     */
    
    void odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg);

    /**
     * @brief Proportional control function
     *
     * Reads current position and publishes updated velocity commands based on chosen gain values
     * 
     */
    void control_loop();

    /**
     * @brief Normalizes angle
     *
     * Normalizes angles to within +/- 2pi 
     * @param double angle
     * @return normalized angles
     */
    double normalize_angle(double angle);

    /**
     * @brief waypoint subscriber
     *Subscriber for waypoint messages
     * 
     */
    rclcpp::Subscription<bot_waypoint_msgs::msg::BotWaypoint>::SharedPtr subscriber_;

    /**
     * @brief velocity publisher
     * publisher for velocity commandss
     * 
     */
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;

    /**
     * @brief next waypoint publisher
     * publishes next waypoint
     * 
     */
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr next_waypoint_publisher_;

    /**
     * @brief odometry subscriber
     * subcribes for odometry data
     * 
     */
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_subscription_;


    /**
     * @brief Current waypoint attribute
     * Contains current waypoint
     * 
     */
    bot_waypoint_msgs::msg::BotWaypoint current_waypoint_;

    /**
     * @brief way point reached boolean
     * true/false on whether waypoint is reached
     * 
     */
    bool waypoint_reached_;

    /**
     * @brief current x position
     * attribute for  current x position
     * 
     */
    double current_x_;

    /**
     * @brief current y position
     * attribute for current y position
     * 
     */
    double current_y_;

    /**
     * @brief current angle
     * attribute for current angle
     * 
     */
    double current_theta_;

    /**
     * @brief distance gainn
     * distance gain value for  proportional controller
     * 
     */
    double kp_distance_;

    /**
     * @brief angle gain
     * angle gain value for proportional controller
     * 
     */
    double kp_angle_;

    /**
     * @brief distance error
     * error value for distance
     * 
     */
    double epsilon_;

    /**
     * @brief angle error
     * error value for angle
     * 
     */
    double epsilon_theta_;

    /**
     * @brief Roll position
     * attribute for roll position
     * 
     */
    double roll_;

    /**
     * @brief pitch position 
     * attribute for pitch position
     * 
     */
    double pitch_;
};