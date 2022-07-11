; Auto-generated. Do not edit!


(cl:in-package pxrf-msg)


;//! \htmlinclude PxrfMsg.msg.html

(cl:defclass <PxrfMsg> (roslisp-msg-protocol:ros-message)
  ((dailyId
    :reader dailyId
    :initarg :dailyId
    :type cl:integer
    :initform 0)
   (testId
    :reader testId
    :initarg :testId
    :type cl:integer
    :initform 0)
   (testDateTime
    :reader testDateTime
    :initarg :testDateTime
    :type cl:string
    :initform "")
   (chemistry
    :reader chemistry
    :initarg :chemistry
    :type cl:string
    :initform ""))
)

(cl:defclass PxrfMsg (<PxrfMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PxrfMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PxrfMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name pxrf-msg:<PxrfMsg> is deprecated: use pxrf-msg:PxrfMsg instead.")))

(cl:ensure-generic-function 'dailyId-val :lambda-list '(m))
(cl:defmethod dailyId-val ((m <PxrfMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pxrf-msg:dailyId-val is deprecated.  Use pxrf-msg:dailyId instead.")
  (dailyId m))

(cl:ensure-generic-function 'testId-val :lambda-list '(m))
(cl:defmethod testId-val ((m <PxrfMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pxrf-msg:testId-val is deprecated.  Use pxrf-msg:testId instead.")
  (testId m))

(cl:ensure-generic-function 'testDateTime-val :lambda-list '(m))
(cl:defmethod testDateTime-val ((m <PxrfMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pxrf-msg:testDateTime-val is deprecated.  Use pxrf-msg:testDateTime instead.")
  (testDateTime m))

(cl:ensure-generic-function 'chemistry-val :lambda-list '(m))
(cl:defmethod chemistry-val ((m <PxrfMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader pxrf-msg:chemistry-val is deprecated.  Use pxrf-msg:chemistry instead.")
  (chemistry m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PxrfMsg>) ostream)
  "Serializes a message object of type '<PxrfMsg>"
  (cl:let* ((signed (cl:slot-value msg 'dailyId)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'testId)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'testDateTime))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'testDateTime))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'chemistry))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'chemistry))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PxrfMsg>) istream)
  "Deserializes a message object of type '<PxrfMsg>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'dailyId) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'testId) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'testDateTime) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'testDateTime) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'chemistry) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'chemistry) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PxrfMsg>)))
  "Returns string type for a message object of type '<PxrfMsg>"
  "pxrf/PxrfMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PxrfMsg)))
  "Returns string type for a message object of type 'PxrfMsg"
  "pxrf/PxrfMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PxrfMsg>)))
  "Returns md5sum for a message object of type '<PxrfMsg>"
  "0ded31cc28f81581de2d0d50d228d3dc")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PxrfMsg)))
  "Returns md5sum for a message object of type 'PxrfMsg"
  "0ded31cc28f81581de2d0d50d228d3dc")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PxrfMsg>)))
  "Returns full string definition for message of type '<PxrfMsg>"
  (cl:format cl:nil "int64 dailyId~%int64 testId~%string testDateTime~%string chemistry~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PxrfMsg)))
  "Returns full string definition for message of type 'PxrfMsg"
  (cl:format cl:nil "int64 dailyId~%int64 testId~%string testDateTime~%string chemistry~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PxrfMsg>))
  (cl:+ 0
     8
     8
     4 (cl:length (cl:slot-value msg 'testDateTime))
     4 (cl:length (cl:slot-value msg 'chemistry))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PxrfMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'PxrfMsg
    (cl:cons ':dailyId (dailyId msg))
    (cl:cons ':testId (testId msg))
    (cl:cons ':testDateTime (testDateTime msg))
    (cl:cons ':chemistry (chemistry msg))
))
