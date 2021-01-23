;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::target)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'target (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::TARGET")
  (make-package "FW_MSGS::TARGET"))

(in-package "ROS")
;;//! \htmlinclude target.msg.html


(defclass fw_msgs::target
  :super ros::object
  :slots (_targetid _latitude _longitude _altitude ))

(defmethod fw_msgs::target
  (:init
   (&key
    ((:targetid __targetid) 0)
    ((:latitude __latitude) 0.0)
    ((:longitude __longitude) 0.0)
    ((:altitude __altitude) 0.0)
    )
   (send-super :init)
   (setq _targetid (round __targetid))
   (setq _latitude (float __latitude))
   (setq _longitude (float __longitude))
   (setq _altitude (float __altitude))
   self)
  (:targetid
   (&optional __targetid)
   (if __targetid (setq _targetid __targetid)) _targetid)
  (:latitude
   (&optional __latitude)
   (if __latitude (setq _latitude __latitude)) _latitude)
  (:longitude
   (&optional __longitude)
   (if __longitude (setq _longitude __longitude)) _longitude)
  (:altitude
   (&optional __altitude)
   (if __altitude (setq _altitude __altitude)) _altitude)
  (:serialization-length
   ()
   (+
    ;; int32 _targetid
    4
    ;; float64 _latitude
    8
    ;; float64 _longitude
    8
    ;; float64 _altitude
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _targetid
       (write-long _targetid s)
     ;; float64 _latitude
       (sys::poke _latitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _longitude
       (sys::poke _longitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _altitude
       (sys::poke _altitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _targetid
     (setq _targetid (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _latitude
     (setq _latitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _longitude
     (setq _longitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _altitude
     (setq _altitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get fw_msgs::target :md5sum-) "0ec4af83b47a479a022174259329355a")
(setf (get fw_msgs::target :datatype-) "fw_msgs/target")
(setf (get fw_msgs::target :definition-)
      "# target.msg

int32 targetid
float64 latitude
float64 longitude
float64 altitude

")



(provide :fw_msgs/target "0ec4af83b47a479a022174259329355a")


