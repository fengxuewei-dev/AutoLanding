; Auto-generated. Do not edit!


(cl:in-package fw_msgs-msg)


;//! \htmlinclude ACKflag.msg.html

(cl:defclass <ACKflag> (roslisp-msg-protocol:ros-message)
  ((ACKflag
    :reader ACKflag
    :initarg :ACKflag
    :type cl:integer
    :initform 0))
)

(cl:defclass ACKflag (<ACKflag>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ACKflag>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ACKflag)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name fw_msgs-msg:<ACKflag> is deprecated: use fw_msgs-msg:ACKflag instead.")))

(cl:ensure-generic-function 'ACKflag-val :lambda-list '(m))
(cl:defmethod ACKflag-val ((m <ACKflag>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:ACKflag-val is deprecated.  Use fw_msgs-msg:ACKflag instead.")
  (ACKflag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ACKflag>) ostream)
  "Serializes a message object of type '<ACKflag>"
  (cl:let* ((signed (cl:slot-value msg 'ACKflag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ACKflag>) istream)
  "Deserializes a message object of type '<ACKflag>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ACKflag) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ACKflag>)))
  "Returns string type for a message object of type '<ACKflag>"
  "fw_msgs/ACKflag")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ACKflag)))
  "Returns string type for a message object of type 'ACKflag"
  "fw_msgs/ACKflag")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ACKflag>)))
  "Returns md5sum for a message object of type '<ACKflag>"
  "45bdb69dba2c6d2adc0542aeb7f54879")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ACKflag)))
  "Returns md5sum for a message object of type 'ACKflag"
  "45bdb69dba2c6d2adc0542aeb7f54879")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ACKflag>)))
  "Returns full string definition for message of type '<ACKflag>"
  (cl:format cl:nil "# ACKflag.msg~%~%int32 ACKflag~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ACKflag)))
  "Returns full string definition for message of type 'ACKflag"
  (cl:format cl:nil "# ACKflag.msg~%~%int32 ACKflag~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ACKflag>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ACKflag>))
  "Converts a ROS message object to a list"
  (cl:list 'ACKflag
    (cl:cons ':ACKflag (ACKflag msg))
))
