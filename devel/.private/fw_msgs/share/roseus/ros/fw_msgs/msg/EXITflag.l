;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::EXITflag)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'EXITflag (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::EXITFLAG")
  (make-package "FW_MSGS::EXITFLAG"))

(in-package "ROS")
;;//! \htmlinclude EXITflag.msg.html


(defclass fw_msgs::EXITflag
  :super ros::object
  :slots (_EXIT_FLAG ))

(defmethod fw_msgs::EXITflag
  (:init
   (&key
    ((:EXIT_FLAG __EXIT_FLAG) 0)
    )
   (send-super :init)
   (setq _EXIT_FLAG (round __EXIT_FLAG))
   self)
  (:EXIT_FLAG
   (&optional __EXIT_FLAG)
   (if __EXIT_FLAG (setq _EXIT_FLAG __EXIT_FLAG)) _EXIT_FLAG)
  (:serialization-length
   ()
   (+
    ;; int32 _EXIT_FLAG
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _EXIT_FLAG
       (write-long _EXIT_FLAG s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _EXIT_FLAG
     (setq _EXIT_FLAG (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get fw_msgs::EXITflag :md5sum-) "eef81bba155a9b445b2c20263a5058af")
(setf (get fw_msgs::EXITflag :datatype-) "fw_msgs/EXITflag")
(setf (get fw_msgs::EXITflag :definition-)
      "# EXITflag.msg

int32 EXIT_FLAG

# 0: 正常      1: 退出
# uavName + \"communication/exitFlag/exitflag\"

")



(provide :fw_msgs/EXITflag "eef81bba155a9b445b2c20263a5058af")


