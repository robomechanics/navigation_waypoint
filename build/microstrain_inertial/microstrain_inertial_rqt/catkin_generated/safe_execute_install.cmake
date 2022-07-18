execute_process(COMMAND "/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_rqt/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/cvx/catkin_ws/build/microstrain_inertial/microstrain_inertial_rqt/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
