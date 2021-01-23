;; Auto-generated. Do not edit!


(when (boundp 'fw_att_control::processer)
  (if (not (find-package "FW_ATT_CONTROL"))
    (make-package "FW_ATT_CONTROL"))
  (shadow 'processer (find-package "FW_ATT_CONTROL")))
(unless (find-package "FW_ATT_CONTROL::PROCESSER")
  (make-package "FW_ATT_CONTROL::PROCESSER"))

(in-package "ROS")
;;//! \htmlinclude processer.msg.html


(defclass fw_att_control::processer
  :super ros::object
  :slots (_execflag ))

(defmethod fw_att_control::processer
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

(setf (get fw_att_control::processer :md5sum-) "fff3fb7d3ee0a7ebfa5a6a893b0503a1")
(setf (get fw_att_control::processer :datatype-) "fw_att_control/processer")
(setf (get fw_att_control::processer :definition-)
      "# processer.msg

float32 execflag

")



(provide :fw_att_control/processer "fff3fb7d3ee0a7ebfa5a6a893b0503a1")


