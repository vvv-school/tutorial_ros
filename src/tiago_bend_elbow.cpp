#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <control_msgs/FollowJointTrajectoryAction.h>

int main (int argc, char **argv)
{
  ros::init(argc, argv, "test_fibonacci");

  actionlib::SimpleActionClient<XYZ> ac("ACTION_NAME", true);

  ROS_INFO_STREAM("Waiting for action server to start.");
  // wait for the action server to start
  ac.waitForServer(); //will wait for infinite time

  ROS_INFO_STREAM("Action server started, sending goal.");

  // http://docs.ros.org/kinetic/api/control_msgs/html/index-msg.html
  // send a goal to the action
  XYZ goal;

  // add "arm_4_joint" to joint_names

  // FILL IN HERE

  // add a JointTrajectoryPoint to the "trajectory" field of "goal"
  // this point should have a desired position in the field "positions" (vector)

  // FILL IN HERE


  // change the "time_from_start" parameter of the trajectory point

  // FILL IN HERE

  // add more points, make sure to keep increasing "time_from_start" between points

  // FILL IN HERE

  ac.sendGoal(goal);

  //wait for the action to return
  bool finished_before_timeout = ac.waitForResult(ros::Duration(30.0));

  if (finished_before_timeout)
  {
    actionlib::SimpleClientGoalState state = ac.getState();
    ROS_INFO_STREAM("Action finished: " << state.toString());
  }
  else
    ROS_INFO_STREAM("Action did not finish before the time out.");

  return 0;
}
