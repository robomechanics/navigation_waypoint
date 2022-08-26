;; Auto-generated. Do not edit!


(when (boundp 'dynamixel_sdk_examples::GetTorque)
  (if (not (find-package "DYNAMIXEL_SDK_EXAMPLES"))
    (make-package "DYNAMIXEL_SDK_EXAMPLES"))
  (shadow 'GetTorque (find-package "DYNAMIXEL_SDK_EXAMPLES")))
(unless (find-package "DYNAMIXEL_SDK_EXAMPLES::GETTORQUE")
  (make-package "DYNAMIXEL_SDK_EXAMPLES::GETTORQUE"))
(unless (find-package "DYNAMIXEL_SDK_EXAMPLES::GETTORQUEREQUEST")
  (make-package "DYNAMIXEL_SDK_EXAMPLES::GETTORQUEREQUEST"))
(unless (find-package "DYNAMIXEL_SDK_EXAMPLES::GETTORQUERESPONSE")
  (make-package "DYNAMIXEL_SDK_EXAMPLES::GETTORQUERESPONSE"))

(in-package "ROS")





(defclass dynamixel_sdk_examples::GetTorqueRequest
  :super ros::object
  :slots (_id ))

(defmethod dynamixel_sdk_examples::GetTorqueRequest
  (:init
   (&key
    ((:id __id) 0)
    )
   (send-super :init)
   (setq _id (round __id))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:serialization-length
   ()
   (+
    ;; uint8 _id
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _id
       (write-byte _id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _id
     (setq _id (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(defclass dynamixel_sdk_examples::GetTorqueResponse
  :super ros::object
  :slots (_torque ))

(defmethod dynamixel_sdk_examples::GetTorqueResponse
  (:init
   (&key
    ((:torque __torque) 0)
    )
   (send-super :init)
   (setq _torque (round __torque))
   self)
  (:torque
   (&optional __torque)
   (if __torque (setq _torque __torque)) _torque)
  (:serialization-length
   ()
   (+
    ;; int32 _torque
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _torque
       (write-long _torque s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _torque
     (setq _torque (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass dynamixel_sdk_examples::GetTorque
  :super ros::object
  :slots ())

(setf (get dynamixel_sdk_examples::GetTorque :md5sum-) "19c4cb65acfb8207353f2423be603ca8")
(setf (get dynamixel_sdk_examples::GetTorque :datatype-) "dynamixel_sdk_examples/GetTorque")
(setf (get dynamixel_sdk_examples::GetTorque :request) dynamixel_sdk_examples::GetTorqueRequest)
(setf (get dynamixel_sdk_examples::GetTorque :response) dynamixel_sdk_examples::GetTorqueResponse)

(defmethod dynamixel_sdk_examples::GetTorqueRequest
  (:response () (instance dynamixel_sdk_examples::GetTorqueResponse :init)))

(setf (get dynamixel_sdk_examples::GetTorqueRequest :md5sum-) "19c4cb65acfb8207353f2423be603ca8")
(setf (get dynamixel_sdk_examples::GetTorqueRequest :datatype-) "dynamixel_sdk_examples/GetTorqueRequest")
(setf (get dynamixel_sdk_examples::GetTorqueRequest :definition-)
      "uint8 id
---
int32 torque

")

(setf (get dynamixel_sdk_examples::GetTorqueResponse :md5sum-) "19c4cb65acfb8207353f2423be603ca8")
(setf (get dynamixel_sdk_examples::GetTorqueResponse :datatype-) "dynamixel_sdk_examples/GetTorqueResponse")
(setf (get dynamixel_sdk_examples::GetTorqueResponse :definition-)
      "uint8 id
---
int32 torque

")



(provide :dynamixel_sdk_examples/GetTorque "19c4cb65acfb8207353f2423be603ca8")


