; Auto-generated. Do not edit!


(cl:in-package communication-msg)


;//! \htmlinclude udpDataTypes.msg.html

(cl:defclass <udpDataTypes> (roslisp-msg-protocol:ros-message)
  ((startUDP_Data
    :reader startUDP_Data
    :initarg :startUDP_Data
    :type cl:fixnum
    :initform 0)
   (startUPD_HOME
    :reader startUPD_HOME
    :initarg :startUPD_HOME
    :type cl:fixnum
    :initform 0)
   (startACK
    :reader startACK
    :initarg :startACK
    :type cl:fixnum
    :initform 0))
)

(cl:defclass udpDataTypes (<udpDataTypes>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <udpDataTypes>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'udpDataTypes)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name communication-msg:<udpDataTypes> is deprecated: use communication-msg:udpDataTypes instead.")))

(cl:ensure-generic-function 'startUDP_Data-val :lambda-list '(m))
(cl:defmethod startUDP_Data-val ((m <udpDataTypes>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:startUDP_Data-val is deprecated.  Use communication-msg:startUDP_Data instead.")
  (startUDP_Data m))

(cl:ensure-generic-function 'startUPD_HOME-val :lambda-list '(m))
(cl:defmethod startUPD_HOME-val ((m <udpDataTypes>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:startUPD_HOME-val is deprecated.  Use communication-msg:startUPD_HOME instead.")
  (startUPD_HOME m))

(cl:ensure-generic-function 'startACK-val :lambda-list '(m))
(cl:defmethod startACK-val ((m <udpDataTypes>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader communication-msg:startACK-val is deprecated.  Use communication-msg:startACK instead.")
  (startACK m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <udpDataTypes>) ostream)
  "Serializes a message object of type '<udpDataTypes>"
  (cl:let* ((signed (cl:slot-value msg 'startUDP_Data)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'startUPD_HOME)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'startACK)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <udpDataTypes>) istream)
  "Deserializes a message object of type '<udpDataTypes>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'startUDP_Data) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'startUPD_HOME) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'startACK) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<udpDataTypes>)))
  "Returns string type for a message object of type '<udpDataTypes>"
  "communication/udpDataTypes")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'udpDataTypes)))
  "Returns string type for a message object of type 'udpDataTypes"
  "communication/udpDataTypes")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<udpDataTypes>)))
  "Returns md5sum for a message object of type '<udpDataTypes>"
  "24c91d25d88a35c807139468a346102b")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'udpDataTypes)))
  "Returns md5sum for a message object of type 'udpDataTypes"
  "24c91d25d88a35c807139468a346102b")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<udpDataTypes>)))
  "Returns full string definition for message of type '<udpDataTypes>"
  (cl:format cl:nil "# udpDataTypes.msg~%~%int8 startUDP_Data~%int8 startUPD_HOME~%int8 startACK~%~%# taskType_sub = nh.advertise<communication::udpDataTypes>~%#           (\"communication/taskTypes/udpDataTypes\", 1);~%~%# taskType_sub = nh.subscribe<communication::QgcCommands>~%#           (uavName + \"/communication/QgcCommands\" + s_i,1, handler_taskType);~%# ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'udpDataTypes)))
  "Returns full string definition for message of type 'udpDataTypes"
  (cl:format cl:nil "# udpDataTypes.msg~%~%int8 startUDP_Data~%int8 startUPD_HOME~%int8 startACK~%~%# taskType_sub = nh.advertise<communication::udpDataTypes>~%#           (\"communication/taskTypes/udpDataTypes\", 1);~%~%# taskType_sub = nh.subscribe<communication::QgcCommands>~%#           (uavName + \"/communication/QgcCommands\" + s_i,1, handler_taskType);~%# ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <udpDataTypes>))
  (cl:+ 0
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <udpDataTypes>))
  "Converts a ROS message object to a list"
  (cl:list 'udpDataTypes
    (cl:cons ':startUDP_Data (startUDP_Data msg))
    (cl:cons ':startUPD_HOME (startUPD_HOME msg))
    (cl:cons ':startACK (startACK msg))
))
