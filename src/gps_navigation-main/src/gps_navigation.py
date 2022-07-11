#!/usr/bin/python3
import rospy
from nav_msgs.msg import Odometry, Path
from geometry_msgs.msg import Point, Quaternion, Twist, TwistStamped, PoseStamped, PointStamped, Vector3
from sensor_msgs.msg import Imu, NavSatFix
from std_msgs.msg import Float64MultiArray,Bool
from math import *
from scipy.spatial.transform import Rotation as R
import numpy as np

class gps_navigation():
    
    def __init__(self):
        self.kp = 100
        self.forwardSpeed = 2.0
        self.goalPos = None # in lon lat degree
        rospy.init_node('gps_navigation',anonymous=True)
        self.odom_sub = rospy.Subscriber('/gx5/nav/odom',Odometry,self.navigate) # do navigation when odom is published
        self.goal_sub = rospy.Subscriber('/gps_navigation/goal',PoseStamped,self.setGoal) # for setting goal
        self.cmd_pub = rospy.Publisher('/cmd_vel/managed',Twist,queue_size=5) # for publishing drive commands
        self.goal_pub = rospy.Publisher('/gps_navigation/current_goal',PoseStamped,queue_size=5) # for publishing status of navigation (running/done)
        # publish status of navigation
        rate = rospy.Rate(10)
        self.lastmsg = PoseStamped()
        while not rospy.is_shutdown():
            msg = PoseStamped()
            # if navigation is off
            if self.goalPos is None:
                msg.pose.position.x = self.lastmsg.pose.position.x
                msg.pose.position.y = self.lastmsg.pose.position.y
                msg.pose.position.z = -1
            # if navigation is on
            else:
                msg.pose.position.x = self.goalPos[0]
                msg.pose.position.y = self.goalPos[1]
                msg.pose.position.z = 1
            self.goal_pub.publish(msg)
            self.lastmsg = msg
            rate.sleep()
    
    def setGoal(self,data):
        if np.isnan(data.pose.position.x) or np.isnan(data.pose.position.y):
            self.lastmsg.pose.position.x = float('nan')
            self.lastmsg.pose.position.y = float('nan')
        if data.pose.position.z < 0:
            self.goalPos = None
        else:
            self.goalPos = np.array([data.pose.position.x,data.pose.position.y])

    def navigate(self,data):
        if self.goalPos is None: # don't need to do anything if no goal set
            return
        # calculate robot position and heading
        robotPos = np.array([data.pose.pose.position.x,data.pose.pose.position.y])
        quat = data.pose.pose.orientation
        r = R.from_quat([quat.x,quat.y,quat.z,quat.w])
        xVec = r.as_dcm()[:,0]
        robotHeading = np.mod(atan2(xVec[1],xVec[0])+np.pi/3.0,2*np.pi)
        # run navigation
        relGoal = self.goalPos-robotPos
        print('----Navigating----')
        print('relative goal: '+ str(relGoal))
        relGoal[1] = relGoal[1]*np.cos(robotPos[0]*np.pi/180)
        print('relative goal scaled: ' +str(relGoal))
        if np.linalg.norm(relGoal)<1e-6:
            self.goalPos=None
            print('----Finished Navigation----')
        goalAngle = np.mod(atan2(relGoal[1],relGoal[0]),2*np.pi)
        print('relative goal angle: %.2f degrees' %(goalAngle*180/np.pi))
        print('robot heading angle: %.2f degrees' %(robotHeading*180/np.pi))
        yaw_diff = np.mod(goalAngle - robotHeading,2*np.pi)
        if yaw_diff > np.pi:
            yaw_diff = yaw_diff-2*np.pi
        print("Yaw Difference: %.2f radians" %(yaw_diff))
        cmd_msg = Twist()
        cmd_msg.linear.x = self.forwardSpeed#*np.cos(yaw_diff)
        cmd_msg.angular.z = self.kp*yaw_diff
        self.cmd_pub.publish(cmd_msg)

if __name__ == '__main__':
    gps_navigation()
