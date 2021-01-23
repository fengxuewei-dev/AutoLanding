; Auto-generated. Do not edit!


(cl:in-package communication-msg)


;//! \htmlinclude UpdHP.msg.html

(cl:defclass <UpdHP> (roslisp-msg-protocol:ros-message)
  ((messageid
    :reader messageid
    :initarg :messageid
    :type cl:fixnum
    :initform 0)
   (uavid
    :reader uavid
    :initarg :uavid
    :type cl:fixnum
    :initform 0)
   (longitude
    :reader longitude
    :initarg :longitude
    :type cl:float
    :initform 0.0)
   (latitude
    :reader latitude
    :initarg :latitude
    :type cl:float
    :initform 0.0)
   (altitude
    :reader altitude
    :initarg :altitude
    :type cl:float
    :initform 0.0)
   (parity
    :reader parity
    :initarg :parity
    :type cl:integer
    :initform 0))
)

(cl:defclass UpdHP (<UpdHP>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <UpdHP>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'UpdHP)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name communication-msg:<UpdHP> is deprecated: use communication-msg:UpdHP instead.")))

(cl:ensure-generic-function 'messageid-val :lambda-list '(m))
(cl:defmethod messageid-val ((m <UpdHP>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:messageid-val is deprecated.  Use communication-msg:messageid instead.")
  (messageid m))

(cl:ensure-generic-function 'uavid-val :lambda-list '(m))
(cl:defmethod uavid-val ((m <UpdHP>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:uavid-val is deprecated.  Use communication-msg:uavid instead.")
  (uavid m))

(cl:ensure-generic-function 'longitude-val :lambda-list '(m))
(cl:defmethod longitude-val ((m <UpdHP>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:longitude-val is deprecated.  Use communication-msg:longitude instead.")
  (longitude m))

(cl:ensure-generic-function 'latitude-val :lambda-list '(m))
(cl:defmethod latitude-val ((m <UpdHP>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:latitude-val is deprecated.  Use communication-msg:latitude instead.")
  (latitude m))

(cl:ensure-generic-function 'altitude-val :lambda-list '(m))
(cl:defmethod altitude-val ((m <UpdHP>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:altitude-val is deprecated.  Use communication-msg:altitude instead.")
  (altitude m))

(cl:ensure-generic-function 'parity-val :lambda-list '(m))
(cl:defmethod parity-val ((m <UpdHP>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:parity-val is deprecated.  Use communication-msg:parity instead.")
  (parity m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <UpdHP>) ostream)
  "Serializes a message object of type '<UpdHP>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'messageid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'messageid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uavid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uavid)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'longitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'latitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'altitude))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'parity)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <UpdHP>) istream)
  "Deserializes a message object of type '<UpdHP>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'messageid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'messageid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uavid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uavid)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'longitude) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'latitude) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'altitude) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'parity) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<UpdHP>)))
  "Returns string type for a message object of type '<UpdHP>"
  "communication/UpdHP")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'UpdHP)))
  "Returns string type for a message object of type 'UpdHP"
  "communication/UpdHP")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<UpdHP>)))
  "Returns md5sum for a message object of type '<UpdHP>"
  "7f25d391682710b024a661224416d7c4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'UpdHP)))
  "Returns md5sum for a message object of type 'UpdHP"
  "7f25d391682710b024a661224416d7c4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<UpdHP>)))
  "Returns full string definition for message of type '<UpdHP>"
  (cl:format cl:nil "# UDPMessage.msg~%~%uint16 messageid~%uint16 uavid~%float64 longitude~%float64 latitude~%float64 altitude ~%int32 parity~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'UpdHP)))
  "Returns full string definition for message of type 'UpdHP"
  (cl:format cl:nil "# UDPMessage.msg~%~%uint16 messageid~%uint16 uavid~%float64 longitude~%float64 latitude~%float64 altitude ~%int32 parity~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <UpdHP>))
  (cl:+ 0
     2
     2
     8
     8
     8
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <UpdHP>))
  "Converts a ROS message object to a list"
  (cl:list 'UpdHP
    (cl:cons ':messageid (messageid msg))
    (cl:cons ':uavid (uavid msg))
    (cl:cons ':longitude (longitude msg))
    (cl:cons ':latitude (latitude msg))
    (cl:cons ':altitude (altitude msg))
    (cl:cons ':parity (parity msg))
))
