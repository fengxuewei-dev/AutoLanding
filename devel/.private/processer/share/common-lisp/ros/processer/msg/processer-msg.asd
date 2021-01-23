
(cl:in-package :asdf)

(defsystem "processer-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "formations" :depends-on ("_package_formations"))
    (:file "_package_formations" :depends-on ("_package"))
    (:file "processer" :depends-on ("_package_processer"))
    (:file "_package_processer" :depends-on ("_package"))
    (:file "uavflag" :depends-on ("_package_uavflag"))
    (:file "_package_uavflag" :depends-on ("_package"))
  ))