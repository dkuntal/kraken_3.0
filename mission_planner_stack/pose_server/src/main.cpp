#include <pose_server/PoseServer.h>
#include <pose_server/DeadReckoning.h>

int main(int argc,char** argv)
{
  ros::init(argc,argv,"PoseServer");
  ros::NodeHandle n;
  kraken_core::DeadReckoning estimator;
  kraken_core::PoseServer server(&estimator);
  ros::ServiceServer service = n.advertiseService("kraken_pose_change",&kraken_core::PoseServer::resetPosition,&server);
  ROS_INFO("POSE SERVER STARTED");
  ros::spin();
  
  return 0;
}
