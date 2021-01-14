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
		case  0:break;//�����ȴ�
		case  50:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//��������ת����ˮ3*50ms,�ȴ�A��ˮ200ms,���500ms,��850
		case  900:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//��������ת����ˮ3*50ms,�ȴ�A��ˮ200ms,���500ms,��850
		case  1750:Led_Tail715_WaterOpen(80);break;//��������ת��30%PWM��ˮ12*50ms,�ȴ�B��ˮ300ms,���100ms��1000ms
		case  2750:Led_Tail715_WaterOpen(255);break;//��������ת��30%PWM��ˮ12*50ms,�ȴ�B��ˮ300ms,���100ms��1000ms
		case  3750:Led_Tail23_WaterOpen();break;//��������ת��100%PWM��ˮ2*50ms,�ȴ�B��ˮ250ms,,���100ms��450ms
		case  4200:Led_Tail1_WaterOpen(255);break;//��������ת��100%PWM��ˮ1*50ms,�ȴ�B��ˮ250ms,���100ms��400ms
		case  4600:break;//
		case  4900:Timer1_Stop();for(;;);break;//ֹͣ��ʱ��������ѭ��
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
		case  0:break;//�����ȴ�
		case  50:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//��������ת����ˮ3*50ms,�ȴ�A��ˮ200ms,���500ms,��850
		case  900:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//��������ת����ˮ3*50ms,�ȴ�A��ˮ200ms,���500ms,��850
		case  1750:break;//�ȴ�A�ر��ƶ���100ms,��100ms
		case  1850:break;//�ȴ�A��ˮ200ms,���100ms,��300ms
		case  2150:delay_ms(250);Led_Tail1_WaterOpen(0);break;//�ȴ�A��ˮ250ms,�ر�LED1 50ms�����100ms,��400ms
		case  2550:delay_ms(250);Led_Tail23_WaterClose();break;//�ȴ�A��ˮ250ms,�ر�LED23 100ms�����100ms,��450ms
		case  3000:delay_ms(300);Led_Tail715_WaterOpen(80);break;//�ȴ�A��ˮ300ms,��������ת����ˮ12*50ms�����100ms,��1000ms
		case  4000:delay_ms(300);Led_Tail715_WaterOpen(0);break;//�ȴ�A��ˮ300ms,��������ת����ˮ12*50ms�����100ms,��1000ms
		case  5000:Timer1_Stop();for(;;);break;//�ƹ�ȫ�𣬽�����ѭ��
		default:break;
		}
	}
}

