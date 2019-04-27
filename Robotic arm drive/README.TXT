TIM2 3
舵机号-通道-引脚
1 tim2-ch1 pa0
2 tim2-ch2 pa1
3 tim2-ch3 pa2
4 tim2-ch4 pa3
5 tim3-ch1 pa6
6 tim3-ch2 pa7

串口发送数据格式
0xnnaaaa0d
第0-1位nn是控制舵机序号
第2-5位aaaa是所选舵机转动角度
第6-7位0d是校验位(不需要的话我删掉)
