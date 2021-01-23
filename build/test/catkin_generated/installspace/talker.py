#!/usr/bin/env python2
#coding:utf-8
# license removed for brevity
import rospy # 写ros节点必须导入的包
from std_msgs.msg import String

def talker():
    # topic: chatter
    # type: String
    # queue size = 10
    pub = rospy.Publisher('chatter', String, queue_size=10)
    
    # node's name
    # Anonymous = True通过在NAME的末尾添加随机数来确保您的节点具有唯一名称。
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(10) # 10hz

    # 判断ros节点是否被关闭
    while not rospy.is_shutdown():
        hello_str = "hello world %s" % rospy.get_time()
        rospy.loginfo(hello_str) # printf
        pub.publish(hello_str) # publish
        rate.sleep()    # sleep

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass