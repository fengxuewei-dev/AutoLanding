;; Auto-generated. Do not edit!


(when (boundp 'navigator::position_setpoint_triplet)
  (if (not (find-package "NAVIGATOR"))
    (make-package "NAVIGATOR"))
  (shadow 'position_setpoint_triplet (find-package "NAVIGATOR")))
(unless (find-package "NAVIGATOR::POSITION_SETPOINT_TRIPLET")
  (make-package "NAVIGATOR::POSITION_SETPOINT_TRIPLET"))

(in-package "ROS")
;;//! \htmlinclude position_setpoint_triplet.msg.html
(if (not (find-package "MAVROS_MSGS"))
  (ros::roseus-add-msgs "mavros_msgs"))


(defclass navigator::position_setpoint_triplet
  :super ros::object
  :slots (_currentWaypoint _nextWaypoint _Throttle _ExistNext ))

(defmethod navigator::position_setpoint_triplet
  (:init
   (&key
    ((:currentWaypoint __currentWaypoint) (instance mavros_msgs::Waypoint :init))
    ((:nextWaypoint __nextWaypoint) (instance mavros_msgs::Waypoint :init))
    ((:Throttle __Throttle) 0)
    ((:ExistNext __ExistNext) 0)
    )
   (send-super :init)
   (setq _currentWaypoint __currentWaypoint)
   (setq _nextWaypoint __nextWaypoint)
   (setq _Throttle (round __Throttle))
   (setq _ExistNext (round __ExistNext))
   self)
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
  (:Throttle
   (&optional __Throttle)
   (if __Throttle (setq _Throttle __Throttle)) _Throttle)
  (:ExistNext
   (&optional __ExistNext)
   (if __ExistNext (setq _ExistNext __ExistNext)) _ExistNext)
  (:serialization-length
   ()
   (+
    ;; mavros_msgs/Waypoint _currentWaypoint
    (send _currentWaypoint :serialization-length)
    ;; mavros_msgs/Waypoint _nextWaypoint
    (send _nextWaypoint :serialization-length)
    ;; int8 _Throttle
    1
    ;; int8 _ExistNext
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; mavros_msgs/Waypoint _currentWaypoint
       (send _currentWaypoint :serialize s)
     ;; mavros_msgs/Waypoint _nextWaypoint
       (send _nextWaypoint :serialize s)
     ;; int8 _Throttle
       (write-byte _Throttle s)
     ;; int8 _ExistNext
       (write-byte _ExistNext s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; mavros_msgs/Waypoint _currentWaypoint
     (send _currentWaypoint :deserialize buf ptr-) (incf ptr- (send _currentWaypoint :serialization-length))
   ;; mavros_msgs/Waypoint _nextWaypoint
     (send _nextWaypoint :deserialize buf ptr-) (incf ptr- (send _nextWaypoint :serialization-length))
   ;; int8 _Throttle
     (setq _Throttle (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _Throttle 127) (setq _Throttle (- _Throttle 256)))
   ;; int8 _ExistNext
     (setq _ExistNext (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _ExistNext 127) (setq _ExistNext (- _ExistNext 256)))
   ;;
   self)
  )

(setf (get navigator::position_setpoint_triplet :md5sum-) "3fb3b9f9f42aa6f50d1505ea97f3c07f")
(setf (get navigator::position_setpoint_triplet :datatype-) "navigator/position_setpoint_triplet")
(setf (get navigator::position_setpoint_triplet :definition-)
      "# position_setpoint_triplet.msg

mavros_msgs/Waypoint currentWaypoint
mavros_msgs/Waypoint nextWaypoint
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



(provide :navigator/position_setpoint_triplet "3fb3b9f9f42aa6f50d1505ea97f3c07f")


