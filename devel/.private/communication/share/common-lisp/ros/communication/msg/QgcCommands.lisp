; Auto-generated. Do not edit!


(cl:in-package communication-msg)


;//! \htmlinclude QgcCommands.msg.html

(cl:defclass <QgcCommands> (roslisp-msg-protocol:ros-message)
  ((messageid
    :reader messageid
    :initarg :messageid
    :type cl:fixnum
    :initform 0)
   (gsid
    :reader gsid
    :initarg :gsid
    :type cl:fixnum
    :initform 0)
   (uavid
    :reader uavid
    :initarg :uavid
    :type cl:fixnum
    :initform 0)
   (uavnumber
    :reader uavnumber
    :initarg :uavnumber
    :type cl:fixnum
    :initform 0)
   (tasktype
    :reader tasktype
    :initarg :tasktype
    :type cl:integer
    :initform 0)
   (plane_state
    :reader plane_state
    :initarg :plane_state
    :type cl:fixnum
    :initform 0)
   (plane_group
    :reader plane_group
    :initarg :plane_group
    :type cl:fixnum
    :initform 0)
   (gapx
    :reader gapx
    :initarg :gapx
    :type cl:fixnum
    :initform 0)
   (gapy
    :reader gapy
    :initarg :gapy
    :type cl:fixnum
    :initform 0)
   (GPStime
    :reader GPStime
    :initarg :GPStime
    :type cl:float
    :initform 0.0)
   (parity
    :reader parity
    :initarg :parity
    :type cl:integer
    :initform 0))
)

(cl:defclass QgcCommands (<QgcCommands>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <QgcCommands>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'QgcCommands)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name communication-msg:<QgcCommands> is deprecated: use communication-msg:QgcCommands instead.")))

(cl:ensure-generic-function 'messageid-val :lambda-list '(m))
(cl:defmethod messageid-val ((m <QgcCommands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:messageid-val is deprecated.  Use communication-msg:messageid instead.")
  (messageid m))

(cl:ensure-generic-function 'gsid-val :lambda-list '(m))
(cl:defmethod gsid-val ((m <QgcCommands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:gsid-val is deprecated.  Use communication-msg:gsid instead.")
  (gsid m))

(cl:ensure-generic-function 'uavid-val :lambda-list '(m))
(cl:defmethod uavid-val ((m <QgcCommands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:uavid-val is deprecated.  Use communication-msg:uavid instead.")
  (uavid m))

(cl:ensure-generic-function 'uavnumber-val :lambda-list '(m))
(cl:defmethod uavnumber-val ((m <QgcCommands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:uavnumber-val is deprecated.  Use communication-msg:uavnumber instead.")
  (uavnumber m))

(cl:ensure-generic-function 'tasktype-val :lambda-list '(m))
(cl:defmethod tasktype-val ((m <QgcCommands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:tasktype-val is deprecated.  Use communication-msg:tasktype instead.")
  (tasktype m))

(cl:ensure-generic-function 'plane_state-val :lambda-list '(m))
(cl:defmethod plane_state-val ((m <QgcCommands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:plane_state-val is deprecated.  Use communication-msg:plane_state instead.")
  (plane_state m))

(cl:ensure-generic-function 'plane_group-val :lambda-list '(m))
(cl:defmethod plane_group-val ((m <QgcCommands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:plane_group-val is deprecated.  Use communication-msg:plane_group instead.")
  (plane_group m))

(cl:ensure-generic-function 'gapx-val :lambda-list '(m))
(cl:defmethod gapx-val ((m <QgcCommands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:gapx-val is deprecated.  Use communication-msg:gapx instead.")
  (gapx m))

(cl:ensure-generic-function 'gapy-val :lambda-list '(m))
(cl:defmethod gapy-val ((m <QgcCommands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:gapy-val is deprecated.  Use communication-msg:gapy instead.")
  (gapy m))

(cl:ensure-generic-function 'GPStime-val :lambda-list '(m))
(cl:defmethod GPStime-val ((m <QgcCommands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:GPStime-val is deprecated.  Use communication-msg:GPStime instead.")
  (GPStime m))

(cl:ensure-generic-function 'parity-val :lambda-list '(m))
(cl:defmethod parity-val ((m <QgcCommands>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:parity-val is deprecated.  Use communication-msg:parity instead.")
  (parity m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <QgcCommands>) ostream)
  "Serializes a message object of type '<QgcCommands>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'messageid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'messageid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gsid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'gsid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uavid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uavid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uavnumber)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uavnumber)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'tasktype)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'plane_state)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'plane_group)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'gapx)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'gapy)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 65536) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'GPStime))))
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <QgcCommands>) istream)
  "Deserializes a message object of type '<QgcCommands>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'messageid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'messageid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gsid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'gsid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uavid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uavid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uavnumber)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uavnumber)) (cl:read-byte istream))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'tasktype) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'plane_state) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'plane_group) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'gapx) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'gapy) (cl:if (cl:< unsigned 32768) unsigned (cl:- unsigned 65536))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'GPStime) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'parity) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<QgcCommands>)))
  "Returns string type for a message object of type '<QgcCommands>"
  "communication/QgcCommands")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'QgcCommands)))
  "Returns string type for a message object of type 'QgcCommands"
  "communication/QgcCommands")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<QgcCommands>)))
  "Returns md5sum for a message object of type '<QgcCommands>"
  "0e2eb4b83ad275dc0706fdd57e60ccec")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'QgcCommands)))
  "Returns md5sum for a message object of type 'QgcCommands"
  "0e2eb4b83ad275dc0706fdd57e60ccec")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<QgcCommands>)))
  "Returns full string definition for message of type '<QgcCommands>"
  (cl:format cl:nil "# UDPMessage.msg~%~%uint16 messageid~%uint16 gsid~%uint16 uavid~%uint16 uavnumber~%int32 tasktype~%int16 plane_state~%int16 plane_group~%int16 gapx~%int16 gapy~%float64 GPStime~%int32 parity~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'QgcCommands)))
  "Returns full string definition for message of type 'QgcCommands"
  (cl:format cl:nil "# UDPMessage.msg~%~%uint16 messageid~%uint16 gsid~%uint16 uavid~%uint16 uavnumber~%int32 tasktype~%int16 plane_state~%int16 plane_group~%int16 gapx~%int16 gapy~%float64 GPStime~%int32 parity~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <QgcCommands>))
  (cl:+ 0
     2
     2
     2
     2
     4
     2
     2
     2
     2
     8
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <QgcCommands>))
  "Converts a ROS message object to a list"
  (cl:list 'QgcCommands
    (cl:cons ':messageid (messageid msg))
    (cl:cons ':gsid (gsid msg))
    (cl:cons ':uavid (uavid msg))
    (cl:cons ':uavnumber (uavnumber msg))
    (cl:cons ':tasktype (tasktype msg))
    (cl:cons ':plane_state (plane_state msg))
    (cl:cons ':plane_group (plane_group msg))
    (cl:cons ':gapx (gapx msg))
    (cl:cons ':gapy (gapy msg))
    (cl:cons ':GPStime (GPStime msg))
    (cl:cons ':parity (parity msg))
))
