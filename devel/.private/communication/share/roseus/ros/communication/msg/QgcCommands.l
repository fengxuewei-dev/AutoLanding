;; Auto-generated. Do not edit!


(when (boundp 'communication::QgcCommands)
  (if (not (find-package "COMMUNICATION"))
    (make-package "COMMUNICATION"))
  (shadow 'QgcCommands (find-package "COMMUNICATION")))
(unless (find-package "COMMUNICATION::QGCCOMMANDS")
  (make-package "COMMUNICATION::QGCCOMMANDS"))

(in-package "ROS")
;;//! \htmlinclude QgcCommands.msg.html


(defclass communication::QgcCommands
  :super ros::object
  :slots (_messageid _gsid _uavid _uavnumber _tasktype _plane_state _plane_group _gapx _gapy _GPStime _parity ))

(defmethod communication::QgcCommands
  (:init
   (&key
    ((:messageid __messageid) 0)
    ((:gsid __gsid) 0)
    ((:uavid __uavid) 0)
    ((:uavnumber __uavnumber) 0)
    ((:tasktype __tasktype) 0)
    ((:plane_state __plane_state) 0)
    ((:plane_group __plane_group) 0)
    ((:gapx __gapx) 0)
    ((:gapy __gapy) 0)
    ((:GPStime __GPStime) 0.0)
    ((:parity __parity) 0)
    )
   (send-super :init)
   (setq _messageid (round __messageid))
   (setq _gsid (round __gsid))
   (setq _uavid (round __uavid))
   (setq _uavnumber (round __uavnumber))
   (setq _tasktype (round __tasktype))
   (setq _plane_state (round __plane_state))
   (setq _plane_group (round __plane_group))
   (setq _gapx (round __gapx))
   (setq _gapy (round __gapy))
   (setq _GPStime (float __GPStime))
   (setq _parity (round __parity))
   self)
  (:messageid
   (&optional __messageid)
   (if __messageid (setq _messageid __messageid)) _messageid)
  (:gsid
   (&optional __gsid)
   (if __gsid (setq _gsid __gsid)) _gsid)
  (:uavid
   (&optional __uavid)
   (if __uavid (setq _uavid __uavid)) _uavid)
  (:uavnumber
   (&optional __uavnumber)
   (if __uavnumber (setq _uavnumber __uavnumber)) _uavnumber)
  (:tasktype
   (&optional __tasktype)
   (if __tasktype (setq _tasktype __tasktype)) _tasktype)
  (:plane_state
   (&optional __plane_state)
   (if __plane_state (setq _plane_state __plane_state)) _plane_state)
  (:plane_group
   (&optional __plane_group)
   (if __plane_group (setq _plane_group __plane_group)) _plane_group)
  (:gapx
   (&optional __gapx)
   (if __gapx (setq _gapx __gapx)) _gapx)
  (:gapy
   (&optional __gapy)
   (if __gapy (setq _gapy __gapy)) _gapy)
  (:GPStime
   (&optional __GPStime)
   (if __GPStime (setq _GPStime __GPStime)) _GPStime)
  (:parity
   (&optional __parity)
   (if __parity (setq _parity __parity)) _parity)
  (:serialization-length
   ()
   (+
    ;; uint16 _messageid
    2
    ;; uint16 _gsid
    2
    ;; uint16 _uavid
    2
    ;; uint16 _uavnumber
    2
    ;; int32 _tasktype
    4
    ;; int16 _plane_state
    2
    ;; int16 _plane_group
    2
    ;; int16 _gapx
    2
    ;; int16 _gapy
    2
    ;; float64 _GPStime
    8
    ;; int32 _parity
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint16 _messageid
       (write-word _messageid s)
     ;; uint16 _gsid
       (write-word _gsid s)
     ;; uint16 _uavid
       (write-word _uavid s)
     ;; uint16 _uavnumber
       (write-word _uavnumber s)
     ;; int32 _tasktype
       (write-long _tasktype s)
     ;; int16 _plane_state
       (write-word _plane_state s)
     ;; int16 _plane_group
       (write-word _plane_group s)
     ;; int16 _gapx
       (write-word _gapx s)
     ;; int16 _gapy
       (write-word _gapy s)
     ;; float64 _GPStime
       (sys::poke _GPStime (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int32 _parity
       (write-long _parity s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint16 _messageid
     (setq _messageid (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _gsid
     (setq _gsid (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _uavid
     (setq _uavid (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _uavnumber
     (setq _uavnumber (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int32 _tasktype
     (setq _tasktype (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int16 _plane_state
     (setq _plane_state (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _plane_group
     (setq _plane_group (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _gapx
     (setq _gapx (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; int16 _gapy
     (setq _gapy (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float64 _GPStime
     (setq _GPStime (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int32 _parity
     (setq _parity (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get communication::QgcCommands :md5sum-) "0e2eb4b83ad275dc0706fdd57e60ccec")
(setf (get communication::QgcCommands :datatype-) "communication/QgcCommands")
(setf (get communication::QgcCommands :definition-)
      "# UDPMessage.msg

uint16 messageid
uint16 gsid
uint16 uavid
uint16 uavnumber
int32 tasktype
int16 plane_state
int16 plane_group
int16 gapx
int16 gapy
float64 GPStime
int32 parity

")



(provide :communication/QgcCommands "0e2eb4b83ad275dc0706fdd57e60ccec")


