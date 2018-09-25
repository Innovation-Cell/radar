#!/usr/bin/python
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
#   import sys
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
global append_array
append_array=[1]*64
global dtheta_dt
dtheta_dt=[0]*64
#print theta
global tim
tim=[1]*3
global count
count=0
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
        start = datetime.datetime.now()
        for track_number in range(1, 65):
            


            if str(track_number)+'_track_range' in radarData:
                global count
                count = count + 1

                track_range = radarData[str(track_number)+'_track_range']
                track_range_rate=radarData[str(track_number)+'_track_range_rate']
                track_width=0.5*radarData[str(track_number)+'_track_width']   #0.5 is the scaling factor
                #print type(Vehicle_speed)
                track_lat_rate=0.25*radarData[str(track_number)+'_track_lat_rate']
                #print track_width
                if track_range_rate<=-Vehicle_speed-0.004 or track_range_rate>=-Vehicle_speed+0.004:

                    #print((track_number,  track_range,track_range_rate,track_width))
                    track_angle = (float(radarData[str(track_number)+'_track_angle'])+90.0)*math.pi/180
                    global append_array
                    append_array[track_number]=track_angle
                    #print append_array
                    x_pos = math.cos(track_angle)*track_range*4
                    y_pos = math.sin(track_angle)*track_range*4

                    cv2.circle(self.img, (self.width/2 + int(x_pos), self.height - int(y_pos)),int(5), (255, 255, 255))
                    font = cv2.FONT_HERSHEY_SIMPLEX
                    cv2.putText(self.img,str(track_number),(self.width/2-30+200, 50 + (10* track_number)), font, 0.5,(255,255,255),2)  
                    cv2.putText(self.img,str(track_range),(self.width/2+200,50 + (10* track_number)), font, 0.5,(255,255,255),2)
                    cv2.putText(self.img,str(track_range_rate),(self.width/2+40+200,50 + (10* track_number)), font, 0.5,(255,255,255),2)  
                    cv2.putText(self.img,str(track_lat_rate),(self.width/2+40+200+100,50 + (10* track_number)), font, 0.5,(255,255,255),2)  
            if count%12==0:
                #print count
                global theta
                global tim
                global append_array
                theta.append(append_array)
                theta.pop(0)
                global dtheta_dt
                for i in range(0, 64):
                    val=((theta[1][i]-theta[0][i])*1000.0/(tim[1])+((theta[2][i]-theta[1][i])*1000.0/(tim[2])-(theta[1][i]-theta[0][i])*1000.0/(tim[1]))/(tim[1]+tim[2]))
                    
                    if (theta[1][i])!=1 :
                        print theta[0][i]
                        print append_array[i]
                        print(theta[2][i]-theta[0][i])
                    print i
                dtheta_dt.append(val)
                dtheta_dt.pop(0)
                #print dtheta_dt
                if (track_number==64) :
                    end = datetime.datetime.now()
                    diff =end -start
                    p=((theta[1][track_number-1]-theta[0][track_number-1])*1000000000)
                    tim.append(diff.microseconds)
                    tim.pop(0)
                #print dtheta_dt

            
        cv2.imshow("Radar", self.img)
        cv2.waitKey(1)
    

visualizer = RadarVisualizer()
def callback(data):
    object = json.loads(data.data)
    visualizer.update(object)
def SterVelcallback(msg1):   
    global Vehicle_speed
    Vehicle_speed = (msg1.x)



    
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

    pub=rospy.Publisher('pub_angle',Float32MultiArray,queue_size=1)
    rate =rospy.Rate(10)

    rospy.Subscriber("esr_front", std_msgs.msg.String, callback)
    rospy.Subscriber('/chatter_vel_sa', Pose2D, SterVelcallback)  ##Vehicle speed 

    while not rospy.is_shutdown():
        global append_array
        pub_array=Float32MultiArray(data=append_array)
        pub.publish(pub_array)
        rate.sleep()
    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

