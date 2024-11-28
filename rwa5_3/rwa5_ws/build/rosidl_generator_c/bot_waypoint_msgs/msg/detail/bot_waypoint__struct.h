// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from bot_waypoint_msgs:msg/BotWaypoint.idl
// generated code does not contain a copyright notice

#ifndef BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__STRUCT_H_
#define BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'SMALL'.
enum
{
  bot_waypoint_msgs__msg__BotWaypoint__SMALL = 1
};

/// Constant 'MEDIUM'.
enum
{
  bot_waypoint_msgs__msg__BotWaypoint__MEDIUM = 2
};

/// Constant 'LARGE'.
enum
{
  bot_waypoint_msgs__msg__BotWaypoint__LARGE = 3
};

// Include directives for member types
// Member 'waypoint'
#include "geometry_msgs/msg/detail/pose2_d__struct.h"

/// Struct defined in msg/BotWaypoint in the package bot_waypoint_msgs.
/**
  * the field tolerance will take only one of the three following values
 */
typedef struct bot_waypoint_msgs__msg__BotWaypoint
{
  uint8_t tolerance;
  /// x, y, theta
  geometry_msgs__msg__Pose2D waypoint;
} bot_waypoint_msgs__msg__BotWaypoint;

// Struct for a sequence of bot_waypoint_msgs__msg__BotWaypoint.
typedef struct bot_waypoint_msgs__msg__BotWaypoint__Sequence
{
  bot_waypoint_msgs__msg__BotWaypoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} bot_waypoint_msgs__msg__BotWaypoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__STRUCT_H_
