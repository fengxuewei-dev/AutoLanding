; Auto-generated. Do not edit!


(cl:in-package fw_msgs-msg)


;//! \htmlinclude NormalSwitchMode.msg.html

(cl:defclass <NormalSwitchMode> (roslisp-msg-protocol:ros-message)
  ((Normal_Switch_Mode_Flag
    :reader Normal_Switch_Mode_Flag
    :initarg :Normal_Switch_Mode_Flag
    :type cl:integer
    :initform 0))
)

(cl:defclass NormalSwitchMode (<NormalSwitchMode>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <NormalSwitchMode>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'NormalSwitchMode)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name fw_msgs-msg:<NormalSwitchMode> is deprecated: use fw_msgs-msg:NormalSwitchMode instead.")))

(cl:ensure-generic-function 'Normal_Switch_Mode_Flag-val :lambda-list '(m))
(cl:defmethod Normal_Switch_Mode_Flag-val ((m <NormalSwitchMode>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:Normal_Switch_Mode_Flag-val is deprecated.  Use fw_msgs-msg:Normal_Switch_Mode_Flag instead.")
  (Normal_Switch_Mode_Flag m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <NormalSwitchMode>) ostream)
  "Serializes a message object of type '<NormalSwitchMode>"
  (cl:let* ((signed (cl:slot-value msg 'Normal_Switch_Mode_Flag)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <NormalSwitchMode>) istream)
  "Deserializes a message object of type '<NormalSwitchMode>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Normal_Switch_Mode_Flag) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<NormalSwitchMode>)))
  "Returns string type for a message object of type '<NormalSwitchMode>"
  "fw_msgs/NormalSwitchMode")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'NormalSwitchMode)))
  "Returns string type for a message object of type 'NormalSwitchMode"
  "fw_msgs/NormalSwitchMode")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<NormalSwitchMode>)))
  "Returns md5sum for a message object of type '<NormalSwitchMode>"
  "a9e01fe0fa34836a4cd37fddd4a5467f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'NormalSwitchMode)))
  "Returns md5sum for a message object of type 'NormalSwitchMode"
  "a9e01fe0fa34836a4cd37fddd4a5467f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<NormalSwitchMode>)))
  "Returns full string definition for message of type '<NormalSwitchMode>"
  (cl:format cl:nil "# NormalSwitchMode.msg~%~%int32 Normal_Switch_Mode_Flag~%~%# \"communication/protectExitFlag/normalSwitchModeFlag\"~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'NormalSwitchMode)))
  "Returns full string definition for message of type 'NormalSwitchMode"
  (cl:format cl:nil "# NormalSwitchMode.msg~%~%int32 Normal_Switch_Mode_Flag~%~%# \"communication/protectExitFlag/normalSwitchModeFlag\"~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <NormalSwitchMode>))
  (cl:+ 0
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <NormalSwitchMode>))
  "Converts a ROS message object to a list"
  (cl:list 'NormalSwitchMode
    (cl:cons ':Normal_Switch_Mode_Flag (Normal_Switch_Mode_Flag msg))
))
