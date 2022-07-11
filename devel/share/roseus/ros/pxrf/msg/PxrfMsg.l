;; Auto-generated. Do not edit!


(when (boundp 'pxrf::PxrfMsg)
  (if (not (find-package "PXRF"))
    (make-package "PXRF"))
  (shadow 'PxrfMsg (find-package "PXRF")))
(unless (find-package "PXRF::PXRFMSG")
  (make-package "PXRF::PXRFMSG"))

(in-package "ROS")
;;//! \htmlinclude PxrfMsg.msg.html


(defclass pxrf::PxrfMsg
  :super ros::object
  :slots (_dailyId _testId _testDateTime _chemistry ))

(defmethod pxrf::PxrfMsg
  (:init
   (&key
    ((:dailyId __dailyId) 0)
    ((:testId __testId) 0)
    ((:testDateTime __testDateTime) "")
    ((:chemistry __chemistry) "")
    )
   (send-super :init)
   (setq _dailyId (round __dailyId))
   (setq _testId (round __testId))
   (setq _testDateTime (string __testDateTime))
   (setq _chemistry (string __chemistry))
   self)
  (:dailyId
   (&optional __dailyId)
   (if __dailyId (setq _dailyId __dailyId)) _dailyId)
  (:testId
   (&optional __testId)
   (if __testId (setq _testId __testId)) _testId)
  (:testDateTime
   (&optional __testDateTime)
   (if __testDateTime (setq _testDateTime __testDateTime)) _testDateTime)
  (:chemistry
   (&optional __chemistry)
   (if __chemistry (setq _chemistry __chemistry)) _chemistry)
  (:serialization-length
   ()
   (+
    ;; int64 _dailyId
    8
    ;; int64 _testId
    8
    ;; string _testDateTime
    4 (length _testDateTime)
    ;; string _chemistry
    4 (length _chemistry)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _dailyId
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _dailyId (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _dailyId) (= (length (_dailyId . bv)) 2)) ;; bignum
              (write-long (ash (elt (_dailyId . bv) 0) 0) s)
              (write-long (ash (elt (_dailyId . bv) 1) -1) s))
             ((and (class _dailyId) (= (length (_dailyId . bv)) 1)) ;; big1
              (write-long (elt (_dailyId . bv) 0) s)
              (write-long (if (>= _dailyId 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _dailyId s)(write-long (if (>= _dailyId 0) 0 #xffffffff) s)))
     ;; int64 _testId
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _testId (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _testId) (= (length (_testId . bv)) 2)) ;; bignum
              (write-long (ash (elt (_testId . bv) 0) 0) s)
              (write-long (ash (elt (_testId . bv) 1) -1) s))
             ((and (class _testId) (= (length (_testId . bv)) 1)) ;; big1
              (write-long (elt (_testId . bv) 0) s)
              (write-long (if (>= _testId 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _testId s)(write-long (if (>= _testId 0) 0 #xffffffff) s)))
     ;; string _testDateTime
       (write-long (length _testDateTime) s) (princ _testDateTime s)
     ;; string _chemistry
       (write-long (length _chemistry) s) (princ _chemistry s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _dailyId
#+(or :alpha :irix6 :x86_64)
      (setf _dailyId (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _dailyId (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int64 _testId
#+(or :alpha :irix6 :x86_64)
      (setf _testId (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _testId (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; string _testDateTime
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _testDateTime (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _chemistry
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _chemistry (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get pxrf::PxrfMsg :md5sum-) "0ded31cc28f81581de2d0d50d228d3dc")
(setf (get pxrf::PxrfMsg :datatype-) "pxrf/PxrfMsg")
(setf (get pxrf::PxrfMsg :definition-)
      "int64 dailyId
int64 testId
string testDateTime
string chemistry

")



(provide :pxrf/PxrfMsg "0ded31cc28f81581de2d0d50d228d3dc")


