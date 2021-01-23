; Auto-generated. Do not edit!


(cl:in-package communication-msg)


;//! \htmlinclude FormationData.msg.html

(cl:defclass <FormationData> (roslisp-msg-protocol:ros-message)
  ((position_x
    :reader position_x
    :initarg :position_x
    :type cl:float
    :initform 0.0)
   (position_y
    :reader position_y
    :initarg :position_y
    :type cl:float
    :initform 0.0)
   (position_z
    :reader position_z
    :initarg :position_z
    :type cl:float
    :initform 0.0)
   (homeLat
    :reader homeLat
    :initarg :homeLat
    :type cl:float
    :initform 0.0)
   (homeLon
    :reader homeLon
    :initarg :homeLon
    :type cl:float
    :initform 0.0)
   (homeAlt
    :reader homeAlt
    :initarg :homeAlt
    :type cl:float
    :initform 0.0)
   (gps_time
    :reader gps_time
    :initarg :gps_time
    :type cl:real
    :initform 0)
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

(cl:defclass FormationData (<FormationData>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <FormationData>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'FormationData)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name communication-msg:<FormationData> is deprecated: use communication-msg:FormationData instead.")))

(cl:ensure-generic-function 'position_x-val :lambda-list '(m))
(cl:defmethod position_x-val ((m <FormationData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:position_x-val is deprecated.  Use communication-msg:position_x instead.")
  (position_x m))

(cl:ensure-generic-function 'position_y-val :lambda-list '(m))
(cl:defmethod position_y-val ((m <FormationData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:position_y-val is deprecated.  Use communication-msg:position_y instead.")
  (position_y m))

(cl:ensure-generic-function 'position_z-val :lambda-list '(m))
(cl:defmethod position_z-val ((m <FormationData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:position_z-val is deprecated.  Use communication-msg:position_z instead.")
  (position_z m))

(cl:ensure-generic-function 'homeLat-val :lambda-list '(m))
(cl:defmethod homeLat-val ((m <FormationData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:homeLat-val is deprecated.  Use communication-msg:homeLat instead.")
  (homeLat m))

(cl:ensure-generic-function 'homeLon-val :lambda-list '(m))
(cl:defmethod homeLon-val ((m <FormationData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:homeLon-val is deprecated.  Use communication-msg:homeLon instead.")
  (homeLon m))

(cl:ensure-generic-function 'homeAlt-val :lambda-list '(m))
(cl:defmethod homeAlt-val ((m <FormationData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:homeAlt-val is deprecated.  Use communication-msg:homeAlt instead.")
  (homeAlt m))

(cl:ensure-generic-function 'gps_time-val :lambda-list '(m))
(cl:defmethod gps_time-val ((m <FormationData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:gps_time-val is deprecated.  Use communication-msg:gps_time instead.")
  (gps_time m))

(cl:ensure-generic-function 'leaderHeading-val :lambda-list '(m))
(cl:defmethod leaderHeading-val ((m <FormationData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:leaderHeading-val is deprecated.  Use communication-msg:leaderHeading instead.")
  (leaderHeading m))

(cl:ensure-generic-function 'leaderCommand_yaw-val :lambda-list '(m))
(cl:defmethod leaderCommand_yaw-val ((m <FormationData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:leaderCommand_yaw-val is deprecated.  Use communication-msg:leaderCommand_yaw instead.")
  (leaderCommand_yaw m))

(cl:ensure-generic-function 'leaderAirspeed-val :lambda-list '(m))
(cl:defmethod leaderAirspeed-val ((m <FormationData>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:leaderAirspeed-val is deprecated.  Use communication-msg:leaderAirspeed instead.")
  (leaderAirspeed m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <FormationData>) ostream)
  "Serializes a message object of type '<FormationData>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'position_x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'position_y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'position_z))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'homeLat))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'homeLon))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'homeAlt))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'gps_time)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'gps_time) (cl:floor (cl:slot-value msg 'gps_time)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <FormationData>) istream)
  "Deserializes a message object of type '<FormationData>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'position_x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'position_y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'position_z) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'homeLat) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'homeLon) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'homeAlt) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'gps_time) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<FormationData>)))
  "Returns string type for a message object of type '<FormationData>"
  "communication/FormationData")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'FormationData)))
  "Returns string type for a message object of type 'FormationData"
  "communication/FormationData")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<FormationData>)))
  "Returns md5sum for a message object of type '<FormationData>"
  "ca7ccece133aa268e8465b3c1b1aa88d")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'FormationData)))
  "Returns md5sum for a message object of type 'FormationData"
  "ca7ccece133aa268e8465b3c1b1aa88d")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<FormationData>)))
  "Returns full string definition for message of type '<FormationData>"
  (cl:format cl:nil "# FormationData.msg~%~%float64 position_x~%float64 position_y~%float64 position_z~%~%float64 homeLat~%float64 homeLon~%float64 homeAlt~%time gps_time~%~%float64 leaderHeading~%float64 leaderCommand_yaw~%float64 leaderAirspeed~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'FormationData)))
  "Returns full string definition for message of type 'FormationData"
  (cl:format cl:nil "# FormationData.msg~%~%float64 position_x~%float64 position_y~%float64 position_z~%~%float64 homeLat~%float64 homeLon~%float64 homeAlt~%time gps_time~%~%float64 leaderHeading~%float64 leaderCommand_yaw~%float64 leaderAirspeed~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <FormationData>))
  (cl:+ 0
     8
     8
     8
     8
     8
     8
     8
     8
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <FormationData>))
  "Converts a ROS message object to a list"
  (cl:list 'FormationData
    (cl:cons ':position_x (position_x msg))
    (cl:cons ':position_y (position_y msg))
    (cl:cons ':position_z (position_z msg))
    (cl:cons ':homeLat (homeLat msg))
    (cl:cons ':homeLon (homeLon msg))
    (cl:cons ':homeAlt (homeAlt msg))
    (cl:cons ':gps_time (gps_time msg))
    (cl:cons ':leaderHeading (leaderHeading msg))
    (cl:cons ':leaderCommand_yaw (leaderCommand_yaw msg))
    (cl:cons ':leaderAirspeed (leaderAirspeed msg))
))
