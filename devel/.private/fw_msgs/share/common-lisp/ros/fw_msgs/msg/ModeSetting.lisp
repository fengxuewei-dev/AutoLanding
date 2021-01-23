; Auto-generated. Do not edit!


(cl:in-package fw_msgs-msg)


;//! \htmlinclude ModeSetting.msg.html

(cl:defclass <ModeSetting> (roslisp-msg-protocol:ros-message)
  ((Mode
    :reader Mode
    :initarg :Mode
    :type cl:float
    :initform 0.0))
)

(cl:defclass ModeSetting (<ModeSetting>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ModeSetting>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ModeSetting)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name fw_msgs-msg:<ModeSetting> is deprecated: use fw_msgs-msg:ModeSetting instead.")))

(cl:ensure-generic-function 'Mode-val :lambda-list '(m))
(cl:defmethod Mode-val ((m <ModeSetting>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:Mode-val is deprecated.  Use fw_msgs-msg:Mode instead.")
  (Mode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ModeSetting>) ostream)
  "Serializes a message object of type '<ModeSetting>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'Mode))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ModeSetting>) istream)
  "Deserializes a message object of type '<ModeSetting>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'Mode) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ModeSetting>)))
  "Returns string type for a message object of type '<ModeSetting>"
  "fw_msgs/ModeSetting")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ModeSetting)))
  "Returns string type for a message object of type 'ModeSetting"
  "fw_msgs/ModeSetting")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ModeSetting>)))
  "Returns md5sum for a message object of type '<ModeSetting>"
  "fa9a51763d03303f4394bfc6178f2b70")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ModeSetting)))
  "Returns md5sum for a message object of type 'ModeSetting"
  "fa9a51763d03303f4394bfc6178f2b70")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ModeSetting>)))
  "Returns full string definition for message of type '<ModeSetting>"
  (cl:format cl:nil "# ModeSetting.msg~%~%float64 Mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ModeSetting)))
  "Returns full string definition for message of type 'ModeSetting"
  (cl:format cl:nil "# ModeSetting.msg~%~%float64 Mode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ModeSetting>))
  (cl:+ 0
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ModeSetting>))
  "Converts a ROS message object to a list"
  (cl:list 'ModeSetting
    (cl:cons ':Mode (Mode msg))
))
