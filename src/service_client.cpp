#include <ros/ros.h>
#include <tutorial/AddTwoInts.h>
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "add_two_ints_client");
  if (argc != 3)
  {
    ROS_INFO_STREAM("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<tutorial::AddTwoInts>("add_two_ints");
  tutorial::AddTwoInts srv;
  srv.request.A = atoll(argv[1]);
  srv.request.B = atoll(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO_STREAM("Sum: " << srv.response.Sum);
  }
  else
  {
    ROS_ERROR_STREAM("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
