#!/usr/bin/env python
# coding:utf-8
import rospy # 写ros节点必须导入的包
import face_recognition_models
import cv2

def capter():
    rospy.init_node('opencv1', anonymous=True)

    video_capter = cv2.VideoCapture(0)

    while True:
        ret, frame = video_capter.read()
    
    video_capter.release()

if __name__ == '__main__':
    try:
        capter()
    except rospy.ROSInterruptException:
        pass