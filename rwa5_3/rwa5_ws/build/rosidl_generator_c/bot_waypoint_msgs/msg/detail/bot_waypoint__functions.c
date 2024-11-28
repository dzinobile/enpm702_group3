// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from bot_waypoint_msgs:msg/BotWaypoint.idl
// generated code does not contain a copyright notice
#include "bot_waypoint_msgs/msg/detail/bot_waypoint__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `waypoint`
#include "geometry_msgs/msg/detail/pose2_d__functions.h"

bool
bot_waypoint_msgs__msg__BotWaypoint__init(bot_waypoint_msgs__msg__BotWaypoint * msg)
{
  if (!msg) {
    return false;
  }
  // tolerance
  // waypoint
  if (!geometry_msgs__msg__Pose2D__init(&msg->waypoint)) {
    bot_waypoint_msgs__msg__BotWaypoint__fini(msg);
    return false;
  }
  return true;
}

void
bot_waypoint_msgs__msg__BotWaypoint__fini(bot_waypoint_msgs__msg__BotWaypoint * msg)
{
  if (!msg) {
    return;
  }
  // tolerance
  // waypoint
  geometry_msgs__msg__Pose2D__fini(&msg->waypoint);
}

bool
bot_waypoint_msgs__msg__BotWaypoint__are_equal(const bot_waypoint_msgs__msg__BotWaypoint * lhs, const bot_waypoint_msgs__msg__BotWaypoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // tolerance
  if (lhs->tolerance != rhs->tolerance) {
    return false;
  }
  // waypoint
  if (!geometry_msgs__msg__Pose2D__are_equal(
      &(lhs->waypoint), &(rhs->waypoint)))
  {
    return false;
  }
  return true;
}

bool
bot_waypoint_msgs__msg__BotWaypoint__copy(
  const bot_waypoint_msgs__msg__BotWaypoint * input,
  bot_waypoint_msgs__msg__BotWaypoint * output)
{
  if (!input || !output) {
    return false;
  }
  // tolerance
  output->tolerance = input->tolerance;
  // waypoint
  if (!geometry_msgs__msg__Pose2D__copy(
      &(input->waypoint), &(output->waypoint)))
  {
    return false;
  }
  return true;
}

bot_waypoint_msgs__msg__BotWaypoint *
bot_waypoint_msgs__msg__BotWaypoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bot_waypoint_msgs__msg__BotWaypoint * msg = (bot_waypoint_msgs__msg__BotWaypoint *)allocator.allocate(sizeof(bot_waypoint_msgs__msg__BotWaypoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(bot_waypoint_msgs__msg__BotWaypoint));
  bool success = bot_waypoint_msgs__msg__BotWaypoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
bot_waypoint_msgs__msg__BotWaypoint__destroy(bot_waypoint_msgs__msg__BotWaypoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    bot_waypoint_msgs__msg__BotWaypoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
bot_waypoint_msgs__msg__BotWaypoint__Sequence__init(bot_waypoint_msgs__msg__BotWaypoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bot_waypoint_msgs__msg__BotWaypoint * data = NULL;

  if (size) {
    data = (bot_waypoint_msgs__msg__BotWaypoint *)allocator.zero_allocate(size, sizeof(bot_waypoint_msgs__msg__BotWaypoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = bot_waypoint_msgs__msg__BotWaypoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        bot_waypoint_msgs__msg__BotWaypoint__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
bot_waypoint_msgs__msg__BotWaypoint__Sequence__fini(bot_waypoint_msgs__msg__BotWaypoint__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      bot_waypoint_msgs__msg__BotWaypoint__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

bot_waypoint_msgs__msg__BotWaypoint__Sequence *
bot_waypoint_msgs__msg__BotWaypoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  bot_waypoint_msgs__msg__BotWaypoint__Sequence * array = (bot_waypoint_msgs__msg__BotWaypoint__Sequence *)allocator.allocate(sizeof(bot_waypoint_msgs__msg__BotWaypoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = bot_waypoint_msgs__msg__BotWaypoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
bot_waypoint_msgs__msg__BotWaypoint__Sequence__destroy(bot_waypoint_msgs__msg__BotWaypoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    bot_waypoint_msgs__msg__BotWaypoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
bot_waypoint_msgs__msg__BotWaypoint__Sequence__are_equal(const bot_waypoint_msgs__msg__BotWaypoint__Sequence * lhs, const bot_waypoint_msgs__msg__BotWaypoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!bot_waypoint_msgs__msg__BotWaypoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
bot_waypoint_msgs__msg__BotWaypoint__Sequence__copy(
  const bot_waypoint_msgs__msg__BotWaypoint__Sequence * input,
  bot_waypoint_msgs__msg__BotWaypoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(bot_waypoint_msgs__msg__BotWaypoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    bot_waypoint_msgs__msg__BotWaypoint * data =
      (bot_waypoint_msgs__msg__BotWaypoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!bot_waypoint_msgs__msg__BotWaypoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          bot_waypoint_msgs__msg__BotWaypoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!bot_waypoint_msgs__msg__BotWaypoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
