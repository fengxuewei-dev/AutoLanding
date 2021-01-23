;; Auto-generated. Do not edit!


(when (boundp 'communication::UDPData)
  (if (not (find-package "COMMUNICATION"))
    (make-package "COMMUNICATION"))
  (shadow 'UDPData (find-package "COMMUNICATION")))
(unless (find-package "COMMUNICATION::UDPDATA")
  (make-package "COMMUNICATION::UDPDATA"))

(in-package "ROS")
;;//! \htmlinclude UDPData.msg.html


(defclass communication::UDPData
  :super ros::object
  :slots (_number _messageid _uavid _plane_state _plane_group _longitudex _latitudey _altitudez _heading _velocity _commandyaw _GPStime _parity ))

(defmethod communication::UDPData
  (:init
   (&key
    ((:number __number) 0)
    ((:messageid __messageid) 0)
    ((:uavid __uavid) 0)
    ((:plane_state __plane_state) 0)
    ((:plane_group __plane_group) 0)
    ((:longitudex __longitudex) 0.0)
    ((:latitudey __latitudey) 0.0)
    ((:altitudez __altitudez) 0.0)
    ((:heading __heading) 0.0)
    ((:velocity __velocity) 0.0)
    ((:commandyaw __commandyaw) 0.0)
    ((:GPStime __GPStime) (instance ros::time :init))
    ((:parity __parity) 0)
    )
   (send-super :init)
   (setq _number (round __number))
   (setq _messageid (round __messageid))
   (setq _uavid (round __uavid))
   (setq _plane_state (round __plane_state))
   (setq _plane_group (round __plane_group))
   (setq _longitudex (float __longitudex))
   (setq _latitudey (float __latitudey))
   (setq _altitudez (float __altitudez))
   (setq _heading (float __heading))
   (setq _velocity (float __velocity))
   (setq _commandyaw (float __commandyaw))
   (setq _GPStime __GPStime)
   (setq _parity (round __parity))
   self)
  (:number
   (&optional __number)
   (if __number (setq _number __number)) _number)
  (:messageid
   (&optional __messageid)
   (if __messageid (setq _messageid __messageid)) _messageid)
  (:uavid
   (&optional __uavid)
   (if __uavid (setq _uavid __uavid)) _uavid)
  (:plane_state
   (&optional __plane_state)
   (if __plane_state (setq _plane_state __plane_state)) _plane_state)
  (:plane_group
   (&optional __plane_group)
   (if __plane_group (setq _plane_group __plane_group)) _plane_group)
  (:longitudex
   (&optional __longitudex)
   (if __longitudex (setq _longitudex __longitudex)) _longitudex)
  (:latitudey
   (&optional __latitudey)
   (if __latitudey (setq _latitudey __latitudey)) _latitudey)
  (:altitudez
   (&optional __altitudez)
   (if __altitudez (setq _altitudez __altitudez)) _altitudez)
  (:heading
   (&optional __heading)
   (if __heading (setq _heading __heading)) _heading)
  (:velocity
   (&optional __velocity)
   (if __velocity (setq _velocity __velocity)) _velocity)
  (:commandyaw
   (&optional __commandyaw)
   (if __commandyaw (setq _commandyaw __commandyaw)) _commandyaw)
  (:GPStime
   (&optional __GPStime)
   (if __GPStime (setq _GPStime __GPStime)) _GPStime)
  (:parity
   (&optional __parity)
   (if __parity (setq _parity __parity)) _parity)
  (:serialization-length
   ()
   (+
    ;; int64 _number
    8
    ;; uint16 _messageid
    2
    ;; uint16 _uavid
    2
    ;; uint16 _plane_state
    2
    ;; uint16 _plane_group
    2
    ;; float64 _longitudex
    8
    ;; float64 _latitudey
    8
    ;; float64 _altitudez
    8
    ;; float64 _heading
    8
    ;; float64 _velocity
    8
    ;; float64 _commandyaw
    8
    ;; time _GPStime
    8
    ;; int32 _parity
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _number
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _number (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _number) (= (length (_number . bv)) 2)) ;; bignum
              (write-long (ash (elt (_number . bv) 0) 0) s)
              (write-long (ash (elt (_number . bv) 1) -1) s))
             ((and (class _number) (= (length (_number . bv)) 1)) ;; big1
              (write-long (elt (_number . bv) 0) s)
              (write-long (if (>= _number 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _number s)(write-long (if (>= _number 0) 0 #xffffffff) s)))
     ;; uint16 _messageid
       (write-word _messageid s)
     ;; uint16 _uavid
       (write-word _uavid s)
     ;; uint16 _plane_state
       (write-word _plane_state s)
     ;; uint16 _plane_group
       (write-word _plane_group s)
     ;; float64 _longitudex
       (sys::poke _longitudex (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _latitudey
       (sys::poke _latitudey (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _altitudez
       (sys::poke _altitudez (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _heading
       (sys::poke _heading (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _velocity
       (sys::poke _velocity (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _commandyaw
       (sys::poke _commandyaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; time _GPStime
       (write-long (send _GPStime :sec) s) (write-long (send _GPStime :nsec) s)
     ;; int32 _parity
       (write-long _parity s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _number
#+(or :alpha :irix6 :x86_64)
      (setf _number (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _number (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; uint16 _messageid
     (setq _messageid (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _uavid
     (setq _uavid (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _plane_state
     (setq _plane_state (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; uint16 _plane_group
     (setq _plane_group (sys::peek buf ptr- :short)) (incf ptr- 2)
   ;; float64 _longitudex
     (setq _longitudex (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _latitudey
     (setq _latitudey (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _altitudez
     (setq _altitudez (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _heading
     (setq _heading (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _velocity
     (setq _velocity (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _commandyaw
     (setq _commandyaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; time _GPStime
     (send _GPStime :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _GPStime :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _parity
     (setq _parity (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get communication::UDPData :md5sum-) "1ff2b4674f767520061c38046240545f")
(setf (get communication::UDPData :datatype-) "communication/UDPData")
(setf (get communication::UDPData :definition-)
      "# UDPMessage.msg

int64 number
uint16 messageid
uint16 uavid
uint16 plane_state
uint16 plane_group
float64 longitudex
float64 latitudey
float64 altitudez 
float64 heading
float64 velocity
float64 commandyaw
time GPStime
int32 parity

")



(provide :communication/UDPData "1ff2b4674f767520061c38046240545f")


