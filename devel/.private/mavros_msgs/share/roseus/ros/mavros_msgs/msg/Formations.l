;; Auto-generated. Do not edit!


(when (boundp 'mavros_msgs::Formations)
  (if (not (find-package "MAVROS_MSGS"))
    (make-package "MAVROS_MSGS"))
  (shadow 'Formations (find-package "MAVROS_MSGS")))
(unless (find-package "MAVROS_MSGS::FORMATIONS")
  (make-package "MAVROS_MSGS::FORMATIONS"))

(in-package "ROS")
;;//! \htmlinclude Formations.msg.html


(defclass mavros_msgs::Formations
  :super ros::object
  :slots (_formationShape ))

(defmethod mavros_msgs::Formations
  (:init
   (&key
    ((:formationShape __formationShape) "")
    )
   (send-super :init)
   (setq _formationShape (string __formationShape))
   self)
  (:formationShape
   (&optional __formationShape)
   (if __formationShape (setq _formationShape __formationShape)) _formationShape)
  (:serialization-length
   ()
   (+
    ;; string _formationShape
    4 (length _formationShape)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _formationShape
       (write-long (length _formationShape) s) (princ _formationShape s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _formationShape
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _formationShape (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get mavros_msgs::Formations :md5sum-) "cb4dc526361d96c967f22a663f5d3a2a")
(setf (get mavros_msgs::Formations :datatype-) "mavros_msgs/Formations")
(setf (get mavros_msgs::Formations :definition-)
      "# Formations.msg

string formationShape 

")



(provide :mavros_msgs/Formations "cb4dc526361d96c967f22a663f5d3a2a")


