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
#to do: get the time step

class PIDController():
    def __init__(self,traj):
        #try to get the vehicle information
        try:
            self.lr = rospy.get_param('~lr')
            self.lf = rospy.get_param('~lf')
            self.m = rospy.get_param('~m')
            self.ca = rospy.get_param('~ca')
            self.g = rospy.get_param('~g')

        except:
            print("couldn't find yaml file. load default parameters")
            self.lr = 0.2
            self.lf = 0.3
            self.ca = 80
            self.g  = 9.81
            self.m = 4
        self.error_angle_cum = 0
        self.error_angle_prev = 0
        self.error_dist_cum = 0
        self.error_dist_prev = 0

    def update(self, traj):
        traj = self.traj
        lr = self.lr
        lf = self.lf
        ca = self.ca
        m = self.m
        g = self.g
        error_dist_cum = self.error_dist_cum
        error_dist_prev = self.error_dist_prev
        error_angle_cum = self.error_angle_cum
        error_angle_prev = self.error_angle_prev
        # PID Tuning parameters
        P_dist = 0.8
        I_dist = 0.6
        D_dist = 0.2
        P_angle = 0.6
        I_angle = 0.6
        D_angle = 0.4
        V_desire = 10

        #get updated states, need to be implemented
        #dt time step

        #Lateral Controller
        error_dist = V_desire - vdot
        error_dist_cum = error_dist * dt + error_dist_cum
        error_dist_diff = (error_dist - error_dist_prev) / dt
        error_dist_prev = error_dist
        throttle = (P_dist * error_dist + I_dist * error_dist_cum + D_dist * error_dist_diff)

        #Longitudal Controller

        #get the next point to go = to do
        angle_desire = np.arctan2((traj[index][1] - Y),(traj[index][0] - X))
        error_angle = wrapTopi(angle_desire - psi)

        error_angle_cum = error_angle * dt + error_angle_cum
        error_angle_diff = (error_angle - error_angle_prev) / dt
        error_angle_prev = error_angle
        delta = (P_angle * error_angle + I_angle * error_angle_cum + D_angle * error_angle_diff)

        return delta,throttle

    def wrapTopi(angle):
        return (angle + np.pi) % (2 * np.pi) - np.pi
    def get_traj(filename):
        with open(filename) as f:
            lines = f.readlines()
            traj = np.zeros((len(lines),2))
            for idx, line in enumerate(lines):
                pos = line.split(",")
                traj[idx,0] = pos[0]
                traj[idx,1] = pos[1]
        return traj
        
    def next_node(X,Y,traj):
        current = np.array([X,Y])
        traj = np.asarray(traj)
        dist = point - traj
        squared = np.sum(dist ** 2, axis = 1)
        minIndex = np.argmin(squared)
        return traj[minIndex]


        #wrap to pi function - to do
if __name__ == '__main__':
    gps_navigation()
