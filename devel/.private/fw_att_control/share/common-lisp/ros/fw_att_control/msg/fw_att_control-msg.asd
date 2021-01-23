
(cl:in-package :asdf)

(defsystem "fw_att_control-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "commands" :depends-on ("_package_commands"))
    (:file "_package_commands" :depends-on ("_package"))
    (:file "formations" :depends-on ("_package_formations"))
    (:file "_package_formations" :depends-on ("_package"))
    (:file "processer" :depends-on ("_package_processer"))
    (:file "_package_processer" :depends-on ("_package"))
  ))