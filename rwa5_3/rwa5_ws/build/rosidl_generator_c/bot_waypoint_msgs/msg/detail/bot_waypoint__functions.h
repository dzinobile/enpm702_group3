// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from bot_waypoint_msgs:msg/BotWaypoint.idl
// generated code does not contain a copyright notice

#ifndef BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__FUNCTIONS_H_
#define BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "bot_waypoint_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "bot_waypoint_msgs/msg/detail/bot_waypoint__struct.h"

/// Initialize msg/BotWaypoint message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * bot_waypoint_msgs__msg__BotWaypoint
 * )) before or use
 * bot_waypoint_msgs__msg__BotWaypoint__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_bot_waypoint_msgs
bool
bot_waypoint_msgs__msg__BotWaypoint__init(bot_waypoint_msgs__msg__BotWaypoint * msg);

/// Finalize msg/BotWaypoint message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bot_waypoint_msgs
void
bot_waypoint_msgs__msg__BotWaypoint__fini(bot_waypoint_msgs__msg__BotWaypoint * msg);

/// Create msg/BotWaypoint message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * bot_waypoint_msgs__msg__BotWaypoint__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bot_waypoint_msgs
bot_waypoint_msgs__msg__BotWaypoint *
bot_waypoint_msgs__msg__BotWaypoint__create();

/// Destroy msg/BotWaypoint message.
/**
 * It calls
 * bot_waypoint_msgs__msg__BotWaypoint__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bot_waypoint_msgs
void
bot_waypoint_msgs__msg__BotWaypoint__destroy(bot_waypoint_msgs__msg__BotWaypoint * msg);

/// Check for msg/BotWaypoint message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bot_waypoint_msgs
bool
bot_waypoint_msgs__msg__BotWaypoint__are_equal(const bot_waypoint_msgs__msg__BotWaypoint * lhs, const bot_waypoint_msgs__msg__BotWaypoint * rhs);

/// Copy a msg/BotWaypoint message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_bot_waypoint_msgs
bool
bot_waypoint_msgs__msg__BotWaypoint__copy(
  const bot_waypoint_msgs__msg__BotWaypoint * input,
  bot_waypoint_msgs__msg__BotWaypoint * output);

/// Initialize array of msg/BotWaypoint messages.
/**
 * It allocates the memory for the number of elements and calls
 * bot_waypoint_msgs__msg__BotWaypoint__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_bot_waypoint_msgs
bool
bot_waypoint_msgs__msg__BotWaypoint__Sequence__init(bot_waypoint_msgs__msg__BotWaypoint__Sequence * array, size_t size);

/// Finalize array of msg/BotWaypoint messages.
/**
 * It calls
 * bot_waypoint_msgs__msg__BotWaypoint__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bot_waypoint_msgs
void
bot_waypoint_msgs__msg__BotWaypoint__Sequence__fini(bot_waypoint_msgs__msg__BotWaypoint__Sequence * array);

/// Create array of msg/BotWaypoint messages.
/**
 * It allocates the memory for the array and calls
 * bot_waypoint_msgs__msg__BotWaypoint__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_bot_waypoint_msgs
bot_waypoint_msgs__msg__BotWaypoint__Sequence *
bot_waypoint_msgs__msg__BotWaypoint__Sequence__create(size_t size);

/// Destroy array of msg/BotWaypoint messages.
/**
 * It calls
 * bot_waypoint_msgs__msg__BotWaypoint__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_bot_waypoint_msgs
void
bot_waypoint_msgs__msg__BotWaypoint__Sequence__destroy(bot_waypoint_msgs__msg__BotWaypoint__Sequence * array);

/// Check for msg/BotWaypoint message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_bot_waypoint_msgs
bool
bot_waypoint_msgs__msg__BotWaypoint__Sequence__are_equal(const bot_waypoint_msgs__msg__BotWaypoint__Sequence * lhs, const bot_waypoint_msgs__msg__BotWaypoint__Sequence * rhs);

/// Copy an array of msg/BotWaypoint messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_bot_waypoint_msgs
bool
bot_waypoint_msgs__msg__BotWaypoint__Sequence__copy(
  const bot_waypoint_msgs__msg__BotWaypoint__Sequence * input,
  bot_waypoint_msgs__msg__BotWaypoint__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__FUNCTIONS_H_
