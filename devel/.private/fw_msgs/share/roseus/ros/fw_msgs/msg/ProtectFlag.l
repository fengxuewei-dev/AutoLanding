;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::ProtectFlag)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'ProtectFlag (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::PROTECTFLAG")
  (make-package "FW_MSGS::PROTECTFLAG"))

(in-package "ROS")
;;//! \htmlinclude ProtectFlag.msg.html


(defclass fw_msgs::ProtectFlag
  :super ros::object
  :slots (_PROTECT_EXIT_FLAG ))

(defmethod fw_msgs::ProtectFlag
  (:init
   (&key
    ((:PROTECT_EXIT_FLAG __PROTECT_EXIT_FLAG) 0)
    )
   (send-super :init)
   (setq _PROTECT_EXIT_FLAG (round __PROTECT_EXIT_FLAG))
   self)
  (:PROTECT_EXIT_FLAG
   (&optional __PROTECT_EXIT_FLAG)
   (if __PROTECT_EXIT_FLAG (setq _PROTECT_EXIT_FLAG __PROTECT_EXIT_FLAG)) _PROTECT_EXIT_FLAG)
  (:serialization-length
   ()
   (+
    ;; int32 _PROTECT_EXIT_FLAG
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _PROTECT_EXIT_FLAG
       (write-long _PROTECT_EXIT_FLAG s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _PROTECT_EXIT_FLAG
     (setq _PROTECT_EXIT_FLAG (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get fw_msgs::ProtectFlag :md5sum-) "3cbdec5b7556f1bc61b85f03babb7b6d")
(setf (get fw_msgs::ProtectFlag :datatype-) "fw_msgs/ProtectFlag")
(setf (get fw_msgs::ProtectFlag :definition-)
      "# ProtectFlag.msg

int32 PROTECT_EXIT_FLAG

# \"communication/protectExitFlag/protecEexitFlag\"
")



(provide :fw_msgs/ProtectFlag "3cbdec5b7556f1bc61b85f03babb7b6d")


