/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "waypoint_publisher.hpp"

WaypointPublisher::WaypointPublisher()
    : Node("waypoint_publisher_node"), current_index_(0), waypoint_published_(false) {
    // QoS settings for reliable and transient local communication
    rclcpp::QoS pub_qos(10);
    pub_qos.reliable();
    pub_qos.transient_local();

    // Initialize the publisher for waypoints
    publisher_ = this->create_publisher<bot_waypoint_msgs::msg::BotWaypoint>("bot_waypoint", pub_qos);

    // Initialize the subscriber for next waypoint signals
    next_waypoint_subscriber_ = this->create_subscription<std_msgs::msg::Bool>(
        "next_waypoint", 10, std::bind(&WaypointPublisher::nextWaypointCallback, this, std::placeholders::_1));

    // Define the sequence of waypoints
    waypoints_[0] = bot_waypoint_msgs::msg::BotWaypoint{{4.0, 4.0, 1.57}, bot_waypoint_msgs::msg::BotWaypoint::SMALL};
    waypoints_[1] = bot_waypoint_msgs::msg::BotWaypoint{{4.0, -4.0, 3.14}, bot_waypoint_msgs::msg::BotWaypoint::MEDIUM};
    waypoints_[2] = bot_waypoint_msgs::msg::BotWaypoint{{-4.0, 4.0, -3.14}, bot_waypoint_msgs::msg::BotWaypoint::LARGE};

    // Publish the first waypoint immediately
    publish_int();

    RCLCPP_INFO_STREAM(this->get_logger(), "WaypointPublisher node started.");
}

void WaypointPublisher::publish_int() {
    if (current_index_ < waypoints_.size()) {
        // Retrieve and publish the current waypoint
        auto message = bot_waypoint_msgs::msg::BotWaypoint();
        message = waypoints_[current_index_];
        publisher_->publish(message);

        RCLCPP_INFO_STREAM(this->get_logger(), "Published waypoint: [" 
            << message.pose.x << ", " << message.pose.y << ", " << message.pose.theta 
            << "] with tolerance " << static_cast<int>(message.tolerance));
    } else {
        RCLCPP_WARN_STREAM(this->get_logger(), "No more waypoints to publish.");
    }
}

void WaypointPublisher::nextWaypointCallback(const std_msgs::msg::Bool::SharedPtr msg) {
    if (msg->data && current_index_ + 1 < waypoints_.size()) {
        // Move to the next waypoint and publish it
        current_index_++;
        publish_int();
    } else if (current_index_ + 1 >= waypoints_.size()) {
        RCLCPP_INFO_STREAM(this->get_logger(), "All waypoints have been published.");
    }
}
