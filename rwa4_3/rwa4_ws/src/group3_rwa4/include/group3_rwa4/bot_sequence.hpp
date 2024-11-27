#pragma once
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <iostream>

class BotSequence: public rclcpp::Node {
    public:
    BotSequence(std::string node_name): rclcpp::Node(node_name){
        //publisher for velocity commands
        velocity_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10)
        
        auto message = geometry_msgs::msg::Twist();
        /**
         * @brief 
         * 
         * @param message 
         */
        velocity_publisher_->publish(message);
        

    
    }

    private:
        /**
        * @brief ROS 2 publisher for velocity commands.
        *
        * Publishes `geometry_msgs::msg::Twist` messages to control the robot's linear
        * and angular velocities.
        */

        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr velocity_publisher_;
    
};
