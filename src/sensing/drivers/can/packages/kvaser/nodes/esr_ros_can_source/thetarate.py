import math
import numpy as np
import argparse
import time
import numpy as np
import rospy
import datetime
import struct
import json
import std_msgs
from std_msgs.msg import String,Float32,Float32MultiArray,MultiArrayLayout,MultiArrayDimension
from geometry_msgs.msg import Pose2D
global theta
theta = [[0]*64]*3
global dtheta_dt
dtheta_dt=[0]*64
global tim
tim=[1]*3
global count
count=0
def theta_callback(msg):
    global theta
    theta.append(msg.data)
    theta.pop(0)
    global tim
    global dtheta_dt
    for i in range(0, 64):
        val=((theta[1][i]-theta[0][i])*1000.0/(tim[1])+((theta[2][i]-theta[1][i])*1000.0/(tim[2])-(theta[1][i]-theta[0][i])*1000.0/(tim[1]))/(tim[1]+tim[2]))
        
        if (theta[1][i])!=1 :
            print theta[0][i]
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


rospy.Subscriber('/pub_angle', Float32MultiArray, theta_callback)


