; Auto-generated. Do not edit!


(cl:in-package fw_msgs-msg)


;//! \htmlinclude uav_ids.msg.html

(cl:defclass <uav_ids> (roslisp-msg-protocol:ros-message)
  ((current_id
    :reader current_id
    :initarg :current_id
    :type cl:fixnum
    :initform 0)
   (leader_id
    :reader leader_id
    :initarg :leader_id
    :type cl:fixnum
    :initform 0))
)

(cl:defclass uav_ids (<uav_ids>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <uav_ids>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'uav_ids)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name fw_msgs-msg:<uav_ids> is deprecated: use fw_msgs-msg:uav_ids instead.")))

(cl:ensure-generic-function 'current_id-val :lambda-list '(m))
(cl:defmethod current_id-val ((m <uav_ids>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:current_id-val is deprecated.  Use fw_msgs-msg:current_id instead.")
  (current_id m))

(cl:ensure-generic-function 'leader_id-val :lambda-list '(m))
(cl:defmethod leader_id-val ((m <uav_ids>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:leader_id-val is deprecated.  Use fw_msgs-msg:leader_id instead.")
  (leader_id m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <uav_ids>) ostream)
  "Serializes a message object of type '<uav_ids>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'current_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'current_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'leader_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'leader_id)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <uav_ids>) istream)
  "Deserializes a message object of type '<uav_ids>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'current_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'current_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'leader_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'leader_id)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<uav_ids>)))
  "Returns string type for a message object of type '<uav_ids>"
  "fw_msgs/uav_ids")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'uav_ids)))
  "Returns string type for a message object of type 'uav_ids"
  "fw_msgs/uav_ids")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<uav_ids>)))
  "Returns md5sum for a message object of type '<uav_ids>"
  "5a866f4d93c1cb2b5a3f11036043cf7f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'uav_ids)))
  "Returns md5sum for a message object of type 'uav_ids"
  "5a866f4d93c1cb2b5a3f11036043cf7f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<uav_ids>)))
  "Returns full string definition for message of type '<uav_ids>"
  (cl:format cl:nil "# uav_ids.msg~%~%uint16 current_id~%uint16 leader_id~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'uav_ids)))
  "Returns full string definition for message of type 'uav_ids"
  (cl:format cl:nil "# uav_ids.msg~%~%uint16 current_id~%uint16 leader_id~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <uav_ids>))
  (cl:+ 0
     2
     2
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <uav_ids>))
  "Converts a ROS message object to a list"
  (cl:list 'uav_ids
    (cl:cons ':current_id (current_id msg))
    (cl:cons ':leader_id (leader_id msg))
))
