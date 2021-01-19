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

void Hello(void)
{
	while(1)
	{
		switch(Time_Counter)
		{
		case  0:break;//启动等待
		case  50:Led_Tail715_WaterOpen(80);break;//启动自身转向30%PWM流水12*50ms,等待B流水500ms,间隔300ms总1400ms
		case  1450:Led_Tail715_WaterOpen(255);break;//启动自身转向30%PWM流水12*50ms,等待B流水500ms,间隔300ms总1400ms
		case  2850:Led_Tail23_BreathOpen();break;//启动自身位置23 呼吸点亮255ms,间隔300ms总555ms
		case  3405:Led_Tail1_BreathOpen();break;//启动自身1 呼吸点亮255ms,间隔300ms总555ms
		case  3960:break;//此时A灯位置6呼吸开
		case  4515:Timer1_Stop();for(;;);break;//停止计时，进入死循环
		default:break;
		}
	}
}
void Bye(void)
{
	while(1)
	{
		switch(Time_Counter)
		{
		case  0:break;//启动等待
		case  50:break;//等待A关闭制动灯100ms,总300ms
		case  350:break;//等待A 呼吸255ms,间隔300ms,总555ms
		case  905:Led_Tail1_BreathClose();break;//A呼吸关255ms,B呼吸关255ms，间隔300ms,总555ms
		case  1460:Led_Tail23_BreathClose();break;//A呼吸关255ms,B呼吸关255ms，间隔300ms,总555ms
		case  2015:delay_ms(500);Led_Tail715_WaterClose(80);break;//等待A流水500ms,启动自身转向流水12*50ms，间隔300ms,总1400ms
		case  3415:delay_ms(500);Led_Tail715_WaterClose(0);break;//等待A流水500ms,启动自身转向流水12*50ms，间隔300ms,总1400ms
		case  4815:Timer1_Stop();for(;;);break;//灯光全灭，进入死循环
		default:break;
		}
	}
}

