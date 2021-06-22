/*
 * HelloBye.c
 *
 *  Created on: 2021-1-13
 *      Author: Rick
 */
#include <KF8A200GQS.h>
#include "PinConfig.h"
#include "Work.h"
#include "Led.h"
#include "SoftSpi.h"
#include "HelloBye.h"

extern uint32_t Time_Counter;

extern void test1(void);
extern void test2(void);
void Hello(void)
{
	while(!Check_Hello_Bye())
	{
		switch(Time_Counter)
		{
		 case  0:break;//启动等待
		 case  50:Led_Tail715_WaterOpen(80);break;//启动自身转向30%PWM流水12*60ms,等待B流水600ms,总1320ms
		 case  1370:Led_Tail715_OpenMax();break;//启动自身转向30%PWM流水12*60ms,等待B流水600ms,总1320ms
		 case  2700:test1();break;//启动自身位置23 呼吸点亮255ms,间隔300ms总555ms
		 case  3000:test2();break;//启动自身位置23 呼吸点亮255ms,间隔300ms总555ms
		 //case  3405:Led_Tail1_BreathOpen();break;//启动自身1 呼吸点亮255ms,间隔300ms总555ms
		 //case  3960:break;//此时A灯位置6呼吸开
		 case  5000:Timer1_Stop();for(;;);break;//停止计时，进入死循环
		 default:break;
		}
	}
	Led_Tail_AllClose();
}
extern void breath_1(void);
void Bye(void)
{
	while(!Check_Hello_Bye())
	{
		switch(Time_Counter)
		{
		 case  0:break;//启动等待
		 case  50:break;//等待A关闭制动灯100ms,总300ms
		 case  350:break;//等待A 呼吸255ms,间隔300ms,总555ms
		 case  650:Led_Tail1_BreathClose();break;//A呼吸关255ms,B呼吸关255ms，间隔340ms,总555ms
		 case  950:breath_1();break;//A呼吸关255ms,B呼吸关255ms，间隔340ms,总555ms
		 //case  1460:Led_Tail23_BreathClose();break;//A呼吸关255ms,B呼吸关255ms，间隔300ms,总555ms
		 case  1930:Led_Tail715_WaterClose(80);break;//等待A流水600ms,启动自身转向流水12*50ms，总1120ms
		 case  3250:Led_Tail715_WaterClose(0);break;//等待A流水600ms,启动自身转向流水12*50ms，总1120ms
		 case  5000:Timer1_Stop();for(;;);break;//灯光全灭，进入死循环
		 default:break;
		}
	}
	Led_Tail_AllClose();
}

