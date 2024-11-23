#include "bot_sequence.hpp"

BotSequence::BotSequence() : Node("bot_sequence"), action_flag_(MOVE_FORWARD),
    start_x_(0.0), start_y_(0.0), current_x_(0.0), current_y_(0.0),
    start_yaw_(0.0), current_yaw_(0.0),
    target_distance_(0.0), target_angle_(0.0),
    linear_velocity_(0.2), angular_velocity_(0.5),
    odom_initialized_(false), current_step_(1) {

    cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odom", 10, std::bind(&BotSequence::odometryCallback, this, std::placeholders::_1));
    timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&BotSequence::timerCallback, this));
}

void BotSequence::odometryCallback(const nav_msgs::msg::Odometry::SharedPtr msg) {
    current_x_ = msg->pose.pose.position.x;
    current_y_ = msg->pose.pose.position.y;

    // Extract yaw from quaternion
    auto orientation = msg->pose.pose.orientation;
    double siny_cosp = 2.0 * (orientation.w * orientation.z + orientation.x * orientation.y);
    double cosy_cosp = 1.0 - 2.0 * (orientation.y * orientation.y + orientation.z * orientation.z);
    current_yaw_ = std::atan2(siny_cosp, cosy_cosp); // Yaw in radians

    if (!odom_initialized_) {
        start_x_ = current_x_;
        start_y_ = current_y_;
        start_yaw_ = current_yaw_;
        odom_initialized_ = true;
    }
}

double BotSequence::calculateDistance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

double BotSequence::calculateAngle(double initial_yaw, double current_yaw) {
    double delta_angle = current_yaw - initial_yaw;

    // Normalize the angle to the range [-180, 180] degrees
    if (delta_angle > M_PI) delta_angle -= 2 * M_PI;
    if (delta_angle < -M_PI) delta_angle += 2 * M_PI;

    return delta_angle * (180.0 / M_PI); // Convert radians to degrees
}

void BotSequence::moveForward(double distance) {
    target_distance_ = distance;
    double traveled_distance = calculateDistance(start_x_, start_y_, current_x_, current_y_);
    RCLCPP_INFO(this->get_logger(), "Distance traveled: %.2f m", traveled_distance);

    if (traveled_distance >= target_distance_) {
        action_flag_ = STOP;
        odom_initialized_ = false;
    } else {
        auto msg = geometry_msgs::msg::Twist();
        msg.linear.x = linear_velocity_;
        cmd_vel_pub_->publish(msg);
    }
}

void BotSequence::rotate(double angle) {
    target_angle_ = angle;
    double rotated_angle = calculateAngle(start_yaw_, current_yaw_);
    RCLCPP_INFO(this->get_logger(), "Angle rotated: %.2f degrees", rotated_angle);

    if (std::abs(rotated_angle) >= std::abs(target_angle_)) {
        action_flag_ = STOP;
        odom_initialized_ = false;
    } else {
        auto msg = geometry_msgs::msg::Twist();
        msg.angular.z = angular_velocity_;
        cmd_vel_pub_->publish(msg);
    }
}

void BotSequence::stopRobot() {
    auto msg = geometry_msgs::msg::Twist();
    cmd_vel_pub_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Robot stopped.");
    if (current_step_ > 5) {
        RCLCPP_INFO(this->get_logger(), "All steps completed. Shutting down...");
        rclcpp::shutdown();
    } else {
        current_step_++;
        action_flag_ = (current_step_ % 2 == 1) ? MOVE_FORWARD : ROTATE;
    }
}

void BotSequence::timerCallback() {
    switch (action_flag_) {
        case MOVE_FORWARD:
            if (target_distance_ == 0.0) {
                target_distance_ = (current_step_ == 1 || current_step_ == 5) ? 10.0 : 5.0;
            }
            moveForward(target_distance_);
            break;

        case ROTATE:
            if (target_angle_ == 0.0) {
                target_angle_ = (current_step_ == 2) ? -90.0 : -45.0;
            }
            rotate(target_angle_);
            break;

        case STOP:
            stopRobot();
            break;
    }
}
