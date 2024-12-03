// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from bot_waypoint_msgs:msg/BotWaypoint.idl
// generated code does not contain a copyright notice

#ifndef BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__BUILDER_HPP_
#define BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "bot_waypoint_msgs/msg/detail/bot_waypoint__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace bot_waypoint_msgs
{

namespace msg
{

namespace builder
{

class Init_BotWaypoint_waypoint
{
public:
  explicit Init_BotWaypoint_waypoint(::bot_waypoint_msgs::msg::BotWaypoint & msg)
  : msg_(msg)
  {}
  ::bot_waypoint_msgs::msg::BotWaypoint waypoint(::bot_waypoint_msgs::msg::BotWaypoint::_waypoint_type arg)
  {
    msg_.waypoint = std::move(arg);
    return std::move(msg_);
  }

private:
  ::bot_waypoint_msgs::msg::BotWaypoint msg_;
};

class Init_BotWaypoint_tolerance
{
public:
  Init_BotWaypoint_tolerance()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BotWaypoint_waypoint tolerance(::bot_waypoint_msgs::msg::BotWaypoint::_tolerance_type arg)
  {
    msg_.tolerance = std::move(arg);
    return Init_BotWaypoint_waypoint(msg_);
  }

private:
  ::bot_waypoint_msgs::msg::BotWaypoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::bot_waypoint_msgs::msg::BotWaypoint>()
{
  return bot_waypoint_msgs::msg::builder::Init_BotWaypoint_tolerance();
}

}  // namespace bot_waypoint_msgs

#endif  // BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__BUILDER_HPP_
