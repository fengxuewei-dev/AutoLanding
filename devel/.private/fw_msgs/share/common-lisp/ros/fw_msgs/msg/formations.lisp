; Auto-generated. Do not edit!


(cl:in-package fw_msgs-msg)


;//! \htmlinclude formations.msg.html

(cl:defclass <formations> (roslisp-msg-protocol:ros-message)
  ((formationShape
    :reader formationShape
    :initarg :formationShape
    :type cl:string
    :initform ""))
)

(cl:defclass formations (<formations>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <formations>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'formations)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name fw_msgs-msg:<formations> is deprecated: use fw_msgs-msg:formations instead.")))

(cl:ensure-generic-function 'formationShape-val :lambda-list '(m))
(cl:defmethod formationShape-val ((m <formations>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader fw_msgs-msg:formationShape-val is deprecated.  Use fw_msgs-msg:formationShape instead.")
  (formationShape m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <formations>) ostream)
  "Serializes a message object of type '<formations>"
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'formationShape))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'formationShape))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <formations>) istream)
  "Deserializes a message object of type '<formations>"
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'formationShape) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'formationShape) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<formations>)))
  "Returns string type for a message object of type '<formations>"
  "fw_msgs/formations")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'formations)))
  "Returns string type for a message object of type 'formations"
  "fw_msgs/formations")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<formations>)))
  "Returns md5sum for a message object of type '<formations>"
  "cb4dc526361d96c967f22a663f5d3a2a")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'formations)))
  "Returns md5sum for a message object of type 'formations"
  "cb4dc526361d96c967f22a663f5d3a2a")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<formations>)))
  "Returns full string definition for message of type '<formations>"
  (cl:format cl:nil "# formations.msg~%~%string formationShape ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'formations)))
  "Returns full string definition for message of type 'formations"
  (cl:format cl:nil "# formations.msg~%~%string formationShape ~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <formations>))
  (cl:+ 0
     4 (cl:length (cl:slot-value msg 'formationShape))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <formations>))
  "Converts a ROS message object to a list"
  (cl:list 'formations
    (cl:cons ':formationShape (formationShape msg))
))
