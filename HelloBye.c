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
//		case  0:break;//�����ȴ�
//		case  50:Led_RT_WaterOpen();delay_ms(200);delay_ms(200);Led_RT_WaterClose();break;//��������ת����ˮ3*50ms,�ȴ�A��ˮ200ms,��200ms�����300ms,��850
//		case  900:Led_RT_WaterOpen();delay_ms(200);delay_ms(200);Led_RT_WaterClose();break;//��������ת����ˮ3*50ms,�ȴ�A��ˮ200ms,��200ms�����300ms,��850
//		case  1750:Led_Tail715_WaterOpen(80);break;//��������ת��30%PWM��ˮ12*50ms,�ȴ�B��ˮ500ms,���300ms��1400ms
//		case  3150:Led_Tail715_WaterOpen(255);break;//��������ת��30%PWM��ˮ12*50ms,�ȴ�B��ˮ500ms,���300ms��1400ms
//		case  4550:Led_Tail23_BreathOpen();break;//��������λ��23 ��������255ms,���300ms��555ms
//		case  5105:Led_Tail1_BreathOpen();break;//��������1 ��������255ms,���300ms��555ms
//		case  5660:break;//��ʱA��λ��6������
//		case  6215:Timer1_Stop();for(;;);break;//ֹͣ��ʱ��������ѭ��
//		default:break;

		case  0:break;//�����ȴ�
		case  50:Led_Tail715_WaterOpen(80);break;//��������ת��30%PWM��ˮ12*50ms,�ȴ�B��ˮ500ms,���300ms��1400ms
		case  1450:Led_Tail715_WaterOpen(255);break;//��������ת��30%PWM��ˮ12*50ms,�ȴ�B��ˮ500ms,���300ms��1400ms
		case  2850:Led_Tail23_BreathOpen();break;//��������λ��23 ��������255ms,���300ms��555ms
		case  3405:Led_Tail1_BreathOpen();break;//��������1 ��������255ms,���300ms��555ms
		case  3960:break;//��ʱA��λ��6������
		case  4515:Timer1_Stop();for(;;);break;//ֹͣ��ʱ��������ѭ��
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
//		case  0:break;//�����ȴ�
//		case  50:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//��������ת����ˮ3*50ms,�ȴ�A��ˮ200ms,���500ms,��850
//		case  900:Led_RT_WaterOpen();delay_ms(200);Led_RT_WaterClose();break;//��������ת����ˮ3*50ms,�ȴ�A��ˮ200ms,���500ms,��850
//		case  1750:break;//�ȴ�A�ر��ƶ���100ms,��300ms
//		case  2050:break;//�ȴ�A ����255ms,���300ms,��555ms
//		case  2605:Led_Tail1_BreathClose();break;//A������255ms,B������255ms�����300ms,��555ms
//		case  3160:Led_Tail23_BreathClose();break;//A������255ms,B������255ms�����300ms,��555ms
//		case  3715:delay_ms(300);Led_Tail715_WaterOpen(80);break;//�ȴ�A��ˮ300ms,��������ת����ˮ12*50ms�����300ms,��1200ms
//		case  5115:delay_ms(300);Led_Tail715_WaterOpen(0);break;//�ȴ�A��ˮ300ms,��������ת����ˮ12*50ms�����300ms,��1200ms
//		case  6515:Timer1_Stop();for(;;);break;//�ƹ�ȫ�𣬽�����ѭ��
//		default:break;
		case  0:break;//�����ȴ�
		case  50:break;//�ȴ�A�ر��ƶ���100ms,��300ms
		case  350:break;//�ȴ�A ����255ms,���300ms,��555ms
		case  905:Led_Tail1_BreathClose();break;//A������255ms,B������255ms�����300ms,��555ms
		case  1460:Led_Tail23_BreathClose();break;//A������255ms,B������255ms�����300ms,��555ms
		case  2015:delay_ms(300);Led_Tail715_WaterOpen(80);break;//�ȴ�A��ˮ500ms,��������ת����ˮ12*50ms�����300ms,��1400ms
		case  3415:delay_ms(300);Led_Tail715_WaterOpen(0);break;//�ȴ�A��ˮ500ms,��������ת����ˮ12*50ms�����300ms,��1400ms
		case  4815:Timer1_Stop();for(;;);break;//�ƹ�ȫ�𣬽�����ѭ��
		default:break;
		}
	}
}

