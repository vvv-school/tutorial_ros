#include <ros/ros.h>
#include <tutorial/AddTwoInts.h>

bool add(tutorial::AddTwoInts::Request  &req,
         tutorial::AddTwoInts::Response &res)
{
  res.Sum = req.A + req.B;
  ROS_INFO_STREAM("request: x=" << req.A << ", y=" << req.B);
  ROS_INFO_STREAM("sending back response: [" << res.Sum << "]");
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("add_two_ints", add);
  ROS_INFO_STREAM("Ready to add two ints.");
  ros::spin();

  return 0;
}
