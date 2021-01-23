;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::processer)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'processer (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::PROCESSER")
  (make-package "FW_MSGS::PROCESSER"))

(in-package "ROS")
;;//! \htmlinclude processer.msg.html


(defclass fw_msgs::processer
  :super ros::object
  :slots (_execflag ))

(defmethod fw_msgs::processer
  (:init
   (&key
    ((:execflag __execflag) 0.0)
    )
   (send-super :init)
   (setq _execflag (float __execflag))
   self)
  (:execflag
   (&optional __execflag)
   (if __execflag (setq _execflag __execflag)) _execflag)
  (:serialization-length
   ()
   (+
    ;; float32 _execflag
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _execflag
       (sys::poke _execflag (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _execflag
     (setq _execflag (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get fw_msgs::processer :md5sum-) "fff3fb7d3ee0a7ebfa5a6a893b0503a1")
(setf (get fw_msgs::processer :datatype-) "fw_msgs/processer")
(setf (get fw_msgs::processer :definition-)
      "# processer.msg

float32 execflag

")



(provide :fw_msgs/processer "fff3fb7d3ee0a7ebfa5a6a893b0503a1")


