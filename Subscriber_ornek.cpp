#include "ros/ros.h"
#include "std_msgs/Int32.h"

void fonk(const std_msgs::Int32::ConstPtr& msg) {
    ROS_INFO("Alinan mesaj: %d", msg->data);
}

int main(int argc, char **argv) {
    
    ros::init(argc, argv, "subscriber"); // ROS düğümünü tanımlıyorum.

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/multiples_of_10", 10, fonk); // Subscriberı tanımlıyorum.

    ros::spin(); //Spini yazmazsak veriler tam çalışmaz.

    return 0;
}

