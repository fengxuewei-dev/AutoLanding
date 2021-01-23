; Auto-generated. Do not edit!


(cl:in-package processer-msg)


;//! \htmlinclude uavflag.msg.html

(cl:defclass <uavflag> (roslisp-msg-protocol:ros-message)
  ((group
    :reader group
    :initarg :group
    :type cl:float
    :initform 0.0)
   (isleader
    :reader isleader
    :initarg :isleader
    :type cl:float
    :initform 0.0)
   (leaderid
    :reader leaderid
    :initarg :leaderid
    :type cl:float
    :initform 0.0)
   (myid
    :reader myid
    :initarg :myid
    :type cl:float
    :initform 0.0)
   (gapx
    :reader gapx
    :initarg :gapx
    :type cl:float
    :initform 0.0)
   (gapy
    :reader gapy
    :initarg :gapy
    :type cl:float
    :initform 0.0))
)

(cl:defclass uavflag (<uavflag>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <uavflag>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'uavflag)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name processer-msg:<uavflag> is deprecated: use processer-msg:uavflag instead.")))

(cl:ensure-generic-function 'group-val :lambda-list '(m))
(cl:defmethod group-val ((m <uavflag>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader processer-msg:group-val is deprecated.  Use processer-msg:group instead.")
  (group m))

(cl:ensure-generic-function 'isleader-val :lambda-list '(m))
(cl:defmethod isleader-val ((m <uavflag>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader processer-msg:isleader-val is deprecated.  Use processer-msg:isleader instead.")
  (isleader m))

(cl:ensure-generic-function 'leaderid-val :lambda-list '(m))
(cl:defmethod leaderid-val ((m <uavflag>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader processer-msg:leaderid-val is deprecated.  Use processer-msg:leaderid instead.")
  (leaderid m))

(cl:ensure-generic-function 'myid-val :lambda-list '(m))
(cl:defmethod myid-val ((m <uavflag>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader processer-msg:myid-val is deprecated.  Use processer-msg:myid instead.")
  (myid m))

(cl:ensure-generic-function 'gapx-val :lambda-list '(m))
(cl:defmethod gapx-val ((m <uavflag>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader processer-msg:gapx-val is deprecated.  Use processer-msg:gapx instead.")
  (gapx m))

(cl:ensure-generic-function 'gapy-val :lambda-list '(m))
(cl:defmethod gapy-val ((m <uavflag>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader processer-msg:gapy-val is deprecated.  Use processer-msg:gapy instead.")
  (gapy m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <uavflag>) ostream)
  "Serializes a message object of type '<uavflag>"
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'group))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'isleader))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'leaderid))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'myid))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'gapx))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'gapy))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <uavflag>) istream)
  "Deserializes a message object of type '<uavflag>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'group) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'isleader) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'leaderid) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'myid) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'gapx) (roslisp-utils:decode-single-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'gapy) (roslisp-utils:decode-single-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<uavflag>)))
  "Returns string type for a message object of type '<uavflag>"
  "processer/uavflag")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'uavflag)))
  "Returns string type for a message object of type 'uavflag"
  "processer/uavflag")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<uavflag>)))
  "Returns md5sum for a message object of type '<uavflag>"
  "5d0019540b3060372b57877eb8d6b603")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'uavflag)))
  "Returns md5sum for a message object of type 'uavflag"
  "5d0019540b3060372b57877eb8d6b603")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<uavflag>)))
  "Returns full string definition for message of type '<uavflag>"
  (cl:format cl:nil "# uavflag.msg~%~%float32 group~%float32 isleader~%float32 leaderid~%float32 myid~%float32 gapx~%float32 gapy~%~%# qgccommand 当前状态~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'uavflag)))
  "Returns full string definition for message of type 'uavflag"
  (cl:format cl:nil "# uavflag.msg~%~%float32 group~%float32 isleader~%float32 leaderid~%float32 myid~%float32 gapx~%float32 gapy~%~%# qgccommand 当前状态~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <uavflag>))
  (cl:+ 0
     4
     4
     4
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <uavflag>))
  "Converts a ROS message object to a list"
  (cl:list 'uavflag
    (cl:cons ':group (group msg))
    (cl:cons ':isleader (isleader msg))
    (cl:cons ':leaderid (leaderid msg))
    (cl:cons ':myid (myid msg))
    (cl:cons ':gapx (gapx msg))
    (cl:cons ':gapy (gapy msg))
))
