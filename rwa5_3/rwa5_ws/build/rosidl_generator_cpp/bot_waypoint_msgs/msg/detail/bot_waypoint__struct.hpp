// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from bot_waypoint_msgs:msg/BotWaypoint.idl
// generated code does not contain a copyright notice

#ifndef BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__STRUCT_HPP_
#define BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'waypoint'
#include "geometry_msgs/msg/detail/pose2_d__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__bot_waypoint_msgs__msg__BotWaypoint __attribute__((deprecated))
#else
# define DEPRECATED__bot_waypoint_msgs__msg__BotWaypoint __declspec(deprecated)
#endif

namespace bot_waypoint_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BotWaypoint_
{
  using Type = BotWaypoint_<ContainerAllocator>;

  explicit BotWaypoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : waypoint(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tolerance = 0;
    }
  }

  explicit BotWaypoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : waypoint(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->tolerance = 0;
    }
  }

  // field types and members
  using _tolerance_type =
    uint8_t;
  _tolerance_type tolerance;
  using _waypoint_type =
    geometry_msgs::msg::Pose2D_<ContainerAllocator>;
  _waypoint_type waypoint;

  // setters for named parameter idiom
  Type & set__tolerance(
    const uint8_t & _arg)
  {
    this->tolerance = _arg;
    return *this;
  }
  Type & set__waypoint(
    const geometry_msgs::msg::Pose2D_<ContainerAllocator> & _arg)
  {
    this->waypoint = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t SMALL =
    1u;
  static constexpr uint8_t MEDIUM =
    2u;
  static constexpr uint8_t LARGE =
    3u;

  // pointer types
  using RawPtr =
    bot_waypoint_msgs::msg::BotWaypoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const bot_waypoint_msgs::msg::BotWaypoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<bot_waypoint_msgs::msg::BotWaypoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<bot_waypoint_msgs::msg::BotWaypoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      bot_waypoint_msgs::msg::BotWaypoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<bot_waypoint_msgs::msg::BotWaypoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      bot_waypoint_msgs::msg::BotWaypoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<bot_waypoint_msgs::msg::BotWaypoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<bot_waypoint_msgs::msg::BotWaypoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<bot_waypoint_msgs::msg::BotWaypoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__bot_waypoint_msgs__msg__BotWaypoint
    std::shared_ptr<bot_waypoint_msgs::msg::BotWaypoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__bot_waypoint_msgs__msg__BotWaypoint
    std::shared_ptr<bot_waypoint_msgs::msg::BotWaypoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BotWaypoint_ & other) const
  {
    if (this->tolerance != other.tolerance) {
      return false;
    }
    if (this->waypoint != other.waypoint) {
      return false;
    }
    return true;
  }
  bool operator!=(const BotWaypoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BotWaypoint_

// alias to use template instance with default allocator
using BotWaypoint =
  bot_waypoint_msgs::msg::BotWaypoint_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BotWaypoint_<ContainerAllocator>::SMALL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BotWaypoint_<ContainerAllocator>::MEDIUM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t BotWaypoint_<ContainerAllocator>::LARGE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace bot_waypoint_msgs

#endif  // BOT_WAYPOINT_MSGS__MSG__DETAIL__BOT_WAYPOINT__STRUCT_HPP_
