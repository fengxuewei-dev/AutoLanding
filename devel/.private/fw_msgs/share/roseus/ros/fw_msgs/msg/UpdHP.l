;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::UpdHP)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'UpdHP (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::UPDHP")
  (make-package "FW_MSGS::UPDHP"))

(in-package "ROS")
;;//! \htmlinclude UpdHP.msg.html


(defclass fw_msgs::UpdHP
  :super ros::object
  :slots (_messageid _uavid _longitude _latitude _altitude _parity ))

(defmethod fw_msgs::UpdHP
  (:init
   (&key
    ((:messageid __messageid) 0)
    ((:uavid __uavid) 0)
    ((:longitude __longitude) 0.0)
    ((:latitude __latitude) 0.0)
    ((:altitude __altitude) 0.0)
    ((:parity __parity) 0)
    )
   (send-super :init)
   (setq _messageid (round __messageid))
   (setq _uavid (round __uavid))
   (setq _longitude (float __longitude))
   (setq _latitude (float __latitude))
   (setq _altitude (float __altitude))
   (setq _parity (round __parity))
   self)
  (:messageid
   (&optional __messageid)
   (if __messageid (setq _messageid __messageid)) _messageid)
  (:uavid
   (&optional __uavid)
   (if __uavid (setq _uavid __uavid)) _uavid)
  (:longitude
   (&optional __longitude)
   (if __longitude (setq _longitude __longitude)) _longitude)
  (:latitude
   (&optional __latitude)
   (if __latitude (setq _latitude __latitude)) _latitude)
  (:altitude
   (&optional __altitude)
   (if __altitude (setq _altitude __altitude)) _altitude)
  (:parity
   (&optional __parity)
   (if __parity (setq _parity __parity)) _parity)
  (:serialization-length
   ()
   (+
    ;; uint16 _messageid
    2
    ;; uint16 _uavid
    2
    ;; float64 _longitude
    8
    ;; float64 _latitude
    8
    ;; float64 _altitude
    8
    ;; int32 _parity
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _messageid
       (write-word _messageid s)
     ;; uint16 _uavid
       (write-word _uavid s)
     ;; float64 _longitude
       (sys::poke _longitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _latitude
       (sys::poke _latitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _altitude
       (sys::poke _altitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int32 _parity
       (write-long _parity s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _messageid
     (setq _messageid (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _uavid
     (setq _uavid (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float64 _longitude
     (setq _longitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _latitude
     (setq _latitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _altitude
     (setq _altitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int32 _parity
     (setq _parity (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get fw_msgs::UpdHP :md5sum-) "7f25d391682710b024a661224416d7c4")
(setf (get fw_msgs::UpdHP :datatype-) "fw_msgs/UpdHP")
(setf (get fw_msgs::UpdHP :definition-)
      "# UDPMessage.msg

uint16 messageid
uint16 uavid
float64 longitude
float64 latitude
float64 altitude 
int32 parity
")



(provide :fw_msgs/UpdHP "7f25d391682710b024a661224416d7c4")


