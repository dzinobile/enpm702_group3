#pragma once
#include <rclcpp/rclcpp.hpp>
#include <unordered_map>
#include <mage_msgs/msg/parts.hpp>
#include <mage_msgs/msg/part_pose.hpp>
#include <mage_msgs/msg/advanced_logical_camera_image.hpp>

class CameraSubscriberNode : public rclcpp::Node {
public:
    explicit CameraSubscriberNode(const std::string &node_name);

private:
    void subscribe_parts(const mage_msgs::msg::Parts::SharedPtr parts_msg_);
    void camera_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);

    std::unordered_map<std::string, rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr> camera_subscriptions_;
    rclcpp::Subscription<mage_msgs::msg::Parts>::SharedPtr part_subscriber_;
    rclcpp::Publisher<mage_msgs::msg::PartPose>::SharedPtr target_publisher_;
    bool camera_message_processed_;
};
