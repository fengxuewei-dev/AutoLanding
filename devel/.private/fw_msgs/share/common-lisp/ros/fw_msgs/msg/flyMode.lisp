; Auto-generated. Do not edit!


(cl:in-package fw_msgs-msg)


;//! \htmlinclude flyMode.msg.html

(cl:defclass <flyMode> (roslisp-msg-protocol:ros-message)
  ((IsSingleMode
    :reader IsSingleMode
    :initarg :IsSingleMode
    :type cl:float
    :initform 0.0)
   (ControlMode
    :reader ControlMode
    :initarg :ControlMode
    :type cl:float
    :initform 0.0))
)

(cl:defclass flyMode (<flyMode>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <flyMode>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'flyMode)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name fw_msgs-msg:<flyMode> is deprecated: use fw_msgs-msg:flyMode instead.")))

(cl:ensure-generic-function 'IsSingleMode-val :lambda-list '(m))
(cl:defmethod IsSingleMode-val ((m <flyMode>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:IsSingleMode-val is deprecated.  Use fw_msgs-msg:IsSingleMode instead.")
  (IsSingleMode m))

(cl:ensure-generic-function 'ControlMode-val :lambda-list '(m))
(cl:defmethod ControlMode-val ((m <flyMode>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:ControlMode-val is deprecated.  Use fw_msgs-msg:ControlMode instead.")
  (ControlMode m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <flyMode>) ostream)
  "Serializes a message object of type '<flyMode>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'IsSingleMode))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'ControlMode))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <flyMode>) istream)
  "Deserializes a message object of type '<flyMode>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'IsSingleMode) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'ControlMode) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<flyMode>)))
  "Returns string type for a message object of type '<flyMode>"
  "fw_msgs/flyMode")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'flyMode)))
  "Returns string type for a message object of type 'flyMode"
  "fw_msgs/flyMode")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<flyMode>)))
  "Returns md5sum for a message object of type '<flyMode>"
  "8bbfbbef36e847700d30280b89afcfb1")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'flyMode)))
  "Returns md5sum for a message object of type 'flyMode"
  "8bbfbbef36e847700d30280b89afcfb1")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<flyMode>)))
  "Returns full string definition for message of type '<flyMode>"
  (cl:format cl:nil "# flyMode.msg~%~%float64 IsSingleMode~%float64 ControlMode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'flyMode)))
  "Returns full string definition for message of type 'flyMode"
  (cl:format cl:nil "# flyMode.msg~%~%float64 IsSingleMode~%float64 ControlMode~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <flyMode>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <flyMode>))
  "Converts a ROS message object to a list"
  (cl:list 'flyMode
    (cl:cons ':IsSingleMode (IsSingleMode msg))
    (cl:cons ':ControlMode (ControlMode msg))
))
