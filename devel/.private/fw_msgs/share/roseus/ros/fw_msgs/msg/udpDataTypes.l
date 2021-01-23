;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::udpDataTypes)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'udpDataTypes (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::UDPDATATYPES")
  (make-package "FW_MSGS::UDPDATATYPES"))

(in-package "ROS")
;;//! \htmlinclude udpDataTypes.msg.html


(defclass fw_msgs::udpDataTypes
  :super ros::object
  :slots (_startUDP_Data _startUPD_HOME _startACK ))

(defmethod fw_msgs::udpDataTypes
  (:init
   (&key
    ((:startUDP_Data __startUDP_Data) 0)
    ((:startUPD_HOME __startUPD_HOME) 0)
    ((:startACK __startACK) 0)
    )
   (send-super :init)
   (setq _startUDP_Data (round __startUDP_Data))
   (setq _startUPD_HOME (round __startUPD_HOME))
   (setq _startACK (round __startACK))
   self)
  (:startUDP_Data
   (&optional __startUDP_Data)
   (if __startUDP_Data (setq _startUDP_Data __startUDP_Data)) _startUDP_Data)
  (:startUPD_HOME
   (&optional __startUPD_HOME)
   (if __startUPD_HOME (setq _startUPD_HOME __startUPD_HOME)) _startUPD_HOME)
  (:startACK
   (&optional __startACK)
   (if __startACK (setq _startACK __startACK)) _startACK)
  (:serialization-length
   ()
   (+
    ;; int8 _startUDP_Data
    1
    ;; int8 _startUPD_HOME
    1
    ;; int8 _startACK
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int8 _startUDP_Data
       (write-byte _startUDP_Data s)
     ;; int8 _startUPD_HOME
       (write-byte _startUPD_HOME s)
     ;; int8 _startACK
       (write-byte _startACK s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int8 _startUDP_Data
     (setq _startUDP_Data (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _startUDP_Data 127) (setq _startUDP_Data (- _startUDP_Data 256)))
   ;; int8 _startUPD_HOME
     (setq _startUPD_HOME (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _startUPD_HOME 127) (setq _startUPD_HOME (- _startUPD_HOME 256)))
   ;; int8 _startACK
     (setq _startACK (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _startACK 127) (setq _startACK (- _startACK 256)))
   ;;
   self)
  )

(setf (get fw_msgs::udpDataTypes :md5sum-) "24c91d25d88a35c807139468a346102b")
(setf (get fw_msgs::udpDataTypes :datatype-) "fw_msgs/udpDataTypes")
(setf (get fw_msgs::udpDataTypes :definition-)
      "# udpDataTypes.msg


int8 startUDP_Data
int8 startUPD_HOME
int8 startACK

# 数据分发
# 数据控制

# taskType_sub = nh.advertise<fw_msgs::udpDataTypes>
#           (\"communication/taskTypes/udpDataTypes\", 1);

# taskType_sub = nh.subscribe<fw_msgs::QgcCommands>
#           (uavName + \"/communication/QgcCommands\" + s_i,1, handler_taskType);
# 

")



(provide :fw_msgs/udpDataTypes "24c91d25d88a35c807139468a346102b")


