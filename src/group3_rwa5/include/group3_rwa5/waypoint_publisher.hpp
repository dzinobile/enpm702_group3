/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#pragma once

#include <rclcpp/rclcpp.hpp>
#include <bot_waypoint_msgs/msg/bot_waypoint.hpp>
#include <std_msgs/msg/bool.hpp>
#include <array>

/**
 * @class WaypointPublisher
 * @brief A ROS 2 node for managing and publishing waypoints for a robot.
 *
 * The WaypointPublisher class stores a predefined list of waypoints and publishes
 * them sequentially on the bot_waypoint topic. It listens for signals indicating
 * readiness for the next waypoint.
 */
class WaypointPublisher : public rclcpp::Node {
public:
    /**
     * @brief Constructor for the WaypointPublisher class.
     *
     * Initializes the publisher for waypoints, the subscriber for next waypoint signals,
     * and stores predefined waypoints in an array.
     */
    WaypointPublisher();

private:
    /**
     * @brief Publishes the current waypoint to the bot_waypoint topic.
     *
     * Retrieves the current waypoint from the array and publishes it. Ensures each
     * waypoint is published only once.
     */
    void publish_int();

    /**
     * @brief Callback function to handle readiness signals for the next waypoint.
     *
     * Updates the waypoint index upon receiving a true signal and publishes the next waypoint.
     *
     * @param msg A shared pointer to the received Bool message indicating readiness for the next waypoint.
     */
    void nextWaypointCallback(const std_msgs::msg::Bool::SharedPtr msg);

    /**
     * @brief Publisher for publishing waypoints.
     *
     * Publishes BotWaypoint messages on the bot_waypoint topic to provide target positions,
     * orientations, and tolerances for navigation.
     */
    rclcpp::Publisher<bot_waypoint_msgs::msg::BotWaypoint>::SharedPtr publisher_;

    /**
     * @brief Subscriber for readiness signals from the WaypointReacher node.
     *
     * Listens for Boolean messages on the next_waypoint topic to determine when
     * to publish the next waypoint.
     */
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr next_waypoint_subscriber_;

    /**
     * @brief Array of predefined waypoints.
     *
     * Stores the sequence of waypoints, each containing a position (x, y), orientation (theta),
     * and tolerance value.
     */
    std::array<bot_waypoint_msgs::msg::BotWaypoint, 3> waypoints_;

    /**
     * @brief Index of the current waypoint being published.
     *
     * Tracks the progress through the sequence of waypoints.
     */
    size_t current_index_;

    /**
     * @brief Flag to indicate if the current waypoint has been published.
     *
     * Ensures that waypoints are not published multiple times.
     */
    bool waypoint_published_;
};
