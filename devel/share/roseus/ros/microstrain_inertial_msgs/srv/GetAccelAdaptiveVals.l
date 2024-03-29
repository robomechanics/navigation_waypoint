;; Auto-generated. Do not edit!


(when (boundp 'microstrain_inertial_msgs::GetAccelAdaptiveVals)
  (if (not (find-package "MICROSTRAIN_INERTIAL_MSGS"))
    (make-package "MICROSTRAIN_INERTIAL_MSGS"))
  (shadow 'GetAccelAdaptiveVals (find-package "MICROSTRAIN_INERTIAL_MSGS")))
(unless (find-package "MICROSTRAIN_INERTIAL_MSGS::GETACCELADAPTIVEVALS")
  (make-package "MICROSTRAIN_INERTIAL_MSGS::GETACCELADAPTIVEVALS"))
(unless (find-package "MICROSTRAIN_INERTIAL_MSGS::GETACCELADAPTIVEVALSREQUEST")
  (make-package "MICROSTRAIN_INERTIAL_MSGS::GETACCELADAPTIVEVALSREQUEST"))
(unless (find-package "MICROSTRAIN_INERTIAL_MSGS::GETACCELADAPTIVEVALSRESPONSE")
  (make-package "MICROSTRAIN_INERTIAL_MSGS::GETACCELADAPTIVEVALSRESPONSE"))

(in-package "ROS")





(defclass microstrain_inertial_msgs::GetAccelAdaptiveValsRequest
  :super ros::object
  :slots ())

(defmethod microstrain_inertial_msgs::GetAccelAdaptiveValsRequest
  (:init
   (&key
    )
   (send-super :init)
   self)
  (:serialization-length
   ()
   (+
    0
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;;
   self)
  )

(defclass microstrain_inertial_msgs::GetAccelAdaptiveValsResponse
  :super ros::object
  :slots (_enable _low_pass_cutoff _min_1sigma _low_limit _high_limit _low_limit_1sigma _high_limit_1sigma _success ))

(defmethod microstrain_inertial_msgs::GetAccelAdaptiveValsResponse
  (:init
   (&key
    ((:enable __enable) 0.0)
    ((:low_pass_cutoff __low_pass_cutoff) 0.0)
    ((:min_1sigma __min_1sigma) 0.0)
    ((:low_limit __low_limit) 0.0)
    ((:high_limit __high_limit) 0.0)
    ((:low_limit_1sigma __low_limit_1sigma) 0.0)
    ((:high_limit_1sigma __high_limit_1sigma) 0.0)
    ((:success __success) nil)
    )
   (send-super :init)
   (setq _enable (float __enable))
   (setq _low_pass_cutoff (float __low_pass_cutoff))
   (setq _min_1sigma (float __min_1sigma))
   (setq _low_limit (float __low_limit))
   (setq _high_limit (float __high_limit))
   (setq _low_limit_1sigma (float __low_limit_1sigma))
   (setq _high_limit_1sigma (float __high_limit_1sigma))
   (setq _success __success)
   self)
  (:enable
   (&optional __enable)
   (if __enable (setq _enable __enable)) _enable)
  (:low_pass_cutoff
   (&optional __low_pass_cutoff)
   (if __low_pass_cutoff (setq _low_pass_cutoff __low_pass_cutoff)) _low_pass_cutoff)
  (:min_1sigma
   (&optional __min_1sigma)
   (if __min_1sigma (setq _min_1sigma __min_1sigma)) _min_1sigma)
  (:low_limit
   (&optional __low_limit)
   (if __low_limit (setq _low_limit __low_limit)) _low_limit)
  (:high_limit
   (&optional __high_limit)
   (if __high_limit (setq _high_limit __high_limit)) _high_limit)
  (:low_limit_1sigma
   (&optional __low_limit_1sigma)
   (if __low_limit_1sigma (setq _low_limit_1sigma __low_limit_1sigma)) _low_limit_1sigma)
  (:high_limit_1sigma
   (&optional __high_limit_1sigma)
   (if __high_limit_1sigma (setq _high_limit_1sigma __high_limit_1sigma)) _high_limit_1sigma)
  (:success
   (&optional (__success :null))
   (if (not (eq __success :null)) (setq _success __success)) _success)
  (:serialization-length
   ()
   (+
    ;; float32 _enable
    4
    ;; float32 _low_pass_cutoff
    4
    ;; float32 _min_1sigma
    4
    ;; float32 _low_limit
    4
    ;; float32 _high_limit
    4
    ;; float32 _low_limit_1sigma
    4
    ;; float32 _high_limit_1sigma
    4
    ;; bool _success
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _enable
       (sys::poke _enable (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _low_pass_cutoff
       (sys::poke _low_pass_cutoff (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _min_1sigma
       (sys::poke _min_1sigma (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _low_limit
       (sys::poke _low_limit (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _high_limit
       (sys::poke _high_limit (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _low_limit_1sigma
       (sys::poke _low_limit_1sigma (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _high_limit_1sigma
       (sys::poke _high_limit_1sigma (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _enable
     (setq _enable (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _low_pass_cutoff
     (setq _low_pass_cutoff (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _min_1sigma
     (setq _min_1sigma (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _low_limit
     (setq _low_limit (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _high_limit
     (setq _high_limit (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _low_limit_1sigma
     (setq _low_limit_1sigma (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _high_limit_1sigma
     (setq _high_limit_1sigma (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(defclass microstrain_inertial_msgs::GetAccelAdaptiveVals
  :super ros::object
  :slots ())

(setf (get microstrain_inertial_msgs::GetAccelAdaptiveVals :md5sum-) "88594dfd6d7363edbe6f8e16638532cc")
(setf (get microstrain_inertial_msgs::GetAccelAdaptiveVals :datatype-) "microstrain_inertial_msgs/GetAccelAdaptiveVals")
(setf (get microstrain_inertial_msgs::GetAccelAdaptiveVals :request) microstrain_inertial_msgs::GetAccelAdaptiveValsRequest)
(setf (get microstrain_inertial_msgs::GetAccelAdaptiveVals :response) microstrain_inertial_msgs::GetAccelAdaptiveValsResponse)

(defmethod microstrain_inertial_msgs::GetAccelAdaptiveValsRequest
  (:response () (instance microstrain_inertial_msgs::GetAccelAdaptiveValsResponse :init)))

(setf (get microstrain_inertial_msgs::GetAccelAdaptiveValsRequest :md5sum-) "88594dfd6d7363edbe6f8e16638532cc")
(setf (get microstrain_inertial_msgs::GetAccelAdaptiveValsRequest :datatype-) "microstrain_inertial_msgs/GetAccelAdaptiveValsRequest")
(setf (get microstrain_inertial_msgs::GetAccelAdaptiveValsRequest :definition-)
      "---
float32 enable
float32 low_pass_cutoff
float32 min_1sigma
float32 low_limit
float32 high_limit
float32 low_limit_1sigma
float32 high_limit_1sigma
bool success

")

(setf (get microstrain_inertial_msgs::GetAccelAdaptiveValsResponse :md5sum-) "88594dfd6d7363edbe6f8e16638532cc")
(setf (get microstrain_inertial_msgs::GetAccelAdaptiveValsResponse :datatype-) "microstrain_inertial_msgs/GetAccelAdaptiveValsResponse")
(setf (get microstrain_inertial_msgs::GetAccelAdaptiveValsResponse :definition-)
      "---
float32 enable
float32 low_pass_cutoff
float32 min_1sigma
float32 low_limit
float32 high_limit
float32 low_limit_1sigma
float32 high_limit_1sigma
bool success

")



(provide :microstrain_inertial_msgs/GetAccelAdaptiveVals "88594dfd6d7363edbe6f8e16638532cc")


