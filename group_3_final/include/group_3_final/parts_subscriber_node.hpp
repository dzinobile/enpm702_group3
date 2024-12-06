#include <rclcpp/rclcpp.hpp>
#include <mage_msgs/msg/parts.hpp>
#include <mage_msgs/msg/part.hpp>
#include <chrono>
using namespace std::chrono_literals; // Enables direct use of literals

class PartSubscriber : public rclcpp::Node
{
public:
    PartSubscriber(std::string node_name) : rclcpp::Node(node_name), first_message_processed_(false)
    {
        // initialize parts subscriber
        part_subscriber_ = this->create_subscription<mage_msgs::msg::Parts>("parts", 10, std::bind(&PartSubscriber::subscribe_parts, this, std::placeholders::_1));
        }

private:
    rclcpp::Subscription<mage_msgs::msg::Parts>::SharedPtr part_subscriber_;
    bool first_message_processed_;
    void subscribe_parts(const mage_msgs::msg::Parts::SharedPtr parts_msg_);
};