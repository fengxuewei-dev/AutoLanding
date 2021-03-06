
(cl:in-package :asdf)

(defsystem "fw_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :mavros_msgs-msg
)
  :components ((:file "_package")
    (:file "ACK" :depends-on ("_package_ACK"))
    (:file "_package_ACK" :depends-on ("_package"))
    (:file "ACKflag" :depends-on ("_package_ACKflag"))
    (:file "_package_ACKflag" :depends-on ("_package"))
    (:file "DataLinkDown" :depends-on ("_package_DataLinkDown"))
    (:file "_package_DataLinkDown" :depends-on ("_package"))
    (:file "EXITflag" :depends-on ("_package_EXITflag"))
    (:file "_package_EXITflag" :depends-on ("_package"))
    (:file "FormationData" :depends-on ("_package_FormationData"))
    (:file "_package_FormationData" :depends-on ("_package"))
    (:file "FormationNavigator" :depends-on ("_package_FormationNavigator"))
    (:file "_package_FormationNavigator" :depends-on ("_package"))
    (:file "FormationPositionContoller" :depends-on ("_package_FormationPositionContoller"))
    (:file "_package_FormationPositionContoller" :depends-on ("_package"))
    (:file "ModeSetting" :depends-on ("_package_ModeSetting"))
    (:file "_package_ModeSetting" :depends-on ("_package"))
    (:file "NormalSwitchMode" :depends-on ("_package_NormalSwitchMode"))
    (:file "_package_NormalSwitchMode" :depends-on ("_package"))
    (:file "ProtectFlag" :depends-on ("_package_ProtectFlag"))
    (:file "_package_ProtectFlag" :depends-on ("_package"))
    (:file "QgcCommands" :depends-on ("_package_QgcCommands"))
    (:file "_package_QgcCommands" :depends-on ("_package"))
    (:file "UDPData" :depends-on ("_package_UDPData"))
    (:file "_package_UDPData" :depends-on ("_package"))
    (:file "UpdHP" :depends-on ("_package_UpdHP"))
    (:file "_package_UpdHP" :depends-on ("_package"))
    (:file "Yaw" :depends-on ("_package_Yaw"))
    (:file "_package_Yaw" :depends-on ("_package"))
    (:file "commands" :depends-on ("_package_commands"))
    (:file "_package_commands" :depends-on ("_package"))
    (:file "flyMode" :depends-on ("_package_flyMode"))
    (:file "_package_flyMode" :depends-on ("_package"))
    (:file "formations" :depends-on ("_package_formations"))
    (:file "_package_formations" :depends-on ("_package"))
    (:file "position_setpoint_triplet" :depends-on ("_package_position_setpoint_triplet"))
    (:file "_package_position_setpoint_triplet" :depends-on ("_package"))
    (:file "processer" :depends-on ("_package_processer"))
    (:file "_package_processer" :depends-on ("_package"))
    (:file "target" :depends-on ("_package_target"))
    (:file "_package_target" :depends-on ("_package"))
    (:file "uav_ids" :depends-on ("_package_uav_ids"))
    (:file "_package_uav_ids" :depends-on ("_package"))
    (:file "uavflag" :depends-on ("_package_uavflag"))
    (:file "_package_uavflag" :depends-on ("_package"))
    (:file "udpDataTypes" :depends-on ("_package_udpDataTypes"))
    (:file "_package_udpDataTypes" :depends-on ("_package"))
  ))