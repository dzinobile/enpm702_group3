#include "camera_subscriber_node.hpp"
#include <string>
#include <vector>

int arr[] = {0,0,0,0,0,0,0,0};

std::vector<mage_msgs::msg::Part> parts_vector{};
void CameraSubscriberNode::subscribe_parts(const mage_msgs::msg::Parts::SharedPtr parts_msg_)
{

    // Loop through all parts in the received message
    
    for (const auto &part : parts_msg_->parts)
    {
        parts_vector.push_back(part);
        
        // auto part_color = static_cast<int>(part.color);
        // auto part_type = static_cast<int>(part.type);

        // RCLCPP_INFO_STREAM(this->get_logger(),
        //                    "Received Part:\n"
        //                        << "Part Color: " << part_color << '\n'
        //                        << "Part Type: " << part_type);

                            
    }

}


 
void CameraSubscriberNode::camera_callback(int camera_id, const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg){
    // Check if the first message has already been processed
        if (camera_message_processed_) {
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
        for (const auto &part : parts_vector){
            if (static_cast<int>(part.color)==static_cast<int>(part_pose.part.color) && static_cast<int>(part.type)==static_cast<int>(part_pose.part.type))
            oss << "MATCH FOUND\n";
            
        }
    }

    RCLCPP_INFO_STREAM(this->get_logger(), oss.str());
    if ((arr[0]+arr[1]+arr[2]+arr[3]+arr[4]+arr[5]+arr[6]+arr[7])==8){
        camera_message_processed_ = true;
    }
    
    
}



