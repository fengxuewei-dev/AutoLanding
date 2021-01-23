; Auto-generated. Do not edit!


(cl:in-package fw_msgs-msg)


;//! \htmlinclude EXITflag.msg.html

(cl:defclass <EXITflag> (roslisp-msg-protocol:ros-message)
  ((EXIT_FLAG
    :reader EXIT_FLAG
    :initarg :EXIT_FLAG
    :type cl:integer
    :initform 0))
)

(cl:defclass EXITflag (<EXITflag>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <EXITflag>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'EXITflag)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name fw_msgs-msg:<EXITflag> is deprecated: use fw_msgs-msg:EXITflag instead.")))

(cl:ensure-generic-function 'EXIT_FLAG-val :lambda-list '(m))
(cl:defmethod EXIT_FLAG-val ((m <EXITflag>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:EXIT_FLAG-val is deprecated.  Use fw_msgs-msg:EXIT_FLAG instead.")
  (EXIT_FLAG m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <EXITflag>) ostream)
  "Serializes a message object of type '<EXITflag>"
  (cl:let* ((signed (cl:slot-value msg 'EXIT_FLAG)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <EXITflag>) istream)
  "Deserializes a message object of type '<EXITflag>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'EXIT_FLAG) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<EXITflag>)))
  "Returns string type for a message object of type '<EXITflag>"
  "fw_msgs/EXITflag")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'EXITflag)))
  "Returns string type for a message object of type 'EXITflag"
  "fw_msgs/EXITflag")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<EXITflag>)))
  "Returns md5sum for a message object of type '<EXITflag>"
  "eef81bba155a9b445b2c20263a5058af")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'EXITflag)))
  "Returns md5sum for a message object of type 'EXITflag"
  "eef81bba155a9b445b2c20263a5058af")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<EXITflag>)))
  "Returns full string definition for message of type '<EXITflag>"
  (cl:format cl:nil "# EXITflag.msg~%~%int32 EXIT_FLAG~%~%# 0: 正常      1: 退出~%# uavName + \"communication/exitFlag/exitflag\"~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'EXITflag)))
  "Returns full string definition for message of type 'EXITflag"
  (cl:format cl:nil "# EXITflag.msg~%~%int32 EXIT_FLAG~%~%# 0: 正常      1: 退出~%# uavName + \"communication/exitFlag/exitflag\"~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <EXITflag>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <EXITflag>))
  "Converts a ROS message object to a list"
  (cl:list 'EXITflag
    (cl:cons ':EXIT_FLAG (EXIT_FLAG msg))
))
