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
    // Define the sequence of waypoints
waypoints_[0] = bot_waypoint_msgs::msg::BotWaypoint();
waypoints_[0].tolerance = bot_waypoint_msgs::msg::BotWaypoint::SMALL;
waypoints_[0].waypoint.x = 4.0;
waypoints_[0].waypoint.y = 4.0;
waypoints_[0].waypoint.theta = 1.57;

waypoints_[1] = bot_waypoint_msgs::msg::BotWaypoint();
waypoints_[1].tolerance = bot_waypoint_msgs::msg::BotWaypoint::MEDIUM;
waypoints_[1].waypoint.x = 4.0;
waypoints_[1].waypoint.y = -4.0;
waypoints_[1].waypoint.theta = 3.14;

waypoints_[2] = bot_waypoint_msgs::msg::BotWaypoint();
waypoints_[2].tolerance = bot_waypoint_msgs::msg::BotWaypoint::LARGE;
waypoints_[2].waypoint.x = -4.0;
waypoints_[2].waypoint.y = 4.0;
waypoints_[2].waypoint.theta = -3.14;

    // Publish the first waypoint immediately
    publish_int();

    RCLCPP_INFO_STREAM(this->get_logger(), "WaypointPublisher node started.");
}
//Current waypoint publisher function
void WaypointPublisher::publish_int() {
    if (current_index_ < waypoints_.size()) {
        // Retrieve and publish the current waypoint
        auto message = bot_waypoint_msgs::msg::BotWaypoint();
        message = waypoints_[current_index_];
        publisher_->publish(message);

        //Send message with current waypoint and tolerance
        RCLCPP_INFO_STREAM(this->get_logger(), "Published waypoint: [" 
            << message.waypoint.x << ", " << message.waypoint.y << ", " << message.waypoint.theta 
            << "] with tolerance " << static_cast<int>(message.tolerance));
    } else {
        RCLCPP_WARN_STREAM(this->get_logger(), "No more waypoints to publish.");
    }
}

//Recieve next waypoint function
void WaypointPublisher::nextWaypointCallback(const std_msgs::msg::Bool::SharedPtr msg) {
    if (msg->data && current_index_ + 1 < waypoints_.size()) {
        // Move to the next waypoint and publish it
        current_index_++;
        publish_int();
    } else if (current_index_ + 1 >= waypoints_.size()) {
        RCLCPP_INFO_STREAM(this->get_logger(), "All waypoints have been published.");
    }
}
