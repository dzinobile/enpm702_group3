#include "bot_sequence.hpp"
#include <rclcpp/rclcpp.hpp>

void BotSequence::print_message_cb(){
    RCLCPP_INFO_STREAM(this->get_logger(),"Hello world" << counter_);
    counter_++;
}
