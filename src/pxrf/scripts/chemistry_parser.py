#!/usr/bin/env python3

import csv
import time
import rospy
from std_msgs.msg import String
from pxrf.msg import PxrfMsg
import sys
sys.path.insert(0,"/home/cvx/catkin_ws/src/pxrf/scripts")
from sensor_msgs.msg import NavSatFix
from plot import generate_plot

class CHEMISTRY_PARSER:
    def __init__(self):

        self.dailyId = -1
        self.testId = -1
        self.testDateTime = ""
        self.chemistry = ""

        self.testStopped = False
        self.longitude = 0
        self.latitude = 0
        self.location = ""
        # initialize node
        rospy.init_node('chemistry_parser', anonymous=True)
        print("Parser started")
        # Subscriber
        rospy.Subscriber("pxrf_data", PxrfMsg, self.writeData)
        rospy.Subscriber("pxrf_response", String, self.listener)
        rospy.Subscriber("gps",NavSatFix,self.gps)
        # spin
        rospy.spin()

    def listener(self, msg):
        if msg.data == "201": # test stopped response
            self.testStopped = True
            print("Test complete")
            
    def gps(self,msg):
        if (msg.longitude != None and msg.latitude != None):
            self.longitude = msg.longitude
            self.latitude = msg.latitude
	
    def writeData(self, msg):
        self.dailyId = msg.dailyId
        self.testId = msg.testId
        self.testDateTime = msg.testDateTime
        self.chemistry = msg.chemistry
        self.location = "Lon: " + str(self.longitude) + " Lat: " + str(self.latitude)
        if self.testStopped == True:
            s = self.chemistry
            s = s.strip()
            s = s.replace(" ", "") # remove whitespace
            s = s.replace("\"","") # remove random backslashes
            s = s.replace("\\","") # remove quotes
            s = s.replace("[","") # remove array beginning
            s = s.replace("]","") # remove array ending
            s = s.replace("{", "")
            s = s.replace("}","")
            s = s.replace("\n","")
            s = s.replace("concentration:","")
            s = s.replace("elementName:","")
            s = s.replace("error:","")
            arr = s.split(",")

            header = [self.dailyId, self.testId, self.testDateTime,self.location]
            concentration = []
            element = []
            error = []

            for i in range(0, len(arr)):
                if (i % 3 == 0):
                    arr[i] = float(arr[i])
                    concentration.append(arr[i])
                elif (i % 3 == 1):
                    # string element name
                    element.append(arr[i])
                else: # i % 3 == 2
                    arr[i] = float(arr[i])
                    error.append(arr[i])

            with open('/home/cvx/catkin_ws/src/pxrf/scripts/chemistry.csv', 'a') as f:
                writer = csv.writer(f)
                writer.writerow(header)
                writer.writerow(element)
                writer.writerow(concentration)
                writer.writerow(error)
                print("Chemistry parsing complete")
                self.testStopped = False
            time.sleep(2)
            generate_plot()

if __name__ == '__main__':
    CHEMISTRY_PARSER()
