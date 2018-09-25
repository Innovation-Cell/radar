#include <iostream>
#include <ros/ros.h>
#include <std_msgs/Float32MultiArray.h>
#include <std_msgs/Float64MultiArray.h>
#include <vector>
using namespace std;

double theta_arr[64][3];
double time_arr[3];
double azi_rate_arr[64];
double range_arr[64];
double range_rate_arr[64];
double v_theta[64];
double speed[64];
std::vector<float> obstacle;
ros::Time begin_time,end_time;

void azimuth_rate(const std_msgs::Float32MultiArray::ConstPtr &msg){
	//Changing the time and theta arrays
	time_arr[0] = time_arr[1];
	time_arr[1] = time_arr[2];
	time_arr[2] = (end_time-begin_time).toSec();
	

}

void range_init(const std_msgs::Float32MultiArray::ConstPtr &msg){
	for(int i=0;i<64;i++)
		range_arr[i] = msg->data[i];
}

void vel_init(const std_msgs::Float32MultiArray::ConstPtr &msg){
	for(int i=0;i<64;i++)
		range_rate_arr[i] = msg->data[i];
}
void ipmdata(const std_msgs::Float64MultiArray::ConstPtr &msg){
	if (msg->data.size()!=0){
		for (int i=0;i<(2*msg->data.size()-1);i++){
			obstacle.push_back(msg->data[i]);

		}
	}
}
int main(int argc, char ** argv){
	ros::init(argc,argv,"azimuth_rate");
	ros::NodeHandle n;
	ros::Subscriber azimuth_sub = n.subscribe("/radar_angle",1,azimuth_rate);
	ros::Subscriber range_sub = n.subscribe("/radar_range",1,range_init);
	ros::Subscriber range_rate_sub = n.subscribe("/radar_vel",1,vel_init);
	ros::Subscriber ipmdata_sub = n.subscribe("/vehicle",1,ipmdata);
	ros::Rate loop_rate(3);
	
	//Initializing the time, theta and azimuth arrays to 0
	for(int i=0;i<64;i++){
		for(int j=0;j<2;j++){
			theta_arr[i][j] = 0;
			time_arr[j] = 0;
		}
		azi_rate_arr[i] = 0;
		range_arr[i] = 0;
		range_rate_arr[i] = 0;
		v_theta[i] = 0;
		speed[i] = 0;
	}

	begin_time = ros::Time::now();

	while(ros::ok()){
		end_time = ros::Time::now();
		ros::spinOnce();
    	loop_rate.sleep();
	}

	return 0;
}