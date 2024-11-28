#include <rclcpp/rclcpp.hpp>
#include <bot_waypoint_msgs/msg/bot_waypoint.hpp>
#include "waypoint_publisher.hpp"

void WaypointPublisher::publish_int() {
    auto message = bot_waypoint_msgs::msg::BotWaypoint();
    message.waypoint = counter_; //GONNA NEED TO FIND A WAY TO SET THIS WAYPOINT
    publisher_->publish(message);
    RCLCPP_INFO_STREAM(this->get_logger(), "published waypoint");
    counter_++;
}
