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
		case  50:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//启动自身转向流水3*50ms,等待A流水200ms,间隔500ms,总850
		case  900:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//启动自身转向流水3*50ms,等待A流水200ms,间隔500ms,总850
		case  1750:Led_Tail715_WaterOpen(80);break;//启动自身转向30%PWM流水12*50ms,等待B流水300ms,间隔100ms总1000ms
		case  2750:Led_Tail715_WaterOpen(255);break;//启动自身转向30%PWM流水12*50ms,等待B流水300ms,间隔100ms总1000ms
		case  3750:Led_Tail23_WaterOpen();break;//启动自身转向100%PWM流水2*50ms,等待B流水250ms,,间隔100ms总450ms
		case  4200:Led_Tail1_WaterOpen(255);break;//启动自身转向100%PWM流水1*50ms,等待B流水250ms,间隔100ms总400ms
		case  4600:break;//
		case  4900:Timer1_Stop();for(;;);break;//停止计时，进入死循环
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
		case  50:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//启动自身转向流水3*50ms,等待A流水200ms,间隔500ms,总850
		case  900:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//启动自身转向流水3*50ms,等待A流水200ms,间隔500ms,总850
		case  1750:break;//等待A关闭制动灯100ms,总100ms
		case  1850:break;//等待A流水200ms,间隔100ms,总300ms
		case  2150:delay_ms(250);Led_Tail1_WaterOpen(0);break;//等待A流水250ms,关闭LED1 50ms，间隔100ms,总400ms
		case  2550:delay_ms(250);Led_Tail23_WaterClose();break;//等待A流水250ms,关闭LED23 100ms，间隔100ms,总450ms
		case  3000:delay_ms(300);Led_Tail715_WaterOpen(80);break;//等待A流水300ms,启动自身转向流水12*50ms，间隔100ms,总1000ms
		case  4000:delay_ms(300);Led_Tail715_WaterOpen(0);break;//等待A流水300ms,启动自身转向流水12*50ms，间隔100ms,总1000ms
		case  5000:Timer1_Stop();for(;;);break;//灯光全灭，进入死循环
		default:break;
		}
	}
}

