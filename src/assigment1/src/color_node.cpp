#include "ros/ros.h"
#include "std_msgs/String.h"
#include "assigment1/Color.h"
#include <sstream>

#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
	

  ros::init(argc, argv, "ass1_color_publisher");
  if(argc!=4)
	{
    ROS_ERROR("you need to enter 3 colors for the program");
    exit(-1);
	}
  
  int r=(unsigned char)atoi(argv[1]);
  int g=(unsigned char)atoi(argv[2]);
  int b=(unsigned char)atoi(argv[3]);


  ros::NodeHandle n;//handler to ros system

  ros::Publisher color_publisher = n.advertise<assigment1::Color>("color_ass1", 1);//publish on colo_ass1 topic with queue size of 1

  ros::Rate loop_rate(10);

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */

  while (n.ok())
  {
    /**
     * This is a message object. You stuff it with data, and then publish it.
     */
    assigment1::Color msg;

    msg.r=r;
    msg.g=g;
    msg.b=b;

    ROS_INFO("r=%d g=%d b=%d", msg.r,msg.g,msg.b);

    color_publisher.publish(msg);//send message away

    ros::spinOnce();
    loop_rate.sleep();
  }


  return 0;
}
