;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::position_setpoint_triplet)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'position_setpoint_triplet (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::POSITION_SETPOINT_TRIPLET")
  (make-package "FW_MSGS::POSITION_SETPOINT_TRIPLET"))

(in-package "ROS")
;;//! \htmlinclude position_setpoint_triplet.msg.html
(if (not (find-package "MAVROS_MSGS"))
  (ros::roseus-add-msgs "mavros_msgs"))


(defclass fw_msgs::position_setpoint_triplet
  :super ros::object
  :slots (_count_number _selforgheading _currentWaypoint _nextWaypoint _enu_currentWaypoint _enu_nextWaypoint _Throttle _ExistNext ))

(defmethod fw_msgs::position_setpoint_triplet
  (:init
   (&key
    ((:count_number __count_number) 0.0)
    ((:selforgheading __selforgheading) 0.0)
    ((:currentWaypoint __currentWaypoint) (instance mavros_msgs::Waypoint :init))
    ((:nextWaypoint __nextWaypoint) (instance mavros_msgs::Waypoint :init))
    ((:enu_currentWaypoint __enu_currentWaypoint) (instance mavros_msgs::Waypoint :init))
    ((:enu_nextWaypoint __enu_nextWaypoint) (instance mavros_msgs::Waypoint :init))
    ((:Throttle __Throttle) 0)
    ((:ExistNext __ExistNext) 0)
    )
   (send-super :init)
   (setq _count_number (float __count_number))
   (setq _selforgheading (float __selforgheading))
   (setq _currentWaypoint __currentWaypoint)
   (setq _nextWaypoint __nextWaypoint)
   (setq _enu_currentWaypoint __enu_currentWaypoint)
   (setq _enu_nextWaypoint __enu_nextWaypoint)
   (setq _Throttle (round __Throttle))
   (setq _ExistNext (round __ExistNext))
   self)
  (:count_number
   (&optional __count_number)
   (if __count_number (setq _count_number __count_number)) _count_number)
  (:selforgheading
   (&optional __selforgheading)
   (if __selforgheading (setq _selforgheading __selforgheading)) _selforgheading)
  (:currentWaypoint
   (&rest __currentWaypoint)
   (if (keywordp (car __currentWaypoint))
       (send* _currentWaypoint __currentWaypoint)
     (progn
       (if __currentWaypoint (setq _currentWaypoint (car __currentWaypoint)))
       _currentWaypoint)))
  (:nextWaypoint
   (&rest __nextWaypoint)
   (if (keywordp (car __nextWaypoint))
       (send* _nextWaypoint __nextWaypoint)
     (progn
       (if __nextWaypoint (setq _nextWaypoint (car __nextWaypoint)))
       _nextWaypoint)))
  (:enu_currentWaypoint
   (&rest __enu_currentWaypoint)
   (if (keywordp (car __enu_currentWaypoint))
       (send* _enu_currentWaypoint __enu_currentWaypoint)
     (progn
       (if __enu_currentWaypoint (setq _enu_currentWaypoint (car __enu_currentWaypoint)))
       _enu_currentWaypoint)))
  (:enu_nextWaypoint
   (&rest __enu_nextWaypoint)
   (if (keywordp (car __enu_nextWaypoint))
       (send* _enu_nextWaypoint __enu_nextWaypoint)
     (progn
       (if __enu_nextWaypoint (setq _enu_nextWaypoint (car __enu_nextWaypoint)))
       _enu_nextWaypoint)))
  (:Throttle
   (&optional __Throttle)
   (if __Throttle (setq _Throttle __Throttle)) _Throttle)
  (:ExistNext
   (&optional __ExistNext)
   (if __ExistNext (setq _ExistNext __ExistNext)) _ExistNext)
  (:serialization-length
   ()
   (+
    ;; float64 _count_number
    8
    ;; float64 _selforgheading
    8
    ;; mavros_msgs/Waypoint _currentWaypoint
    (send _currentWaypoint :serialization-length)
    ;; mavros_msgs/Waypoint _nextWaypoint
    (send _nextWaypoint :serialization-length)
    ;; mavros_msgs/Waypoint _enu_currentWaypoint
    (send _enu_currentWaypoint :serialization-length)
    ;; mavros_msgs/Waypoint _enu_nextWaypoint
    (send _enu_nextWaypoint :serialization-length)
    ;; int8 _Throttle
    1
    ;; int8 _ExistNext
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _count_number
       (sys::poke _count_number (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _selforgheading
       (sys::poke _selforgheading (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; mavros_msgs/Waypoint _currentWaypoint
       (send _currentWaypoint :serialize s)
     ;; mavros_msgs/Waypoint _nextWaypoint
       (send _nextWaypoint :serialize s)
     ;; mavros_msgs/Waypoint _enu_currentWaypoint
       (send _enu_currentWaypoint :serialize s)
     ;; mavros_msgs/Waypoint _enu_nextWaypoint
       (send _enu_nextWaypoint :serialize s)
     ;; int8 _Throttle
       (write-byte _Throttle s)
     ;; int8 _ExistNext
       (write-byte _ExistNext s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _count_number
     (setq _count_number (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _selforgheading
     (setq _selforgheading (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; mavros_msgs/Waypoint _currentWaypoint
     (send _currentWaypoint :deserialize buf ptr-) (incf ptr- (send _currentWaypoint :serialization-length))
   ;; mavros_msgs/Waypoint _nextWaypoint
     (send _nextWaypoint :deserialize buf ptr-) (incf ptr- (send _nextWaypoint :serialization-length))
   ;; mavros_msgs/Waypoint _enu_currentWaypoint
     (send _enu_currentWaypoint :deserialize buf ptr-) (incf ptr- (send _enu_currentWaypoint :serialization-length))
   ;; mavros_msgs/Waypoint _enu_nextWaypoint
     (send _enu_nextWaypoint :deserialize buf ptr-) (incf ptr- (send _enu_nextWaypoint :serialization-length))
   ;; int8 _Throttle
     (setq _Throttle (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _Throttle 127) (setq _Throttle (- _Throttle 256)))
   ;; int8 _ExistNext
     (setq _ExistNext (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _ExistNext 127) (setq _ExistNext (- _ExistNext 256)))
   ;;
   self)
  )

(setf (get fw_msgs::position_setpoint_triplet :md5sum-) "5c2856e9a0135c7692129a603be86694")
(setf (get fw_msgs::position_setpoint_triplet :datatype-) "fw_msgs/position_setpoint_triplet")
(setf (get fw_msgs::position_setpoint_triplet :definition-)
      "# position_setpoint_triplet.msg

float64 count_number
float64 selforgheading
mavros_msgs/Waypoint currentWaypoint
mavros_msgs/Waypoint nextWaypoint
mavros_msgs/Waypoint enu_currentWaypoint
mavros_msgs/Waypoint enu_nextWaypoint
int8 Throttle
int8 ExistNext

================================================================================
MSG: mavros_msgs/Waypoint
# Waypoint.msg
#
# ROS representation of MAVLink MISSION_ITEM
# See mavlink documentation



# see enum MAV_FRAME
uint8 frame
uint8 FRAME_GLOBAL = 0
uint8 FRAME_LOCAL_NED = 1
uint8 FRAME_MISSION = 2
uint8 FRAME_GLOBAL_REL_ALT = 3
uint8 FRAME_LOCAL_ENU = 4

# see enum MAV_CMD and CommandCode.msg
uint16 command

bool is_current
bool autocontinue
# meaning of this params described in enum MAV_CMD
float32 param1
float32 param2
float32 param3
float32 param4
float64 x_lat
float64 y_long
float64 z_alt

")



(provide :fw_msgs/position_setpoint_triplet "5c2856e9a0135c7692129a603be86694")


