;; Auto-generated. Do not edit!


(when (boundp 'kvaser::CANESR)
  (if (not (find-package "KVASER"))
    (make-package "KVASER"))
  (shadow 'CANESR (find-package "KVASER")))
(unless (find-package "KVASER::CANESR")
  (make-package "KVASER::CANESR"))

(in-package "ROS")
;;//! \htmlinclude CANESR.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass kvaser::CANESR
  :super ros::object
  :slots (_header _esrjson ))

(defmethod kvaser::CANESR
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:esrjson __esrjson) "")
    )
   (send-super :init)
   (setq _header __header)
   (setq _esrjson (string __esrjson))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:esrjson
   (&optional __esrjson)
   (if __esrjson (setq _esrjson __esrjson)) _esrjson)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; string _esrjson
    4 (length _esrjson)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; string _esrjson
       (write-long (length _esrjson) s) (princ _esrjson s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; string _esrjson
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _esrjson (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get kvaser::CANESR :md5sum-) "fddc53a50846bc21262a9e34771e8931")
(setf (get kvaser::CANESR :datatype-) "kvaser/CANESR")
(setf (get kvaser::CANESR :definition-)
      "Header header
string esrjson

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
# 0: no frame
# 1: global frame
string frame_id

")



(provide :kvaser/CANESR "fddc53a50846bc21262a9e34771e8931")


