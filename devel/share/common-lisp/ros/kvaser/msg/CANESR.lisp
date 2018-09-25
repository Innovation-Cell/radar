; Auto-generated. Do not edit!


(cl:in-package kvaser-msg)


;//! \htmlinclude CANESR.msg.html

(cl:defclass <CANESR> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (esrjson
    :reader esrjson
    :initarg :esrjson
    :type cl:string
    :initform ""))
)

(cl:defclass CANESR (<CANESR>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CANESR>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CANESR)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name kvaser-msg:<CANESR> is deprecated: use kvaser-msg:CANESR instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <CANESR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kvaser-msg:header-val is deprecated.  Use kvaser-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'esrjson-val :lambda-list '(m))
(cl:defmethod esrjson-val ((m <CANESR>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader kvaser-msg:esrjson-val is deprecated.  Use kvaser-msg:esrjson instead.")
  (esrjson m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CANESR>) ostream)
  "Serializes a message object of type '<CANESR>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'esrjson))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'esrjson))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CANESR>) istream)
  "Deserializes a message object of type '<CANESR>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'esrjson) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'esrjson) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CANESR>)))
  "Returns string type for a message object of type '<CANESR>"
  "kvaser/CANESR")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CANESR)))
  "Returns string type for a message object of type 'CANESR"
  "kvaser/CANESR")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CANESR>)))
  "Returns md5sum for a message object of type '<CANESR>"
  "fddc53a50846bc21262a9e34771e8931")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CANESR)))
  "Returns md5sum for a message object of type 'CANESR"
  "fddc53a50846bc21262a9e34771e8931")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CANESR>)))
  "Returns full string definition for message of type '<CANESR>"
  (cl:format cl:nil "Header header~%string esrjson~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CANESR)))
  "Returns full string definition for message of type 'CANESR"
  (cl:format cl:nil "Header header~%string esrjson~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%# 0: no frame~%# 1: global frame~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CANESR>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:length (cl:slot-value msg 'esrjson))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CANESR>))
  "Converts a ROS message object to a list"
  (cl:list 'CANESR
    (cl:cons ':header (header msg))
    (cl:cons ':esrjson (esrjson msg))
))
