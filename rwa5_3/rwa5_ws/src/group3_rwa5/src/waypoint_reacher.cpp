#include <rclcpp/rclcpp.hpp>
#include <bot_waypoint_msgs/msg/bot_waypoint.hpp>
#include "waypoint_reacher.hpp"

void WaypointReacher::receive_int(const bot_waypoint_msgs::msg::BotWaypoint msg) {
    RCLCPP_INFO_STREAM(this->get_logger(), "Received")
}