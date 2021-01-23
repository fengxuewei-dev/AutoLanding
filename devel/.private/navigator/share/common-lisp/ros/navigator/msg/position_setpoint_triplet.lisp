; Auto-generated. Do not edit!


(cl:in-package navigator-msg)


;//! \htmlinclude position_setpoint_triplet.msg.html

(cl:defclass <position_setpoint_triplet> (roslisp-msg-protocol:ros-message)
  ((currentWaypoint
    :reader currentWaypoint
    :initarg :currentWaypoint
    :type mavros_msgs-msg:Waypoint
    :initform (cl:make-instance 'mavros_msgs-msg:Waypoint))
   (nextWaypoint
    :reader nextWaypoint
    :initarg :nextWaypoint
    :type mavros_msgs-msg:Waypoint
    :initform (cl:make-instance 'mavros_msgs-msg:Waypoint))
   (Throttle
    :reader Throttle
    :initarg :Throttle
    :type cl:fixnum
    :initform 0)
   (ExistNext
    :reader ExistNext
    :initarg :ExistNext
    :type cl:fixnum
    :initform 0))
)

(cl:defclass position_setpoint_triplet (<position_setpoint_triplet>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <position_setpoint_triplet>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'position_setpoint_triplet)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name navigator-msg:<position_setpoint_triplet> is deprecated: use navigator-msg:position_setpoint_triplet instead.")))

(cl:ensure-generic-function 'currentWaypoint-val :lambda-list '(m))
(cl:defmethod currentWaypoint-val ((m <position_setpoint_triplet>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader navigator-msg:currentWaypoint-val is deprecated.  Use navigator-msg:currentWaypoint instead.")
  (currentWaypoint m))

(cl:ensure-generic-function 'nextWaypoint-val :lambda-list '(m))
(cl:defmethod nextWaypoint-val ((m <position_setpoint_triplet>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader navigator-msg:nextWaypoint-val is deprecated.  Use navigator-msg:nextWaypoint instead.")
  (nextWaypoint m))

(cl:ensure-generic-function 'Throttle-val :lambda-list '(m))
(cl:defmethod Throttle-val ((m <position_setpoint_triplet>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader navigator-msg:Throttle-val is deprecated.  Use navigator-msg:Throttle instead.")
  (Throttle m))

(cl:ensure-generic-function 'ExistNext-val :lambda-list '(m))
(cl:defmethod ExistNext-val ((m <position_setpoint_triplet>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader navigator-msg:ExistNext-val is deprecated.  Use navigator-msg:ExistNext instead.")
  (ExistNext m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <position_setpoint_triplet>) ostream)
  "Serializes a message object of type '<position_setpoint_triplet>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'currentWaypoint) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'nextWaypoint) ostream)
  (cl:let* ((signed (cl:slot-value msg 'Throttle)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'ExistNext)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <position_setpoint_triplet>) istream)
  "Deserializes a message object of type '<position_setpoint_triplet>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'currentWaypoint) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'nextWaypoint) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'Throttle) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'ExistNext) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<position_setpoint_triplet>)))
  "Returns string type for a message object of type '<position_setpoint_triplet>"
  "navigator/position_setpoint_triplet")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'position_setpoint_triplet)))
  "Returns string type for a message object of type 'position_setpoint_triplet"
  "navigator/position_setpoint_triplet")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<position_setpoint_triplet>)))
  "Returns md5sum for a message object of type '<position_setpoint_triplet>"
  "3fb3b9f9f42aa6f50d1505ea97f3c07f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'position_setpoint_triplet)))
  "Returns md5sum for a message object of type 'position_setpoint_triplet"
  "3fb3b9f9f42aa6f50d1505ea97f3c07f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<position_setpoint_triplet>)))
  "Returns full string definition for message of type '<position_setpoint_triplet>"
  (cl:format cl:nil "# position_setpoint_triplet.msg~%~%mavros_msgs/Waypoint currentWaypoint~%mavros_msgs/Waypoint nextWaypoint~%int8 Throttle~%int8 ExistNext~%~%================================================================================~%MSG: mavros_msgs/Waypoint~%# Waypoint.msg~%#~%# ROS representation of MAVLink MISSION_ITEM~%# See mavlink documentation~%~%~%~%# see enum MAV_FRAME~%uint8 frame~%uint8 FRAME_GLOBAL = 0~%uint8 FRAME_LOCAL_NED = 1~%uint8 FRAME_MISSION = 2~%uint8 FRAME_GLOBAL_REL_ALT = 3~%uint8 FRAME_LOCAL_ENU = 4~%~%# see enum MAV_CMD and CommandCode.msg~%uint16 command~%~%bool is_current~%bool autocontinue~%# meaning of this params described in enum MAV_CMD~%float32 param1~%float32 param2~%float32 param3~%float32 param4~%float64 x_lat~%float64 y_long~%float64 z_alt~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'position_setpoint_triplet)))
  "Returns full string definition for message of type 'position_setpoint_triplet"
  (cl:format cl:nil "# position_setpoint_triplet.msg~%~%mavros_msgs/Waypoint currentWaypoint~%mavros_msgs/Waypoint nextWaypoint~%int8 Throttle~%int8 ExistNext~%~%================================================================================~%MSG: mavros_msgs/Waypoint~%# Waypoint.msg~%#~%# ROS representation of MAVLink MISSION_ITEM~%# See mavlink documentation~%~%~%~%# see enum MAV_FRAME~%uint8 frame~%uint8 FRAME_GLOBAL = 0~%uint8 FRAME_LOCAL_NED = 1~%uint8 FRAME_MISSION = 2~%uint8 FRAME_GLOBAL_REL_ALT = 3~%uint8 FRAME_LOCAL_ENU = 4~%~%# see enum MAV_CMD and CommandCode.msg~%uint16 command~%~%bool is_current~%bool autocontinue~%# meaning of this params described in enum MAV_CMD~%float32 param1~%float32 param2~%float32 param3~%float32 param4~%float64 x_lat~%float64 y_long~%float64 z_alt~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <position_setpoint_triplet>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'currentWaypoint))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'nextWaypoint))
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <position_setpoint_triplet>))
  "Converts a ROS message object to a list"
  (cl:list 'position_setpoint_triplet
    (cl:cons ':currentWaypoint (currentWaypoint msg))
    (cl:cons ':nextWaypoint (nextWaypoint msg))
    (cl:cons ':Throttle (Throttle msg))
    (cl:cons ':ExistNext (ExistNext msg))
))
