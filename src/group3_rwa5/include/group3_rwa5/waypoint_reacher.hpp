/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#pragma once

#include <rclcpp/rclcpp.hpp>
#include <bot_waypoint_msgs/msg/bot_waypoint.hpp>
#include <geometry_msgs/msg/twist.hpp>

/**
 * @class WaypointReacher
 * @brief A ROS 2 node for guiding a robot to navigate through waypoints.
 *
 * The WaypointReacher class subscribes to waypoint messages, calculates the necessary
 * motion commands using proportional control, and signals when the robot is ready
 * to move to the next waypoint.
 */
class WaypointReacher : public rclcpp::Node {
public:
    /**
     * @brief Constructor for the WaypointReacher class.
     *
     * Initializes the subscriber for waypoints, publishers for velocity commands
     * and next waypoint signals, and sets up the node.
     */
    WaypointReacher();

private:
    /**
     * @brief Callback function to handle received waypoint messages.
     *
     * Updates the current waypoint and triggers the robot's movement toward the
     * target using proportional control.
     *
     * @param msg A shared pointer to the received BotWaypoint message.
     */
    void receive_int(const bot_waypoint_msgs::msg::BotWaypoint::SharedPtr msg);

    /**
     * @brief Moves the robot toward the current waypoint using proportional control.
     *
     * Calculates the required linear and angular velocities to guide the robot
     * to the target waypoint. Stops the robot upon reaching the target.
     */
    void move_toward_waypoint();

    /**
     * @brief Publishes a signal to indicate readiness for the next waypoint.
     *
     * Sends a Boolean message (`true`) to the next_waypoint topic after the
     * current waypoint is successfully reached.
     */
    void publish_next_waypoint_signal();

    /**
     * @brief Subscriber to the bot_waypoint topic.
     *
     * Listens for waypoint messages containing position, orientation, and tolerance
     * information for navigation.
     */
    rclcpp::Subscription<bot_waypoint_msgs::msg::BotWaypoint>::SharedPtr subscriber_;

    /**
     * @brief Publisher for velocity commands to control the robot's movement.
     *
     * Publishes Twist messages on the /cmd_vel topic.
     */
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;

    /**
     * @brief Publisher to signal readiness for the next waypoint.
     *
     * Publishes Boolean messages (`true`) on the next_waypoint topic.
     */
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr next_waypoint_publisher_;

    /**
     * @brief The current waypoint being navigated to.
     *
     * Stores the position, orientation, and tolerance for the target waypoint.
     */
    bot_waypoint_msgs::msg::BotWaypoint current_waypoint_;

    /**
     * @brief Flag to indicate whether the current waypoint has been reached.
     *
     * Used to prevent unnecessary commands once the target is reached.
     */
    bool waypoint_reached_;
};
