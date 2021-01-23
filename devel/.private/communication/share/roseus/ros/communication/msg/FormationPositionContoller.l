;; Auto-generated. Do not edit!


(when (boundp 'communication::FormationPositionContoller)
  (if (not (find-package "COMMUNICATION"))
    (make-package "COMMUNICATION"))
  (shadow 'FormationPositionContoller (find-package "COMMUNICATION")))
(unless (find-package "COMMUNICATION::FORMATIONPOSITIONCONTOLLER")
  (make-package "COMMUNICATION::FORMATIONPOSITIONCONTOLLER"))

(in-package "ROS")
;;//! \htmlinclude FormationPositionContoller.msg.html


(defclass communication::FormationPositionContoller
  :super ros::object
  :slots (_count_number _leaderHeading _leaderCommand_yaw _leaderAirspeed ))

(defmethod communication::FormationPositionContoller
  (:init
   (&key
    ((:count_number __count_number) 0.0)
    ((:leaderHeading __leaderHeading) 0.0)
    ((:leaderCommand_yaw __leaderCommand_yaw) 0.0)
    ((:leaderAirspeed __leaderAirspeed) 0.0)
    )
   (send-super :init)
   (setq _count_number (float __count_number))
   (setq _leaderHeading (float __leaderHeading))
   (setq _leaderCommand_yaw (float __leaderCommand_yaw))
   (setq _leaderAirspeed (float __leaderAirspeed))
   self)
  (:count_number
   (&optional __count_number)
   (if __count_number (setq _count_number __count_number)) _count_number)
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
   ;; float64 _leaderHeading
     (setq _leaderHeading (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _leaderCommand_yaw
     (setq _leaderCommand_yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _leaderAirspeed
     (setq _leaderAirspeed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get communication::FormationPositionContoller :md5sum-) "d87d2620f7eee8afb717e021cba9a3f4")
(setf (get communication::FormationPositionContoller :datatype-) "communication/FormationPositionContoller")
(setf (get communication::FormationPositionContoller :definition-)
      "# FormationPositionContoller.msg

float64 count_number
float64 leaderHeading
float64 leaderCommand_yaw
float64 leaderAirspeed

")



(provide :communication/FormationPositionContoller "d87d2620f7eee8afb717e021cba9a3f4")


