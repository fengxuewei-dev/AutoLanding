;; Auto-generated. Do not edit!


(when (boundp 'communication::Yaw)
  (if (not (find-package "COMMUNICATION"))
    (make-package "COMMUNICATION"))
  (shadow 'Yaw (find-package "COMMUNICATION")))
(unless (find-package "COMMUNICATION::YAW")
  (make-package "COMMUNICATION::YAW"))

(in-package "ROS")
;;//! \htmlinclude Yaw.msg.html


(defclass communication::Yaw
  :super ros::object
  :slots (_yaw ))

(defmethod communication::Yaw
  (:init
   (&key
    ((:yaw __yaw) 0.0)
    )
   (send-super :init)
   (setq _yaw (float __yaw))
   self)
  (:yaw
   (&optional __yaw)
   (if __yaw (setq _yaw __yaw)) _yaw)
  (:serialization-length
   ()
   (+
    ;; float64 _yaw
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _yaw
       (sys::poke _yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _yaw
     (setq _yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get communication::Yaw :md5sum-) "08cb8274b6ddb17af5a842bca0b17db1")
(setf (get communication::Yaw :datatype-) "communication/Yaw")
(setf (get communication::Yaw :definition-)
      "# yaw.msg

float64 yaw

")



(provide :communication/Yaw "08cb8274b6ddb17af5a842bca0b17db1")


