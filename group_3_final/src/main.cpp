/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib
#include <rclcpp/rclcpp.hpp>
#include "parts_subscriber_node.hpp"
#include "camera_subscriber_node.hpp"


int main(int argc, char **argv) {
    rclcpp::init(argc, argv);

    // Initialize both nodes
    auto parts_subscriber_node = std::make_shared<PartSubscriber>("parts_subscriber_node");
    auto camera_subscriber_node = std::make_shared<CameraSubscriberNode>("camera_subscriber_node");
   

    // Multi-threaded executor to manage callbacks from both nodes
    rclcpp::executors::MultiThreadedExecutor executor;

    // Add the nodes to the executor
    executor.add_node(parts_subscriber_node);
    executor.add_node(camera_subscriber_node);
    

    // Spin the executor to process callbacks
    executor.spin();

    rclcpp::shutdown();

    return 0;
}