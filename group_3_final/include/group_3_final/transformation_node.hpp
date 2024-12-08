#pragma once
#include <rclcpp/rclcpp.hpp>
#include <memory>
#include  <array>
#include <mage_msgs/msg/advanced_logical_camera_image.hpp>
#include <rclcpp/rclcpp.hpp>
#include <mage_msgs/msg/advanced_logical_camera_image.hpp>
#include <unordered_map>

using namespace std::chrono_literals; // Enables direct use of literals

class TransformationNode : public rclcpp::Node
{
    public:
    TransformationNode(std::string node_name):
    rclcpp::Node(node_name)
    {
        camera_sub_ = this->create_subscription<mage_msgs::msg::PartPose>("/target_positions", rclcpp::SensorDataQoS(), std::bind(&TransformationNode::subscribe_targets, this, std::placeholders::_1));
    }

    private:
    void subscribe_targets(const mage_msgs::msg::PartPose::SharedPtr trgts_msg_);
    rclcpp::Subscription<mage_msgs::msg::PartPose>::SharedPtr camera_sub_;

};// 