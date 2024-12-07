#include "camera_subscriber_node.hpp"
#include <string>

void CameraSubscriberNode::camera_callback(int camera_id, const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg){
    std::ostringstream oss; // String stream to build the log message
    oss << "\nCAMERA " << camera_id << "--------------------------------------\n"
     <<"camera position (x): " << static_cast<double>(msg->sensor_pose.position.x) << '\n'
    <<"camera posiiton (y): " << static_cast<double>(msg->sensor_pose.position.y) << '\n'
    <<"camera position (z): " << static_cast<double>(msg->sensor_pose.position.z) << '\n'
    <<"camera orientation (x): " << static_cast<double>(msg->sensor_pose.orientation.x) << '\n'
    <<"camera orientation (y): " << static_cast<double>(msg->sensor_pose.orientation.y) << '\n'
    <<"camera orientation (z): " << static_cast<double>(msg->sensor_pose.orientation.z) << '\n'
    <<"camera orientation (w): " << static_cast<double>(msg->sensor_pose.orientation.w) << '\n';
        int  i = 1;
    for (const auto& part_pose : msg->part_poses) {
        // Assuming part_pose has fields like 'name', 'position', and 'orientation'.
        oss << "Part " << i << ":\n"
        << "    Type: " << static_cast<int>(part_pose.part.type) << '\n' 
        << "    Color: " << static_cast<int>(part_pose.part.color) << '\n'
        << "    Position (x): " << static_cast<double>(part_pose.pose.position.x) << '\n'
        << "    Position (y): " <<static_cast<double>(part_pose.pose.position.y) <<  '\n'
        << "    Position (z): " <<static_cast<double>(part_pose.pose.position.z) << '\n'
        << "    Orientation (x): " <<static_cast<double>(part_pose.pose.orientation.x) << '\n'
        << "    Orientation (y): " <<static_cast<double>(part_pose.pose.orientation.y) << '\n'
        << "    Orientation (z): " << static_cast<double>(part_pose.pose.orientation.z) << '\n'
        << "    Orientation (w): " << static_cast<double>(part_pose.pose.orientation.w) << '\n';
        i++;
    }

    RCLCPP_INFO_STREAM(this->get_logger(), oss.str());
}


// void CameraSubscriberNode::camera1_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
//     std::ostringstream oss; // String stream to build the log message

//     oss << "\nCAMERA 1------------------------------------------------------------\n"
//     <<"camera position (x): " << static_cast<double>(msg->sensor_pose.position.x) << '\n'
//     <<"camera posiiton (y): " << static_cast<double>(msg->sensor_pose.position.y) << '\n'
//     <<"camera position (z): " << static_cast<double>(msg->sensor_pose.position.z) << '\n'
//     <<"camera orientation (x): " << static_cast<double>(msg->sensor_pose.orientation.x) << '\n'
//     <<"camera orientation (y): " << static_cast<double>(msg->sensor_pose.orientation.y) << '\n'
//     <<"camera orientation (z): " << static_cast<double>(msg->sensor_pose.orientation.z) << '\n'
//     <<"camera orientation (w): " << static_cast<double>(msg->sensor_pose.orientation.w) << '\n';
//     int  i = 1;
//     for (const auto& part_pose : msg->part_poses) {
//         // Assuming part_pose has fields like 'name', 'position', and 'orientation'.
//         oss << "Part " << i << ":\n"
//         << "    Type: " << static_cast<int>(part_pose.part.type) << '\n' 
//         << "    Color: " << static_cast<int>(part_pose.part.color) << '\n'
//         << "    Position (x): " << static_cast<double>(part_pose.pose.position.x) << '\n'
//         << "    Position (y): " <<static_cast<double>(part_pose.pose.position.y) <<  '\n'
//         << "    Position (z): " <<static_cast<double>(part_pose.pose.position.z) << '\n'
//         << "    Orientation (x): " <<static_cast<double>(part_pose.pose.orientation.x) << '\n'
//         << "    Orientation (y): " <<static_cast<double>(part_pose.pose.orientation.y) << '\n'
//         << "    Orientation (z): " << static_cast<double>(part_pose.pose.orientation.z) << '\n'
//         << "    Orientation (w): " << static_cast<double>(part_pose.pose.orientation.w) << '\n';
//         i++;
//     }

//     RCLCPP_INFO_STREAM(this->get_logger(), oss.str());

// }


// void CameraSubscriberNode::camera2_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
//     std::ostringstream oss; // String stream to build the log message

//     oss << "\nCAMERA 2------------------------------------------------------------\n"
//     <<"camera position (x): " << static_cast<double>(msg->sensor_pose.position.x) << '\n'
//     <<"camera posiiton (y): " << static_cast<double>(msg->sensor_pose.position.y) << '\n'
//     <<"camera position (z): " << static_cast<double>(msg->sensor_pose.position.z) << '\n'
//     <<"camera orientation (x): " << static_cast<double>(msg->sensor_pose.orientation.x) << '\n'
//     <<"camera orientation (y): " << static_cast<double>(msg->sensor_pose.orientation.y) << '\n'
//     <<"camera orientation (z): " << static_cast<double>(msg->sensor_pose.orientation.z) << '\n'
//     <<"camera orientation (w): " << static_cast<double>(msg->sensor_pose.orientation.w) << '\n';
//     int  i = 1;
//     for (const auto& part_pose : msg->part_poses) {
//         // Assuming part_pose has fields like 'name', 'position', and 'orientation'.
//         oss << "Part " << i << ":\n"
//         << "    Type: " << static_cast<int>(part_pose.part.type) << '\n' 
//         << "    Color: " << static_cast<int>(part_pose.part.color) << '\n'
//         << "    Position (x): " << static_cast<double>(part_pose.pose.position.x) << '\n'
//         << "    Position (y): " <<static_cast<double>(part_pose.pose.position.y) <<  '\n'
//         << "    Position (z): " <<static_cast<double>(part_pose.pose.position.z) << '\n'
//         << "    Orientation (x): " <<static_cast<double>(part_pose.pose.orientation.x) << '\n'
//         << "    Orientation (y): " <<static_cast<double>(part_pose.pose.orientation.y) << '\n'
//         << "    Orientation (z): " << static_cast<double>(part_pose.pose.orientation.z) << '\n'
//         << "    Orientation (w): " << static_cast<double>(part_pose.pose.orientation.w) << '\n';
//         i++;
//     }

//     RCLCPP_INFO_STREAM(this->get_logger(), oss.str());

// }

// void CameraSubscriberNode::camera3_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
//     std::ostringstream oss; // String stream to build the log message

//     oss << "\nCAMERA 3------------------------------------------------------------\n"
//     <<"camera position (x): " << static_cast<double>(msg->sensor_pose.position.x) << '\n'
//     <<"camera posiiton (y): " << static_cast<double>(msg->sensor_pose.position.y) << '\n'
//     <<"camera position (z): " << static_cast<double>(msg->sensor_pose.position.z) << '\n'
//     <<"camera orientation (x): " << static_cast<double>(msg->sensor_pose.orientation.x) << '\n'
//     <<"camera orientation (y): " << static_cast<double>(msg->sensor_pose.orientation.y) << '\n'
//     <<"camera orientation (z): " << static_cast<double>(msg->sensor_pose.orientation.z) << '\n'
//     <<"camera orientation (w): " << static_cast<double>(msg->sensor_pose.orientation.w) << '\n';
//     int  i = 1;
//     for (const auto& part_pose : msg->part_poses) {
//         // Assuming part_pose has fields like 'name', 'position', and 'orientation'.
//         oss << "Part " << i << ":\n"
//         << "    Type: " << static_cast<int>(part_pose.part.type) << '\n' 
//         << "    Color: " << static_cast<int>(part_pose.part.color) << '\n'
//         << "    Position (x): " << static_cast<double>(part_pose.pose.position.x) << '\n'
//         << "    Position (y): " <<static_cast<double>(part_pose.pose.position.y) <<  '\n'
//         << "    Position (z): " <<static_cast<double>(part_pose.pose.position.z) << '\n'
//         << "    Orientation (x): " <<static_cast<double>(part_pose.pose.orientation.x) << '\n'
//         << "    Orientation (y): " <<static_cast<double>(part_pose.pose.orientation.y) << '\n'
//         << "    Orientation (z): " << static_cast<double>(part_pose.pose.orientation.z) << '\n'
//         << "    Orientation (w): " << static_cast<double>(part_pose.pose.orientation.w) << '\n';
//         i++;
//     }

//     RCLCPP_INFO_STREAM(this->get_logger(), oss.str());

// }

// void CameraSubscriberNode::camera4_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
//     std::ostringstream oss; // String stream to build the log message

//     oss << "\nCAMERA 4------------------------------------------------------------\n"
//     <<"camera position (x): " << static_cast<double>(msg->sensor_pose.position.x) << '\n'
//     <<"camera posiiton (y): " << static_cast<double>(msg->sensor_pose.position.y) << '\n'
//     <<"camera position (z): " << static_cast<double>(msg->sensor_pose.position.z) << '\n'
//     <<"camera orientation (x): " << static_cast<double>(msg->sensor_pose.orientation.x) << '\n'
//     <<"camera orientation (y): " << static_cast<double>(msg->sensor_pose.orientation.y) << '\n'
//     <<"camera orientation (z): " << static_cast<double>(msg->sensor_pose.orientation.z) << '\n'
//     <<"camera orientation (w): " << static_cast<double>(msg->sensor_pose.orientation.w) << '\n';
//     int  i = 1;
//     for (const auto& part_pose : msg->part_poses) {
//         // Assuming part_pose has fields like 'name', 'position', and 'orientation'.
//         oss << "Part " << i << ":\n"
//         << "    Type: " << static_cast<int>(part_pose.part.type) << '\n' 
//         << "    Color: " << static_cast<int>(part_pose.part.color) << '\n'
//         << "    Position (x): " << static_cast<double>(part_pose.pose.position.x) << '\n'
//         << "    Position (y): " <<static_cast<double>(part_pose.pose.position.y) <<  '\n'
//         << "    Position (z): " <<static_cast<double>(part_pose.pose.position.z) << '\n'
//         << "    Orientation (x): " <<static_cast<double>(part_pose.pose.orientation.x) << '\n'
//         << "    Orientation (y): " <<static_cast<double>(part_pose.pose.orientation.y) << '\n'
//         << "    Orientation (z): " << static_cast<double>(part_pose.pose.orientation.z) << '\n'
//         << "    Orientation (w): " << static_cast<double>(part_pose.pose.orientation.w) << '\n';
//         i++;
//     }

//     RCLCPP_INFO_STREAM(this->get_logger(), oss.str());

// }

// void CameraSubscriberNode::camera5_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
//     std::ostringstream oss; // String stream to build the log message

//     oss << "\nCAMERA 5------------------------------------------------------------\n"
//     <<"camera position (x): " << static_cast<double>(msg->sensor_pose.position.x) << '\n'
//     <<"camera posiiton (y): " << static_cast<double>(msg->sensor_pose.position.y) << '\n'
//     <<"camera position (z): " << static_cast<double>(msg->sensor_pose.position.z) << '\n'
//     <<"camera orientation (x): " << static_cast<double>(msg->sensor_pose.orientation.x) << '\n'
//     <<"camera orientation (y): " << static_cast<double>(msg->sensor_pose.orientation.y) << '\n'
//     <<"camera orientation (z): " << static_cast<double>(msg->sensor_pose.orientation.z) << '\n'
//     <<"camera orientation (w): " << static_cast<double>(msg->sensor_pose.orientation.w) << '\n';
//     int  i = 1;
//     for (const auto& part_pose : msg->part_poses) {
//         // Assuming part_pose has fields like 'name', 'position', and 'orientation'.
//         oss << "Part " << i << ":\n"
//         << "    Type: " << static_cast<int>(part_pose.part.type) << '\n' 
//         << "    Color: " << static_cast<int>(part_pose.part.color) << '\n'
//         << "    Position (x): " << static_cast<double>(part_pose.pose.position.x) << '\n'
//         << "    Position (y): " <<static_cast<double>(part_pose.pose.position.y) <<  '\n'
//         << "    Position (z): " <<static_cast<double>(part_pose.pose.position.z) << '\n'
//         << "    Orientation (x): " <<static_cast<double>(part_pose.pose.orientation.x) << '\n'
//         << "    Orientation (y): " <<static_cast<double>(part_pose.pose.orientation.y) << '\n'
//         << "    Orientation (z): " << static_cast<double>(part_pose.pose.orientation.z) << '\n'
//         << "    Orientation (w): " << static_cast<double>(part_pose.pose.orientation.w) << '\n';
//         i++;
//     }

//     RCLCPP_INFO_STREAM(this->get_logger(), oss.str());

// }

// void CameraSubscriberNode::camera6_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
//     std::ostringstream oss; // String stream to build the log message

//     oss << "\nCAMERA 6------------------------------------------------------------\n"
//     <<"camera position (x): " << static_cast<double>(msg->sensor_pose.position.x) << '\n'
//     <<"camera posiiton (y): " << static_cast<double>(msg->sensor_pose.position.y) << '\n'
//     <<"camera position (z): " << static_cast<double>(msg->sensor_pose.position.z) << '\n'
//     <<"camera orientation (x): " << static_cast<double>(msg->sensor_pose.orientation.x) << '\n'
//     <<"camera orientation (y): " << static_cast<double>(msg->sensor_pose.orientation.y) << '\n'
//     <<"camera orientation (z): " << static_cast<double>(msg->sensor_pose.orientation.z) << '\n'
//     <<"camera orientation (w): " << static_cast<double>(msg->sensor_pose.orientation.w) << '\n';
//     int  i = 1;
//     for (const auto& part_pose : msg->part_poses) {
//         // Assuming part_pose has fields like 'name', 'position', and 'orientation'.
//         oss << "Part " << i << ":\n"
//         << "    Type: " << static_cast<int>(part_pose.part.type) << '\n' 
//         << "    Color: " << static_cast<int>(part_pose.part.color) << '\n'
//         << "    Position (x): " << static_cast<double>(part_pose.pose.position.x) << '\n'
//         << "    Position (y): " <<static_cast<double>(part_pose.pose.position.y) <<  '\n'
//         << "    Position (z): " <<static_cast<double>(part_pose.pose.position.z) << '\n'
//         << "    Orientation (x): " <<static_cast<double>(part_pose.pose.orientation.x) << '\n'
//         << "    Orientation (y): " <<static_cast<double>(part_pose.pose.orientation.y) << '\n'
//         << "    Orientation (z): " << static_cast<double>(part_pose.pose.orientation.z) << '\n'
//         << "    Orientation (w): " << static_cast<double>(part_pose.pose.orientation.w) << '\n';
//         i++;
//     }

//     RCLCPP_INFO_STREAM(this->get_logger(), oss.str());

// }

// void CameraSubscriberNode::camera7_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
//     std::ostringstream oss; // String stream to build the log message

//     oss << "\nCAMERA 7------------------------------------------------------------\n"
//     <<"camera position (x): " << static_cast<double>(msg->sensor_pose.position.x) << '\n'
//     <<"camera posiiton (y): " << static_cast<double>(msg->sensor_pose.position.y) << '\n'
//     <<"camera position (z): " << static_cast<double>(msg->sensor_pose.position.z) << '\n'
//     <<"camera orientation (x): " << static_cast<double>(msg->sensor_pose.orientation.x) << '\n'
//     <<"camera orientation (y): " << static_cast<double>(msg->sensor_pose.orientation.y) << '\n'
//     <<"camera orientation (z): " << static_cast<double>(msg->sensor_pose.orientation.z) << '\n'
//     <<"camera orientation (w): " << static_cast<double>(msg->sensor_pose.orientation.w) << '\n';
//     int  i = 1;
//     for (const auto& part_pose : msg->part_poses) {
//         // Assuming part_pose has fields like 'name', 'position', and 'orientation'.
//         oss << "Part " << i << ":\n"
//         << "    Type: " << static_cast<int>(part_pose.part.type) << '\n' 
//         << "    Color: " << static_cast<int>(part_pose.part.color) << '\n'
//         << "    Position (x): " << static_cast<double>(part_pose.pose.position.x) << '\n'
//         << "    Position (y): " <<static_cast<double>(part_pose.pose.position.y) <<  '\n'
//         << "    Position (z): " <<static_cast<double>(part_pose.pose.position.z) << '\n'
//         << "    Orientation (x): " <<static_cast<double>(part_pose.pose.orientation.x) << '\n'
//         << "    Orientation (y): " <<static_cast<double>(part_pose.pose.orientation.y) << '\n'
//         << "    Orientation (z): " << static_cast<double>(part_pose.pose.orientation.z) << '\n'
//         << "    Orientation (w): " << static_cast<double>(part_pose.pose.orientation.w) << '\n';
//         i++;
//     }

//     RCLCPP_INFO_STREAM(this->get_logger(), oss.str());

// }

// void CameraSubscriberNode::camera8_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
//     std::ostringstream oss; // String stream to build the log message

//     oss << "\nCAMERA 8------------------------------------------------------------\n"
//     <<"camera position (x): " << static_cast<double>(msg->sensor_pose.position.x) << '\n'
//     <<"camera posiiton (y): " << static_cast<double>(msg->sensor_pose.position.y) << '\n'
//     <<"camera position (z): " << static_cast<double>(msg->sensor_pose.position.z) << '\n'
//     <<"camera orientation (x): " << static_cast<double>(msg->sensor_pose.orientation.x) << '\n'
//     <<"camera orientation (y): " << static_cast<double>(msg->sensor_pose.orientation.y) << '\n'
//     <<"camera orientation (z): " << static_cast<double>(msg->sensor_pose.orientation.z) << '\n'
//     <<"camera orientation (w): " << static_cast<double>(msg->sensor_pose.orientation.w) << '\n';
//     int  i = 1;
//     for (const auto& part_pose : msg->part_poses) {
//         // Assuming part_pose has fields like 'name', 'position', and 'orientation'.
//         oss << "Part " << i << ":\n"
//         << "    Type: " << static_cast<int>(part_pose.part.type) << '\n' 
//         << "    Color: " << static_cast<int>(part_pose.part.color) << '\n'
//         << "    Position (x): " << static_cast<double>(part_pose.pose.position.x) << '\n'
//         << "    Position (y): " <<static_cast<double>(part_pose.pose.position.y) <<  '\n'
//         << "    Position (z): " <<static_cast<double>(part_pose.pose.position.z) << '\n'
//         << "    Orientation (x): " <<static_cast<double>(part_pose.pose.orientation.x) << '\n'
//         << "    Orientation (y): " <<static_cast<double>(part_pose.pose.orientation.y) << '\n'
//         << "    Orientation (z): " << static_cast<double>(part_pose.pose.orientation.z) << '\n'
//         << "    Orientation (w): " << static_cast<double>(part_pose.pose.orientation.w) << '\n';
//         i++;
//     }

//     RCLCPP_INFO_STREAM(this->get_logger(), oss.str());

// }