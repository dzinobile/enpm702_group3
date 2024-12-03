#pragma once
#include <rclcpp/rclcpp.hpp>
#include <bot_waypoint_msgs/msg/bot_waypoint.hpp>
#include <geometry_msgs/msg/twist.hpp>

class WaypointReacher : public rclcpp::Node {
    public:
        WaypointReacher()
            : Node("waypoint_reacher_node") {
            //initialize the subscriber
            rclcpp::QoS sub_qos(10); //keep the last 10 messages
            sub_qos.reliable();
            sub_qos.transient_local();
            subscriber_ = this->create_subscription<bot_waypoint_msgs::msg::BotWaypoint>(
                "waypoint_reacher", sub_qos, std::bind(&WaypointReacher ::receive_int, this, std::placeholders::_1));//IDK WHY STD PLACEHOLDERS IS THERE
            velocity_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel, 10");
            RCLCPP_INFO_STREAM(this->get_logger(), "waypoint_reacher");
            }
            

    private:

     /**
     * @brief Callback function to handle received messages of type Int64.
     *
     * This function is called whenever a message is received on the subscribed topic.
     * It processes the message of type `example_interfaces::msg::Int64`.
     *
     * @param msg A shared pointer to the received message.
     */
    void receive_int(const bot_waypoint_msgs::msg::BotWaypoint::SharedPtr msg);

    /**
     * @brief Subscriber to topics publishing messages of type Int64.
     *
     * This subscriber listens to messages of type `example_interfaces::msg::Int64`.
     * It invokes the `receive_int` callback function whenever a new message is received.
     */
    rclcpp::Subscription<bot_waypoint_msgs::msg::BotWaypoint>::SharedPtr subscriber_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;
};//  class Waypoint Reacher