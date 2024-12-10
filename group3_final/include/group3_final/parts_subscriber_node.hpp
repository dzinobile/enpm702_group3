#pragma once
#include <rclcpp/rclcpp.hpp>
#include <mage_msgs/msg/parts.hpp>

class PartSubscriber : public rclcpp::Node {
public:
    PartSubscriber(const std::string &node_name);

private:
    void subscribe_parts(const mage_msgs::msg::Parts::SharedPtr parts_msg_);

    rclcpp::Subscription<mage_msgs::msg::Parts>::SharedPtr part_subscriber_;
    bool first_message_processed_;
};
