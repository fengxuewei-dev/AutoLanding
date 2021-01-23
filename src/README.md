# fixedWing project

## 介绍

lib: 存放项目需要的公共头文件, 按照文件夹的形式进行存放  
modules: 项目主要功能实现  
modules 下的每个子功能 没有 src 的子文件夹, 将主要功能存放再一个源文件中, 存在一个相应的头文件, 内部的CMakeLists.txt文件夹内部主要实现的是 add_modules 的功能

## 修改日志

### 2020.6.15日

解决了自定义的msg文件被当前包调用以及其他包进行调用的问题  

目前的modules是第一版添加了 offboard 和 logger 的代码. 
