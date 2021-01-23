;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::DataLinkDown)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'DataLinkDown (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::DATALINKDOWN")
  (make-package "FW_MSGS::DATALINKDOWN"))

(in-package "ROS")
;;//! \htmlinclude DataLinkDown.msg.html


(defclass fw_msgs::DataLinkDown
  :super ros::object
  :slots (_isDataLinkDown ))

(defmethod fw_msgs::DataLinkDown
  (:init
   (&key
    ((:isDataLinkDown __isDataLinkDown) 0)
    )
   (send-super :init)
   (setq _isDataLinkDown (round __isDataLinkDown))
   self)
  (:isDataLinkDown
   (&optional __isDataLinkDown)
   (if __isDataLinkDown (setq _isDataLinkDown __isDataLinkDown)) _isDataLinkDown)
  (:serialization-length
   ()
   (+
    ;; int32 _isDataLinkDown
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _isDataLinkDown
       (write-long _isDataLinkDown s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _isDataLinkDown
     (setq _isDataLinkDown (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get fw_msgs::DataLinkDown :md5sum-) "27e3a3f98f0830d328812cc2b4a61f31")
(setf (get fw_msgs::DataLinkDown :datatype-) "fw_msgs/DataLinkDown")
(setf (get fw_msgs::DataLinkDown :definition-)
      "# DataLinkDown.msg

int32 isDataLinkDown

# \"communication/dataLinkDown/isBreak\"
")



(provide :fw_msgs/DataLinkDown "27e3a3f98f0830d328812cc2b4a61f31")


