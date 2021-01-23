; Auto-generated. Do not edit!


(cl:in-package fw_att_control-msg)


;//! \htmlinclude commands.msg.html

(cl:defclass <commands> (roslisp-msg-protocol:ros-message)
  ((yaw
    :reader yaw
    :initarg :yaw
    :type cl:float
    :initform 0.0)
   (throttle
    :reader throttle
    :initarg :throttle
    :type cl:float
    :initform 0.0)
   (roll
    :reader roll
    :initarg :roll
    :type cl:float
    :initform 0.0)
   (pitch
    :reader pitch
    :initarg :pitch
    :type cl:float
    :initform 0.0))
)

(cl:defclass commands (<commands>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <commands>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'commands)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name fw_att_control-msg:<commands> is deprecated: use fw_att_control-msg:commands instead.")))

(cl:ensure-generic-function 'yaw-val :lambda-list '(m))
(cl:defmethod yaw-val ((m <commands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_att_control-msg:yaw-val is deprecated.  Use fw_att_control-msg:yaw instead.")
  (yaw m))

(cl:ensure-generic-function 'throttle-val :lambda-list '(m))
(cl:defmethod throttle-val ((m <commands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_att_control-msg:throttle-val is deprecated.  Use fw_att_control-msg:throttle instead.")
  (throttle m))

(cl:ensure-generic-function 'roll-val :lambda-list '(m))
(cl:defmethod roll-val ((m <commands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_att_control-msg:roll-val is deprecated.  Use fw_att_control-msg:roll instead.")
  (roll m))

(cl:ensure-generic-function 'pitch-val :lambda-list '(m))
(cl:defmethod pitch-val ((m <commands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_att_control-msg:pitch-val is deprecated.  Use fw_att_control-msg:pitch instead.")
  (pitch m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <commands>) ostream)
  "Serializes a message object of type '<commands>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'yaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'throttle))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'roll))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'pitch))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <commands>) istream)
  "Deserializes a message object of type '<commands>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'yaw) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'throttle) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'roll) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'pitch) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<commands>)))
  "Returns string type for a message object of type '<commands>"
  "fw_att_control/commands")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'commands)))
  "Returns string type for a message object of type 'commands"
  "fw_att_control/commands")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<commands>)))
  "Returns md5sum for a message object of type '<commands>"
  "3ed53da7ed658276464982ccd25dbfcd")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'commands)))
  "Returns md5sum for a message object of type 'commands"
  "3ed53da7ed658276464982ccd25dbfcd")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<commands>)))
  "Returns full string definition for message of type '<commands>"
  (cl:format cl:nil "# commands.msg~%~%float32 yaw~%float32 throttle~%float32 roll~%float32 pitch~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'commands)))
  "Returns full string definition for message of type 'commands"
  (cl:format cl:nil "# commands.msg~%~%float32 yaw~%float32 throttle~%float32 roll~%float32 pitch~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <commands>))
  (cl:+ 0
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <commands>))
  "Converts a ROS message object to a list"
  (cl:list 'commands
    (cl:cons ':yaw (yaw msg))
    (cl:cons ':throttle (throttle msg))
    (cl:cons ':roll (roll msg))
    (cl:cons ':pitch (pitch msg))
))
