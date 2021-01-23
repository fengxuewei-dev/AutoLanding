
(cl:in-package :asdf)

(defsystem "navigator-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :mavros_msgs-msg
)
  :components ((:file "_package")
    (:file "position_setpoint_triplet" :depends-on ("_package_position_setpoint_triplet"))
    (:file "_package_position_setpoint_triplet" :depends-on ("_package"))
  ))