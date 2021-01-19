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
//		case  0:break;//启动等待
//		case  50:Led_RT_WaterOpen();delay_ms(200);delay_ms(200);Led_RT_WaterClose();break;//启动自身转向流水3*50ms,等待A流水200ms,亮200ms，间隔300ms,总850
//		case  900:Led_RT_WaterOpen();delay_ms(200);delay_ms(200);Led_RT_WaterClose();break;//启动自身转向流水3*50ms,等待A流水200ms,亮200ms，间隔300ms,总850
//		case  1750:Led_Tail715_WaterOpen(80);break;//启动自身转向30%PWM流水12*50ms,等待B流水500ms,间隔300ms总1400ms
//		case  3150:Led_Tail715_WaterOpen(255);break;//启动自身转向30%PWM流水12*50ms,等待B流水500ms,间隔300ms总1400ms
//		case  4550:Led_Tail23_BreathOpen();break;//启动自身位置23 呼吸点亮255ms,间隔300ms总555ms
//		case  5105:Led_Tail1_BreathOpen();break;//启动自身1 呼吸点亮255ms,间隔300ms总555ms
//		case  5660:break;//此时A灯位置6呼吸开
//		case  6215:Timer1_Stop();for(;;);break;//停止计时，进入死循环
//		default:break;

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
//		case  0:break;//启动等待
//		case  50:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//启动自身转向流水3*50ms,等待A流水200ms,间隔500ms,总850
//		case  900:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//启动自身转向流水3*50ms,等待A流水200ms,间隔500ms,总850
//		case  1750:break;//等待A关闭制动灯100ms,总300ms
//		case  2050:break;//等待A 呼吸255ms,间隔300ms,总555ms
//		case  2605:Led_Tail1_BreathClose();break;//A呼吸关255ms,B呼吸关255ms，间隔300ms,总555ms
//		case  3160:Led_Tail23_BreathClose();break;//A呼吸关255ms,B呼吸关255ms，间隔300ms,总555ms
//		case  3715:delay_ms(300);Led_Tail715_WaterOpen(80);break;//等待A流水300ms,启动自身转向流水12*50ms，间隔300ms,总1200ms
//		case  5115:delay_ms(300);Led_Tail715_WaterOpen(0);break;//等待A流水300ms,启动自身转向流水12*50ms，间隔300ms,总1200ms
//		case  6515:Timer1_Stop();for(;;);break;//灯光全灭，进入死循环
//		default:break;
		case  0:break;//启动等待
		case  50:break;//等待A关闭制动灯100ms,总300ms
		case  350:break;//等待A 呼吸255ms,间隔300ms,总555ms
		case  905:Led_Tail1_BreathClose();break;//A呼吸关255ms,B呼吸关255ms，间隔300ms,总555ms
		case  1460:Led_Tail23_BreathClose();break;//A呼吸关255ms,B呼吸关255ms，间隔300ms,总555ms
		case  2015:delay_ms(300);Led_Tail715_WaterOpen(80);break;//等待A流水500ms,启动自身转向流水12*50ms，间隔300ms,总1400ms
		case  3415:delay_ms(300);Led_Tail715_WaterOpen(0);break;//等待A流水500ms,启动自身转向流水12*50ms，间隔300ms,总1400ms
		case  4815:Timer1_Stop();for(;;);break;//灯光全灭，进入死循环
		default:break;
		}
	}
}

