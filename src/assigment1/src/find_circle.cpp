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
  boost::shared_ptr<assigment1::Color const> color_message;
  boost::shared_ptr<sensor_msgs::Image const> img;
 bool got_img=false;
 bool got_color=false;

void color_callback(const   boost::shared_ptr<assigment1::Color const> message)
{
if(message!=0)
 {
 color_message=message;
 got_color=true; 
 }
}
void img_callback(const boost::shared_ptr<sensor_msgs::Image const> msg)
{
if(msg!=0)
  {
   img=msg;
   got_img=true;
  }
}

int main(int argc, char ** argv)
{
  ros::init(argc, argv, "ass1_circle_Search");
  
  ros::NodeHandle n;
  ros::Subscriber color_Sub=n.subscribe("ass1/Color",1,color_callback);
  ros::Subscriber img_Sub = n.subscribe("ass1/Image",1,img_callback);
      ros::Rate rate(5);
       while(n.ok()&&(!(got_img&&got_color)))
{
ros::spinOnce();
rate.sleep();
}
if(!n.ok())
{
exit(0);
}
img_Sub.shutdown();
color_Sub.shutdown();
 // color_message=ros::topic::waitForMessage<assigment1::Color>("ass1/Color");
 // img=ros::topic::waitForMessage<sensor_msgs::Image>("ass1/Image");


   cv::Mat colored_img=cv_bridge::toCvShare(img, "bgr8")->image;//the image
   cv::Mat color_ref(1,1,CV_8UC3,cv::Scalar(color_message->r,color_message->g,color_message->b));//get the color as mat object 
 
   cv::Mat blured_img;
  //cv::medianBlur(colored_img, colored_img, 7);//blur grey image
   cv::GaussianBlur(colored_img,blured_img,cv::Size(13,13),0,0);

   cv::Mat hsv_color;
   cv::cvtColor(color_ref,hsv_color,CV_RGB2HSV);//convert color to hsv
   unsigned char * p=hsv_color.ptr(0,0);
      int hue=p[0];


  cv::Mat mask;
   if(hue<15||hue>=170)//red is special case
   {
   std::cout<<"hsv"<<hsv_color<<std::endl;
   std::cout<<"rgb"<<color_ref<<std::endl;
   cv::Scalar scalarmin(0,50,50);
   cv::Scalar scalarmax(15,255,255);
   cv::Scalar scalarmin1(170,50,50);
   cv::Scalar scalarmax1(180,255,255);
   cv::Mat hsv_img;//image as hsv
  cv::Mat mask2;
   cv::cvtColor(blured_img,hsv_img,CV_BGR2HSV);//fill image in hsv
   cv::inRange(hsv_img,scalarmin,scalarmax,mask);//image with only the choosen color
   cv::inRange(hsv_img,scalarmin1,scalarmax1,mask2);//image with only the choosen color
   cv::addWeighted(mask,1.0,mask2,1.0,0.0,mask);
   }
   else
{
   std::cout<<"hsv"<<hsv_color<<std::endl;
   std::cout<<"rgb"<<color_ref<<std::endl;

   cv::Scalar scalarmin(p[0]-15,min(40,p[1]),min(40,p[2]));
   cv::Scalar scalarmax(p[0]+15,min(p[1]+40,255),min(p[2]+40,255));
   cv::Mat hsv_img;//image as hsv
   cv::cvtColor(blured_img,hsv_img,CV_BGR2HSV);//fill image in hsv
   cv::inRange(hsv_img,scalarmin,scalarmax,mask);//image with only the choosen color
}
   cv::erode(mask,mask,cv::Mat(),cv::Point(-1,-1),2);
   cv::dilate(mask,mask,cv::Mat(),cv::Point(-1,-1),2);
   cv::Canny(mask,mask,100,200,3,false);

   std::vector<std::vector<cv::Point> > contours;
   std::vector<cv::Vec4i> hierarchy;
   cv::findContours(mask,contours,hierarchy,CV_RETR_TREE,CV_CHAIN_APPROX_SIMPLE);

   std::cout<<"contours size "<<contours.size()<<std::endl;

     double min_len=-1;
     int min_index=-1;    
	if(contours.size()==0)
	{ROS_INFO("ball wasnt detected for given color\n");
	 exit(0);
	}
	for(size_t i=0;i<contours.size();i++)
	{
	//std::cout<<"i="<<i<<"contur size = "<<contourArea(contours[i])<<std::endl;
	if(contourArea(contours[i])>min_len)
	   {
		min_index=i;
		min_len=contourArea(contours[i]);
	   }
	}
	//std::cout<<"i max= "<<min_index<<std::endl;
 
   	float radius;
	cv::Point2f center;
	cv::minEnclosingCircle(contours[min_index],center,radius);
	cv::Moments object_moments=cv::moments(contours[min_index]);
	int center_x=(int)object_moments.m10/object_moments.m00;
	int center_y=(int)object_moments.m01/object_moments.m00;


   try
      {
     ros::Publisher circle_publisher = n.advertise<assigment1::Circle>("ass1/Circle", 1);//publish on
      ros::Rate loop_rate(5);
     assigment1::Circle msg;


    msg.x=center_x;
    msg.y=center_y;
    msg.radius=(int)radius;


       while(n.ok())
	{

	circle_publisher.publish(msg);
	ROS_INFO("SENT CIRCLE DATA\n");
        ros::spinOnce();
	loop_rate.sleep();
     }
}
     catch (cv_bridge::Exception& e)
     {
       ROS_ERROR("Could not convert from '%s' to 'bgr8'.", img->encoding.c_str());
     }

   //std_msgs::ColorRGBA msg = ros::topic::waitForMessage<std_msgs::String>("/chatter");
   //if (msg) std::cout<<"Msg received!"<<std::endl;
   // else std::cout<<"No message!"<<std::endl;
  return 0;
}
