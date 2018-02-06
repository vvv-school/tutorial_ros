#include <ros/ros.h>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "read_param");
  ros::NodeHandle n("~");

  int number;
  n.param("number", number, -1);

  ROS_INFO_STREAM("Int param: " << number);

  std::vector<double> numbers;
  n.param("list", numbers, std::vector<double>());

  ROS_INFO_STREAM("3nd number in list: " << numbers[2]);

  std::vector<int> ints;
  n.param("list", ints, std::vector<int>());

  ROS_INFO_STREAM("3nd number in list: " << ints[2]);

  return 0;
}
