#pragma once
#include <rclcpp/rclcpp.hpp>
#include <bot_waypoint_msgs/msg/bot_waypoint.hpp>

class WaypointPublisher : rclcpp::Node {
    public:
        WaypointPublisher()
            : Node("waypoint_publisher_node") {
                //QoS setting for the publisher
                rclcpp::QoS pub_qos(10);
                pub_qos.reliable();
                pub_qos.transient_local();
                //initialize the publisher
                publisher_ = this->create_publisher<bot_waypoint_msgs::msg::BotWaypoint>("waypoint_publisher", pub_qos);
                
                //initialize the timer
                timer_ = this->create_wall_timer(
                    std::chrono::milliseconds(500),
                    std::bind(&WaypointPublisher::publish_int, this));
                RCLCPP_INFO_STREAM(this->get_logger(), "waypoint_publisher_node started");

                
            }

    private:
        /**
     * @brief Counter variable used for publishing integer values.
     *
     * Tracks the current count to be published by the `publish_int` method.
     * Initialized to zero.
     */
    int counter_{0};

        /**
     * @brief Publishes the current counter value as an `Int64` message.
     *
     * This function retrieves the current value of the `counter_` variable
     * and publishes it to the associated topic using the `publisher_`.
     */
    void publish_int();

    /**
     * @brief ROS 2 publisher for publishing integer values.
     *
     * Publishes `example_interfaces::msg::Int64` messages containing the value of `counter_`.
     */
    rclcpp::Publisher<bot_waypoint_msgs::msg::BotWaypoint>::SharedPtr publisher_;

        /**
     * @brief ROS 2 timer for scheduling periodic publishing.
     *
     * Triggers the `publish_int` method at regular intervals.
     */
    rclcpp::TimerBase::SharedPtr timer_;

};//class WaypointPublisher