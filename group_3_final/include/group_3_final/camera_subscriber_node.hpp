#pragma once
#include <rclcpp/rclcpp.hpp>
#include <memory>
#include  <array>
#include <mage_msgs/msg/advanced_logical_camera_image.hpp>
#include <rclcpp/rclcpp.hpp>
#include <mage_msgs/msg/advanced_logical_camera_image.hpp>
#include <unordered_map>

class CameraSubscriberNode : public rclcpp::Node
{
public:
    CameraSubscriberNode(std::string node_name) 
        : rclcpp::Node(node_name)
    {
        for (int i = 1; i <= 8; ++i)
        {
            std::string topic_name = "/mage/camera" + std::to_string(i) + "/image";
            auto callback = [this, i](const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
                this->camera_callback(i, msg);
            };

            auto subscription = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>(
                topic_name, 
                rclcpp::SensorDataQoS(), 
                callback
            );

            camera_subscriptions_[i] = subscription;
        }
    }

private:
    void camera_callback(int camera_id, const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);
    bool first_message_processed_;
    std::unordered_map<int, rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr> camera_subscriptions_;
};


