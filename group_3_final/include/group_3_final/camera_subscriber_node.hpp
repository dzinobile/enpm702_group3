#pragma once
#include <rclcpp/rclcpp.hpp>
#include <memory>
#include  <array>
#include <mage_msgs/msg/advanced_logical_camera_image.hpp>
#include <rclcpp/rclcpp.hpp>
#include <mage_msgs/msg/advanced_logical_camera_image.hpp>
#include <unordered_map>

class CameraSubscriberNode : public rclcpp::Node
{
public:
    CameraSubscriberNode(std::string node_name) 
        : rclcpp::Node(node_name)
    {
        for (int i = 1; i <= 8; ++i)
        {
            std::string topic_name = "/mage/camera" + std::to_string(i) + "/image";
            auto callback = [this, i](const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg) {
                this->camera_callback(i, msg);
            };

            auto subscription = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>(
                topic_name, 
                rclcpp::SensorDataQoS(), 
                callback
            );

            camera_subscriptions_[i] = subscription;
        }
    }

private:
    void camera_callback(int camera_id, const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);

    std::unordered_map<int, rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr> camera_subscriptions_;
};



// std::string camera_topics[8]{
//     "/mage/camera1/image", 
//     "/mage/camera2/image", 
//     "/mage/camera3/image",
//     "/mage/camera4/image",
//     "/mage/camera5/image",
//     "/mage/camera6/image",
//     "/mage/camera7/image",
//     "/mage/camera8/image"};

// std::shared_ptr<rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>> camera_subscribers[8]{};

// class CameraSubscriberNode :  public rclcpp::Node
// {
//     public:
//     CameraSubscriberNode(std::string node_name) : rclcpp::Node(node_name)
//     {
//         for (int i=0;i<8;i++){
//             camera_subscribers[i] = 


//         }
//     }

//     private:

// };// camera subscriber node


// class CameraSubscriberNode : public rclcpp::Node
// {
//     public:
//     CameraSubscriberNode(std::string node_name) : rclcpp::Node(node_name)
//     {
//         camera1_sub_ = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>("/mage/camera1/image", 
//         rclcpp::SensorDataQoS(), 
//         std::bind(&CameraSubscriberNode::camera1_callback, this,std::placeholders::_1));

//         camera2_sub_ = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>("/mage/camera2/image", 
//         rclcpp::SensorDataQoS(), 
//         std::bind(&CameraSubscriberNode::camera2_callback, this,std::placeholders::_1));

//         camera3_sub_ = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>("/mage/camera3/image", 
//         rclcpp::SensorDataQoS(), 
//         std::bind(&CameraSubscriberNode::camera3_callback, this,std::placeholders::_1));

//         camera4_sub_ = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>("/mage/camera4/image", 
//         rclcpp::SensorDataQoS(), 
//         std::bind(&CameraSubscriberNode::camera4_callback, this,std::placeholders::_1));

//         camera5_sub_ = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>("/mage/camera5/image", 
//         rclcpp::SensorDataQoS(), 
//         std::bind(&CameraSubscriberNode::camera5_callback, this,std::placeholders::_1));

//         camera6_sub_ = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>("/mage/camera6/image", 
//         rclcpp::SensorDataQoS(), 
//         std::bind(&CameraSubscriberNode::camera6_callback, this,std::placeholders::_1));

//         camera7_sub_ = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>("/mage/camera7/image", 
//         rclcpp::SensorDataQoS(), 
//         std::bind(&CameraSubscriberNode::camera7_callback, this,std::placeholders::_1));

//         camera8_sub_ = this->create_subscription<mage_msgs::msg::AdvancedLogicalCameraImage>("/mage/camera8/image", 
//         rclcpp::SensorDataQoS(), 
//         std::bind(&CameraSubscriberNode::camera8_callback, this,std::placeholders::_1));
//     }

//     private:
//     void camera1_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);
//     void camera2_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);
//     void camera3_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);
//     void camera4_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);
//     void camera5_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);
//     void camera6_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);
//     void camera7_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);
//     void camera8_callback(const mage_msgs::msg::AdvancedLogicalCameraImage::SharedPtr msg);

//     rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr camera1_sub_;
//     rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr camera2_sub_;
//     rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr camera3_sub_;
//     rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr camera4_sub_;
//     rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr camera5_sub_;
//     rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr camera6_sub_;
//     rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr camera7_sub_;
//     rclcpp::Subscription<mage_msgs::msg::AdvancedLogicalCameraImage>::SharedPtr camera8_sub_;

// };//Camera subscriber node
