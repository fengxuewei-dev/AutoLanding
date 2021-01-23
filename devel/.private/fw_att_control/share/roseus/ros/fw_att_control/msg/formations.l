;; Auto-generated. Do not edit!


(when (boundp 'fw_att_control::formations)
  (if (not (find-package "FW_ATT_CONTROL"))
    (make-package "FW_ATT_CONTROL"))
  (shadow 'formations (find-package "FW_ATT_CONTROL")))
(unless (find-package "FW_ATT_CONTROL::FORMATIONS")
  (make-package "FW_ATT_CONTROL::FORMATIONS"))

(in-package "ROS")
;;//! \htmlinclude formations.msg.html


(defclass fw_att_control::formations
  :super ros::object
  :slots (_formationShape ))

(defmethod fw_att_control::formations
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

(setf (get fw_att_control::formations :md5sum-) "cb4dc526361d96c967f22a663f5d3a2a")
(setf (get fw_att_control::formations :datatype-) "fw_att_control/formations")
(setf (get fw_att_control::formations :definition-)
      "# formations.msg

string formationShape 

")



(provide :fw_att_control/formations "cb4dc526361d96c967f22a663f5d3a2a")


