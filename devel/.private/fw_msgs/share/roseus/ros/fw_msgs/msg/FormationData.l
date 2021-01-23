;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::FormationData)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'FormationData (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::FORMATIONDATA")
  (make-package "FW_MSGS::FORMATIONDATA"))

(in-package "ROS")
;;//! \htmlinclude FormationData.msg.html


(defclass fw_msgs::FormationData
  :super ros::object
  :slots (_count_number _position_x _position_y _position_z _homeLat _homeLon _homeAlt _gps_time _leaderHeading _leaderCommand_yaw _leaderAirspeed ))

(defmethod fw_msgs::FormationData
  (:init
   (&key
    ((:count_number __count_number) 0.0)
    ((:position_x __position_x) 0.0)
    ((:position_y __position_y) 0.0)
    ((:position_z __position_z) 0.0)
    ((:homeLat __homeLat) 0.0)
    ((:homeLon __homeLon) 0.0)
    ((:homeAlt __homeAlt) 0.0)
    ((:gps_time __gps_time) (instance ros::time :init))
    ((:leaderHeading __leaderHeading) 0.0)
    ((:leaderCommand_yaw __leaderCommand_yaw) 0.0)
    ((:leaderAirspeed __leaderAirspeed) 0.0)
    )
   (send-super :init)
   (setq _count_number (float __count_number))
   (setq _position_x (float __position_x))
   (setq _position_y (float __position_y))
   (setq _position_z (float __position_z))
   (setq _homeLat (float __homeLat))
   (setq _homeLon (float __homeLon))
   (setq _homeAlt (float __homeAlt))
   (setq _gps_time __gps_time)
   (setq _leaderHeading (float __leaderHeading))
   (setq _leaderCommand_yaw (float __leaderCommand_yaw))
   (setq _leaderAirspeed (float __leaderAirspeed))
   self)
  (:count_number
   (&optional __count_number)
   (if __count_number (setq _count_number __count_number)) _count_number)
  (:position_x
   (&optional __position_x)
   (if __position_x (setq _position_x __position_x)) _position_x)
  (:position_y
   (&optional __position_y)
   (if __position_y (setq _position_y __position_y)) _position_y)
  (:position_z
   (&optional __position_z)
   (if __position_z (setq _position_z __position_z)) _position_z)
  (:homeLat
   (&optional __homeLat)
   (if __homeLat (setq _homeLat __homeLat)) _homeLat)
  (:homeLon
   (&optional __homeLon)
   (if __homeLon (setq _homeLon __homeLon)) _homeLon)
  (:homeAlt
   (&optional __homeAlt)
   (if __homeAlt (setq _homeAlt __homeAlt)) _homeAlt)
  (:gps_time
   (&optional __gps_time)
   (if __gps_time (setq _gps_time __gps_time)) _gps_time)
  (:leaderHeading
   (&optional __leaderHeading)
   (if __leaderHeading (setq _leaderHeading __leaderHeading)) _leaderHeading)
  (:leaderCommand_yaw
   (&optional __leaderCommand_yaw)
   (if __leaderCommand_yaw (setq _leaderCommand_yaw __leaderCommand_yaw)) _leaderCommand_yaw)
  (:leaderAirspeed
   (&optional __leaderAirspeed)
   (if __leaderAirspeed (setq _leaderAirspeed __leaderAirspeed)) _leaderAirspeed)
  (:serialization-length
   ()
   (+
    ;; float64 _count_number
    8
    ;; float64 _position_x
    8
    ;; float64 _position_y
    8
    ;; float64 _position_z
    8
    ;; float64 _homeLat
    8
    ;; float64 _homeLon
    8
    ;; float64 _homeAlt
    8
    ;; time _gps_time
    8
    ;; float64 _leaderHeading
    8
    ;; float64 _leaderCommand_yaw
    8
    ;; float64 _leaderAirspeed
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _count_number
       (sys::poke _count_number (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _position_x
       (sys::poke _position_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _position_y
       (sys::poke _position_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _position_z
       (sys::poke _position_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _homeLat
       (sys::poke _homeLat (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _homeLon
       (sys::poke _homeLon (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _homeAlt
       (sys::poke _homeAlt (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; time _gps_time
       (write-long (send _gps_time :sec) s) (write-long (send _gps_time :nsec) s)
     ;; float64 _leaderHeading
       (sys::poke _leaderHeading (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _leaderCommand_yaw
       (sys::poke _leaderCommand_yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _leaderAirspeed
       (sys::poke _leaderAirspeed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _count_number
     (setq _count_number (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _position_x
     (setq _position_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _position_y
     (setq _position_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _position_z
     (setq _position_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _homeLat
     (setq _homeLat (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _homeLon
     (setq _homeLon (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _homeAlt
     (setq _homeAlt (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; time _gps_time
     (send _gps_time :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _gps_time :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _leaderHeading
     (setq _leaderHeading (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _leaderCommand_yaw
     (setq _leaderCommand_yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _leaderAirspeed
     (setq _leaderAirspeed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get fw_msgs::FormationData :md5sum-) "2928bb8a289249d6e0ebeda4942d0551")
(setf (get fw_msgs::FormationData :datatype-) "fw_msgs/FormationData")
(setf (get fw_msgs::FormationData :definition-)
      "# FormationData.msg

float64 count_number
float64 position_x
float64 position_y
float64 position_z

float64 homeLat
float64 homeLon
float64 homeAlt
time gps_time

float64 leaderHeading
float64 leaderCommand_yaw
float64 leaderAirspeed
")



(provide :fw_msgs/FormationData "2928bb8a289249d6e0ebeda4942d0551")


