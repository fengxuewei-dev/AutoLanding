;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::uav_ids)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'uav_ids (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::UAV_IDS")
  (make-package "FW_MSGS::UAV_IDS"))

(in-package "ROS")
;;//! \htmlinclude uav_ids.msg.html


(defclass fw_msgs::uav_ids
  :super ros::object
  :slots (_current_id _leader_id ))

(defmethod fw_msgs::uav_ids
  (:init
   (&key
    ((:current_id __current_id) 0)
    ((:leader_id __leader_id) 0)
    )
   (send-super :init)
   (setq _current_id (round __current_id))
   (setq _leader_id (round __leader_id))
   self)
  (:current_id
   (&optional __current_id)
   (if __current_id (setq _current_id __current_id)) _current_id)
  (:leader_id
   (&optional __leader_id)
   (if __leader_id (setq _leader_id __leader_id)) _leader_id)
  (:serialization-length
   ()
   (+
    ;; uint16 _current_id
    2
    ;; uint16 _leader_id
    2
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _current_id
       (write-word _current_id s)
     ;; uint16 _leader_id
       (write-word _leader_id s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _current_id
     (setq _current_id (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _leader_id
     (setq _leader_id (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;;
   self)
  )

(setf (get fw_msgs::uav_ids :md5sum-) "5a866f4d93c1cb2b5a3f11036043cf7f")
(setf (get fw_msgs::uav_ids :datatype-) "fw_msgs/uav_ids")
(setf (get fw_msgs::uav_ids :definition-)
      "# uav_ids.msg

uint16 current_id
uint16 leader_id
")



(provide :fw_msgs/uav_ids "5a866f4d93c1cb2b5a3f11036043cf7f")


