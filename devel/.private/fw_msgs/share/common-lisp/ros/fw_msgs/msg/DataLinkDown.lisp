; Auto-generated. Do not edit!


(cl:in-package fw_msgs-msg)


;//! \htmlinclude DataLinkDown.msg.html

(cl:defclass <DataLinkDown> (roslisp-msg-protocol:ros-message)
  ((isDataLinkDown
    :reader isDataLinkDown
    :initarg :isDataLinkDown
    :type cl:integer
    :initform 0))
)

(cl:defclass DataLinkDown (<DataLinkDown>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DataLinkDown>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DataLinkDown)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name fw_msgs-msg:<DataLinkDown> is deprecated: use fw_msgs-msg:DataLinkDown instead.")))

(cl:ensure-generic-function 'isDataLinkDown-val :lambda-list '(m))
(cl:defmethod isDataLinkDown-val ((m <DataLinkDown>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:isDataLinkDown-val is deprecated.  Use fw_msgs-msg:isDataLinkDown instead.")
  (isDataLinkDown m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DataLinkDown>) ostream)
  "Serializes a message object of type '<DataLinkDown>"
  (cl:let* ((signed (cl:slot-value msg 'isDataLinkDown)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DataLinkDown>) istream)
  "Deserializes a message object of type '<DataLinkDown>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'isDataLinkDown) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DataLinkDown>)))
  "Returns string type for a message object of type '<DataLinkDown>"
  "fw_msgs/DataLinkDown")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DataLinkDown)))
  "Returns string type for a message object of type 'DataLinkDown"
  "fw_msgs/DataLinkDown")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DataLinkDown>)))
  "Returns md5sum for a message object of type '<DataLinkDown>"
  "27e3a3f98f0830d328812cc2b4a61f31")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DataLinkDown)))
  "Returns md5sum for a message object of type 'DataLinkDown"
  "27e3a3f98f0830d328812cc2b4a61f31")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DataLinkDown>)))
  "Returns full string definition for message of type '<DataLinkDown>"
  (cl:format cl:nil "# DataLinkDown.msg~%~%int32 isDataLinkDown~%~%# \"communication/dataLinkDown/isBreak\"~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DataLinkDown)))
  "Returns full string definition for message of type 'DataLinkDown"
  (cl:format cl:nil "# DataLinkDown.msg~%~%int32 isDataLinkDown~%~%# \"communication/dataLinkDown/isBreak\"~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DataLinkDown>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DataLinkDown>))
  "Converts a ROS message object to a list"
  (cl:list 'DataLinkDown
    (cl:cons ':isDataLinkDown (isDataLinkDown msg))
))
