
(cl:in-package :asdf)

(defsystem "test-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "stringMsg" :depends-on ("_package_stringMsg"))
    (:file "_package_stringMsg" :depends-on ("_package"))
  ))