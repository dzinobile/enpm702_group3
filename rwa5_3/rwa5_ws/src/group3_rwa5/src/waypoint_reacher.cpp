#include "waypoint_reacher.hpp"

WaypointReacher::WaypointReacher()
    : Node("waypoint_reacher_node"), waypoint_reached_(false) {
    rclcpp::QoS sub_qos(10); //Quality of service declarations
    sub_qos.reliable();
    sub_qos.transient_local();

    //create subscriber to bot_waypoint topic
    subscriber_ = this->create_subscription<bot_waypoint_msgs::msg::BotWaypoint>(
        "bot_waypoint", sub_qos, std::bind(&WaypointReacher::receive_int, this, std::placeholders::_1));
    //create publisher to publish velocities to cmd_vel topic
    velocity_publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    //create publisher to next_waypoint topic
    next_waypoint_publisher_ = this->create_publisher<std_msgs::msg::Bool>("next_waypoint", 10);
    //create subscriber to /odom topic
    odom_subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odom", 10, std::bind(&WaypointReacher::odom_callback, this, std::placeholders::_1));

    //set gain values and epsilon values
    kp_distance_ = 0.08;
    kp_angle_ = 0.1;
    epsilon_ = 0.1;
    epsilon_theta_ = 0.05;

    RCLCPP_INFO(this->get_logger(), "WaypointReacher node started.");
}

//recieve current waypoint function
void WaypointReacher::receive_int(const bot_waypoint_msgs::msg::BotWaypoint::SharedPtr msg) {
    current_waypoint_ = *msg;
    waypoint_reached_ = false;
    RCLCPP_INFO_STREAM(this->get_logger(), "Received waypoint: [" << current_waypoint_.waypoint.x << ", " 
                       << current_waypoint_.waypoint.y << ", " << current_waypoint_.waypoint.theta 
                       << "] with tolerance " << static_cast<double>(current_waypoint_.tolerance));
}

//Function to read current position and pass to control loop
void WaypointReacher::odom_callback(const nav_msgs::msg::Odometry::SharedPtr msg) {
    current_x_ = msg->pose.pose.position.x;
    current_y_ = msg->pose.pose.position.y;

    tf2::Quaternion quaternion;
    tf2::fromMsg(msg->pose.pose.orientation, quaternion);
    tf2::Matrix3x3(quaternion).getRPY(roll_, pitch_, current_theta_);

    control_loop();
}

//Proportional control function
void WaypointReacher::control_loop() {
    if (!waypoint_reached_) {
        double distance_error = std::sqrt(std::pow(current_waypoint_.waypoint.x - current_x_, 2) +
                                          std::pow(current_waypoint_.waypoint.y - current_y_, 2));
        double desired_angle = std::atan2(current_waypoint_.waypoint.y - current_y_,
                                          current_waypoint_.waypoint.x - current_x_);
        double angle_error = normalize_angle(desired_angle - current_theta_);
        double final_orientation_error = normalize_angle(current_waypoint_.waypoint.theta - current_theta_);

        if (distance_error > epsilon_) {
            double linear_velocity = kp_distance_ * distance_error;
            double angular_velocity = kp_angle_ * angle_error;

            auto cmd_msg = geometry_msgs::msg::Twist();
            cmd_msg.linear.x = linear_velocity;
            cmd_msg.angular.z = angular_velocity;
            velocity_publisher_->publish(cmd_msg);

            RCLCPP_INFO(this->get_logger(), "Moving toward waypoint: linear.x=%.2f, angular.z=%.2f",
                        cmd_msg.linear.x, cmd_msg.angular.z);
        } else if (std::abs(final_orientation_error) > epsilon_theta_) {
            auto cmd_msg = geometry_msgs::msg::Twist();
            cmd_msg.angular.z = kp_angle_ * final_orientation_error;
            velocity_publisher_->publish(cmd_msg);

            RCLCPP_INFO(this->get_logger(), "Adjusting final orientation: angular.z=%.2f", cmd_msg.angular.z);
        } else {
            waypoint_reached_ = true;
            auto stop_msg = geometry_msgs::msg::Twist();
            velocity_publisher_->publish(stop_msg);

            RCLCPP_INFO(this->get_logger(), "Waypoint reached: [%.2f, %.2f, %.2f]",
                        current_waypoint_.waypoint.x, current_waypoint_.waypoint.y, current_waypoint_.waypoint.theta);
            publish_next_waypoint_signal(); //Once waypoint achieved command to achieve next waypoint signal
        }
    }
}

//Function to recieve next waypoint signal
void WaypointReacher::publish_next_waypoint_signal() {
    auto signal_msg = std_msgs::msg::Bool();
    signal_msg.data = true;
    next_waypoint_publisher_->publish(signal_msg);
    RCLCPP_INFO(this->get_logger(), "Published signal to request the next waypoint.");
}

//Function for normalizing angles between +/- 2pi 
double WaypointReacher::normalize_angle(double angle) {
    while (angle > M_PI)
        angle -= 2.0 * M_PI;
    while (angle < -M_PI)
        angle += 2.0 * M_PI;
    return angle;
}