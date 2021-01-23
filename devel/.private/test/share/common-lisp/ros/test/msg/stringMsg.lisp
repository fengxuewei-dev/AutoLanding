; Auto-generated. Do not edit!


(cl:in-package test-msg)


;//! \htmlinclude stringMsg.msg.html

(cl:defclass <stringMsg> (roslisp-msg-protocol:ros-message)
  ((number
    :reader number
    :initarg :number
    :type cl:integer
    :initform 0)
   (testData1
    :reader testData1
    :initarg :testData1
    :type cl:integer
    :initform 0)
   (testData2
    :reader testData2
    :initarg :testData2
    :type cl:integer
    :initform 0))
)

(cl:defclass stringMsg (<stringMsg>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <stringMsg>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'stringMsg)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name test-msg:<stringMsg> is deprecated: use test-msg:stringMsg instead.")))

(cl:ensure-generic-function 'number-val :lambda-list '(m))
(cl:defmethod number-val ((m <stringMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:number-val is deprecated.  Use test-msg:number instead.")
  (number m))

(cl:ensure-generic-function 'testData1-val :lambda-list '(m))
(cl:defmethod testData1-val ((m <stringMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:testData1-val is deprecated.  Use test-msg:testData1 instead.")
  (testData1 m))

(cl:ensure-generic-function 'testData2-val :lambda-list '(m))
(cl:defmethod testData2-val ((m <stringMsg>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader test-msg:testData2-val is deprecated.  Use test-msg:testData2 instead.")
  (testData2 m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <stringMsg>) ostream)
  "Serializes a message object of type '<stringMsg>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'number)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'testData1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'testData1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'testData1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'testData1)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'testData2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'testData2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'testData2)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'testData2)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <stringMsg>) istream)
  "Deserializes a message object of type '<stringMsg>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'number)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'number)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'number)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'number)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'testData1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'testData1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'testData1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'testData1)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'testData2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'testData2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'testData2)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'testData2)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<stringMsg>)))
  "Returns string type for a message object of type '<stringMsg>"
  "test/stringMsg")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'stringMsg)))
  "Returns string type for a message object of type 'stringMsg"
  "test/stringMsg")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<stringMsg>)))
  "Returns md5sum for a message object of type '<stringMsg>"
  "ceb80582456c5541e317ccd118b86605")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'stringMsg)))
  "Returns md5sum for a message object of type 'stringMsg"
  "ceb80582456c5541e317ccd118b86605")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<stringMsg>)))
  "Returns full string definition for message of type '<stringMsg>"
  (cl:format cl:nil "# stringMsg.msg~%~%uint32 number~%uint32 testData1~%uint32 testData2~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'stringMsg)))
  "Returns full string definition for message of type 'stringMsg"
  (cl:format cl:nil "# stringMsg.msg~%~%uint32 number~%uint32 testData1~%uint32 testData2~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <stringMsg>))
  (cl:+ 0
     4
     4
     4
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <stringMsg>))
  "Converts a ROS message object to a list"
  (cl:list 'stringMsg
    (cl:cons ':number (number msg))
    (cl:cons ':testData1 (testData1 msg))
    (cl:cons ':testData2 (testData2 msg))
))
