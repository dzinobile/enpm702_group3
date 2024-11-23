#include "bot_sequence.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <rclcpp/rclcpp.hpp>    
int main(int arg, char **argv){
    rclcpp::init(arg, argv);
    auto node = std::make_shared<BotSequence>("bot_sequence");
    rclcpp::spin(node);
    rclcpp::shutdown();
}