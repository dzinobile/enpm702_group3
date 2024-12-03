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

    // Initialize the subscriber for readiness signals
    next_waypoint_subscriber_ = this->create_subscription<std_msgs::msg::Bool>(
        "next_waypoint", 10, std::bind(&WaypointPublisher::nextWaypointCallback, this, std::placeholders::_1));

    // Define and initialize the sequence of waypoints
    bot_waypoint_msgs::msg::BotWaypoint waypoint1;
    waypoint1.waypoint.x = 4.0;
    waypoint1.waypoint.y = 4.0;
    waypoint1.waypoint.theta = 1.57;
    waypoint1.tolerance = bot_waypoint_msgs::msg::BotWaypoint::SMALL;
    waypoints_[0] = waypoint1;

    bot_waypoint_msgs::msg::BotWaypoint waypoint2;
    waypoint2.waypoint.x = 4.0;
    waypoint2.waypoint.y = -4.0;
    waypoint2.waypoint.theta = 3.14;
    waypoint2.tolerance = bot_waypoint_msgs::msg::BotWaypoint::MEDIUM;
    waypoints_[1] = waypoint2;

    bot_waypoint_msgs::msg::BotWaypoint waypoint3;
    waypoint3.waypoint.x = -4.0;
    waypoint3.waypoint.y = 4.0;
    waypoint3.waypoint.theta = -3.14;
    waypoint3.tolerance = bot_waypoint_msgs::msg::BotWaypoint::LARGE;
    waypoints_[2] = waypoint3;

    // Publish the first waypoint
    publish_int();

    RCLCPP_INFO_STREAM(this->get_logger(), "WaypointPublisher node started.");
}

void WaypointPublisher::publish_int() {
    if (current_index_ < waypoints_.size()) {
        auto message = waypoints_[current_index_]; // Get the current waypoint
        publisher_->publish(message); // Publish the waypoint

        RCLCPP_INFO_STREAM(this->get_logger(), "Published waypoint: [" 
            << message.waypoint.x << ", " << message.waypoint.y << ", " << message.waypoint.theta 
            << "] with tolerance " << static_cast<int>(message.tolerance));
    } else {
        RCLCPP_WARN_STREAM(this->get_logger(), "No more waypoints to publish.");
    }
}

void WaypointPublisher::nextWaypointCallback(const std_msgs::msg::Bool::SharedPtr msg) {
    if (msg->data && current_index_ + 1 < waypoints_.size()) {
        current_index_++; // Move to the next waypoint
        publish_int();    // Publish the next waypoint
    } else if (current_index_ + 1 >= waypoints_.size()) {
        RCLCPP_INFO_STREAM(this->get_logger(), "All waypoints have been published.");
    }
}
