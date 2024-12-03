/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#pragma once

#include <rclcpp/rclcpp.hpp>
#include <bot_waypoint_msgs/msg/bot_waypoint.hpp>
#include <std_msgs/msg/bool.hpp>
#include <array>

/**
 * @class WaypointPublisher
 * @brief A ROS 2 node for managing and publishing waypoints sequentially.
 *
 * Publishes a predefined set of waypoints on the "bot_waypoint" topic and listens for
 * readiness signals on the "next_waypoint" topic.
 */
class WaypointPublisher : public rclcpp::Node {
public:
    /**
     * @brief Constructor for the WaypointPublisher class.
     *
     * Initializes the publisher, subscriber, and predefined waypoints.
     */
    WaypointPublisher();

private:
    /**
     * @brief Publishes the current waypoint to the "bot_waypoint" topic.
     *
     * Ensures that each waypoint is published only once and handles edge cases
     * when no more waypoints are left.
     */
    void publish_int();

    /**
     * @brief Callback function for readiness signals from the "next_waypoint" topic.
     *
     * Updates the waypoint index upon receiving a true signal and publishes the next waypoint.
     *
     * @param msg A shared pointer to the received Bool message.
     */
    void nextWaypointCallback(const std_msgs::msg::Bool::SharedPtr msg);

    /// Publisher for publishing waypoints to the "bot_waypoint" topic
    rclcpp::Publisher<bot_waypoint_msgs::msg::BotWaypoint>::SharedPtr publisher_;

    /// Subscriber for receiving readiness signals from the "next_waypoint" topic
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr next_waypoint_subscriber_;

    /// Predefined array of waypoints
    std::array<bot_waypoint_msgs::msg::BotWaypoint, 3> waypoints_;

    /// Current index of the waypoint being processed
    size_t current_index_;

    /// Boolean flag to ensure each waypoint is published only once
    bool waypoint_published_;
};
