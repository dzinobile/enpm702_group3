/// ENPM702 Assignment - 3
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

#include "waypoint_reacher.hpp"

// Constructor for the WaypointReacher class
// Initializes the node, sets up subscribers and publishers, and logs the node's startup.
WaypointReacher::WaypointReacher()
    : Node("waypoint_reacher_node"), waypoint_reached_(false) {
    // Define QoS settings for reliable and transient local communication
    rclcpp::QoS sub_qos(10);
    sub_qos.reliable();
    sub_qos.transient_local();

    // Subscriber to the "bot_waypoint" topic to receive waypoint data
    subscriber_ = this->create_subscription<bot_waypoint_msgs::msg::BotWaypoint>(
        "bot_waypoint", sub_qos, std::bind(&WaypointReacher::receive_int, this, std::placeholders::_1));

    // Publisher for velocity commands to control the robot
    velocity_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);

    // Publisher for signaling readiness for the next waypoint
    next_waypoint_publisher_ = this->create_publisher<std_msgs::msg::Bool>("next_waypoint", 10);

    RCLCPP_INFO(this->get_logger(), "WaypointReacher node started.");
}

// Callback function triggered when a waypoint is received.
// Updates the current target waypoint and initiates movement toward it.
void WaypointReacher::receive_int(const bot_waypoint_msgs::msg::BotWaypoint::SharedPtr msg) {
    // Update the current waypoint with the received message
    current_waypoint_ = *msg;

    // Reset the waypoint reached flag
    waypoint_reached_ = false;

    // Log the details of the received waypoint
    RCLCPP_INFO_STREAM(this->get_logger(), "Received waypoint: [" 
        << current_waypoint_.waypoint.x << ", " << current_waypoint_.waypoint.y << ", " 
        << current_waypoint_.waypoint.theta << "] with tolerance " 
        << static_cast<int>(current_waypoint_.tolerance));

    // Start moving toward the received waypoint
    move_toward_waypoint();
}

// Moves the robot toward the current waypoint using proportional control.
// Calculates the linear and angular velocities required to guide the robot to the waypoint.
// Stops the robot and signals readiness for the next waypoint upon reaching the target.
void WaypointReacher::move_toward_waypoint() {
    // Calculate the difference between the robot's current position and the waypoint
    double dx = current_waypoint_.waypoint.x - 0.0; // Replace 0.0 with actual x position from odometry
    double dy = current_waypoint_.waypoint.y - 0.0; // Replace 0.0 with actual y position from odometry
    double distance = std::sqrt(dx * dx + dy * dy); // Euclidean distance to the waypoint

    // Check if the robot is within the tolerance distance of the waypoint
    if (distance <= current_waypoint_.tolerance / 10.0) {
        waypoint_reached_ = true;

        // Stop the robot by publishing zero velocities
        auto stop_msg = geometry_msgs::msg::Twist();
        velocity_publisher_->publish(stop_msg);

        // Log that the waypoint has been reached
        RCLCPP_INFO_STREAM(this->get_logger(), "Waypoint reached: [" 
            << current_waypoint_.waypoint.x << ", " << current_waypoint_.waypoint.y << ", " 
            << current_waypoint_.waypoint.theta << "]");

        // Publish a signal to indicate readiness for the next waypoint
        publish_next_waypoint_signal();
        return;
    }

    // Proportional control: calculate linear and angular velocities
    auto cmd_msg = geometry_msgs::msg::Twist();
    cmd_msg.linear.x = 0.2 * distance; // Adjust linear velocity based on distance
    cmd_msg.angular.z = 0.1 * (current_waypoint_.waypoint.theta - 0.0); // Adjust angular velocity based on orientation difference

    // Publish the velocity command to move the robot
    velocity_publisher_->publish(cmd_msg);

    // Log the velocity commands for debugging
    RCLCPP_INFO_STREAM(this->get_logger(), "Moving toward waypoint: linear.x=" 
        << cmd_msg.linear.x << ", angular.z=" << cmd_msg.angular.z);
}

// Publishes a signal indicating readiness for the next waypoint.
// Sends a Boolean message (`true`) to the "next_waypoint" topic to notify the WaypointPublisher
// that the robot is ready to receive the next waypoint.
void WaypointReacher::publish_next_waypoint_signal() {
    // Create a Bool message with data set to true
    auto signal_msg = std_msgs::msg::Bool();
    signal_msg.data = true;

    // Publish the readiness signal
    next_waypoint_publisher_->publish(signal_msg);

    // Log the signal publication
    RCLCPP_INFO(this->get_logger(), "Published signal to request the next waypoint.");
}