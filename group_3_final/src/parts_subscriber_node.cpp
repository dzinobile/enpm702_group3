#include "parts_subscriber_node.hpp"
#include <mage_msgs/msg/part.hpp>
#include <mage_msgs/msg/parts.hpp>
#include <rclcpp/rclcpp.hpp>

void PartSubscriber::subscribe_parts(const mage_msgs::msg::Parts::SharedPtr parts_msg_)
{
    // Check if the first message has already been processed
        if (first_message_processed_) {
            RCLCPP_INFO(this->get_logger(), "Message ignored (already processed the first message).");
            return;
        }

    // Loop through all parts in the received message
    for (const auto &part : parts_msg_->parts)
    {
        auto part_color = static_cast<int>(part.color);
        auto part_type = static_cast<int>(part.type);

        RCLCPP_INFO_STREAM(this->get_logger(),
                           "Received Part:\n"
                               << "Part Color: " << part_color << '\n'
                               << "Part Type: " << part_type);
                            
    }
    // Set the flag to true after processing the first message
        first_message_processed_ = true;
}
