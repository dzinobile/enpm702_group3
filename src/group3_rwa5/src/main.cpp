/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include <rclcpp/rclcpp.hpp>
#include "waypoint_publisher.hpp"
#include "waypoint_reacher.hpp"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    // Initialize both nodes
    auto waypoint_publisher_node = std::make_shared<WaypointPublisher>();
    auto waypoint_reacher_node = std::make_shared<WaypointReacher>();

    // Multi-threaded executor to manage callbacks from both nodes
    rclcpp::executors::MultiThreadedExecutor executor;

    // Add the nodes to the executor
    executor.add_node(waypoint_publisher_node);
    executor.add_node(waypoint_reacher_node);

    // Spin the executor to process callbacks
    executor.spin();

    rclcpp::shutdown();

    return 0;
}
