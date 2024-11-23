#include <rclcpp/rclcpp.hpp>
#include "group3_rwa4/bot_sequence.hpp"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BotSequence>());
    rclcpp::shutdown();
}
