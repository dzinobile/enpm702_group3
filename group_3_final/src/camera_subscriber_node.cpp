#include "camera_subscriber_node.hpp"
#include <string>

int arr[] = {0,0,0,0,0,0,0,0};
 
void CameraSubscriberNode::camera_callback(int camera_id, const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg){
    // Check if the first message has already been processed
        if (first_message_processed_) {
            RCLCPP_INFO(this->get_logger(), "Message ignored (already processed the first message).");
            return;
        }

    arr[camera_id-1] = 1;
    std::ostringstream oss; // String stream to build the log message
    oss << "\nCAMERA " << camera_id << "--------------------------------------\n"
     <<"camera position (x): " << static_cast<double>(msg->sensor_pose.position.x) << '\n'
    <<"camera posiiton (y): " << static_cast<double>(msg->sensor_pose.position.y) << '\n'
    <<"camera position (z): " << static_cast<double>(msg->sensor_pose.position.z) << '\n'
    <<"camera orientation (x): " << static_cast<double>(msg->sensor_pose.orientation.x) << '\n'
    <<"camera orientation (y): " << static_cast<double>(msg->sensor_pose.orientation.y) << '\n'
    <<"camera orientation (z): " << static_cast<double>(msg->sensor_pose.orientation.z) << '\n'
    <<"camera orientation (w): " << static_cast<double>(msg->sensor_pose.orientation.w) << '\n';
        int  n = 1;
    for (const auto& part_pose : msg->part_poses) {
        
        oss << "Part " << n << ":\n"
        << "    Type: " << static_cast<int>(part_pose.part.type) << '\n' 
        << "    Color: " << static_cast<int>(part_pose.part.color) << '\n'
        << "    Position (x): " << static_cast<double>(part_pose.pose.position.x) << '\n'
        << "    Position (y): " <<static_cast<double>(part_pose.pose.position.y) <<  '\n'
        << "    Position (z): " <<static_cast<double>(part_pose.pose.position.z) << '\n'
        << "    Orientation (x): " <<static_cast<double>(part_pose.pose.orientation.x) << '\n'
        << "    Orientation (y): " <<static_cast<double>(part_pose.pose.orientation.y) << '\n'
        << "    Orientation (z): " << static_cast<double>(part_pose.pose.orientation.z) << '\n'
        << "    Orientation (w): " << static_cast<double>(part_pose.pose.orientation.w) << '\n';
        n++;
    }

    RCLCPP_INFO_STREAM(this->get_logger(), oss.str());
    if ((arr[0]+arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7])==8){
        first_message_processed_ = true;
    }
    
    
}



