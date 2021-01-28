# AutoLanding

课题代码库

## 调参意见

1. 先调节自己标准VF的控制逻辑，如果实在调节参数没有什么成果

2. 复现之前的算法
3. 在matlab中将算法搭建起来，看看是否是算法的问题，排除ros环境或者固件的问题。

<<<<<<< HEAD
## 修改记录

2021年 01月 23日 星期六 22:35:32 CST: 修正了MAV_SIDE 的错误

=======
>>>>>>> c2115532ea1cef96091e69fb388f4ef700c2d7af
## 目前的问题：

在飞行到最后阶段的时候，出现了MAV_Side 计算错误 <== 计算距离偏差地方

把 MAV SIDE 改正过来之后，计算出来的 $\theta^c$ 不需要改变了，所以不应该乘以-1, 不对。。。

> 查看内部的打印输出, 看看是否有什么问题?
>
> 好像是 油门一致不稳,导致高度;
>
> 但是又感觉像是 参数 的问题, 是后面 姿态控制器的参数导致调节不及时,因为当 输出的值为 1.04, 也就是 $\pi / 3$的时候,高度是可以就降下来,但是当值为0.xxx 的时候高度就又加上去了. == 将姿态控制中的 Kp 的值往高提呢? 
>
> 目前 Kp_pitch = 4; 设置为 10 , 设置成 2, 还是设置成 4 吧

> 距离阈值设置的太大? 目前是 30 , 设置成 10 呢? === 表现的是 目前阈值 范围内压根儿就没有起作用

> 主要作用还是调节 alpha.
>
> 一开始设置的是 0.4578 , 现在设置成为 16, 查看一下现象, 现象差不多!
>
> 继续放大: 32

目前使用的计算Error的z轴的误差, 已经带有正负号了, 但是现在还是在正负号的基础上,又乘以了 MAV SIDE 的符号. 

把油门的控制设置为常量, 验证一下. 水平飞行的时候, 没有问题, 但是爬坡的时候,  有问题, 爬不上. 或者高度下降的时候, 降不下来. 现在的油门PID控制是可以爬升的 === 不对, 如果输入油门常量, 那么高度能不能爬升?  == 是可以的

>  三维和二维高度控制上, 有什么区别?
>
>  三维Pitch发送的数值为 期望弧度, 需要和当前 Theta 的值做 PID;
>
>  二维Pitch发送的是期望高度, 和当前高度做一个PID;
>
>  那就和当前的油门设定值没有关系

调节姿态控制器中的P控制

> 之前是 4  ->  1 (和之前一样)  --> 16(和之前一样) --> 4

1. 将作用范围控制在阈值范围内：

   >  验证-1：

   > channel pitch 越大，应该低头吗？ ==> 对的

   ```c++
   att_sp[PITCH_CHANNEL - 1] = map(40, -60, 60, 1000, 2000);       // 开发板
   ```

   > channel pitch 越小，应该抬头吗？ ==> 对的

   ```c++
   att_sp[PITCH_CHANNEL - 1] = map(-40, -60, 60, 1000, 2000);       // 开发板
   ```

   <font face="微软雅黑" color=#FF0000 size=6 >pitch out 大于0，则低头；小于0，则抬头。</font>

   > 验证-2：

   > 油门为常量, 能否进行爬高控制 （姿态控制器中，油门没有做P控制，只是使用期望的油门做了一个映射）

   > 油门不归零，但要求高度降低，可以降低吗？ ==> 是可以的

   ```c++
   att_sp[THROTTLE_CHANNEL - 1]  = map(24, 15, 30, RC_MIN,RC_MAX);
   ```

   <font face="微软雅黑" color=#FF0000 size=6 >RC_OVERRIDE 油门和高度在这里的控制是不相互影响的。</font>

   ​	$$\theta^d = \theta^f - (\theta^e)(\frac{\epsilon}{\tau})^k$$ 

   ​	$$\theta^c = \theta^d - (\frac{k \theta^e S}{\alpha \tau^k}) \epsilon^{k-1}sin\theta$$

   > 1. 输出的值大于0，(最后输出的数据，根据 $\dot{\theta}=\alpha(\theta^c - \theta)$), 即$\theta^c > 0$, 测试时，$\theta$是大于或者等于0的。。。 最终决定低头还是抬头是根据 当前的$\theta$决定的。
   >
   >    
   >
   >    若当前 $\theta$ 为正，$\theta^c$ 大于 0，期望执行低头动作， 还应该依赖 $\theta^c$ 和 $\theta$ 的大小关系；
   >
   >    若当前 $\theta$ 为负，$\theta^c$ 大于 0，期望执行低头动作， 可以满足要求。
   >
   >    
   >
   >    若当前 $\theta$ 为正，$\theta^c$ 小于 0，期望执行抬头动作， 可以满足要求。
   >
   >    若当前 $\theta$ 为负，$\theta^c$ 小于 0，期望执行抬头动作， 还应该依赖 $\theta^c$ 和 $\theta$ 的大小关系；
   >
   >    
   >
   >    2. 上述的逻辑在 水平平面内也是存在的。
   >
   >       $\psi + \chi$
   >
   >    3. 
   >
   >    
   >
   > alpha 越大， 后面的因式越小，整体减小的幅度也越小；
   >
   > alpha 越小， 后面的因式越大，整体减小的幅度也越大；
   >
   > $\theta^f > 0$: 当前位置，高于航线，代码中计算的 epsilon > 0，得到的 $0 < \theta^c < \theta^f$, 输出的是 相反数，是负数，则应该抬头幅度大于当前航线的角度值。
   >
   > $\theta^f < 0$: 当前位置，高于航线，代码中计算的 epsilon > 0，得到的 $\theta^c < \theta^f < 0$, 输出的是 相反数，是正数，则应该低头幅度大于当前航线的角度值。

   > 将后面的map函数放大。

2. 将之前的算法跑起来，之后，在matlab simulink中搭建仿真平台，看看能不能成功

   > 修正的地方：
   >
   > 1. END 转到 NED
   > 2. 旋转的角度为 $-\alpha$
   > 3. 计算error，使用当前位置 p 减去 开始的航点.
   >
   > 上述现象是:高度提不上来; 调节一下
   >
   > 按照论文内部给定的参数运行一下，查验一下现象
   >
   > s_theta：0.457(现象不好，高度提不上来) -- 0.04(高度再下降) -- 10()

## 计算距离偏差

开始航点：$Start(x, y, z)$

结束航点：$End(x, y, z)$

当前位置:  $Position(x, y, z)$

定义向量 $\vec{SE} = End - Start$; $\vec{SP} = Position - Start $; $\vec{OS} = Start - Home$

当前位置到期望航线上的投影点距离 $Start$ 点的距离：
$$
\frac{\vec{SE} \cdot \vec{SP}}{|\vec{SE}|}
$$
投影点（home 点为原点）
$$
p_{project} = \vec{OS} + \frac{\vec{SE}}{|\vec{SE}|}(\frac{\vec{SE} \cdot \vec{SP}}{|\vec{SE}|})
$$


距离偏差
$$
ERROR = Position_{project} - Position = (Error_x, Error_y, Error_z)
$$
 其中 $Error_z$ 带有正负号，正数表示在期望航线上的投影点低；反之高；

$\sqrt{Error_x^2 + Error_y^2}$ 表示在水平方向上的距离偏差。具体在哪一侧，需要借助下面的方法来计算



 纵向控制中：当飞机的当前位置高于期望航线的， MAV_Side 为-1，那么就会更高，所以应该当飞机的当前位置高于期望航线的side是 1

## 计算位于航线的哪一侧



开始航点：$Start(x, y)$

结束航点：$End(x, y)$

当前位置:  $Position(x, y)$

定义向量 $\vec{SE} = End - Start$; $\vec{SP} = Position - Start $; $\vec{OS} = Start - Home$

水平方向的计算方法：
$$
\vec{SE} \times \vec{SP} = ||\vec{SE}|| ||\vec{SP}|| sin \theta, \theta是从SE到SP逆时针的角度
$$
当值大于0，则表示当前位于航线方向的逆时针方向；反之为顺时针

# 逻辑（没有修改）

1. 计算当前执行航线的 的方向角 $\chi^f$、

   无人机在当前执行航线的映射$s^*$, 

   无人机当前位置距离期望航线的距离 $\epsilon$、

   无人机当前位置位于期望航线的那一侧$\rho$(右侧为正，反侧为负)

2. if $|\epsilon| > \tau$:  

   ​	$\chi^c = \chi^d = \chi^f - \rho \chi^e$

3. else: 

   ​	$$\chi^d = \chi^f - (\chi^e)(\frac{\epsilon}{\tau})^k$$ 

   ​	$$\chi^c = \chi^d - (\frac{k \chi^e S}{\alpha \tau^k}) \epsilon^{k-1}sin\chi$$

# Proof  ==> $|\rho \epsilon| > \tau$

假设期望航点位于 x 轴(North)上，则
$$
\chi^f=0
$$
那么，期望航向角
$$
\begin{aligned}
\chi^d &= \chi^f - \rho \chi^e = - \rho \chi^e\\
\chi^c &= \chi^d = - \rho \chi^e\\
\end{aligned}
$$
航向角偏差
$$
\begin{aligned}
\tilde{\chi} &= \chi^d - \chi = - \rho \chi^e - \chi \\ \\
\dot{\tilde{\chi}} &= - \dot{\chi} = - \alpha (\chi^c - \chi) = - \alpha \tilde{\chi}
\end{aligned}
$$

## 求解微分方程 $\dot{\tilde{\chi}}= - \alpha \tilde{\chi}$

令 $\tilde{\chi} = y$, 则 
$$
\begin{equation}
\left\{
\begin{array}{lr}
\dot{y} = - \alpha y \\
y(0) = \chi^d(0) - \chi(0) = \tilde{\chi(t_0)} 
\end{array}
\right.
\end{equation}
$$
形如 $\frac{\mathrm{d} y }{\mathrm{d} x} + P(x)y = 0$,   解是  $y = C e^{- \int P(x) dx }$

则
$$
y = C e^{- \int P(x) dx } = C e^{-\alpha x}
$$
令
$$
t = 0, 则 y(0) = \tilde{\chi(t_0)} = C
$$
所以
$$
\tilde{\chi} = e^{-\alpha t} \cdot \tilde{\chi(t_0)}
$$

## 证明 $\chi^d$ 的收敛稳定性

设 Laypunov 函数
$$
W = \frac{1}{2} y^2
$$
对变量 y 进行求导
$$
\begin{aligned}
\dot{W} = y \cdot \dot{y} &= y \cdot v_g \cdot 
sin(\chi^d(y)) \\
&= y \cdot v_g \cdot sin(\chi^f - \rho \chi^e) \\
&= y \cdot v_g \cdot sin(- \rho \chi^e) 
\end{aligned}
$$

1. 当飞机位于航线右侧，$\rho > 0$
   $$
   \dot{W} = y \cdot v_g \cdot sin(- \rho \chi^e)
   $$
   其中，$y > 0$, $-\rho \chi^e < 0$, $sin(-\rho \chi^e) < 0$, 所以
   $$
   \dot{W} = y \cdot v_g \cdot sin(- \rho \chi^e) < 0
   $$

2. 当飞机位于航线左侧，$\rho < 0$
   $$
   \dot{W} = y \cdot v_g \cdot sin(- \rho \chi^e)
   $$
   其中，$y < 0$, $-\rho \chi^e > 0$, $sin(-\rho \chi^e) > 0$, 所以
   $$
   \dot{W} = y \cdot v_g \cdot sin(- \rho \chi^e) < 0
   $$

综上所述: $|\epsilon| > \tau $, $\dot{W} < 0$

## 证明 $\tilde{\chi} = \chi - \chi^d(y)$ 的收敛稳定性

$$
\tilde{\chi} = e^{-\alpha t} \cdot \tilde{\chi(t_0)}
$$

所以，随着 $t \uparrow$， $e^{-\alpha t} = 0$
$$
\tilde{\chi} = 0
$$
故
$$
\begin{aligned}
\tilde{\chi} &= \chi^d - \chi = 0 \\
\chi^d &= \chi
\end{aligned}
$$
所以
$$
\chi = - \rho \chi^e
$$
航向角最终会收敛于 $- \rho \chi^e$



## 当 $0 < \chi(t_0) < \pi$ 时

在这个时候，飞机会远离边界线，

随着
$$
t_0 \rightarrow \infty
$$
那么
$$
\chi(t) = -\chi^e
$$
<font face="微软雅黑" color=#FF0000 size=4 >没有推导完全</font>



# Proof  ==> $|\rho \epsilon| < \tau$

结论：
$$
\begin{aligned}
\chi^d &= \chi^f - (\chi^e) (\frac{\epsilon}{\tau})^k \\
\chi^c &= \chi^d - (\frac{k \chi^e S}{\alpha \tau^k}) \epsilon^{k-1} sin \chi
\end{aligned}
$$
假设期望航点位于 x 轴(North)上，且飞机当前的位置位于航线的右侧，则
$$
y > 0 \\
\chi^f=0 \\
$$
那么，期望航向角
$$
\begin{aligned}
\chi^d &= - (\chi^e) (\frac{\epsilon}{\tau})^k \\
 &= - (\chi^e) (\frac{y}{\tau})^k 
\end{aligned}
$$


设 Laypunov 函数为
$$
v(y, \tilde{\chi}) = \frac{1}{2} y^2 + \frac{1}{2} \tilde{\chi}^2
$$
对下面若干个因式分别进行求导
$$
\begin{aligned}
\chi^d &= - (\chi^e) (\frac{\rho \epsilon}{\tau})^k \\
 &= - (\chi^e) (\frac{\rho y}{\tau})^k \\
  \chi &= \chi^d - \tilde{\chi} \\
\dot{\chi^d(y)} &= - \chi^e \cdot k \cdot (\frac{\rho y}{\tau})^{k-1} \cdot (\frac{\rho}{\tau} \cdot \dot{y}) \\
&= - \chi^e \cdot k \cdot (\frac{\rho}{\tau})^{k} \cdot y^{k-1} \cdot S \cdot sin \chi \\
\dot{\chi} &= \alpha(\chi^c - \chi)
\end{aligned}
$$
对时间t进行求导
$$
\begin{aligned}
\dot{v} &= y \cdot \dot{y} + \tilde{\chi}\cdot \dot{\tilde{\chi}} \\
&= y \cdot S \cdot sin(\chi) + \tilde{\chi} \cdot (\dot{\chi^d} - \dot{\chi}) \\
&= y \cdot S \cdot sin(\chi^d(y) - \tilde{\chi}) + \tilde{\chi} \cdot (\dot{\chi^d} - \dot{\chi}) \\
&= y \cdot S \cdot sin(- (\chi^e) (\frac{\epsilon}{\tau})^k  - \tilde{\chi}) + \tilde{\chi} \cdot ((\frac{-\chi^e \cdot k \cdot S}{\tau^k}) \cdot y^{k - 1} sin \chi - \alpha (\chi^c - \chi)) \\
&= y \cdot S \cdot sin(- (\chi^e) (\frac{\epsilon}{\tau})^k  - \tilde{\chi}) - \alpha \tilde{\chi}^2
\end{aligned}
$$
要使得 $\dot{v} < 0$，则
$$
sin(- (\chi^e) (\frac{\epsilon}{\tau})^k  - \tilde{\chi})  <0 \\
- \pi < - (\chi^e) (\frac{\epsilon}{\tau})^k  - \tilde{\chi} <0 \\
- \pi < - (\chi^e) (\frac{\epsilon}{\tau})^k  - (\chi^d - \chi) <0 \\
- \pi < - (\chi^e) (\frac{\epsilon}{\tau})^k  - \chi^d + \chi <0 \\
- \pi < - (\chi^e) (\frac{\epsilon}{\tau})^k  + (\chi^e) (\frac{y}{\tau})^k + \chi <0 \\
- \pi < - (\chi^e) (\frac{\epsilon}{\tau})^k  + (\chi^e) (\frac{\epsilon}{\tau})^k + \chi <0 \\ 
\\
- \pi <  \chi <0 \\
$$
<font size=5>当 $- \pi <  \chi <0$, $\dot{v} < 0$ </font >
$$
M = \{(y, \chi): - \pi <= \chi <= 0, -\tau <= y <= \tau\}
$$


