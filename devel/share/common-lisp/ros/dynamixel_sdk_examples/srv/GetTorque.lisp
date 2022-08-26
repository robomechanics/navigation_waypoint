; Auto-generated. Do not edit!


(cl:in-package dynamixel_sdk_examples-srv)


;//! \htmlinclude GetTorque-request.msg.html

(cl:defclass <GetTorque-request> (roslisp-msg-protocol:ros-message)
  ((id
    :reader id
    :initarg :id
    :type cl:fixnum
    :initform 0))
)

(cl:defclass GetTorque-request (<GetTorque-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetTorque-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetTorque-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dynamixel_sdk_examples-srv:<GetTorque-request> is deprecated: use dynamixel_sdk_examples-srv:GetTorque-request instead.")))

(cl:ensure-generic-function 'id-val :lambda-list '(m))
(cl:defmethod id-val ((m <GetTorque-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dynamixel_sdk_examples-srv:id-val is deprecated.  Use dynamixel_sdk_examples-srv:id instead.")
  (id m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetTorque-request>) ostream)
  "Serializes a message object of type '<GetTorque-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetTorque-request>) istream)
  "Deserializes a message object of type '<GetTorque-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'id)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetTorque-request>)))
  "Returns string type for a service object of type '<GetTorque-request>"
  "dynamixel_sdk_examples/GetTorqueRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetTorque-request)))
  "Returns string type for a service object of type 'GetTorque-request"
  "dynamixel_sdk_examples/GetTorqueRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetTorque-request>)))
  "Returns md5sum for a message object of type '<GetTorque-request>"
  "19c4cb65acfb8207353f2423be603ca8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetTorque-request)))
  "Returns md5sum for a message object of type 'GetTorque-request"
  "19c4cb65acfb8207353f2423be603ca8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetTorque-request>)))
  "Returns full string definition for message of type '<GetTorque-request>"
  (cl:format cl:nil "uint8 id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetTorque-request)))
  "Returns full string definition for message of type 'GetTorque-request"
  (cl:format cl:nil "uint8 id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetTorque-request>))
  (cl:+ 0
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetTorque-request>))
  "Converts a ROS message object to a list"
  (cl:list 'GetTorque-request
    (cl:cons ':id (id msg))
))
;//! \htmlinclude GetTorque-response.msg.html

(cl:defclass <GetTorque-response> (roslisp-msg-protocol:ros-message)
  ((torque
    :reader torque
    :initarg :torque
    :type cl:integer
    :initform 0))
)

(cl:defclass GetTorque-response (<GetTorque-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GetTorque-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GetTorque-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name dynamixel_sdk_examples-srv:<GetTorque-response> is deprecated: use dynamixel_sdk_examples-srv:GetTorque-response instead.")))

(cl:ensure-generic-function 'torque-val :lambda-list '(m))
(cl:defmethod torque-val ((m <GetTorque-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader dynamixel_sdk_examples-srv:torque-val is deprecated.  Use dynamixel_sdk_examples-srv:torque instead.")
  (torque m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GetTorque-response>) ostream)
  "Serializes a message object of type '<GetTorque-response>"
  (cl:let* ((signed (cl:slot-value msg 'torque)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GetTorque-response>) istream)
  "Deserializes a message object of type '<GetTorque-response>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'torque) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GetTorque-response>)))
  "Returns string type for a service object of type '<GetTorque-response>"
  "dynamixel_sdk_examples/GetTorqueResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetTorque-response)))
  "Returns string type for a service object of type 'GetTorque-response"
  "dynamixel_sdk_examples/GetTorqueResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GetTorque-response>)))
  "Returns md5sum for a message object of type '<GetTorque-response>"
  "19c4cb65acfb8207353f2423be603ca8")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GetTorque-response)))
  "Returns md5sum for a message object of type 'GetTorque-response"
  "19c4cb65acfb8207353f2423be603ca8")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GetTorque-response>)))
  "Returns full string definition for message of type '<GetTorque-response>"
  (cl:format cl:nil "int32 torque~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GetTorque-response)))
  "Returns full string definition for message of type 'GetTorque-response"
  (cl:format cl:nil "int32 torque~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GetTorque-response>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GetTorque-response>))
  "Converts a ROS message object to a list"
  (cl:list 'GetTorque-response
    (cl:cons ':torque (torque msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'GetTorque)))
  'GetTorque-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'GetTorque)))
  'GetTorque-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GetTorque)))
  "Returns string type for a service object of type '<GetTorque>"
  "dynamixel_sdk_examples/GetTorque")