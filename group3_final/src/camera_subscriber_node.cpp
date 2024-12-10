#include "camera_subscriber_node.hpp"
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

CameraSubscriberNode::CameraSubscriberNode(const std::string &node_name)
    : rclcpp::Node(node_name), camera_message_processed_(false) {
    // Initialize publisher
    target_publisher_ = this->create_publisher<mage_msgs::msg::PartPose>("/target_positions", 10);

    // Initialize parts subscriber
    part_subscriber_ = this->create_subscription<mage_msgs::msg::Parts>(
        "parts", 10, std::bind(&CameraSubscriberNode::subscribe_parts, this, std::placeholders::_1));

    // Initialize camera subscriptions for 8 cameras
    for (int i = 1; i <= 8; ++i) {
        std::string topic_name = "/mage/camera" + std::to_string(i) + "/image";
        camera_subscriptions_[topic_name] = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>(
            topic_name, rclcpp::SensorDataQoS(),
            [this, topic_name](const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
                this->camera_callback(msg);
            });
    }
}

void CameraSubscriberNode::subscribe_parts(const mage_msgs::msg::Parts::SharedPtr parts_msg_) {
    for (const auto &part : parts_msg_->parts) {
        RCLCPP_INFO_STREAM(this->get_logger(),
                           "Part received: Color " << static_cast<int>(part.color)
                           << ", Type " << static_cast<int>(part.type));
    }
}

void CameraSubscriberNode::camera_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
    if (camera_message_processed_) {
        RCLCPP_INFO(this->get_logger(), "Camera data ignored");
        return;
    }

    for (const auto &part_pose : msg->part_poses) {
        RCLCPP_INFO(this->get_logger(),
                    "Detected part: Color %d, Type %d at (%.2f, %.2f, %.2f)",
                    static_cast<int>(part_pose.part.color), static_cast<int>(part_pose.part.type),
                    part_pose.pose.position.x, part_pose.pose.position.y, part_pose.pose.position.z);

        // Publish the detected part pose
        target_publisher_->publish(part_pose);
    }

    camera_message_processed_ = true;
}

