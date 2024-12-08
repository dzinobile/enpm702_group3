#include <rclcpp/rclcpp.hpp>
#include <memory>
#include  <array>
#include <mage_msgs/msg/advanced_logical_camera_image.hpp>
#include <rclcpp/rclcpp.hpp>
#include <mage_msgs/msg/advanced_logical_camera_image.hpp>
#include <unordered_map>
#include "transformation_node.hpp"

void TransformationNode::subscribe_targets(const mage_msgs::msg::PartPose::SharedPtr trgts_msg_)
{
     std::ostringstream oss;
     oss << "-------------------------------------------------------\n"
     << "x: " <<static_cast<double>(trgts_msg_->pose.position.x) << '\n'
     << "y: " <<static_cast<double>(trgts_msg_->pose.position.y) << '\n'
     << "z: " <<static_cast<double>(trgts_msg_->pose.position.z) <<'\n';
     RCLCPP_INFO_STREAM(this->get_logger(), oss.str());

}