#include "transformation_node.hpp"
#include <sstream>

TransformationNode::TransformationNode(const std::string &node_name)
    : rclcpp::Node(node_name) {
    camera_sub_ = this->create_subscription<mage_msgs::msg::PartPose>(
        "/target_positions", rclcpp::SensorDataQoS(),
        std::bind(&TransformationNode::subscribe_targets, this, std::placeholders::_1));
}

void TransformationNode::subscribe_targets(const mage_msgs::msg::PartPose::SharedPtr trgts_msg_) {
    std::ostringstream oss;
    oss << "-------------------------------------------------------\n"
        << "Target Position (x): " << trgts_msg_->pose.position.x << '\n'
        << "Target Position (y): " << trgts_msg_->pose.position.y << '\n'
        << "Target Position (z): " << trgts_msg_->pose.position.z << '\n';
    RCLCPP_INFO_STREAM(this->get_logger(), oss.str());
}
