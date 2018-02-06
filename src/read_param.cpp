#include <ros/ros.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "read_param");
  ros::NodeHandle n("~");

  int number;
  n.param("number", number, -1);

  ROS_INFO_STREAM("Int param: " << number);

  return 0;
}
