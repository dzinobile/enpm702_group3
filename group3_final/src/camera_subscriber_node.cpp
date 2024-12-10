#include "camera_subscriber_node.hpp"
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

void CameraSubscriberNode::subscribe_parts(const mage_msgs::msg::Parts::SharedPtr parts_msg_) {
    for (const auto &part : parts_msg_->parts) {
        RCLCPP_INFO_STREAM(this->get_logger(),
                           "Part received: Color " << static_cast<int>(part.color)
                           << ", Type " << static_cast<int>(part.type));
    }
}

void CameraSubscriberNode::camera_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg, int camera_id) {
    if (camera_message_processed_) {
        RCLCPP_INFO(this->get_logger(), "Camera data ignored for ID %d", camera_id);
        return;
    }

    for (const auto &part_pose : msg->part_poses) {
        RCLCPP_INFO(this->get_logger(),
                    "Detected part: Color %d, Type %d at (%.2f, %.2f, %.2f)",
                    static_cast<int>(part_pose.part.color), static_cast<int>(part_pose.part.type),
                    part_pose.pose.position.x, part_pose.pose.position.y, part_pose.pose.position.z);

        target_publisher_->publish(part_pose);
    }

    RCLCPP_INFO(this->get_logger(), "Camera %d processed", camera_id);
    camera_message_processed_ = true;
}
