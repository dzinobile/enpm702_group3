// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from bot_waypoint_msgs:msg/BotWaypoint.idl
// generated code does not contain a copyright notice

#ifndef BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__TRAITS_HPP_
#define BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "bot_waypoint_msgs/msg/detail/bot_waypoint__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'waypoint'
#include "geometry_msgs/msg/detail/pose2_d__traits.hpp"

namespace bot_waypoint_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const BotWaypoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: tolerance
  {
    out << "tolerance: ";
    rosidl_generator_traits::value_to_yaml(msg.tolerance, out);
    out << ", ";
  }

  // member: waypoint
  {
    out << "waypoint: ";
    to_flow_style_yaml(msg.waypoint, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BotWaypoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: tolerance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tolerance: ";
    rosidl_generator_traits::value_to_yaml(msg.tolerance, out);
    out << "\n";
  }

  // member: waypoint
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "waypoint:\n";
    to_block_style_yaml(msg.waypoint, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BotWaypoint & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace bot_waypoint_msgs

namespace rosidl_generator_traits
{

[[deprecated("use bot_waypoint_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const bot_waypoint_msgs::msg::BotWaypoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  bot_waypoint_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use bot_waypoint_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const bot_waypoint_msgs::msg::BotWaypoint & msg)
{
  return bot_waypoint_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<bot_waypoint_msgs::msg::BotWaypoint>()
{
  return "bot_waypoint_msgs::msg::BotWaypoint";
}

template<>
inline const char * name<bot_waypoint_msgs::msg::BotWaypoint>()
{
  return "bot_waypoint_msgs/msg/BotWaypoint";
}

template<>
struct has_fixed_size<bot_waypoint_msgs::msg::BotWaypoint>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Pose2D>::value> {};

template<>
struct has_bounded_size<bot_waypoint_msgs::msg::BotWaypoint>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Pose2D>::value> {};

template<>
struct is_message<bot_waypoint_msgs::msg::BotWaypoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__TRAITS_HPP_
