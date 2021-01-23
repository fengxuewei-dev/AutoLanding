;; Auto-generated. Do not edit!


(when (boundp 'mavros_msgs::Commands)
  (if (not (find-package "MAVROS_MSGS"))
    (make-package "MAVROS_MSGS"))
  (shadow 'Commands (find-package "MAVROS_MSGS")))
(unless (find-package "MAVROS_MSGS::COMMANDS")
  (make-package "MAVROS_MSGS::COMMANDS"))

(in-package "ROS")
;;//! \htmlinclude Commands.msg.html


(defclass mavros_msgs::Commands
  :super ros::object
  :slots (_altitude _yaw _throttle _roll _pitch ))

(defmethod mavros_msgs::Commands
  (:init
   (&key
    ((:altitude __altitude) 0.0)
    ((:yaw __yaw) 0.0)
    ((:throttle __throttle) 0.0)
    ((:roll __roll) 0.0)
    ((:pitch __pitch) 0.0)
    )
   (send-super :init)
   (setq _altitude (float __altitude))
   (setq _yaw (float __yaw))
   (setq _throttle (float __throttle))
   (setq _roll (float __roll))
   (setq _pitch (float __pitch))
   self)
  (:altitude
   (&optional __altitude)
   (if __altitude (setq _altitude __altitude)) _altitude)
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:throttle
   (&optional __throttle)
   (if __throttle (setq _throttle __throttle)) _throttle)
  (:roll
   (&optional __roll)
   (if __roll (setq _roll __roll)) _roll)
  (:pitch
   (&optional __pitch)
   (if __pitch (setq _pitch __pitch)) _pitch)
  (:serialization-length
   ()
   (+
    ;; float32 _altitude
    4
    ;; float32 _yaw
    4
    ;; float32 _throttle
    4
    ;; float32 _roll
    4
    ;; float32 _pitch
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _altitude
       (sys::poke _altitude (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _yaw
       (sys::poke _yaw (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _throttle
       (sys::poke _throttle (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _roll
       (sys::poke _roll (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _pitch
       (sys::poke _pitch (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _altitude
     (setq _altitude (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _yaw
     (setq _yaw (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _throttle
     (setq _throttle (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _roll
     (setq _roll (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _pitch
     (setq _pitch (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get mavros_msgs::Commands :md5sum-) "af1cda18f844353b7524568098cfa306")
(setf (get mavros_msgs::Commands :datatype-) "mavros_msgs/Commands")
(setf (get mavros_msgs::Commands :definition-)
      "# Commands.msg

float32 altitude
float32 yaw
float32 throttle
float32 roll
float32 pitch

")



(provide :mavros_msgs/Commands "af1cda18f844353b7524568098cfa306")


