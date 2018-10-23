#include "ros/ros.h"

#include "assigment1/Color.h"

#include "assigment1/Circle.h"
#include <sstream>



#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <cv_bridge/cv_bridge.h>

#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>


int min(int x,int y)
{
if(x<y)
return x;
else return y;
}

int main(int argc, char ** argv)
{
  ros::init(argc, argv, "ass1_draw");
 
  ros::NodeHandle n;

  boost::shared_ptr<sensor_msgs::Image const> img;
  boost::shared_ptr<assigment1::Circle const> circle;

  img=ros::topic::waitForMessage<sensor_msgs::Image>("ass1/Image");
  circle=ros::topic::waitForMessage<assigment1::Circle>("ass1/Circle");

  cv::Mat colored_img=cv_bridge::toCvShare(img, "bgr8")->image;//the image

  cv::circle(colored_img,cv::Point(circle->x,circle->y),(int)circle->radius,cv::Scalar(0,244,0),5);
  
  cv::imshow("img",colored_img);
  cv::waitKey(0);
  cv::destroyAllWindows();
return 0;
}
