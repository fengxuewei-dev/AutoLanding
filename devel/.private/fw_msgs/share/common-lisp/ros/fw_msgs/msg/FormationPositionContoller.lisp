; Auto-generated. Do not edit!


(cl:in-package fw_msgs-msg)


;//! \htmlinclude FormationPositionContoller.msg.html

(cl:defclass <FormationPositionContoller> (roslisp-msg-protocol:ros-message)
  ((count_number
    :reader count_number
    :initarg :count_number
    :type cl:float
    :initform 0.0)
   (leaderHeading
    :reader leaderHeading
    :initarg :leaderHeading
    :type cl:float
    :initform 0.0)
   (leaderCommand_yaw
    :reader leaderCommand_yaw
    :initarg :leaderCommand_yaw
    :type cl:float
    :initform 0.0)
   (leaderAirspeed
    :reader leaderAirspeed
    :initarg :leaderAirspeed
    :type cl:float
    :initform 0.0))
)

(cl:defclass FormationPositionContoller (<FormationPositionContoller>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FormationPositionContoller>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FormationPositionContoller)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name fw_msgs-msg:<FormationPositionContoller> is deprecated: use fw_msgs-msg:FormationPositionContoller instead.")))

(cl:ensure-generic-function 'count_number-val :lambda-list '(m))
(cl:defmethod count_number-val ((m <FormationPositionContoller>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:count_number-val is deprecated.  Use fw_msgs-msg:count_number instead.")
  (count_number m))

(cl:ensure-generic-function 'leaderHeading-val :lambda-list '(m))
(cl:defmethod leaderHeading-val ((m <FormationPositionContoller>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:leaderHeading-val is deprecated.  Use fw_msgs-msg:leaderHeading instead.")
  (leaderHeading m))

(cl:ensure-generic-function 'leaderCommand_yaw-val :lambda-list '(m))
(cl:defmethod leaderCommand_yaw-val ((m <FormationPositionContoller>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:leaderCommand_yaw-val is deprecated.  Use fw_msgs-msg:leaderCommand_yaw instead.")
  (leaderCommand_yaw m))

(cl:ensure-generic-function 'leaderAirspeed-val :lambda-list '(m))
(cl:defmethod leaderAirspeed-val ((m <FormationPositionContoller>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:leaderAirspeed-val is deprecated.  Use fw_msgs-msg:leaderAirspeed instead.")
  (leaderAirspeed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FormationPositionContoller>) ostream)
  "Serializes a message object of type '<FormationPositionContoller>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'count_number))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'leaderHeading))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'leaderCommand_yaw))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'leaderAirspeed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FormationPositionContoller>) istream)
  "Deserializes a message object of type '<FormationPositionContoller>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'count_number) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'leaderHeading) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'leaderCommand_yaw) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'leaderAirspeed) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FormationPositionContoller>)))
  "Returns string type for a message object of type '<FormationPositionContoller>"
  "fw_msgs/FormationPositionContoller")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FormationPositionContoller)))
  "Returns string type for a message object of type 'FormationPositionContoller"
  "fw_msgs/FormationPositionContoller")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FormationPositionContoller>)))
  "Returns md5sum for a message object of type '<FormationPositionContoller>"
  "d87d2620f7eee8afb717e021cba9a3f4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FormationPositionContoller)))
  "Returns md5sum for a message object of type 'FormationPositionContoller"
  "d87d2620f7eee8afb717e021cba9a3f4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FormationPositionContoller>)))
  "Returns full string definition for message of type '<FormationPositionContoller>"
  (cl:format cl:nil "# FormationPositionContoller.msg~%~%float64 count_number~%float64 leaderHeading~%float64 leaderCommand_yaw~%float64 leaderAirspeed~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FormationPositionContoller)))
  "Returns full string definition for message of type 'FormationPositionContoller"
  (cl:format cl:nil "# FormationPositionContoller.msg~%~%float64 count_number~%float64 leaderHeading~%float64 leaderCommand_yaw~%float64 leaderAirspeed~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FormationPositionContoller>))
  (cl:+ 0
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FormationPositionContoller>))
  "Converts a ROS message object to a list"
  (cl:list 'FormationPositionContoller
    (cl:cons ':count_number (count_number msg))
    (cl:cons ':leaderHeading (leaderHeading msg))
    (cl:cons ':leaderCommand_yaw (leaderCommand_yaw msg))
    (cl:cons ':leaderAirspeed (leaderAirspeed msg))
))
