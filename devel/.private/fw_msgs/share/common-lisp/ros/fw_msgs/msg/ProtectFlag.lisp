; Auto-generated. Do not edit!


(cl:in-package fw_msgs-msg)


;//! \htmlinclude ProtectFlag.msg.html

(cl:defclass <ProtectFlag> (roslisp-msg-protocol:ros-message)
  ((PROTECT_EXIT_FLAG
    :reader PROTECT_EXIT_FLAG
    :initarg :PROTECT_EXIT_FLAG
    :type cl:integer
    :initform 0))
)

(cl:defclass ProtectFlag (<ProtectFlag>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ProtectFlag>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ProtectFlag)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name fw_msgs-msg:<ProtectFlag> is deprecated: use fw_msgs-msg:ProtectFlag instead.")))

(cl:ensure-generic-function 'PROTECT_EXIT_FLAG-val :lambda-list '(m))
(cl:defmethod PROTECT_EXIT_FLAG-val ((m <ProtectFlag>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:PROTECT_EXIT_FLAG-val is deprecated.  Use fw_msgs-msg:PROTECT_EXIT_FLAG instead.")
  (PROTECT_EXIT_FLAG m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ProtectFlag>) ostream)
  "Serializes a message object of type '<ProtectFlag>"
  (cl:let* ((signed (cl:slot-value msg 'PROTECT_EXIT_FLAG)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ProtectFlag>) istream)
  "Deserializes a message object of type '<ProtectFlag>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'PROTECT_EXIT_FLAG) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ProtectFlag>)))
  "Returns string type for a message object of type '<ProtectFlag>"
  "fw_msgs/ProtectFlag")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ProtectFlag)))
  "Returns string type for a message object of type 'ProtectFlag"
  "fw_msgs/ProtectFlag")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ProtectFlag>)))
  "Returns md5sum for a message object of type '<ProtectFlag>"
  "3cbdec5b7556f1bc61b85f03babb7b6d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ProtectFlag)))
  "Returns md5sum for a message object of type 'ProtectFlag"
  "3cbdec5b7556f1bc61b85f03babb7b6d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ProtectFlag>)))
  "Returns full string definition for message of type '<ProtectFlag>"
  (cl:format cl:nil "# ProtectFlag.msg~%~%int32 PROTECT_EXIT_FLAG~%~%# \"communication/protectExitFlag/protecEexitFlag\"~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ProtectFlag)))
  "Returns full string definition for message of type 'ProtectFlag"
  (cl:format cl:nil "# ProtectFlag.msg~%~%int32 PROTECT_EXIT_FLAG~%~%# \"communication/protectExitFlag/protecEexitFlag\"~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ProtectFlag>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ProtectFlag>))
  "Converts a ROS message object to a list"
  (cl:list 'ProtectFlag
    (cl:cons ':PROTECT_EXIT_FLAG (PROTECT_EXIT_FLAG msg))
))
