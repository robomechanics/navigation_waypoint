# Install script for directory: /home/cvx/catkin_ws/src/microstrain_inertial/microstrain_inertial_driver

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/cvx/catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/catkin_generated/installspace/microstrain_inertial_driver.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/microstrain_inertial_driver/cmake" TYPE FILE FILES
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/catkin_generated/installspace/microstrain_inertial_driverConfig.cmake"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/catkin_generated/installspace/microstrain_inertial_driverConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/microstrain_inertial_driver" TYPE FILE FILES "/home/cvx/catkin_ws/src/microstrain_inertial/microstrain_inertial_driver/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmicrostrain_inertial_driver.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmicrostrain_inertial_driver.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmicrostrain_inertial_driver.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/cvx/catkin_ws/devel/lib/libmicrostrain_inertial_driver.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmicrostrain_inertial_driver.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmicrostrain_inertial_driver.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmicrostrain_inertial_driver.so"
         OLD_RPATH "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl:/opt/ros/noetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmicrostrain_inertial_driver.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/microstrain_inertial_driver/microstrain_inertial_driver_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/microstrain_inertial_driver/microstrain_inertial_driver_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/microstrain_inertial_driver/microstrain_inertial_driver_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/microstrain_inertial_driver" TYPE EXECUTABLE FILES "/home/cvx/catkin_ws/devel/lib/microstrain_inertial_driver/microstrain_inertial_driver_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/microstrain_inertial_driver/microstrain_inertial_driver_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/microstrain_inertial_driver/microstrain_inertial_driver_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/microstrain_inertial_driver/microstrain_inertial_driver_node"
         OLD_RPATH "/home/cvx/catkin_ws/devel/lib:/opt/ros/noetic/lib:/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/microstrain_inertial_driver/microstrain_inertial_driver_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/microstrain_inertial_driver" TYPE DIRECTORY FILES
    "/home/cvx/catkin_ws/src/microstrain_inertial/microstrain_inertial_driver/launch"
    "/home/cvx/catkin_ws/src/microstrain_inertial/microstrain_inertial_driver/config"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/microstrain_inertial_driver/microstrain_inertial_driver_common" TYPE DIRECTORY FILES "/home/cvx/catkin_ws/src/microstrain_inertial/microstrain_inertial_driver/microstrain_inertial_driver_common/config")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_chrono.a"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_chrono.so"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_chrono.so.1.68.0"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_filesystem.a"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_filesystem.so"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_filesystem.so.1.68.0"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_prg_exec_monitor.a"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_prg_exec_monitor.so"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_prg_exec_monitor.so.1.68.0"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_system.a"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_system.so"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_system.so.1.68.0"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_test_exec_monitor.a"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_timer.a"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_timer.so"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_timer.so.1.68.0"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_unit_test_framework.a"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_unit_test_framework.so"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/Boost/lib/libboost_unit_test_framework.so.1.68.0"
    "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_driver/c++-mscl_64/usr/share/c++-mscl/libmscl.so"
    )
endif()

