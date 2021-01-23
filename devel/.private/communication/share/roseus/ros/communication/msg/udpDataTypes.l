;; Auto-generated. Do not edit!


(when (boundp 'communication::udpDataTypes)
  (if (not (find-package "COMMUNICATION"))
    (make-package "COMMUNICATION"))
  (shadow 'udpDataTypes (find-package "COMMUNICATION")))
(unless (find-package "COMMUNICATION::UDPDATATYPES")
  (make-package "COMMUNICATION::UDPDATATYPES"))

(in-package "ROS")
;;//! \htmlinclude udpDataTypes.msg.html


(defclass communication::udpDataTypes
  :super ros::object
  :slots (_startUDP_Data _startUPD_HOME _startACK ))

(defmethod communication::udpDataTypes
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

(setf (get communication::udpDataTypes :md5sum-) "24c91d25d88a35c807139468a346102b")
(setf (get communication::udpDataTypes :datatype-) "communication/udpDataTypes")
(setf (get communication::udpDataTypes :definition-)
      "# udpDataTypes.msg

int8 startUDP_Data
int8 startUPD_HOME
int8 startACK

# taskType_sub = nh.advertise<communication::udpDataTypes>
#           (\"communication/taskTypes/udpDataTypes\", 1);

# taskType_sub = nh.subscribe<communication::QgcCommands>
#           (uavName + \"/communication/QgcCommands\" + s_i,1, handler_taskType);
# 

")



(provide :communication/udpDataTypes "24c91d25d88a35c807139468a346102b")


