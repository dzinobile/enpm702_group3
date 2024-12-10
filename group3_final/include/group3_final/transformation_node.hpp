#pragma once
#include <rclcpp/rclcpp.hpp>
#include <mage_msgs/msg/part_pose.hpp>

class TransformationNode : public rclcpp::Node {
public:
    TransformationNode(const std::string &node_name);

private:
    void subscribe_targets(const mage_msgs::msg::PartPose::SharedPtr trgts_msg_);

    rclcpp::Subscription<mage_msgs::msg::PartPose>::SharedPtr camera_sub_;
};
