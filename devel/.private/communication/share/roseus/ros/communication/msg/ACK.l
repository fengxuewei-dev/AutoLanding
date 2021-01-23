;; Auto-generated. Do not edit!


(when (boundp 'communication::ACK)
  (if (not (find-package "COMMUNICATION"))
    (make-package "COMMUNICATION"))
  (shadow 'ACK (find-package "COMMUNICATION")))
(unless (find-package "COMMUNICATION::ACK")
  (make-package "COMMUNICATION::ACK"))

(in-package "ROS")
;;//! \htmlinclude ACK.msg.html


(defclass communication::ACK
  :super ros::object
  :slots (_messageid _uavid _GPStime _judge _parity ))

(defmethod communication::ACK
  (:init
   (&key
    ((:messageid __messageid) 0)
    ((:uavid __uavid) 0)
    ((:GPStime __GPStime) (instance ros::time :init))
    ((:judge __judge) nil)
    ((:parity __parity) 0)
    )
   (send-super :init)
   (setq _messageid (round __messageid))
   (setq _uavid (round __uavid))
   (setq _GPStime __GPStime)
   (setq _judge __judge)
   (setq _parity (round __parity))
   self)
  (:messageid
   (&optional __messageid)
   (if __messageid (setq _messageid __messageid)) _messageid)
  (:uavid
   (&optional __uavid)
   (if __uavid (setq _uavid __uavid)) _uavid)
  (:GPStime
   (&optional __GPStime)
   (if __GPStime (setq _GPStime __GPStime)) _GPStime)
  (:judge
   (&optional __judge)
   (if __judge (setq _judge __judge)) _judge)
  (:parity
   (&optional __parity)
   (if __parity (setq _parity __parity)) _parity)
  (:serialization-length
   ()
   (+
    ;; uint16 _messageid
    2
    ;; uint16 _uavid
    2
    ;; time _GPStime
    8
    ;; bool _judge
    1
    ;; int32 _parity
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _messageid
       (write-word _messageid s)
     ;; uint16 _uavid
       (write-word _uavid s)
     ;; time _GPStime
       (write-long (send _GPStime :sec) s) (write-long (send _GPStime :nsec) s)
     ;; bool _judge
       (if _judge (write-byte -1 s) (write-byte 0 s))
     ;; int32 _parity
       (write-long _parity s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _messageid
     (setq _messageid (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _uavid
     (setq _uavid (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; time _GPStime
     (send _GPStime :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _GPStime :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _judge
     (setq _judge (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; int32 _parity
     (setq _parity (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get communication::ACK :md5sum-) "1572b006872bc5799fbee1b02a88be5b")
(setf (get communication::ACK :datatype-) "communication/ACK")
(setf (get communication::ACK :definition-)
      "# UDPMessage.msg

uint16 messageid
uint16 uavid
time GPStime
bool judge
int32 parity
")



(provide :communication/ACK "1572b006872bc5799fbee1b02a88be5b")


