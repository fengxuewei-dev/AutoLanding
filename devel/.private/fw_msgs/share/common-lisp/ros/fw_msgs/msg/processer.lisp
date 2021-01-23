; Auto-generated. Do not edit!


(cl:in-package fw_msgs-msg)


;//! \htmlinclude processer.msg.html

(cl:defclass <processer> (roslisp-msg-protocol:ros-message)
  ((execflag
    :reader execflag
    :initarg :execflag
    :type cl:float
    :initform 0.0))
)

(cl:defclass processer (<processer>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <processer>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'processer)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name fw_msgs-msg:<processer> is deprecated: use fw_msgs-msg:processer instead.")))

(cl:ensure-generic-function 'execflag-val :lambda-list '(m))
(cl:defmethod execflag-val ((m <processer>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:execflag-val is deprecated.  Use fw_msgs-msg:execflag instead.")
  (execflag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <processer>) ostream)
  "Serializes a message object of type '<processer>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'execflag))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <processer>) istream)
  "Deserializes a message object of type '<processer>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'execflag) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<processer>)))
  "Returns string type for a message object of type '<processer>"
  "fw_msgs/processer")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'processer)))
  "Returns string type for a message object of type 'processer"
  "fw_msgs/processer")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<processer>)))
  "Returns md5sum for a message object of type '<processer>"
  "fff3fb7d3ee0a7ebfa5a6a893b0503a1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'processer)))
  "Returns md5sum for a message object of type 'processer"
  "fff3fb7d3ee0a7ebfa5a6a893b0503a1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<processer>)))
  "Returns full string definition for message of type '<processer>"
  (cl:format cl:nil "# processer.msg~%~%float32 execflag~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'processer)))
  "Returns full string definition for message of type 'processer"
  (cl:format cl:nil "# processer.msg~%~%float32 execflag~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <processer>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <processer>))
  "Converts a ROS message object to a list"
  (cl:list 'processer
    (cl:cons ':execflag (execflag msg))
))
