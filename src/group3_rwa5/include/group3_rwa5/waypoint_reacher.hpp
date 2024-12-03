/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#pragma once

#include <rclcpp/rclcpp.hpp>
#include <bot_waypoint_msgs/msg/bot_waypoint.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <std_msgs/msg/bool.hpp>

/**
 * @class WaypointReacher
 * @brief A ROS 2 node for guiding a robot to navigate through waypoints.
 *
 * This class handles the reception of waypoints, computes motion commands for the robot,
 * and publishes signals when the robot is ready to move to the next waypoint.
 */
class WaypointReacher : public rclcpp::Node {
public:
    /**
     * @brief Constructs the WaypointReacher node.
     *
     * Initializes the waypoint subscriber, velocity publisher, and next waypoint signal publisher.
     */
    WaypointReacher();

private:
    /**
     * @brief Callback function to handle received waypoint messages.
     *
     * This function processes the waypoint message received on the "bot_waypoint" topic,
     * updates the current target waypoint, and triggers the robot's movement toward the target.
     *
     * @param msg A shared pointer to the received BotWaypoint message, containing:
     * - The target position (x, y).
     * - The orientation (theta).
     * - The tolerance for considering the waypoint reached.
     */
    void receive_int(const bot_waypoint_msgs::msg::BotWaypoint::SharedPtr msg);

    /**
     * @brief Moves the robot toward the current waypoint using proportional control.
     *
     * This function calculates linear and angular velocities based on the difference between
     * the robot's current position and the target waypoint. It stops the robot when the waypoint
     * is within the specified tolerance.
     */
    void move_toward_waypoint();

    /**
     * @brief Publishes a signal indicating readiness for the next waypoint.
     *
     * This function sends a `true` Boolean message on the "next_waypoint" topic after the
     * robot successfully reaches the current waypoint.
     */
    void publish_next_waypoint_signal();

    /**
     * @brief Subscriber to the "bot_waypoint" topic.
     *
     * This subscriber listens for waypoint messages containing:
     * - The target position (x, y).
     * - Orientation (theta).
     * - Tolerance for waypoint completion.
     */
    rclcpp::Subscription<bot_waypoint_msgs::msg::BotWaypoint>::SharedPtr subscriber_;

    /**
     * @brief Publisher for sending velocity commands to the robot.
     *
     * This publisher sends `geometry_msgs::msg::Twist` messages on the "/cmd_vel" topic,
     * which control the robot's linear and angular velocities.
     */
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;

    /**
     * @brief Publisher for readiness signals on the "next_waypoint" topic.
     *
     * This publisher sends a `std_msgs::msg::Bool` message to indicate when the robot
     * is ready for the next waypoint.
     */
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr next_waypoint_publisher_;

    /**
     * @brief Stores the current target waypoint.
     *
     * Contains the target position, orientation, and tolerance values received from the
     * "bot_waypoint" topic.
     */
    bot_waypoint_msgs::msg::BotWaypoint current_waypoint_;

    /**
     * @brief Indicates whether the current waypoint has been reached.
     *
     * This flag ensures that the robot stops moving and signals readiness for the next waypoint
     * only once per target.
     */
    bool waypoint_reached_;
};
