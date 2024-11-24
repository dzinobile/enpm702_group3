/// ENPM702 Assignment - 4
/// Authors: Pritom Gomes, Daniel Zinobile and Khuzema Habib

// #include "bot_sequence.hpp"

// BotSequence::BotSequence() : Node("bot_sequence"), 
//     start_x_(0.0), start_y_(0.0), current_x_(0.0), current_y_(0.0),
//     start_yaw_(0.0), current_yaw_(0.0),
//     target_distance_(0.0), target_angle_(0.0),
//     linear_velocity_(1.0), angular_velocity_(0.3),
//     odom_initialized_(false), current_step_(1) {

//     cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
//     odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
//         "/odom", 10, std::bind(&BotSequence::odometryCallback, this, std::placeholders::_1));
//     timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&BotSequence::timerCallback, this));
// }

// void BotSequence::odometryCallback(const nav_msgs::msg::Odometry::SharedPtr msg) {
//     current_x_ = msg->pose.pose.position.x;
//     current_y_ = msg->pose.pose.position.y;

//     // Extract yaw from quaternion
//     auto orientation = msg->pose.pose.orientation;
//     double siny_cosp = 2.0 * (orientation.w * orientation.z + orientation.x * orientation.y);
//     double cosy_cosp = 1.0 - 2.0 * (orientation.y * orientation.y + orientation.z * orientation.z);
//     current_yaw_ = std::atan2(siny_cosp, cosy_cosp); // Yaw in radians

//     if (!odom_initialized_) {
//         start_x_ = current_x_;
//         start_y_ = current_y_;
//         start_yaw_ = current_yaw_;
//         odom_initialized_ = true;
//     }
// }

// double BotSequence::calculateDistance(double x1, double y1, double x2, double y2) {
//     return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
// }

// double BotSequence::calculateAngle(double initial_yaw, double current_yaw) {
//     double delta_angle = current_yaw - initial_yaw;

//     // Normalize the angle to the range [-180, 180] degrees
//     if (delta_angle > M_PI) delta_angle -= 2 * M_PI;
//     if (delta_angle < -M_PI) delta_angle += 2 * M_PI;

//     return delta_angle * (180.0 / M_PI); // Convert radians to degrees
// }

// void BotSequence::handleMoveForward(double distance) {
//     if (target_distance_ == 0.0) {
//         target_distance_ = distance; // Set the target distance for this step
//     }

//     double traveled_distance = calculateDistance(start_x_, start_y_, current_x_, current_y_);
//     RCLCPP_INFO(this->get_logger(), "Step %d: Distance traveled: %.2f m", current_step_, traveled_distance);

//     if (traveled_distance >= target_distance_) {
//         RCLCPP_INFO(this->get_logger(), "Step %d: Reached target distance of %.2f m.", current_step_, target_distance_);
//         target_distance_ = 0.0; // Reset target distance
//         odom_initialized_ = false;
//         current_step_++; // Move to the next step
//     } else {
//         auto msg = geometry_msgs::msg::Twist();
//         msg.linear.x = linear_velocity_;
//         cmd_vel_pub_->publish(msg);
//     }
// }

// void BotSequence::handleRotate(double angle) {
//     if (target_angle_ == 0.0) {
//         target_angle_ = angle; // Set the target angle for this step
//     }

//     double rotated_angle = calculateAngle(start_yaw_, current_yaw_);
//     RCLCPP_INFO(this->get_logger(), "Step %d: Angle rotated: %.2f degrees", current_step_, rotated_angle);

//     if (std::abs(rotated_angle) >= std::abs(target_angle_)) {
//         RCLCPP_INFO(this->get_logger(), "Step %d: Reached target angle of %.2f degrees.", current_step_, target_angle_);
//         target_angle_ = 0.0; // Reset target angle
//         odom_initialized_ = false;
//         current_step_++; // Move to the next step
//     } else {
//         auto msg = geometry_msgs::msg::Twist();
//         msg.angular.z = (angle < 0) ? -angular_velocity_ : angular_velocity_; // Clockwise if angle < 0
//         cmd_vel_pub_->publish(msg);
//     }
// }

// void BotSequence::handleStop() {
//     auto msg = geometry_msgs::msg::Twist();
//     cmd_vel_pub_->publish(msg);
//     RCLCPP_INFO(this->get_logger(), "Step %d: Robot stopped. All steps completed.", current_step_);
//     rclcpp::shutdown();
// }

// void BotSequence::timerCallback() {
//     switch (current_step_) {
//         case 1:
//             handleMoveForward(10.0); // Step 1: Move forward 10 meters
//             break;

//         case 2:
//             handleRotate(-90.0); // Step 2: Rotate 90 degrees clockwise
//             break;

//         case 3:
//             handleMoveForward(5.0); // Step 3: Move forward 5 meters
//             break;

//         case 4:
//             handleRotate(-45.0); // Step 4: Rotate 45 degrees clockwise
//             break;

//         case 5:
//             handleMoveForward(10.0); // Step 5: Move forward 10 meters
//             break;

//         case 6:
//             handleStop(); // Step 6: Stop and shut down the node
//             break;

//         default:
//             RCLCPP_ERROR(this->get_logger(), "Invalid step encountered!");
//             rclcpp::shutdown();
//             break;
//     }
// }


// #include "bot_sequence.hpp"

// BotSequence::BotSequence() : Node("bot_sequence"),
//     start_x_(0.0), start_y_(0.0), current_x_(0.0), current_y_(0.0),
//     start_yaw_(0.0), current_yaw_(0.0),
//     target_distance_(0.0), target_angle_(0.0),
//     odom_initialized_(false), current_step_(1) {

//     cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
//     odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
//         "/odom", 10, std::bind(&BotSequence::odometryCallback, this, std::placeholders::_1));
//     timer_ = this->create_wall_timer(std::chrono::milliseconds(100), std::bind(&BotSequence::timerCallback, this));
// }

// void BotSequence::odometryCallback(const nav_msgs::msg::Odometry::SharedPtr msg) {
//     current_x_ = msg->pose.pose.position.x;
//     current_y_ = msg->pose.pose.position.y;

//     auto orientation = msg->pose.pose.orientation;
//     double siny_cosp = 2.0 * (orientation.w * orientation.z + orientation.x * orientation.y);
//     double cosy_cosp = 1.0 - 2.0 * (orientation.y * orientation.y + orientation.z * orientation.z);
//     current_yaw_ = std::atan2(siny_cosp, cosy_cosp);

//     if (!odom_initialized_) {
//         start_x_ = current_x_;
//         start_y_ = current_y_;
//         start_yaw_ = current_yaw_;
//         odom_initialized_ = true;
//     }
// }

// void BotSequence::handleMoveForward(double distance) {
//     if (target_distance_ == 0.0) {
//         target_distance_ = distance;
//     }

//     double traveled_distance = calculateDistance(start_x_, start_y_, current_x_, current_y_);
//     RCLCPP_INFO(this->get_logger(), "Step %d: Distance traveled: %.2f m", current_step_, traveled_distance);

//     if (traveled_distance >= target_distance_) {
//         RCLCPP_INFO(this->get_logger(), "Step %d: Reached target distance of %.2f m.", current_step_, target_distance_);
//         target_distance_ = 0.0;
//         odom_initialized_ = false;
//         current_step_++;
//     } else {
//         auto msg = geometry_msgs::msg::Twist();
//         msg.linear.x = LINEAR_VELOCITY;
//         cmd_vel_pub_->publish(msg);
//     }
// }

// void BotSequence::handleRotate(double angle) {
//     if (target_angle_ == 0.0) {
//         target_angle_ = angle;
//     }

//     double rotated_angle = calculateAngle(start_yaw_, current_yaw_);
//     RCLCPP_INFO(this->get_logger(), "Step %d: Angle rotated: %.2f degrees", current_step_, rotated_angle);

//     if (std::abs(rotated_angle) >= std::abs(target_angle_)) {
//         RCLCPP_INFO(this->get_logger(), "Step %d: Reached target angle of %.2f degrees.", current_step_, target_angle_);
//         target_angle_ = 0.0;
//         odom_initialized_ = false;
//         current_step_++;
//     } else {
//         auto msg = geometry_msgs::msg::Twist();
//         msg.angular.z = (angle < 0) ? -ANGULAR_VELOCITY : ANGULAR_VELOCITY;
//         cmd_vel_pub_->publish(msg);
//     }
// }

// void BotSequence::handleStop() {
//     auto msg = geometry_msgs::msg::Twist();
//     cmd_vel_pub_->publish(msg);
//     RCLCPP_INFO(this->get_logger(), "Step %d: Robot stopped. All steps completed.", current_step_);
//     rclcpp::shutdown();
// }

// void BotSequence::timerCallback() {
//     switch (current_step_) {
//         case 1:
//             handleMoveForward(10.0);
//             break;
//         case 2:
//             handleRotate(-90.0);
//             break;
//         case 3:
//             handleMoveForward(5.0);
//             break;
//         case 4:
//             handleRotate(-45.0);
//             break;
//         case 5:
//             handleMoveForward(10.0);
//             break;
//         case 6:
//             handleStop();
//             break;
//         default:
//             RCLCPP_ERROR(this->get_logger(), "Invalid step encountered!");
//             rclcpp::shutdown();
//             break;
//     }
// }


#include "bot_sequence.hpp"

BotSequence::BotSequence() : Node("bot_sequence"),
    start_x_(0.0), start_y_(0.0), current_x_(0.0), current_y_(0.0),
    start_yaw_(0.0), current_yaw_(0.0),
    target_distance_(0.0), target_angle_(0.0),
    odom_initialized_(false), current_step_(1) {

    cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
        "/odom", 10, std::bind(&BotSequence::odometryCallback, this, std::placeholders::_1));
    timer_ = this->create_wall_timer(std::chrono::milliseconds(50), std::bind(&BotSequence::timerCallback, this)); // Faster timer for better control
}

void BotSequence::odometryCallback(const nav_msgs::msg::Odometry::SharedPtr msg) {
    current_x_ = msg->pose.pose.position.x;
    current_y_ = msg->pose.pose.position.y;

    auto orientation = msg->pose.pose.orientation;
    double siny_cosp = 2.0 * (orientation.w * orientation.z + orientation.x * orientation.y);
    double cosy_cosp = 1.0 - 2.0 * (orientation.y * orientation.y + orientation.z * orientation.z);
    current_yaw_ = std::atan2(siny_cosp, cosy_cosp);

    if (!odom_initialized_) {
        start_x_ = current_x_;
        start_y_ = current_y_;
        start_yaw_ = current_yaw_;
        odom_initialized_ = true;
    }
}

void BotSequence::handleMoveForward(double distance) {
    if (target_distance_ == 0.0) {
        target_distance_ = distance;
    }

    double traveled_distance = calculateDistance(start_x_, start_y_, current_x_, current_y_);
    RCLCPP_INFO(this->get_logger(), "Step %d: Distance traveled: %.2f m", current_step_, traveled_distance);

    if (traveled_distance >= target_distance_) {
        RCLCPP_INFO(this->get_logger(), "Step %d: Reached target distance of %.2f m.", current_step_, target_distance_);
        target_distance_ = 0.0;
        odom_initialized_ = false;
        current_step_++;
    } else {
        auto msg = geometry_msgs::msg::Twist();
        msg.linear.x = LINEAR_VELOCITY;
        cmd_vel_pub_->publish(msg);
    }
}

void BotSequence::handleRotate(double angle) {
    if (target_angle_ == 0.0) {
        target_angle_ = angle;
    }

    double rotated_angle = calculateAngle(start_yaw_, current_yaw_);
    RCLCPP_INFO(this->get_logger(), "Step %d: Angle rotated: %.2f degrees", current_step_, rotated_angle);

    if (std::abs(rotated_angle - target_angle_) <= TOLERANCE) {
        RCLCPP_INFO(this->get_logger(), "Step %d: Reached target angle of %.2f degrees.", current_step_, target_angle_);
        target_angle_ = 0.0;
        odom_initialized_ = false;
        current_step_++;
    } else {
        auto msg = geometry_msgs::msg::Twist();
        msg.angular.z = (angle < 0) ? -ANGULAR_VELOCITY : ANGULAR_VELOCITY;
        cmd_vel_pub_->publish(msg);
    }
}

void BotSequence::handleStop() {
    auto msg = geometry_msgs::msg::Twist();
    cmd_vel_pub_->publish(msg);
    RCLCPP_INFO(this->get_logger(), "Step %d: Robot stopped. All steps completed.", current_step_);
    rclcpp::shutdown();
}

void BotSequence::timerCallback() {
    switch (current_step_) {
        case 1:
            handleMoveForward(10.0);
            break;
        case 2:
            handleRotate(-90.0);
            break;
        case 3:
            handleMoveForward(5.0);
            break;
        case 4:
            handleRotate(-45.0);
            break;
        case 5:
            handleMoveForward(10.0);
            break;
        case 6:
            handleStop();
            break;
        default:
            RCLCPP_ERROR(this->get_logger(), "Invalid step encountered!");
            rclcpp::shutdown();
            break;
    }
}
