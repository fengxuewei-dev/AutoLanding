;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::NormalSwitchMode)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'NormalSwitchMode (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::NORMALSWITCHMODE")
  (make-package "FW_MSGS::NORMALSWITCHMODE"))

(in-package "ROS")
;;//! \htmlinclude NormalSwitchMode.msg.html


(defclass fw_msgs::NormalSwitchMode
  :super ros::object
  :slots (_Normal_Switch_Mode_Flag ))

(defmethod fw_msgs::NormalSwitchMode
  (:init
   (&key
    ((:Normal_Switch_Mode_Flag __Normal_Switch_Mode_Flag) 0)
    )
   (send-super :init)
   (setq _Normal_Switch_Mode_Flag (round __Normal_Switch_Mode_Flag))
   self)
  (:Normal_Switch_Mode_Flag
   (&optional __Normal_Switch_Mode_Flag)
   (if __Normal_Switch_Mode_Flag (setq _Normal_Switch_Mode_Flag __Normal_Switch_Mode_Flag)) _Normal_Switch_Mode_Flag)
  (:serialization-length
   ()
   (+
    ;; int32 _Normal_Switch_Mode_Flag
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _Normal_Switch_Mode_Flag
       (write-long _Normal_Switch_Mode_Flag s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _Normal_Switch_Mode_Flag
     (setq _Normal_Switch_Mode_Flag (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get fw_msgs::NormalSwitchMode :md5sum-) "a9e01fe0fa34836a4cd37fddd4a5467f")
(setf (get fw_msgs::NormalSwitchMode :datatype-) "fw_msgs/NormalSwitchMode")
(setf (get fw_msgs::NormalSwitchMode :definition-)
      "# NormalSwitchMode.msg

int32 Normal_Switch_Mode_Flag

# \"communication/protectExitFlag/normalSwitchModeFlag\"
")



(provide :fw_msgs/NormalSwitchMode "a9e01fe0fa34836a4cd37fddd4a5467f")


