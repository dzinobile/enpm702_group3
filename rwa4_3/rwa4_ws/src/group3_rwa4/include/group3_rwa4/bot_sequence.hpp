#pragma once
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <iostream>

class BotSequence: public rclcpp::Node {
    public:
    BotSequence(std::string node_name): rclcpp::Node(node_name){
        velocity_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10)
        
        auto message = geometry_msgs::msg::Twist();

        velocity_publisher_->publish(message);
        

    
    }

    private:
        rclcpp::Publisher<geometry_msgs
    
};
