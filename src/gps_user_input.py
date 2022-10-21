#!/usr/bin/python3
import rospy
import wget
import sys
import os
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import pyqtgraph as pg
from pyqtgraph.Qt import QtCore, QtGui, QtWidgets
import numpy as np
import math
from scipy.spatial.transform import Rotation as R
from nav_msgs.msg import Odometry, Path
from geometry_msgs.msg import Point, Quaternion, Twist, TwistStamped, PoseStamped, PointStamped, Vector3
import pandas as pd
import csv
from std_msgs.msg import String
from sensor_msgs.msg import NavSatFix
from microstrain_inertial_msgs.msg import FilterHeading
sys.path.insert(0,"/home/cvx/catkin_ws/src/pxrf/scripts")
from plot import generate_plot
from gps_user_location import read_location

#testing
lat_set = 0
lon_set = 0
zoom_set = 0
width_set = 0
height_set = 0
#gps_fidelity = 1.0


#convert from deg to tile number
def deg2num(lat_deg, lon_deg, zoom):
    lat_rad = math.radians(lat_deg)
    n = 2.0 ** zoom
    xtile = ((lon_deg + 180.0) / 360.0 * n)
    ytile = ((1.0 - math.asinh(math.tan(lat_rad)) / math.pi) / 2.0 * n)
    return (xtile, ytile)

#convert from tile number to deg
def num2deg(xtile, ytile, zoom):
    n = 2.0 ** zoom
    lon_deg = xtile / n * 360.0 - 180.0
    lat_rad = math.atan(math.sinh(math.pi * (1 - 2 * ytile / n)))
    lat_deg = math.degrees(lat_rad)
    return (lat_deg, lon_deg)

# download the gps images from mapbox api and store them locally
class satelliteImage(object):
    def __init__(self,coord=(0,0),dim=(0,0),zoom=0,loadFile=None):
        if loadFile is None:
            print("downloading satellite images")
            self.downloadAllTiles(coord,dim,zoom)
    def downloadAllTiles(self,coord,dim,zoom):
        x,y = deg2num(coord[0],coord[1],zoom)
        xs = np.arange(-dim[0],dim[0]+1) + round(x)
        ys = np.arange(-dim[1],dim[1]+1) + round(y)
        completeTile = None
        for i in range(len(xs)):
            verticalTile = None
            for j in range(len(ys)):
                print('loading map tile ',j+i*len(ys),'/',len(xs)*len(ys))
                tile = self.getMapTile(zoom,xs[i],ys[j])
                verticalTile = tile if verticalTile is None else np.concatenate((verticalTile,tile),axis=0)
            completeTile = verticalTile if completeTile is None else np.concatenate((completeTile,verticalTile),axis=1)
        print('\r')
        self.tile = completeTile
        self.x = xs[0]
        self.y = ys[0]
        self.zoom = zoom
    def pixel2Coord(self,pix):
        x = pix[0]/512.0 + self.x
        y = pix[1]/512.0 + self.y
        return num2deg(x,y,self.zoom)
    def coord2Pixel(self,coord):
        x,y = deg2num(coord[0],coord[1],self.zoom)
        x = round(512.0*(x-self.x))
        y = round(512.0*(y-self.y))
        return x,y
        
    def getMapTile(self,z,x,y):
        baseMapLink = "https://api.mapbox.com/styles/v1/mapbox/satellite-v9/tiles/512/%s/%s/%s?access_token=pk.eyJ1Ijoic2Vhbmp3YW5nIiwiYSI6ImNrb2c3d2M5bjBhcHcyb2xsd2VyNXdkNnEifQ.5uaSXmSX1HdSAlEf4LReNg"
        mapLink = baseMapLink%(z,x,y)
        mapDirectory = 'gps_navigation_satellite_tiles'
        if not os.path.isdir(mapDirectory):
            os.mkdir(mapDirectory)
        mapFile = os.path.join(mapDirectory,'satellite_%d_%d_%d'%(x,y,z))
        if not os.path.isfile(mapFile):
            wget.download(mapLink,out=mapFile)
        tile = np.asarray(mpimg.imread(mapFile))
        return tile

#record the click on the map
class plotWithClick(pg.PlotItem):
    def mouseClickEvent(self,ev):
        xClick = self.getViewBox().mapSceneToView(ev.scenePos()).x()
        yClick = self.getViewBox().mapSceneToView(ev.scenePos()).y()
        self.addROIPoint([xClick,yClick])

class PolyLineROI_noHover(pg.PolyLineROI):
    def hoverEvent(self,ev):
        pass

class gps_user_input(object):
    def __init__(self):
        self.prev_lat = 0
        self.prev_lon = 0
        self.prev_heading = 0
        def prevGoal():
            self.changeGoal(changeDir=-1)
        def nextGoal():
            self.changeGoal(changeDir=1)
        def clearHistory():
            self.setHistory(clear = True)

        rospy.init_node('gps_user_input',anonymous=True)
        # load map
        try:
           # lat = rospy.get_param('~lat')
           # lon = rospy.get_param('~lon')
           # self.prev_lat = lat
           # self.prev_lon = lon
           # height = rospy.get_param('~height')
           # width = rospy.get_param('~width')
           # zoom = rospy.get_param('~zoom')
           lat = float(lat_set)
           lon = float(lon_set)
           self.prev_lat = float(lat_set)
           self.prev_lon = float(lon_set)
           height = int(height_set)
           width = int(width_set)
           zoom = int(zoom_set)
        except:
            print("we can't load that location")
            QtWidgets.QApplication.instance().exec_()    
        #pxrf control
        self.pxrfRunning = False
        
        #speed display
        self.highSpeed = True
        #lat = 36.701774
        #lon = -105.497102
        #height = 5
        #width = 5
        #zoom = 20
        #get the map
        print([lat, lon, height, width, zoom])
        self.satMap = satelliteImage(coord=(lat,lon),dim=(width,height),zoom=zoom)
        # init widget
        self.widget = pg.LayoutWidget()
        # add plot for map
        satGUI = pg.GraphicsLayoutWidget()
        self.widget.addWidget(satGUI,row=0,col=0,colspan=8)
        satGUI.setBackground('w')
        self.p = plotWithClick()
        satGUI.addItem(self.p)
        # show satellite image
        pg.setConfigOption('imageAxisOrder', 'row-major')
        img = pg.ImageItem(self.satMap.tile)
        self.p.addItem(img)
        self.p.showAxes(False)
        self.p.setAspectLocked()
        self.p.invertY()

        # add arrow to show robot
        self.robotArrow = pg.ArrowItem(headLen=40,tipAngle=30,brush='r')
        self.p.addItem(self.robotArrow)
        # init ROI for editing path
        self.pathRoi = PolyLineROI_noHover([], closed=False)
        self.p.addItem(self.pathRoi)
        # init plot for path
        self.pathPlotPoints = []
        self.pathGPS = []
        self.heading = 0
        self.pathPlot = self.p.plot(symbolBrush=(255,0,255))
        self.currentGoalMarker = self.p.plot(symbolBrush=(0,0,255))
        self.pathIndex = 0
        # interaction for adding path points
        self.p.addROIPoint = self.addROIPoint
        # robot's history (path measured by gps)
        self.historyPoints = []
        self.historyPlot = self.p.plot(pen=pg.mkPen('g',width=3))
        self.setHistory()
        # add buttons
        clearHistoryBtn = QtWidgets.QPushButton('Clear History')
        clearHistoryBtn.clicked.connect(clearHistory)
        clearPathBtn = QtWidgets.QPushButton('Clear Path')
        clearPathBtn.clicked.connect(self.clearPath)
        self.editPathBtn = QtWidgets.QPushButton('Edit Path')
        self.editPathMode = False
        self.editPathBtn.clicked.connect(self.editPath)
        loadPathFileBtn = QtWidgets.QPushButton('Load Path')
        loadPathFileBtn.clicked.connect(self.loadPathFile)
        savePathBtn = QtWidgets.QPushButton('Save Path')
        savePathBtn.clicked.connect(self.savePath)
        self.startPauseBtn = QtWidgets.QPushButton('Start Navigation')
        self.startPauseStatus = False
        self.startPauseBtn.clicked.connect(self.startPause)
        prevGoalBtn = QtWidgets.QPushButton('Prev Goal')
        prevGoalBtn.clicked.connect(prevGoal)
        nextGoalBtn = QtWidgets.QPushButton('Next Goal')
        nextGoalBtn.clicked.connect(nextGoal)
        
        #second row of buttons
        self.boundaryBtn = QtWidgets.QPushButton('Draw Boundary')
        self.boundaryStatus = False
        self.boundaryBtn.clicked.connect(self.draw_boundary)
        self.bdBtn = QtWidgets.QPushButton('Boustrophedon')
        self.bdStatus = False
        self.bdBtn.clicked.connect(self.boustrophedon)
        self.adaptiveBtn = QtWidgets.QPushButton('Adaptive')
        self.adaptiveStatus = False
        self.adaptiveBtn.clicked.connect(self.adaptive)
        self.widget.addWidget(self.boundaryBtn, row = 3, col = 0, colspan = 1)
        self.widget.addWidget(self.bdBtn, row = 3, col = 1, colspan = 1)
        self.widget.addWidget(self.adaptiveBtn, row = 3, col = 2, colspan = 1)
        self.stopBtn = QtWidgets.QPushButton('STOP ROBOT')
        self.stopStatus = False
        self.stopBtn.setStyleSheet("background-color : red")
        self.stopBtn.clicked.connect(self.stop)
        self.widget.addWidget(self.stopBtn, row = 3, col = 6, colspan = 2)
        self.pxrfBtn = QtWidgets.QPushButton('Sample')
        self.pxrfStatus = False
        self.pxrfBtn.clicked.connect(self.pxrf)
        self.widget.addWidget(self.pxrfBtn, row = 3, col = 3, colspan = 1)
        #text widget

        self.statusGPS = QtWidgets.QLineEdit()
        self.statusGPS.setText('GPS Connecting')
        self.statusGPS.setReadOnly(True)
        
        self.statusNav = QtWidgets.QLineEdit()
        self.statusNav.setText('Manual Mode')
        self.statusNav.setReadOnly(True)
        
        self.statusPxrf = QtWidgets.QLineEdit()
        self.statusPxrf.setText('Ready to collect')
        self.statusPxrf.setReadOnly(True)
       
        self.statusSpeed = QtWidgets.QLineEdit()
        self.statusSpeed.setText('High Speed')
        self.statusSpeed.setReadOnly(True)

        #self.status = pg.TextItem('')
        #self.status.setColor(pg.Qt.QtGui.QColor("red"))
        #self.status.setText("testing")
        #self.widget.addWidget(self.status, row = 1, col = 1)
        self.widget.addWidget(clearHistoryBtn,row=2,col=0)
        self.widget.addWidget(clearPathBtn,row=2,col=1)
        self.widget.addWidget(self.editPathBtn,row=2,col=2)
        self.widget.addWidget(loadPathFileBtn,row=2,col=3)
        self.widget.addWidget(savePathBtn,row=2,col=4)
        self.widget.addWidget(self.startPauseBtn,row=2,col=5, colspan = 1)
        self.widget.addWidget(prevGoalBtn,row=2,col=6)
        self.widget.addWidget(nextGoalBtn,row=2,col=7)
        self.widget.addWidget(self.statusGPS, row = 1, col = 0, colspan = 5)
        self.widget.addWidget(self.statusNav, row = 1, col = 5, colspan = 1)
        self.widget.addWidget(self.statusSpeed, row = 1, col = 6, colspan = 1)
        self.widget.addWidget(self.statusPxrf, row = 1, col = 7, colspan = 1)
        #self.widget.addLabel(text = "Mode: "+ self.statusNav, row = 1, col = 0, colspan = 2 )
        #self.widget.addLabel(text = "GPS: " + self.statusGPS, row = 1, col = 3, colspan = 2 )
        #self.widget.addLabel(text = "PXRF status: " + self.statusPxrf,  row = 1,  col = 5, colspan = 2)
        
        # ros sub pub
        self.odom_sub = rospy.Subscriber('/nav/odom',Odometry,self.readOdom) # plotRobotPosition
        self.navigation_sub = rospy.Subscriber('/gps_navigation/current_goal',PoseStamped,self.readNavigation) # get status of navigation controller
        self.goal_pub = rospy.Publisher('/gps_navigation/goal',PoseStamped,queue_size=5)
        self.location_sub = rospy.Subscriber('/gnss1/fix', NavSatFix, self.location)
        self.set_heading = rospy.Subscriber('/nav/heading', FilterHeading, self.set_heading)
        self.pubCTRL = rospy.Publisher('pxrf_gui', String, queue_size = 2)
        self.subCTRL = rospy.Subscriber('pxrf_response', String, self.pxrfListener)
        self.speedRead = rospy.Subscriber('/motor_controller/command', Twist, self.speedListener)
        self.stopCommand = rospy.Publisher('/cmd_vel/managed', Twist, queue_size = 5)
    
    def speedListener(self, msg):
        if msg.angular.x == 1:
            self.highSpeed = True
            self.statusSpeed.setText("High Speed")
        elif msg.angular.x == -1:
            self.highSpeed = False
            self.statusSpeed.setText("Low Speed")


    def pxrfListener(self, msg):
        print(msg.data)
        if  msg.data == "201":
            self.pxrfRunning = False
            self.statusPxrf.setText('Ready to collect')
            self.pxrfStatus = False
            self.pxrfBtn.setText("Sample")
            self.pubCTRL.publish("stop")
            #generate_plot()


    #This function sets the heading of the robot
    def set_heading(self, data):
        #if abs(self.prev_heading - self.heading) < 0.5:
        #    self.heading = data.heading_rad
        #else:
        #    self.heading = self.prev_heading
        if(data.heading_rad == 0 and data.heading_deg == 0):
            return
        self.heading = data.heading_rad 

        #self.prev_heading = self. heading
        # This function adds points to roi (when user is editing path)
    def addROIPoint(self,point):
        if self.editPathMode:
            points = [[handle['pos'].x(),handle['pos'].y()] for handle in self.pathRoi.handles]
            points.append(point)
            self.pathRoi.setPoints(points)
    
    # This function converts the current path from gps coordinates to pixels
    def pathGPS2points(self):
        self.pathPlotPoints = []
        for gpsPoint in self.pathGPS:
            point = list(self.satMap.coord2Pixel(gpsPoint[0:2]))
            self.pathPlotPoints.append(point)

    # This fuction converts the current path from pixels to gps coordinates
    def pathPoints2GPS(self):
        self.pathGPS = []
        for point in self.pathPlotPoints:
            gpsPoint = list(self.satMap.pixel2Coord(point))
            gpsPoint.append(1)
            self.pathGPS.append(gpsPoint)
    
    # This function clears robot's history path
    def setHistory(self,clear=False):
        if clear:
            self.historyPoints=[]
        self.historyPlot.setData(x=[point[0] for point in self.historyPoints],y=[point[1] for point in self.historyPoints])
    
    # This function clears the current path
    def clearPath(self):
        self.pathRoi.setPoints([])
        self.pathPlotPoints= []
        self.pathGPS = []
        self.pathPlot.setData(x=[],y=[])
        self.updateGoalMarker()
        self.startPauseStatus = False
        self.startPauseBtn.setText('start navigation')

    # This function turns on/off editing mode
    def editPath(self):
        self.editPathMode = not self.editPathMode
        if self.editPathMode:
            self.editPathBtn.setText('Set Path')
            self.pathRoi.setPoints([])
            for point in self.pathPlotPoints:
                self.addROIPoint(point)
        else:
            self.editPathBtn.setText('Edit Path')
            self.pathPlotPoints = [[handle['pos'].x(),handle['pos'].y()] for handle in self.pathRoi.handles]
            self.pathPoints2GPS()
            self.pathPlot.setData(x=[point[0] for point in self.pathPlotPoints],y=[point[1] for point in self.pathPlotPoints])
            self.pathRoi.setPoints([])
            self.updateGoalMarker()
    
    # This function loads path from csv file chosen by user
    def loadPathFile(self):
        fn = str(pg.QtGui.QFileDialog.getOpenFileName()[0])
        #pathFn = easygui.fileopenbox()
        if fn =='':
            return
        if self.editPathMode:
            self.editPath()
        self.clearPath()
        csvData = pd.read_csv(fn)
        csvData = np.array(csvData.iloc[:,:])
        for i in range(csvData.shape[0]):
            toStop = True
            if csvData.shape[1]>2:
                toStop = bool(csvData[i,2])
            gpsPoint = [csvData[i,0],csvData[i,1],toStop]
            self.pathGPS.append(gpsPoint)
        self.pathGPS2points()
        self.pathPlot.setData(x=[point[0] for point in self.pathPlotPoints],y=[point[1] for point in self.pathPlotPoints])
        self.changeGoal(reset=True)

    # this function saves the current path as csv file
    def savePath(self):
        fn = str(pg.QtGui.QFileDialog.getSaveFileName()[0])
        csvFile = open(fn,'w',newline='')
        csvWriter = csv.writer(csvFile,delimiter=',')
        csvWriter.writerow(['lat','lon','stop'])
        for gpsPoint in self.pathGPS:
            csvWriter.writerow(gpsPoint)

    # This function starts/ pauses the navigation
    def startPause(self):
        if (len(self.pathGPS) == 0):
            return
        self.startPauseStatus = not self.startPauseStatus
        if self.startPauseStatus:
            self.startPauseBtn.setText('Pause Navigation')
        elif self.pathIndex == 0:
            self.startPauseBtn.setText('Start Navigation')
        else:
            self.startPauseBtn.setText('Continue Navigation')

    # This function changes the goal to another waypoint on path
    def changeGoal(self,reset=False,changeDir=1):
        self.pathIndex = self.pathIndex + changeDir
        if self.pathIndex < 0:
            self.pathIndex+=len(self.pathPlotPoints)
        if reset or self.pathIndex >= len(self.pathPlotPoints):
            self.pathIndex = 0
            if self.startPauseStatus:
                self.startPause()
        self.updateGoalMarker()

    # This function updates the marked goal on the path
    def updateGoalMarker(self):
        if self.pathIndex < len(self.pathPlotPoints):
            point = self.pathPlotPoints[self.pathIndex]
            self.currentGoalMarker.setData(x=[point[0]],y=[point[1]])
        else:
            self.currentGoalMarker.setData(x=[],y=[])

    # This function is called by subscriber of gps sensor
    def readOdom(self,data):
        if (abs(data.pose.pose.position.x - self.prev_lat) < 2 or abs(data.pose.pose.position.y - self.prev_lon) < 2):
            lat = data.pose.pose.position.x
            #print("lat" + str(lat))
            lon = data.pose.pose.position.y
        else:
            lat = self.prev_lat
            lon = self.prev_lon

        #calculate heading based on gps coordinates 
        pixX,pixY = self.satMap.coord2Pixel([lat,lon])
        prevpixX,prevpixY = self.satMap.coord2Pixel([self.prev_lat, self.prev_lon])
        #robotHeading = calcHeading * (1 - gps_fidelity) + self.heading * gps_fidelity
        robotHeading = self.heading
        #print("robotHeading "+ str(robotHeading))
        quat = data.pose.pose.orientation
        r = R.from_quat([quat.x,quat.y,quat.z,quat.w])
        #xVec = r.as_dcm()[:,0]
        #robotHeading = np.mod(math.atan2(xVec[1],xVec[0])+np.pi/3.0,2*np.pi)
        #robotHeading = self.heading #math.atan2(xVec[0],xVec[1])
        if not self.robotArrow is None:
            self.robotArrow.setStyle(angle = robotHeading*180.0/np.pi + 90.0)
            self.robotArrow.setPos(pixX,pixY)
            self.robotArrow.update()
        self.historyPoints.append([pixX,pixY])
        self.setHistory()
        self.prev_lat = lat
        self.prev_lon = lon
        self.prev_heading = robotHeading
    
    # This function updates the value of longitude and latitude information
    def location(self, data):
        print("location")
        if(data.longitude != 0.0 and data.latitude != 0.0):
            print("found")
            self.longitude = data.longitude
            self.latitude = data.latitude
            self.statusGPS.setText("lon: " + str(round(self.longitude,4)) + " " +"lat: " + str(round(self.latitude, 4)) )
        else:
            self.statusGPS.setText("GPS connecting")
    #this function checks status of navigation controller
    def readNavigation(self,data):
        if self.startPauseStatus:
            self.statusNav.setText("Automatic navigation")
            currNavGoal = np.array([data.pose.position.y,data.pose.position.x])
            desNavGoal = np.array(self.pathGPS[self.pathIndex][0:2])
            onCurrentGoal = np.linalg.norm(desNavGoal-currNavGoal) < 1e-4
            navFinished = data.pose.position.z < 0
            if onCurrentGoal and navFinished:
                if self.pathGPS[self.pathIndex][2]:
                    self.startPause()
                self.changeGoal()
            else:
                msg = PoseStamped()
                msg.pose.position.y = desNavGoal[0]
                msg.pose.position.x = desNavGoal[1]
                self.goal_pub.publish(msg)
        else:
            # stop the navigation
            self.statusNav.setText("Manual")
            msg = PoseStamped()
            msg.pose.position.x = float('nan')
            msg.pose.position.y = float('nan')
            msg.pose.position.z = -1
            self.goal_pub.publish(msg)
    def boustrophedon(self):
        return
    def draw_boundary(self):
        return
    def adaptive(self):
        return
    def stop(self):
        self.startPauseStatus = 0
        command = Twist()
        command.linear.x = 0
        command.linear.y = 0
        command.linear.z = 0
        command.angular.x = 0
        command.angular.y = 0
        command.angular.z = 0
        self.stopCommand.publish(command)
        return
    def pxrf(self):
        if not self.pxrfStatus:
            print("condition 1")
            self.statusPxrf.setText("Collecting")
            self.pxrfRunning = True
            self.pxrfBtn.setText("STOP pxrf")
            self.pubCTRL.publish("start")
            self.pxrfStatus = True
        else:
            print("condition 2")
            self.statusPxrf.setText("Ready to collect")
            self.pxrfRunning = False
            self.pxrfBtn.setText("Sample")
            self.pubCTRL.publish("stop")
            self.pxrfStatus = False
        return
if __name__ == '__main__':
    location_input = read_location()
    lat_set, lon_set, zoom_set, width_set, height_set = location_input[1:6]
    print([lat_set, lon_set, zoom_set, width_set, height_set])
    app = QtWidgets.QApplication([])
    mw = QtWidgets.QMainWindow()
    gps_node = gps_user_input()
    mw.setCentralWidget(gps_node.widget)
    mw.show()
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
        QtWidgets.QApplication.instance().exec_()
