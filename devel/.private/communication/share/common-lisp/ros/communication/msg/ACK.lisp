; Auto-generated. Do not edit!


(cl:in-package communication-msg)


;//! \htmlinclude ACK.msg.html

(cl:defclass <ACK> (roslisp-msg-protocol:ros-message)
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
   (GPStime
    :reader GPStime
    :initarg :GPStime
    :type cl:real
    :initform 0)
   (judge
    :reader judge
    :initarg :judge
    :type cl:boolean
    :initform cl:nil)
   (parity
    :reader parity
    :initarg :parity
    :type cl:integer
    :initform 0))
)

(cl:defclass ACK (<ACK>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ACK>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ACK)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name communication-msg:<ACK> is deprecated: use communication-msg:ACK instead.")))

(cl:ensure-generic-function 'messageid-val :lambda-list '(m))
(cl:defmethod messageid-val ((m <ACK>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:messageid-val is deprecated.  Use communication-msg:messageid instead.")
  (messageid m))

(cl:ensure-generic-function 'uavid-val :lambda-list '(m))
(cl:defmethod uavid-val ((m <ACK>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:uavid-val is deprecated.  Use communication-msg:uavid instead.")
  (uavid m))

(cl:ensure-generic-function 'GPStime-val :lambda-list '(m))
(cl:defmethod GPStime-val ((m <ACK>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:GPStime-val is deprecated.  Use communication-msg:GPStime instead.")
  (GPStime m))

(cl:ensure-generic-function 'judge-val :lambda-list '(m))
(cl:defmethod judge-val ((m <ACK>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:judge-val is deprecated.  Use communication-msg:judge instead.")
  (judge m))

(cl:ensure-generic-function 'parity-val :lambda-list '(m))
(cl:defmethod parity-val ((m <ACK>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:parity-val is deprecated.  Use communication-msg:parity instead.")
  (parity m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ACK>) ostream)
  "Serializes a message object of type '<ACK>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'messageid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'messageid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uavid)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uavid)) ostream)
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'GPStime)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'GPStime) (cl:floor (cl:slot-value msg 'GPStime)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'judge) 1 0)) ostream)
  (cl:let* ((signed (cl:slot-value msg 'parity)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ACK>) istream)
  "Deserializes a message object of type '<ACK>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'messageid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'messageid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'uavid)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'uavid)) (cl:read-byte istream))
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'GPStime) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
    (cl:setf (cl:slot-value msg 'judge) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'parity) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ACK>)))
  "Returns string type for a message object of type '<ACK>"
  "communication/ACK")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ACK)))
  "Returns string type for a message object of type 'ACK"
  "communication/ACK")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ACK>)))
  "Returns md5sum for a message object of type '<ACK>"
  "1572b006872bc5799fbee1b02a88be5b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ACK)))
  "Returns md5sum for a message object of type 'ACK"
  "1572b006872bc5799fbee1b02a88be5b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ACK>)))
  "Returns full string definition for message of type '<ACK>"
  (cl:format cl:nil "# UDPMessage.msg~%~%uint16 messageid~%uint16 uavid~%time GPStime~%bool judge~%int32 parity~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ACK)))
  "Returns full string definition for message of type 'ACK"
  (cl:format cl:nil "# UDPMessage.msg~%~%uint16 messageid~%uint16 uavid~%time GPStime~%bool judge~%int32 parity~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ACK>))
  (cl:+ 0
     2
     2
     8
     1
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ACK>))
  "Converts a ROS message object to a list"
  (cl:list 'ACK
    (cl:cons ':messageid (messageid msg))
    (cl:cons ':uavid (uavid msg))
    (cl:cons ':GPStime (GPStime msg))
    (cl:cons ':judge (judge msg))
    (cl:cons ':parity (parity msg))
))
