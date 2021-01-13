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
		case  0:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//启动自身转向流水3*50ms,等待A流水200ms,间隔500ms,总850
		case  850:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//启动自身转向流水3*50ms,等待A流水200ms,间隔500ms,总850
		case  1700:Led_Tail715_WaterOpen(80);delay_ms(300);break;//启动自身转向30%PWM流水12*50ms,等待B流水300ms,间隔100ms总1000ms
		case  2700:Led_Tail715_WaterOpen(255);delay_ms(300);break;//启动自身转向30%PWM流水12*50ms,等待B流水300ms,间隔100ms总1000ms
		case  3700:Led_Tail23_WaterOpen();delay_ms(250);break;//启动自身转向100%PWM流水2*50ms,等待B流水250ms,,间隔100ms总450ms
		case  4150:Led_Tail1_WaterOpen(255);delay_ms(300);break;//启动自身转向100%PWM流水1*50ms,等待B流水250ms,,间隔100ms总400ms
		case  4550:break;//
		case  4850:Timer1_Stop();for(;;);break;//停止计时，进入死循环
		default:break;
		}
	}
}
void Bye(void)
{
	LED_All_Open();//3265B全开除转向
	while(1)
	{
		switch(Time_Counter)
		{
		case  0:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//启动自身转向流水3*50ms,等待A流水200ms,间隔500ms,总850
		case  850:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//启动自身转向流水3*50ms,等待A流水200ms,间隔500ms,总850
		case  1700:delay_ms(100);break;//等待A关闭制动灯100ms,总100ms
		case  1800:break;//等待A流水200ms,间隔100ms,总300ms
		case  2100:delay_ms(250);Led_Tail1_WaterOpen(0);break;//等待A流水250ms,关闭LED1 50ms，间隔100ms,总400ms
		case  2500:delay_ms(250);Led_Tail23_WaterClose();break;//等待A流水250ms,关闭LED23 100ms，间隔100ms,总450ms
		case  2950:delay_ms(250);Led_Tail715_WaterOpen(80);break;//等待A流水300ms,启动自身转向流水12*50ms，间隔100ms,总1000ms
		case  3950:delay_ms(250);Led_Tail715_WaterOpen(0);break;//等待A流水300ms,启动自身转向流水12*50ms，间隔100ms,总1000ms
		case  4950:Timer1_Stop();for(;;);break;//灯光全灭，进入死循环
		default:break;
		}
	}
}

