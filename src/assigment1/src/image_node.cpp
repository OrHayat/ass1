#include "ros/ros.h"
#include "std_msgs/String.h"
#include "assigment1/Color.h"
#include <sstream>

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <cv_bridge/cv_bridge.h>

#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
int main( int argc,  char** argv )
{

ros::init(argc, argv, "ass1_img_node");
ros::NodeHandle n;
image_transport::ImageTransport it(n);
image_transport::Publisher image_pub = it.advertise("ass1_imageNode", 1);

cv::Mat image=cv::imread("colors.jpg",CV_LOAD_IMAGE_COLOR);
if(image.empty())
{
ROS_ERROR("error opening image colors.jpg\n");
exit(-1);
}
sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
    ros::Rate loop_rate(5);

while(n.ok())
	{
	 image_pub.publish(msg);
	 ros::spinOnce();
	ROS_INFO("sent image\n");
	 loop_rate.sleep();
	}
return 0;
}
