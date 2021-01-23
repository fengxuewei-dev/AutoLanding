;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::ACKflag)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'ACKflag (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::ACKFLAG")
  (make-package "FW_MSGS::ACKFLAG"))

(in-package "ROS")
;;//! \htmlinclude ACKflag.msg.html


(defclass fw_msgs::ACKflag
  :super ros::object
  :slots (_ACKflag ))

(defmethod fw_msgs::ACKflag
  (:init
   (&key
    ((:ACKflag __ACKflag) 0)
    )
   (send-super :init)
   (setq _ACKflag (round __ACKflag))
   self)
  (:ACKflag
   (&optional __ACKflag)
   (if __ACKflag (setq _ACKflag __ACKflag)) _ACKflag)
  (:serialization-length
   ()
   (+
    ;; int32 _ACKflag
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _ACKflag
       (write-long _ACKflag s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _ACKflag
     (setq _ACKflag (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get fw_msgs::ACKflag :md5sum-) "45bdb69dba2c6d2adc0542aeb7f54879")
(setf (get fw_msgs::ACKflag :datatype-) "fw_msgs/ACKflag")
(setf (get fw_msgs::ACKflag :definition-)
      "# ACKflag.msg

int32 ACKflag
")



(provide :fw_msgs/ACKflag "45bdb69dba2c6d2adc0542aeb7f54879")


