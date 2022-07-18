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

#testing
lat_set = 31.845095
lon_set = -101.988534
zoom_set = 20
width_set = 5
height_set = 5
 
def deg2num(lat_deg, lon_deg, zoom):
    lat_rad = math.radians(lat_deg)
    n = 2.0 ** zoom
    xtile = ((lon_deg + 180.0) / 360.0 * n)
    ytile = ((1.0 - math.asinh(math.tan(lat_rad)) / math.pi) / 2.0 * n)
    return (xtile, ytile)

def num2deg(xtile, ytile, zoom):
    n = 2.0 ** zoom
    lon_deg = xtile / n * 360.0 - 180.0
    lat_rad = math.atan(math.sinh(math.pi * (1 - 2 * ytile / n)))
    lat_deg = math.degrees(lat_rad)
    return (lat_deg, lon_deg)

class satelliteImage(object):
    def __init__(self,coord=(0,0),dim=(0,0),zoom=0,loadFile=None):
        if loadFile is None:
            self.downloadAllTiles(coord,dim,zoom)
    def downloadAllTiles(self,coord,dim,zoom):
        x,y = deg2num(coord[0],coord[1],zoom)
        xs = np.arange(-dim[0],dim[0]+1) + round(x)
        ys = np.arange(-dim[1],dim[1]+1) + round(y)
        completeTile = None
        for i in range(len(xs)):
            verticalTile = None
            for j in range(len(ys)):
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
        def prevGoal():
            self.changeGoal(changeDir=-1)
        def nextGoal():
            self.changeGoal(changeDir=1)
        def clearHistory():
            self.setHistory(clear = True)

        rospy.init_node('gps_user_input',anonymous=True)
        # load map
        try:
            lat = rospy.get_param('~lat')
            lon = rospy.get_param('~lon')
            height = rospy.get_param('~height')
            width = rospy.get_param('~width')
            zoom = rospy.get_param('~zoom')
        except:
            print("couldn't find yaml file. load parameters from the python file")
            lat = lat_set
            lon = lon_set
            height = height_set
            width = width_set
            zoom = zoom_set

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
        self.startPauseBtn = QtWidgets.QPushButton('Start Nav.')
        self.startPauseStatus = False
        self.startPauseBtn.clicked.connect(self.startPause)
        prevGoalBtn = QtWidgets.QPushButton('Prev Goal')
        prevGoalBtn.clicked.connect(prevGoal)
        nextGoalBtn = QtWidgets.QPushButton('Next Goal')
        nextGoalBtn.clicked.connect(nextGoal)
        
        #text widget
        self.statusNav = "Normal"
        self.statusGPS = "Connecting to GPS"
        #self.status = pg.TextItem('')
        #self.status.setColor(pg.Qt.QtGui.QColor("red"))
        #self.status.setText("testing")
        #self.widget.addWidget(self.status, row = 1, col = 1)
        self.widget.addWidget(clearHistoryBtn,row=2,col=0)
        self.widget.addWidget(clearPathBtn,row=2,col=1)
        self.widget.addWidget(self.editPathBtn,row=2,col=2)
        self.widget.addWidget(loadPathFileBtn,row=2,col=3)
        self.widget.addWidget(savePathBtn,row=2,col=4)
        self.widget.addWidget(self.startPauseBtn,row=2,col=4)
        self.widget.addWidget(prevGoalBtn,row=2,col=6)
        self.widget.addWidget(nextGoalBtn,row=2,col=7)
        self.widget.addLabel(text = "Status: "+ self.statusNav, row = 1, col = 0, colspan = 3 )
        self.widget.addLabel(text = "GPS: " + self.statusGPS, row = 1, col = 4, colspan = 2 )

        # ros sub pub
        self.odom_sub = rospy.Subscriber('/gx5/nav/odom',Odometry,self.readOdom) # plotRobotPosition
        self.navigation_sub = rospy.Subscriber('/gps_navigation/current_goal',PoseStamped,self.readNavigation) # get status of navigation controller
        self.goal_pub = rospy.Publisher('/gps_navigation/goal',PoseStamped,queue_size=5)
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
        lat = data.pose.pose.position.y
        lon = data.pose.pose.position.x
        pixX,pixY = self.satMap.coord2Pixel([lat,lon])
        quat = data.pose.pose.orientation
        r = R.from_quat([quat.x,quat.y,quat.z,quat.w])
        xVec = r.as_dcm()[:,0]
        #robotHeading = np.mod(math.atan2(xVec[1],xVec[0])+np.pi/3.0,2*np.pi)
        robotHeading = math.atan2(xVec[0],xVec[1])
        if not self.robotArrow is None:
            self.robotArrow.setStyle(angle = robotHeading*180/np.pi+np.pi/2.0)
            self.robotArrow.setPos(pixX,pixY)
            self.robotArrow.update()
        self.historyPoints.append([pixX,pixY])
        self.setHistory()
    
    # This function checks status of navigation controller
    def readNavigation(self,data):
        if self.startPauseStatus:
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
            msg = PoseStamped()
            msg.pose.position.x = float('nan')
            msg.pose.position.y = float('nan')
            msg.pose.position.z = -1
            self.goal_pub.publish(msg)

if __name__ == '__main__':
    app = QtWidgets.QApplication([])
    mw = QtWidgets.QMainWindow()
    gps_node = gps_user_input()
    mw.setCentralWidget(gps_node.widget)
    mw.show()
    if (sys.flags.interactive != 1) or not hasattr(QtCore, 'PYQT_VERSION'):
        QtWidgets.QApplication.instance().exec_()
