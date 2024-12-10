#pragma once
#include <rclcpp/rclcpp.hpp>
#include <unordered_map>
#include <mage_msgs/msg/parts.hpp>
#include <mage_msgs/msg/part_pose.hpp>
#include <mage_msgs/msg/advanced_logical_camera_image.hpp>

class CameraSubscriberNode : public rclcpp::Node {
public:
    CameraSubscriberNode(const std::string &node_name)
        : rclcpp::Node(node_name), camera_message_processed_(false) {
        target_publisher_ = this->create_publisher<mage_msgs::msg::PartPose>("/target_positions", 10);
        part_subscriber_ = this->create_subscription<mage_msgs::msg::Parts>(
            "parts", 10, std::bind(&CameraSubscriberNode::subscribe_parts, this, std::placeholders::_1));

        for (int i = 1; i <= 8; ++i) {
            std::string topic_name = "/mage/camera" + std::to_string(i) + "/image";
            auto subscription = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>(
                topic_name, rclcpp::SensorDataQoS(),
                std::bind(&CameraSubscriberNode::camera_callback, this, std::placeholders::_1, i));
            camera_subscriptions_[i] = subscription;
        }
    }

private:
    void subscribe_parts(const mage_msgs::msg::Parts::SharedPtr parts_msg_);
    void camera_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg, int camera_id);

    std::unordered_map<int, rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr> camera_subscriptions_;
    rclcpp::Subscription<mage_msgs::msg::Parts>::SharedPtr part_subscriber_;
    rclcpp::Publisher<mage_msgs::msg::PartPose>::SharedPtr target_publisher_;
    bool camera_message_processed_;
};
