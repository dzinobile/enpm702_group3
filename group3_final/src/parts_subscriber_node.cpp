#include "parts_subscriber_node.hpp"

PartSubscriber::PartSubscriber(const std::string &node_name)
    : rclcpp::Node(node_name), first_message_processed_(false) {
    part_subscriber_ = this->create_subscription<mage_msgs::msg::Parts>(
        "parts", 10, std::bind(&PartSubscriber::subscribe_parts, this, std::placeholders::_1));
}

void PartSubscriber::subscribe_parts(const mage_msgs::msg::Parts::SharedPtr parts_msg_) {
    if (first_message_processed_) {
        RCLCPP_INFO(this->get_logger(), "Message ignored: already processed the first message.");
        return;
    }

    for (const auto &part : parts_msg_->parts) {
        RCLCPP_INFO(this->get_logger(),
                    "Received Part: Color %d, Type %d",
                    static_cast<int>(part.color), static_cast<int>(part.type));
    }

    first_message_processed_ = true;
}
