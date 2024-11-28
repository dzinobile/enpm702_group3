#include <rclcpp/rclcpp.hpp>
#include <bot_waypoint_msgs/msg/bot_waypoint.hpp>
#include "waypoint_publisher.hpp"
#include  "waypoint_reacher.hpp"

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node1 = std::make_shared<WaypointPublisher>("node1");
    auto node2 = std::make_shared<WaypointReacher>("node2");

    rclcpp::executors::MultiThreadedExecutor executor;

    executor.add_node(node1);
    executor.add_node(node2);

    executor.spin();

}