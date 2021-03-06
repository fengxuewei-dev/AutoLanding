
(cl:in-package :asdf)

(defsystem "communication-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "ACK" :depends-on ("_package_ACK"))
    (:file "_package_ACK" :depends-on ("_package"))
    (:file "FormationData" :depends-on ("_package_FormationData"))
    (:file "_package_FormationData" :depends-on ("_package"))
    (:file "FormationNavigator" :depends-on ("_package_FormationNavigator"))
    (:file "_package_FormationNavigator" :depends-on ("_package"))
    (:file "FormationPositionContoller" :depends-on ("_package_FormationPositionContoller"))
    (:file "_package_FormationPositionContoller" :depends-on ("_package"))
    (:file "QgcCommands" :depends-on ("_package_QgcCommands"))
    (:file "_package_QgcCommands" :depends-on ("_package"))
    (:file "UDPData" :depends-on ("_package_UDPData"))
    (:file "_package_UDPData" :depends-on ("_package"))
    (:file "UpdHP" :depends-on ("_package_UpdHP"))
    (:file "_package_UpdHP" :depends-on ("_package"))
    (:file "Yaw" :depends-on ("_package_Yaw"))
    (:file "_package_Yaw" :depends-on ("_package"))
    (:file "udpDataTypes" :depends-on ("_package_udpDataTypes"))
    (:file "_package_udpDataTypes" :depends-on ("_package"))
  ))