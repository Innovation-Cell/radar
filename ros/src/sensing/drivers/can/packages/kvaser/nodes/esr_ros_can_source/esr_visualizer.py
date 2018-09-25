#!/usr/bin/python3
"""
esr_visualizer.py: version 0.1.0

Todo:
convert rosbag can_raw ESR track data to image

History:
2016/10/28: Initial version to display visual radar data from ros topic 'esr_front'.
"""

#from datetime import datetime
import math
import numpy as np
import argparse
import sys
import time
import numpy as np
import rospy
import datetime
import struct
import json
import std_msgs
from std_msgs.msg import String,Float32,Float32MultiArray,MultiArrayLayout,MultiArrayDimension
from geometry_msgs.msg import Pose2D
Vehicle_speed=0
global theta
theta = [[0]*64]*3
global temp
temp=[0]
global theta_array
theta_array=[1.0]*64
global range_array
range_array=[1.0]*64
global vel_array
vel_array=[0.0]*64
global append_array
append_array=[[1.0]*64]*3
global dtheta_dt
dtheta_dt=[0]*64
global tim
tim=[1]*3
global count
count=0
global value
value=[0]*64
global start
start = datetime.datetime.now()
global end
end = datetime.datetime.now()
from sensor_msgs.msg import (
    Image,
)
try:
    import cv2
except ImportError:
    print "Error importing opencv"
    pass

class RadarVisualizer(object):
    def __init__(self, width=1600, height=920, channels=3):
        self.width = width
        self.height = height
        self.channels = channels
        self.font = cv2.FONT_HERSHEY_SIMPLEX 
        self.img = np.zeros((self.height, self.width, self.channels), np.uint8)
        cv2.imshow("Radar", self.img)
        pass

    def update(self, radarData):
        self.img = np.zeros((self.height, self.width, self.channels), np.uint8)
        cv2.line(self.img, (self.width/2-self.height, 0), (self.width/2 , self.height), (100, 255, 255)) #check for truncation
        cv2.line(self.img, (self.width/2+self.height, 0), (self.width/2 , self.height), (100, 255, 255))
        cv2.line(self.img, (self.width/2-self.height/4, 0), (self.width/2 , self.height), (100, 255, 100))
        cv2.line(self.img, (self.width/2+self.height/4, 0), (self.width/2 , self.height), (100, 255, 100))
        global start
        start = datetime.datetime.now()
        for track_number in range(1, 65):
            global temp
            if(track_number in temp):
                global theta_array
                global append_array
                global range_array
                global vel_array
                append_array.append(range_array)
                append_array.append(vel_array)
                append_array.append(theta_array)
                append_array.pop(0)
                append_array.pop(0)
                append_array.pop(0)
                theta_array=[-1]*64
                vel_array=[0.0]*64
                range_array=[-1]*64
                temp=[]
                temp.append(track_number)
            elif (temp[0]==0):
                temp=[]
                temp.append(track_number)
            if str(track_number)+'_track_range' in radarData:
                global count
                count = count + 1

                track_range = float(radarData[str(track_number)+'_track_range'])
                track_range_rate=float(radarData[str(track_number)+'_track_range_rate'])
                track_width=0.5*float(radarData[str(track_number)+'_track_width'])   #0.5 is the scaling factor
                track_lat_rate=0.25*radarData[str(track_number)+'_track_lat_rate']
                global theta_array
                theta_array[track_number-1]=-1
                if track_range_rate<=-Vehicle_speed-0.01 or track_range_rate>=-Vehicle_speed+0.01:
                    track_angle = (float(radarData[str(track_number)+'_track_angle'])+90.0)*math.pi/180
                    global theta_array
                    global range_array
                    global vel_array
                    theta_array[track_number-1]=track_angle
                    range_array[track_number-1]=track_range
                    vel_array[track_number-1]=track_range_rate
                    x_pos = 2*math.cos(track_angle)*track_range*4
                    y_pos = 2*math.sin(track_angle)*track_range*4
                    cv2.circle(self.img, (self.width/2 + int(x_pos), self.height - int(y_pos)),int(10), (255, 255, 255))
                    font = cv2.FONT_HERSHEY_SIMPLEX
                    cv2.putText(self.img,str(track_number),(self.width/2-30+200, 50 + (10* track_number)), font, 0.5,(255,255,255),2)  
                    cv2.putText(self.img,str(track_range),(self.width/2+200,50 + (10* track_number)), font, 0.5,(255,255,255),2)
                    cv2.putText(self.img,str(track_range_rate),(self.width/2+40+200,50 + (10* track_number)), font, 0.5,(255,255,255),2)  
                    cv2.putText(self.img,str(track_lat_rate),(self.width/2+40+200+100,50 + (10* track_number)), font, 0.5,(255,255,255),2)  

        cv2.imshow("Radar", self.img)
        cv2.waitKey(1)
    

visualizer = RadarVisualizer()
def callback(data):
    object = json.loads(data.data)
    visualizer.update(object)
def SterVelcallback(msg1):   
    global Vehicle_speed
    Vehicle_speed = (msg1.x)

def theta_callback(msg):
    global end
    end = datetime.datetime.now()
    diff =end -start
    tim.append(diff.microseconds)
    tim.pop(0)
    global theta
    theta.append(msg.data)
    theta.pop(0)
    
    global dtheta_dt
    for i in range(0, 64):
        global value
        global tim
        value[i]=((theta[1][i]-theta[0][i])*1000000.0/(tim[1])+((theta[2][i]-theta[1][i])*1000000.0/(tim[2])-(theta[1][i]-theta[0][i])*1000000.0/(tim[1]))*(2*tim[1]+tim[0])/(tim[0]+tim[1]))
    dtheta_dt.append(value)
    dtheta_dt.pop(0)
    global start
    start = datetime.datetime.now()
        
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Udacity SDC Micro Challenge Radar viewer')
    parser.add_argument('--debug', action='store_true', default=False, help='display debug messages')
    args = parser.parse_args()
    debug = args.debug

    
    # In ROS, nodes are uniquely named. If two nodes with the same
    # node are launched, the previous one is kicked off. The
    # anonymous=True flag means that rospy will choose a unique
    # name for our 'listener' node so that multiple listeners can
    # run simultaneously.
    rospy.init_node('ros_esr_visualizer', anonymous=True)

    pub=rospy.Publisher('radar_angle',Float32MultiArray,queue_size=3)
    pub1=rospy.Publisher('radar_range',Float32MultiArray,queue_size=3)
    pub2=rospy.Publisher('radar_vel',Float32MultiArray,queue_size=3)
    rate =rospy.Rate(10)

    rospy.Subscriber("esr_front", std_msgs.msg.String, callback)
    rospy.Subscriber('/chatter_vel_sa', Pose2D, SterVelcallback)  ##Vehicle speed 
    rospy.Subscriber('/pub_angle', Float32MultiArray, theta_callback)
    while not rospy.is_shutdown():
        global append_array
        pub_array=Float32MultiArray(data=append_array[2]) #angle
        pub.publish(pub_array)
        pub_array1=Float32MultiArray(data=append_array[0]) #range 
        pub1.publish(pub_array1)
        pub_array2=Float32MultiArray(data=append_array[1]) #velocity
        pub2.publish(pub_array2)
        rate.sleep()
    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

