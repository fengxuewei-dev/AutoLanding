;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::commands)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'commands (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::COMMANDS")
  (make-package "FW_MSGS::COMMANDS"))

(in-package "ROS")
;;//! \htmlinclude commands.msg.html


(defclass fw_msgs::commands
  :super ros::object
  :slots (_count_number _yaw _throttle _roll _pitch ))

(defmethod fw_msgs::commands
  (:init
   (&key
    ((:count_number __count_number) 0.0)
    ((:yaw __yaw) 0.0)
    ((:throttle __throttle) 0.0)
    ((:roll __roll) 0.0)
    ((:pitch __pitch) 0.0)
    )
   (send-super :init)
   (setq _count_number (float __count_number))
   (setq _yaw (float __yaw))
   (setq _throttle (float __throttle))
   (setq _roll (float __roll))
   (setq _pitch (float __pitch))
   self)
  (:count_number
   (&optional __count_number)
   (if __count_number (setq _count_number __count_number)) _count_number)
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
    ;; float64 _count_number
    8
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
     ;; float64 _count_number
       (sys::poke _count_number (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
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
   ;; float64 _count_number
     (setq _count_number (sys::peek buf ptr- :double)) (incf ptr- 8)
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

(setf (get fw_msgs::commands :md5sum-) "73a1c84c794a64e07f2b99ac4fa81c59")
(setf (get fw_msgs::commands :datatype-) "fw_msgs/commands")
(setf (get fw_msgs::commands :definition-)
      "# commands.msg

float64 count_number
float32 yaw
float32 throttle
float32 roll
float32 pitch

")



(provide :fw_msgs/commands "73a1c84c794a64e07f2b99ac4fa81c59")


