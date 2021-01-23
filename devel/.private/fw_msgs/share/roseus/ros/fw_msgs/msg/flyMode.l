;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::flyMode)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'flyMode (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::FLYMODE")
  (make-package "FW_MSGS::FLYMODE"))

(in-package "ROS")
;;//! \htmlinclude flyMode.msg.html


(defclass fw_msgs::flyMode
  :super ros::object
  :slots (_IsSingleMode _ControlMode ))

(defmethod fw_msgs::flyMode
  (:init
   (&key
    ((:IsSingleMode __IsSingleMode) 0.0)
    ((:ControlMode __ControlMode) 0.0)
    )
   (send-super :init)
   (setq _IsSingleMode (float __IsSingleMode))
   (setq _ControlMode (float __ControlMode))
   self)
  (:IsSingleMode
   (&optional __IsSingleMode)
   (if __IsSingleMode (setq _IsSingleMode __IsSingleMode)) _IsSingleMode)
  (:ControlMode
   (&optional __ControlMode)
   (if __ControlMode (setq _ControlMode __ControlMode)) _ControlMode)
  (:serialization-length
   ()
   (+
    ;; float64 _IsSingleMode
    8
    ;; float64 _ControlMode
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _IsSingleMode
       (sys::poke _IsSingleMode (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _ControlMode
       (sys::poke _ControlMode (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _IsSingleMode
     (setq _IsSingleMode (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _ControlMode
     (setq _ControlMode (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get fw_msgs::flyMode :md5sum-) "8bbfbbef36e847700d30280b89afcfb1")
(setf (get fw_msgs::flyMode :datatype-) "fw_msgs/flyMode")
(setf (get fw_msgs::flyMode :definition-)
      "# flyMode.msg

float64 IsSingleMode
float64 ControlMode

")



(provide :fw_msgs/flyMode "8bbfbbef36e847700d30280b89afcfb1")


