;; Auto-generated. Do not edit!


(when (boundp 'test::stringMsg)
  (if (not (find-package "TEST"))
    (make-package "TEST"))
  (shadow 'stringMsg (find-package "TEST")))
(unless (find-package "TEST::STRINGMSG")
  (make-package "TEST::STRINGMSG"))

(in-package "ROS")
;;//! \htmlinclude stringMsg.msg.html


(defclass test::stringMsg
  :super ros::object
  :slots (_number _testData1 _testData2 ))

(defmethod test::stringMsg
  (:init
   (&key
    ((:number __number) 0)
    ((:testData1 __testData1) 0)
    ((:testData2 __testData2) 0)
    )
   (send-super :init)
   (setq _number (round __number))
   (setq _testData1 (round __testData1))
   (setq _testData2 (round __testData2))
   self)
  (:number
   (&optional __number)
   (if __number (setq _number __number)) _number)
  (:testData1
   (&optional __testData1)
   (if __testData1 (setq _testData1 __testData1)) _testData1)
  (:testData2
   (&optional __testData2)
   (if __testData2 (setq _testData2 __testData2)) _testData2)
  (:serialization-length
   ()
   (+
    ;; uint32 _number
    4
    ;; uint32 _testData1
    4
    ;; uint32 _testData2
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _number
       (write-long _number s)
     ;; uint32 _testData1
       (write-long _testData1 s)
     ;; uint32 _testData2
       (write-long _testData2 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _number
     (setq _number (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _testData1
     (setq _testData1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _testData2
     (setq _testData2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get test::stringMsg :md5sum-) "ceb80582456c5541e317ccd118b86605")
(setf (get test::stringMsg :datatype-) "test/stringMsg")
(setf (get test::stringMsg :definition-)
      "# stringMsg.msg

uint32 number
uint32 testData1
uint32 testData2


")



(provide :test/stringMsg "ceb80582456c5541e317ccd118b86605")


