;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::ModeSetting)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'ModeSetting (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::MODESETTING")
  (make-package "FW_MSGS::MODESETTING"))

(in-package "ROS")
;;//! \htmlinclude ModeSetting.msg.html


(defclass fw_msgs::ModeSetting
  :super ros::object
  :slots (_Mode ))

(defmethod fw_msgs::ModeSetting
  (:init
   (&key
    ((:Mode __Mode) 0.0)
    )
   (send-super :init)
   (setq _Mode (float __Mode))
   self)
  (:Mode
   (&optional __Mode)
   (if __Mode (setq _Mode __Mode)) _Mode)
  (:serialization-length
   ()
   (+
    ;; float64 _Mode
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _Mode
       (sys::poke _Mode (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _Mode
     (setq _Mode (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get fw_msgs::ModeSetting :md5sum-) "fa9a51763d03303f4394bfc6178f2b70")
(setf (get fw_msgs::ModeSetting :datatype-) "fw_msgs/ModeSetting")
(setf (get fw_msgs::ModeSetting :definition-)
      "# ModeSetting.msg

float64 Mode

")



(provide :fw_msgs/ModeSetting "fa9a51763d03303f4394bfc6178f2b70")


