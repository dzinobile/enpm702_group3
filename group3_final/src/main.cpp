#include <rclcpp/rclcpp.hpp>
#include "parts_subscriber_node.hpp"
#include "camera_subscriber_node.hpp"
#include "transformation_node.hpp"
#include "p_navigation_node.hpp"

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    // Create nodes
    auto parts_subscriber_node = std::make_shared<PartSubscriber>("parts_subscriber_node");
    auto camera_subscriber_node = std::make_shared<CameraSubscriberNode>("camera_subscriber_node");
    auto transformation_node = std::make_shared<TransformationNode>("transformation_node");
    auto navigation_node = std::make_shared<NavigationNode>();

    // Create a multithreaded executor
    rclcpp::executors::MultiThreadedExecutor executor;

    // Add nodes to the executor
    executor.add_node(parts_subscriber_node);
    executor.add_node(camera_subscriber_node);
    executor.add_node(transformation_node);
    executor.add_node(navigation_node);

    // Spin the executor to process callbacks
    executor.spin();

    rclcpp::shutdown();
    return 0;
}
