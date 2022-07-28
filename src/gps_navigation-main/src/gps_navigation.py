#!/usr/bin/python3
import rospy
from nav_msgs.msg import Odometry, Path
from geometry_msgs.msg import Point, Quaternion, Twist, TwistStamped, PoseStamped, PointStamped, Vector3
from sensor_msgs.msg import Imu, NavSatFix
from std_msgs.msg import Float64MultiArray,Bool
from math import *
from scipy.spatial.transform import Rotation as R
from scipy import signal, linalg
import numpy as np

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

#The output should be normalized



class gps_navigation():
    
    def __init__(self):
        #init parameters needed for waypoint nav
        self.X = 0
        self.Y = 0
        self.xdot = 0
        self.ydot = 0
        self.psi = 0
        self.psidot = 0
        self.t_prev = 0 
        self.t_curr = 0
        self.dt = 0
        self.prev = rospy.get_rostime()
        
        #init controller
        self.controller = PIDcontroller()

        self.goalPos = None # in lon lat degree
        rospy.init_node('gps_navigation',anonymous=True)
        self.odom_sub = rospy.Subscriber('/nav/odom',Odometry,self.navigate) # do navigation when odom is published
        self.goal_sub = rospy.Subscriber('/gps_navigation/goal',PoseStamped,self.setGoal) # for setting goal
        self.cmd_pub = rospy.Publisher('/cmd_vel/managed',Twist,queue_size=5) # for publishing drive commands
        #need a subscriber to find the yaw
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
        self.X = data.pose.pose.position.x
        self.Y = data.pose.pose.position.y
        self.xdot = data.twist.twist.linear.x
        self.ydot = data.twist.twist.linear.y
        self.psidot = data.twist.twist.angular.z
        # calculate robot position and heading
        robotPos = np.array([data.pose.pose.position.x,data.pose.pose.position.y])
        quat = data.pose.pose.orientation
        r = R.from_quat([quat.x,quat.y,quat.z,quat.w])
        xVec = r.as_dcm()[:,0]
        robotHeading = np.mod(atan2(xVec[1],xVec[0])+np.pi/3.0,2*np.pi)
        self.psi = robotHeading
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
        current_time = rospy.get_rostime()
        self.dt = current_time - self.prev
        angle, speed = self.controller.update(self, self.goalPos, self.dt, self.X, self.Y, self.xdot, self.ydot, self.psidot)
        cmd_msg = Twist()
        cmd_msg.linear.x = speed
        cmd_msg.angular.z = angle 
        self.cmd_pub.publish(cmd_msg)
        self.prev = current_time
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

    def update(self, goal, psi, dt, X, Y, xdot, ydot, psidot):
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
        angle_desire = np.arctan2((goal[0] - Y),(goal[1] - X))
        error_angle = wrapTopi(angle_desire - psi)

        error_angle_cum = error_angle * dt + error_angle_cum
        error_angle_diff = (error_angle - error_angle_prev) / dt
        error_angle_prev = error_angle
        delta = (P_angle * error_angle + I_angle * error_angle_cum + D_angle * error_angle_diff)

        return delta,throttle

class LQRController():
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
        self.error1_prev = 0
        self.error2_prev = 0
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
        e1 = point #this is the next point
        e1_dot = (e1 - error1_prev) / dt
        e2 = wrapTopi(-angle_desire + psi)
        e2_dot = (e2 - error2_prev ) / dt
        A = np.matrix([[0, 1, 0, 0], [0, -(4 * ca / (m * xdot)), (4 * ca / m), -(2 * ca * (lf - lr) / (m * xdot))], [0, 0, 0, 1], [0, -(2 * ca * (lf - lr) / (z * xdot)), (2 * ca * (lf - lr) / Z), -(2 * ca * (lf ** 2 + lr ** 2)) / (Z * xdot), 0]])
        B = np.matrix([[0 , 0], [(2 * ca / m), 0], [0, 0], [(2 * ca * lf / Z), 0]])
        C = np.identity(4)
        D = 0 
        d_system = signal.cont2discrete((A, B, C, D), dt)
        A_dis = d_system[0]
        B_dis = d_system[1]

        #Tunable
        Q = np.matrix([[0.1, 0, 0, 0],[0, 0.1, 0, 0],[0, 0, 20, 0],[0, 0, 0, 6]])
        R = np.matrix([[1,0],[0,2]])
        S = np.matrix(linalg.solve_discrete_are(A_dis, B_dis, Q, R))
        K = np.matrix(linalg.inv(B_dis.T@S@B + R) @ (B_dis.T@))
        error_angle_cum = error_angle * dt + error_angle_cum
        error_angle_diff = (error_angle - error_angle_prev) / dt
        error_angle_prev = error_angle
        delta = (P_angle * error_angle + I_angle * error_angle_cum + D_angle * error_angle_diff)

        return delta,throttle


if __name__ == '__main__':
    gps_navigation()
