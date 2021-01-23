;; Auto-generated. Do not edit!


(when (boundp 'fw_msgs::uavflag)
  (if (not (find-package "FW_MSGS"))
    (make-package "FW_MSGS"))
  (shadow 'uavflag (find-package "FW_MSGS")))
(unless (find-package "FW_MSGS::UAVFLAG")
  (make-package "FW_MSGS::UAVFLAG"))

(in-package "ROS")
;;//! \htmlinclude uavflag.msg.html


(defclass fw_msgs::uavflag
  :super ros::object
  :slots (_group _isleader _leaderid _myid _gapx _gapy _controlmode ))

(defmethod fw_msgs::uavflag
  (:init
   (&key
    ((:group __group) 0.0)
    ((:isleader __isleader) 0.0)
    ((:leaderid __leaderid) 0.0)
    ((:myid __myid) 0.0)
    ((:gapx __gapx) 0.0)
    ((:gapy __gapy) 0.0)
    ((:controlmode __controlmode) 0.0)
    )
   (send-super :init)
   (setq _group (float __group))
   (setq _isleader (float __isleader))
   (setq _leaderid (float __leaderid))
   (setq _myid (float __myid))
   (setq _gapx (float __gapx))
   (setq _gapy (float __gapy))
   (setq _controlmode (float __controlmode))
   self)
  (:group
   (&optional __group)
   (if __group (setq _group __group)) _group)
  (:isleader
   (&optional __isleader)
   (if __isleader (setq _isleader __isleader)) _isleader)
  (:leaderid
   (&optional __leaderid)
   (if __leaderid (setq _leaderid __leaderid)) _leaderid)
  (:myid
   (&optional __myid)
   (if __myid (setq _myid __myid)) _myid)
  (:gapx
   (&optional __gapx)
   (if __gapx (setq _gapx __gapx)) _gapx)
  (:gapy
   (&optional __gapy)
   (if __gapy (setq _gapy __gapy)) _gapy)
  (:controlmode
   (&optional __controlmode)
   (if __controlmode (setq _controlmode __controlmode)) _controlmode)
  (:serialization-length
   ()
   (+
    ;; float32 _group
    4
    ;; float32 _isleader
    4
    ;; float32 _leaderid
    4
    ;; float32 _myid
    4
    ;; float32 _gapx
    4
    ;; float32 _gapy
    4
    ;; float32 _controlmode
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float32 _group
       (sys::poke _group (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _isleader
       (sys::poke _isleader (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _leaderid
       (sys::poke _leaderid (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _myid
       (sys::poke _myid (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _gapx
       (sys::poke _gapx (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _gapy
       (sys::poke _gapy (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _controlmode
       (sys::poke _controlmode (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float32 _group
     (setq _group (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _isleader
     (setq _isleader (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _leaderid
     (setq _leaderid (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _myid
     (setq _myid (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _gapx
     (setq _gapx (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _gapy
     (setq _gapy (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _controlmode
     (setq _controlmode (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get fw_msgs::uavflag :md5sum-) "c1082356661093bc9487862125a2ea71")
(setf (get fw_msgs::uavflag :datatype-) "fw_msgs/uavflag")
(setf (get fw_msgs::uavflag :definition-)
      "# uavflag.msg

float32 group
float32 isleader
float32 leaderid
float32 myid
float32 gapx
float32 gapy
float32 controlmode
")



(provide :fw_msgs/uavflag "c1082356661093bc9487862125a2ea71")


