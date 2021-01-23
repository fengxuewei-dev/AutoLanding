;; Auto-generated. Do not edit!


(when (boundp 'mavros_msgs::Formation_fixed_wing)
  (if (not (find-package "MAVROS_MSGS"))
    (make-package "MAVROS_MSGS"))
  (shadow 'Formation_fixed_wing (find-package "MAVROS_MSGS")))
(unless (find-package "MAVROS_MSGS::FORMATION_FIXED_WING")
  (make-package "MAVROS_MSGS::FORMATION_FIXED_WING"))

(in-package "ROS")
;;//! \htmlinclude Formation_fixed_wing.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass mavros_msgs::Formation_fixed_wing
  :super ros::object
  :slots (_planeID _targ_planeID _altitude_lock _in_air _mode _orientation _ground_speed_ned_param1 _ground_speed_ned_param2 _ground_speed _global_vel_x _global_vel_y _global_vel_z _air_speed _wind_estimate_x _wind_estimate_y _wind_estimate_z _relative_hight _latitude _altitude _longtitude _relative_alt _ned_altitude _ned_pos_x _ned_pos_y _ned_pos_z _ned_vel_x _ned_vel_y _ned_vel_z _ned_acc_x _ned_acc_y _ned_acc_z _ned_acc _body_acc_x _body_acc_y _body_acc_z _body_acc _pitch_angle _yaw_angle _roll_angle _battery_voltage _battery_precentage _battery_current ))

(defmethod mavros_msgs::Formation_fixed_wing
  (:init
   (&key
    ((:planeID __planeID) 0)
    ((:targ_planeID __targ_planeID) 0)
    ((:altitude_lock __altitude_lock) nil)
    ((:in_air __in_air) nil)
    ((:mode __mode) "")
    ((:orientation __orientation) (instance geometry_msgs::Quaternion :init))
    ((:ground_speed_ned_param1 __ground_speed_ned_param1) 0.0)
    ((:ground_speed_ned_param2 __ground_speed_ned_param2) 0.0)
    ((:ground_speed __ground_speed) 0.0)
    ((:global_vel_x __global_vel_x) 0.0)
    ((:global_vel_y __global_vel_y) 0.0)
    ((:global_vel_z __global_vel_z) 0.0)
    ((:air_speed __air_speed) 0.0)
    ((:wind_estimate_x __wind_estimate_x) 0.0)
    ((:wind_estimate_y __wind_estimate_y) 0.0)
    ((:wind_estimate_z __wind_estimate_z) 0.0)
    ((:relative_hight __relative_hight) 0.0)
    ((:latitude __latitude) 0.0)
    ((:altitude __altitude) 0.0)
    ((:longtitude __longtitude) 0.0)
    ((:relative_alt __relative_alt) 0.0)
    ((:ned_altitude __ned_altitude) 0.0)
    ((:ned_pos_x __ned_pos_x) 0.0)
    ((:ned_pos_y __ned_pos_y) 0.0)
    ((:ned_pos_z __ned_pos_z) 0.0)
    ((:ned_vel_x __ned_vel_x) 0.0)
    ((:ned_vel_y __ned_vel_y) 0.0)
    ((:ned_vel_z __ned_vel_z) 0.0)
    ((:ned_acc_x __ned_acc_x) 0.0)
    ((:ned_acc_y __ned_acc_y) 0.0)
    ((:ned_acc_z __ned_acc_z) 0.0)
    ((:ned_acc __ned_acc) (instance geometry_msgs::Vector3 :init))
    ((:body_acc_x __body_acc_x) 0.0)
    ((:body_acc_y __body_acc_y) 0.0)
    ((:body_acc_z __body_acc_z) 0.0)
    ((:body_acc __body_acc) (instance geometry_msgs::Vector3 :init))
    ((:pitch_angle __pitch_angle) 0.0)
    ((:yaw_angle __yaw_angle) 0.0)
    ((:roll_angle __roll_angle) 0.0)
    ((:battery_voltage __battery_voltage) 0.0)
    ((:battery_precentage __battery_precentage) 0.0)
    ((:battery_current __battery_current) 0.0)
    )
   (send-super :init)
   (setq _planeID (round __planeID))
   (setq _targ_planeID (round __targ_planeID))
   (setq _altitude_lock __altitude_lock)
   (setq _in_air __in_air)
   (setq _mode (string __mode))
   (setq _orientation __orientation)
   (setq _ground_speed_ned_param1 (float __ground_speed_ned_param1))
   (setq _ground_speed_ned_param2 (float __ground_speed_ned_param2))
   (setq _ground_speed (float __ground_speed))
   (setq _global_vel_x (float __global_vel_x))
   (setq _global_vel_y (float __global_vel_y))
   (setq _global_vel_z (float __global_vel_z))
   (setq _air_speed (float __air_speed))
   (setq _wind_estimate_x (float __wind_estimate_x))
   (setq _wind_estimate_y (float __wind_estimate_y))
   (setq _wind_estimate_z (float __wind_estimate_z))
   (setq _relative_hight (float __relative_hight))
   (setq _latitude (float __latitude))
   (setq _altitude (float __altitude))
   (setq _longtitude (float __longtitude))
   (setq _relative_alt (float __relative_alt))
   (setq _ned_altitude (float __ned_altitude))
   (setq _ned_pos_x (float __ned_pos_x))
   (setq _ned_pos_y (float __ned_pos_y))
   (setq _ned_pos_z (float __ned_pos_z))
   (setq _ned_vel_x (float __ned_vel_x))
   (setq _ned_vel_y (float __ned_vel_y))
   (setq _ned_vel_z (float __ned_vel_z))
   (setq _ned_acc_x (float __ned_acc_x))
   (setq _ned_acc_y (float __ned_acc_y))
   (setq _ned_acc_z (float __ned_acc_z))
   (setq _ned_acc __ned_acc)
   (setq _body_acc_x (float __body_acc_x))
   (setq _body_acc_y (float __body_acc_y))
   (setq _body_acc_z (float __body_acc_z))
   (setq _body_acc __body_acc)
   (setq _pitch_angle (float __pitch_angle))
   (setq _yaw_angle (float __yaw_angle))
   (setq _roll_angle (float __roll_angle))
   (setq _battery_voltage (float __battery_voltage))
   (setq _battery_precentage (float __battery_precentage))
   (setq _battery_current (float __battery_current))
   self)
  (:planeID
   (&optional __planeID)
   (if __planeID (setq _planeID __planeID)) _planeID)
  (:targ_planeID
   (&optional __targ_planeID)
   (if __targ_planeID (setq _targ_planeID __targ_planeID)) _targ_planeID)
  (:altitude_lock
   (&optional __altitude_lock)
   (if __altitude_lock (setq _altitude_lock __altitude_lock)) _altitude_lock)
  (:in_air
   (&optional __in_air)
   (if __in_air (setq _in_air __in_air)) _in_air)
  (:mode
   (&optional __mode)
   (if __mode (setq _mode __mode)) _mode)
  (:orientation
   (&rest __orientation)
   (if (keywordp (car __orientation))
       (send* _orientation __orientation)
     (progn
       (if __orientation (setq _orientation (car __orientation)))
       _orientation)))
  (:ground_speed_ned_param1
   (&optional __ground_speed_ned_param1)
   (if __ground_speed_ned_param1 (setq _ground_speed_ned_param1 __ground_speed_ned_param1)) _ground_speed_ned_param1)
  (:ground_speed_ned_param2
   (&optional __ground_speed_ned_param2)
   (if __ground_speed_ned_param2 (setq _ground_speed_ned_param2 __ground_speed_ned_param2)) _ground_speed_ned_param2)
  (:ground_speed
   (&optional __ground_speed)
   (if __ground_speed (setq _ground_speed __ground_speed)) _ground_speed)
  (:global_vel_x
   (&optional __global_vel_x)
   (if __global_vel_x (setq _global_vel_x __global_vel_x)) _global_vel_x)
  (:global_vel_y
   (&optional __global_vel_y)
   (if __global_vel_y (setq _global_vel_y __global_vel_y)) _global_vel_y)
  (:global_vel_z
   (&optional __global_vel_z)
   (if __global_vel_z (setq _global_vel_z __global_vel_z)) _global_vel_z)
  (:air_speed
   (&optional __air_speed)
   (if __air_speed (setq _air_speed __air_speed)) _air_speed)
  (:wind_estimate_x
   (&optional __wind_estimate_x)
   (if __wind_estimate_x (setq _wind_estimate_x __wind_estimate_x)) _wind_estimate_x)
  (:wind_estimate_y
   (&optional __wind_estimate_y)
   (if __wind_estimate_y (setq _wind_estimate_y __wind_estimate_y)) _wind_estimate_y)
  (:wind_estimate_z
   (&optional __wind_estimate_z)
   (if __wind_estimate_z (setq _wind_estimate_z __wind_estimate_z)) _wind_estimate_z)
  (:relative_hight
   (&optional __relative_hight)
   (if __relative_hight (setq _relative_hight __relative_hight)) _relative_hight)
  (:latitude
   (&optional __latitude)
   (if __latitude (setq _latitude __latitude)) _latitude)
  (:altitude
   (&optional __altitude)
   (if __altitude (setq _altitude __altitude)) _altitude)
  (:longtitude
   (&optional __longtitude)
   (if __longtitude (setq _longtitude __longtitude)) _longtitude)
  (:relative_alt
   (&optional __relative_alt)
   (if __relative_alt (setq _relative_alt __relative_alt)) _relative_alt)
  (:ned_altitude
   (&optional __ned_altitude)
   (if __ned_altitude (setq _ned_altitude __ned_altitude)) _ned_altitude)
  (:ned_pos_x
   (&optional __ned_pos_x)
   (if __ned_pos_x (setq _ned_pos_x __ned_pos_x)) _ned_pos_x)
  (:ned_pos_y
   (&optional __ned_pos_y)
   (if __ned_pos_y (setq _ned_pos_y __ned_pos_y)) _ned_pos_y)
  (:ned_pos_z
   (&optional __ned_pos_z)
   (if __ned_pos_z (setq _ned_pos_z __ned_pos_z)) _ned_pos_z)
  (:ned_vel_x
   (&optional __ned_vel_x)
   (if __ned_vel_x (setq _ned_vel_x __ned_vel_x)) _ned_vel_x)
  (:ned_vel_y
   (&optional __ned_vel_y)
   (if __ned_vel_y (setq _ned_vel_y __ned_vel_y)) _ned_vel_y)
  (:ned_vel_z
   (&optional __ned_vel_z)
   (if __ned_vel_z (setq _ned_vel_z __ned_vel_z)) _ned_vel_z)
  (:ned_acc_x
   (&optional __ned_acc_x)
   (if __ned_acc_x (setq _ned_acc_x __ned_acc_x)) _ned_acc_x)
  (:ned_acc_y
   (&optional __ned_acc_y)
   (if __ned_acc_y (setq _ned_acc_y __ned_acc_y)) _ned_acc_y)
  (:ned_acc_z
   (&optional __ned_acc_z)
   (if __ned_acc_z (setq _ned_acc_z __ned_acc_z)) _ned_acc_z)
  (:ned_acc
   (&rest __ned_acc)
   (if (keywordp (car __ned_acc))
       (send* _ned_acc __ned_acc)
     (progn
       (if __ned_acc (setq _ned_acc (car __ned_acc)))
       _ned_acc)))
  (:body_acc_x
   (&optional __body_acc_x)
   (if __body_acc_x (setq _body_acc_x __body_acc_x)) _body_acc_x)
  (:body_acc_y
   (&optional __body_acc_y)
   (if __body_acc_y (setq _body_acc_y __body_acc_y)) _body_acc_y)
  (:body_acc_z
   (&optional __body_acc_z)
   (if __body_acc_z (setq _body_acc_z __body_acc_z)) _body_acc_z)
  (:body_acc
   (&rest __body_acc)
   (if (keywordp (car __body_acc))
       (send* _body_acc __body_acc)
     (progn
       (if __body_acc (setq _body_acc (car __body_acc)))
       _body_acc)))
  (:pitch_angle
   (&optional __pitch_angle)
   (if __pitch_angle (setq _pitch_angle __pitch_angle)) _pitch_angle)
  (:yaw_angle
   (&optional __yaw_angle)
   (if __yaw_angle (setq _yaw_angle __yaw_angle)) _yaw_angle)
  (:roll_angle
   (&optional __roll_angle)
   (if __roll_angle (setq _roll_angle __roll_angle)) _roll_angle)
  (:battery_voltage
   (&optional __battery_voltage)
   (if __battery_voltage (setq _battery_voltage __battery_voltage)) _battery_voltage)
  (:battery_precentage
   (&optional __battery_precentage)
   (if __battery_precentage (setq _battery_precentage __battery_precentage)) _battery_precentage)
  (:battery_current
   (&optional __battery_current)
   (if __battery_current (setq _battery_current __battery_current)) _battery_current)
  (:serialization-length
   ()
   (+
    ;; uint16 _planeID
    2
    ;; uint16 _targ_planeID
    2
    ;; bool _altitude_lock
    1
    ;; bool _in_air
    1
    ;; string _mode
    4 (length _mode)
    ;; geometry_msgs/Quaternion _orientation
    (send _orientation :serialization-length)
    ;; float64 _ground_speed_ned_param1
    8
    ;; float64 _ground_speed_ned_param2
    8
    ;; float64 _ground_speed
    8
    ;; float64 _global_vel_x
    8
    ;; float64 _global_vel_y
    8
    ;; float64 _global_vel_z
    8
    ;; float64 _air_speed
    8
    ;; float64 _wind_estimate_x
    8
    ;; float64 _wind_estimate_y
    8
    ;; float64 _wind_estimate_z
    8
    ;; float64 _relative_hight
    8
    ;; float64 _latitude
    8
    ;; float64 _altitude
    8
    ;; float64 _longtitude
    8
    ;; float64 _relative_alt
    8
    ;; float64 _ned_altitude
    8
    ;; float64 _ned_pos_x
    8
    ;; float64 _ned_pos_y
    8
    ;; float64 _ned_pos_z
    8
    ;; float64 _ned_vel_x
    8
    ;; float64 _ned_vel_y
    8
    ;; float64 _ned_vel_z
    8
    ;; float64 _ned_acc_x
    8
    ;; float64 _ned_acc_y
    8
    ;; float64 _ned_acc_z
    8
    ;; geometry_msgs/Vector3 _ned_acc
    (send _ned_acc :serialization-length)
    ;; float64 _body_acc_x
    8
    ;; float64 _body_acc_y
    8
    ;; float64 _body_acc_z
    8
    ;; geometry_msgs/Vector3 _body_acc
    (send _body_acc :serialization-length)
    ;; float64 _pitch_angle
    8
    ;; float64 _yaw_angle
    8
    ;; float64 _roll_angle
    8
    ;; float64 _battery_voltage
    8
    ;; float64 _battery_precentage
    8
    ;; float64 _battery_current
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _planeID
       (write-word _planeID s)
     ;; uint16 _targ_planeID
       (write-word _targ_planeID s)
     ;; bool _altitude_lock
       (if _altitude_lock (write-byte -1 s) (write-byte 0 s))
     ;; bool _in_air
       (if _in_air (write-byte -1 s) (write-byte 0 s))
     ;; string _mode
       (write-long (length _mode) s) (princ _mode s)
     ;; geometry_msgs/Quaternion _orientation
       (send _orientation :serialize s)
     ;; float64 _ground_speed_ned_param1
       (sys::poke _ground_speed_ned_param1 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ground_speed_ned_param2
       (sys::poke _ground_speed_ned_param2 (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ground_speed
       (sys::poke _ground_speed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _global_vel_x
       (sys::poke _global_vel_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _global_vel_y
       (sys::poke _global_vel_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _global_vel_z
       (sys::poke _global_vel_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _air_speed
       (sys::poke _air_speed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _wind_estimate_x
       (sys::poke _wind_estimate_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _wind_estimate_y
       (sys::poke _wind_estimate_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _wind_estimate_z
       (sys::poke _wind_estimate_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _relative_hight
       (sys::poke _relative_hight (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _latitude
       (sys::poke _latitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _altitude
       (sys::poke _altitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _longtitude
       (sys::poke _longtitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _relative_alt
       (sys::poke _relative_alt (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ned_altitude
       (sys::poke _ned_altitude (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ned_pos_x
       (sys::poke _ned_pos_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ned_pos_y
       (sys::poke _ned_pos_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ned_pos_z
       (sys::poke _ned_pos_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ned_vel_x
       (sys::poke _ned_vel_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ned_vel_y
       (sys::poke _ned_vel_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ned_vel_z
       (sys::poke _ned_vel_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ned_acc_x
       (sys::poke _ned_acc_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ned_acc_y
       (sys::poke _ned_acc_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ned_acc_z
       (sys::poke _ned_acc_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; geometry_msgs/Vector3 _ned_acc
       (send _ned_acc :serialize s)
     ;; float64 _body_acc_x
       (sys::poke _body_acc_x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _body_acc_y
       (sys::poke _body_acc_y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _body_acc_z
       (sys::poke _body_acc_z (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; geometry_msgs/Vector3 _body_acc
       (send _body_acc :serialize s)
     ;; float64 _pitch_angle
       (sys::poke _pitch_angle (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _yaw_angle
       (sys::poke _yaw_angle (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _roll_angle
       (sys::poke _roll_angle (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _battery_voltage
       (sys::poke _battery_voltage (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _battery_precentage
       (sys::poke _battery_precentage (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _battery_current
       (sys::poke _battery_current (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _planeID
     (setq _planeID (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _targ_planeID
     (setq _targ_planeID (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; bool _altitude_lock
     (setq _altitude_lock (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; bool _in_air
     (setq _in_air (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _mode
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _mode (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; geometry_msgs/Quaternion _orientation
     (send _orientation :deserialize buf ptr-) (incf ptr- (send _orientation :serialization-length))
   ;; float64 _ground_speed_ned_param1
     (setq _ground_speed_ned_param1 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ground_speed_ned_param2
     (setq _ground_speed_ned_param2 (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ground_speed
     (setq _ground_speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _global_vel_x
     (setq _global_vel_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _global_vel_y
     (setq _global_vel_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _global_vel_z
     (setq _global_vel_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _air_speed
     (setq _air_speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _wind_estimate_x
     (setq _wind_estimate_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _wind_estimate_y
     (setq _wind_estimate_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _wind_estimate_z
     (setq _wind_estimate_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _relative_hight
     (setq _relative_hight (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _latitude
     (setq _latitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _altitude
     (setq _altitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _longtitude
     (setq _longtitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _relative_alt
     (setq _relative_alt (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ned_altitude
     (setq _ned_altitude (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ned_pos_x
     (setq _ned_pos_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ned_pos_y
     (setq _ned_pos_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ned_pos_z
     (setq _ned_pos_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ned_vel_x
     (setq _ned_vel_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ned_vel_y
     (setq _ned_vel_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ned_vel_z
     (setq _ned_vel_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ned_acc_x
     (setq _ned_acc_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ned_acc_y
     (setq _ned_acc_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ned_acc_z
     (setq _ned_acc_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; geometry_msgs/Vector3 _ned_acc
     (send _ned_acc :deserialize buf ptr-) (incf ptr- (send _ned_acc :serialization-length))
   ;; float64 _body_acc_x
     (setq _body_acc_x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _body_acc_y
     (setq _body_acc_y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _body_acc_z
     (setq _body_acc_z (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; geometry_msgs/Vector3 _body_acc
     (send _body_acc :deserialize buf ptr-) (incf ptr- (send _body_acc :serialization-length))
   ;; float64 _pitch_angle
     (setq _pitch_angle (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _yaw_angle
     (setq _yaw_angle (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _roll_angle
     (setq _roll_angle (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _battery_voltage
     (setq _battery_voltage (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _battery_precentage
     (setq _battery_precentage (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _battery_current
     (setq _battery_current (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get mavros_msgs::Formation_fixed_wing :md5sum-) "7ec6d134ed05358bd4c569b719cf99ef")
(setf (get mavros_msgs::Formation_fixed_wing :datatype-) "mavros_msgs/Formation_fixed_wing")
(setf (get mavros_msgs::Formation_fixed_wing :definition-)
      "# Message 固定翼的编队控制，可能用到的消息类型全定义
		uint16 planeID

        uint16 targ_planeID
        
        bool altitude_lock

		bool in_air

		string mode

		geometry_msgs/Quaternion orientation #姿态四元数，只能在外面弄下旋转矩阵了

		float64 ground_speed_ned_param1

		float64 ground_speed_ned_param2

		float64 ground_speed

		float64 global_vel_x

		float64 global_vel_y

		float64 global_vel_z

		float64 air_speed

		float64 wind_estimate_x

		float64 wind_estimate_y

		float64 wind_estimate_z

		float64 relative_hight

		float64 latitude

		float64 altitude

		float64 longtitude

		float64 relative_alt

		float64 ned_altitude

		float64 ned_pos_x

		float64 ned_pos_y

		float64 ned_pos_z

		float64 ned_vel_x

		float64 ned_vel_y

		float64 ned_vel_z

		float64 ned_acc_x

		float64 ned_acc_y

		float64 ned_acc_z

		geometry_msgs/Vector3 ned_acc

		float64 body_acc_x

		float64 body_acc_y

		float64 body_acc_z

		geometry_msgs/Vector3 body_acc

		float64 pitch_angle

		float64 yaw_angle

		float64 roll_angle

		float64 battery_voltage

		float64 battery_precentage

		float64 battery_current

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
")



(provide :mavros_msgs/Formation_fixed_wing "7ec6d134ed05358bd4c569b719cf99ef")


