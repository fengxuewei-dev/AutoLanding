;; Auto-generated. Do not edit!


(when (boundp 'fw_att_control::commands)
  (if (not (find-package "FW_ATT_CONTROL"))
    (make-package "FW_ATT_CONTROL"))
  (shadow 'commands (find-package "FW_ATT_CONTROL")))
(unless (find-package "FW_ATT_CONTROL::COMMANDS")
  (make-package "FW_ATT_CONTROL::COMMANDS"))

(in-package "ROS")
;;//! \htmlinclude commands.msg.html


(defclass fw_att_control::commands
  :super ros::object
  :slots (_yaw _throttle _roll _pitch ))

(defmethod fw_att_control::commands
  (:init
   (&key
    ((:yaw __yaw) 0.0)
    ((:throttle __throttle) 0.0)
    ((:roll __roll) 0.0)
    ((:pitch __pitch) 0.0)
    )
   (send-super :init)
   (setq _yaw (float __yaw))
   (setq _throttle (float __throttle))
   (setq _roll (float __roll))
   (setq _pitch (float __pitch))
   self)
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

(setf (get fw_att_control::commands :md5sum-) "3ed53da7ed658276464982ccd25dbfcd")
(setf (get fw_att_control::commands :datatype-) "fw_att_control/commands")
(setf (get fw_att_control::commands :definition-)
      "# commands.msg

float32 yaw
float32 throttle
float32 roll
float32 pitch

")



(provide :fw_att_control/commands "3ed53da7ed658276464982ccd25dbfcd")


