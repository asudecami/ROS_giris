#include "ros/ros.h"
#include "std_msgs/Int32.h"

int main(int argc, char **argv) {

    ros::init(argc, argv, "multiples_of_10_publisher"); // Baslatacagimiz dugumun adini tanimliyoruz.

    ros::NodeHandle nh; // Dugumler arasinda iletişimin saglanmasi icin NodeHandle tanimlamaliyiz.

    ros::Publisher pub = nh.advertise<std_msgs::Int32>("/multiples_of_10", 10); // Publisher olusturdum.

    ros::Rate loop_rate(10); // Yayin hizini belirliyoruz. 10 Hz yaptim.

    int count = 0;

    while (ros::ok()) {
        
        int multiple_of_10 = count * 10; // 10'un katini hesaplar.
        
        std_msgs::Int32 msg;
        msg.data = multiple_of_10; //Sayac verilerini data tutar.
        pub.publish(msg); // Mesaj oluşturur ve yayinlar.

        ROS_INFO("Publishing: %d", multiple_of_10);

        loop_rate.sleep(); // Hizi korur. 10 Hz'den asagisi gerceklesirse araya sleep girer.

        count++;
    }

    return 0;
}

