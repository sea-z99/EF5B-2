/*
 * Work.c
 *
 *  Created on: 2020-10-7
 *      Author: Rick
 */
#include<KF8A200GQS.h>
#include "PinConfig.h"
#include "Work.h"
#include "Led.h"
#include "SoftSpi.h"
#include "HelloBye.h"

#define HelloByeTest 1

uint32_t Time_Counter = 0;
uint32_t Hello_Bye_Counter = 0;

uint16_t PastMode=0;
uint16_t NowMode=0;
uint16_t ActMode=0;
uint16_t RT_PastMode=0;
uint16_t RT_NowMode=0;
uint16_t RT_ActMode=0;

volatile uint8_t RT_Status,Fog_Status,Tail_Status=0;
volatile uint8_t RT_EN_Status,WB_Status,Music_Status=0;

void Time_Increase(void)
{
	Time_Counter++;
}
void Time_Clear(void)
{
	Time_Counter=0;
}
void Init_42ms(void)
{
	T1CTL2 = 0x0C;	//	ʱ��Դ��SCLK/4��8��Ƶ
	T1H=0;
	T1L=0;
	PWMMODE = 1;	//ʹ������
	PP2=0xA4;		//42ms
	PP1=0x10;
	T1CS =0;
}
void Init_1ms(void)
{
	T1CTL2 = 0x0C;	//	ʱ��Դ��SCLK/4��8��Ƶ
	T1H=0;
	T1L=0;
	PWMMODE = 1;	//ʹ������
	PP2=0x03;		//1000
	PP1=0xE8;
	T1CS =0;
}
void Timer1_Start(void)
{
	Time_Counter=0;
	T1ON = 1;		//T1��ʱ������
	T1IF = 0;
	T1IE = 1;	//ʹ��T1��ʱ�����жϹ���
}
void Timer1_Stop(void)
{
	Time_Counter=0;
	T1ON = 0;		//T1��ʱ������
	T1IF = 0;
	T1IE = 0;	//ʹ��T1��ʱ�����жϹ���
}
void Timer2_Init(void)
{
	T2CTL0 = 0x0B;	//	Ԥ��Ƶ16�����Ƶ2
	T2CTL1 = 0x02; //���ϼ���,ʱ��Դ��SCLK-32M��
	T2H=0;
	T2L=0;
	PP60H=0;		//1000
	PP60L=0x0A;
}
void Timer2_Start(void)
{
	T2IF = 0;
	T2ON = 1;		//T2��ʱ������
	T2IE = 1;
}
void Timer2_Stop(void)
{
	T2IF = 0;
	T2ON = 0;		//T2��ʱ��ֹͣ
	T2IE = 0;
}
void PwmRisingInit(void)
{
	INT0IF=0;
	INT0IE=1;
	INT0SE=1;		//������
}
void PwmFallingInit(void)
{
	INT0IF=0;
	INT0IE=1;
	INT0SE=0;		//�½���
}
void PwmDeInit(void)
{
	INT0IE=0;
}
void Hello_Bye_Callback(void)
{
	Hello_Bye_Counter+=10;
}
typedef struct
{
	uint8_t State;
	uint32_t R_Time;
	uint32_t F_Time;
	uint32_t T_Time;
	float Duty;
	uint8_t ActFlag;
	uint8_t FromInteruppt;
}PwmStatus;
PwmStatus PwmDetectStatus;
void PwmFromInteruppt(void)
{
	PwmDetectStatus.FromInteruppt=1;
}
uint8_t SearchPwmFlag(void)
{
	return PwmDetectStatus.ActFlag;
}
void PwmStatusClear(void)
{
    PwmDetectStatus.State = 0;
    PwmDetectStatus.R_Time = 0;
    PwmDetectStatus.F_Time = 0;
    PwmDetectStatus.T_Time = 0;
    PwmDetectStatus.Duty = 0;
    PwmDetectStatus.ActFlag = 0;
    PwmDetectStatus.FromInteruppt = 0;
}
void PwmDetect(void)
{
	uint16_t time=5690;
	PwmStatusClear();
	Timer2_Init();
	PwmRisingInit();
	while(PwmDetectStatus.State!=3&&time-->0)
	{
		if(PwmDetectStatus.FromInteruppt)
		{
			PwmDetectStatus.FromInteruppt=0;
			switch(PwmDetectStatus.State)
			{
			case 0:
				Timer2_Start();
				PwmFallingInit();
				PwmDetectStatus.State = 1;
				break;
			case 1:
				PwmDetectStatus.R_Time = Hello_Bye_Counter;
				PwmRisingInit();
				PwmDetectStatus.State = 2;
				Hello_Bye_Counter = 0;
				break;
			case 2:
				PwmDetectStatus.F_Time = Hello_Bye_Counter;
				PwmDeInit();
				Timer2_Stop();
                PwmDetectStatus.T_Time = PwmDetectStatus.R_Time + PwmDetectStatus.F_Time;
                PwmDetectStatus.Duty = (float)PwmDetectStatus.F_Time / (float)PwmDetectStatus.T_Time;
				PwmDetectStatus.State = 3;
				break;
			default:break;
			}
		}
	}
    if(PwmDetectStatus.R_Time==0)
    {
        PwmDetectStatus.ActFlag=0;
        return;
    }
    if(PwmDetectStatus.T_Time>=3500&&PwmDetectStatus.T_Time<=4400)//127--187
    {
        if(PwmDetectStatus.Duty>=0.2&&PwmDetectStatus.Duty<=0.4)//30-40
        {
            PwmDetectStatus.ActFlag=1;
        }
        if(PwmDetectStatus.Duty>=0.6&&PwmDetectStatus.Duty<=0.8)//70-80
        {
            PwmDetectStatus.ActFlag=2;
        }
    }
}
uint8_t Get_Music(void)
{
	return MUSIC_EN;
}
void Led_Hello_Check(uint8_t Flag)
{
//	Tail_Status = TAIL;//43λ��
//	RT_Status = RT;//ת��
//	WB_Status = WB_EN;
//	if(Tail_Status==1&&RT_Status==1&&WB_Status==1)
//	{
//		Init_1ms();
//		Hello();
//	}
//	if(Tail_Status==1&&RT_Status==1&&WB_Status==0)
//	{
//		Init_1ms();
//		LED_All_Open();//3265Bȫ����ת��
//		//Timer1_Start();
//		Bye();
//	}
	Tail_Status = TAIL;//43λ��
	if(Tail_Status==1&&Flag==1)
	{
		Init_1ms();
		Timer1_Start();
		Hello();
	}
	if(Tail_Status==1&&Flag==2)
	{
		Init_1ms();
		LED_All_Open();//3265Bȫ����ת��
		Timer1_Start();
		Bye();
	}
}
void Tail_Fog_Check_Input(void)
{
	Tail_Status = TAIL;//43λ��
	Fog_Status = FOG;//42�ƶ�

	if(Tail_Status==0&&Fog_Status==0)//ȫ��
	{
		PastMode = NowMode;NowMode = Mode0_Status;
		if(NowMode==PastMode)
		{
			ActMode=0;
		}
		else
		{
			ActMode=NowMode;
		}
	}
	else if(Tail_Status==1&&Fog_Status==0)//λ��
	{
		PastMode = NowMode;NowMode = Mode1_Status;
		if(NowMode==PastMode)
		{
			ActMode=0;
		}
		else
		{
			ActMode=NowMode;
		}
	}
	else if(Tail_Status==0&&Fog_Status==1)//���
	{
		PastMode = NowMode;NowMode = Mode2_Status;
		if(NowMode==PastMode)
		{
			ActMode=0;
		}
		else
		{
			ActMode=NowMode;
		}
	}
	else if(Tail_Status==1&&Fog_Status==1)//λ�����
	{
		PastMode = NowMode;NowMode = Mode3_Status;
		if(NowMode==PastMode)
		{
			ActMode=0;
		}
		else
		{
			ActMode=NowMode;
		}
	}
	Mode_Act();
}
void Mode_Act(void)
{
	switch(ActMode)
	{
	case Mode0_Status:
		Led_Tail_AllClose();	//λ�ùر�
		Fog_Close();			//��ƹر�
		break;
	case Mode1_Status:
		Led_Tail_AllOpen();		//λ�ÿ���
		Fog_Close();			//��ƹر�
		break;
	case Mode2_Status:
		Led_Tail_AllClose();	//λ�ùر�
		Fog_Open();				//��ƿ���
		break;
	case Mode3_Status:
		Led_Tail_AllOpen();		//λ�ÿ���
		Fog_Open();				//��ƿ���
		break;
	default:break;
	}
}
void RT_Mode_Act(void)
{
	switch(RT_ActMode)
	{
	case Mode0_Status:
		Led_RT_AllClose();
		break;
	case Mode1_Status:
		Clear_RT();
		Led_RT_WaterOpen();
		Detect_RT();
		break;
	case Mode2_Status:
		Clear_RT();
		Led_RT_AllOpen();
		delay_ms(1);
		Detect_RT();
		break;
	default:break;
	}
}
void RT_Check_Input(void)
{
	RT_Status = RT;//ת��
	RT_EN_Status = RT_EN;//ת��ʹ��

	if(RT_Status==0)//ȫ��
	{
		RT_PastMode = RT_NowMode;RT_NowMode = Mode0_Status;
		if(RT_NowMode==RT_PastMode)
		{
			RT_ActMode=0;
		}
		else
		{
			RT_ActMode=RT_NowMode;
		}
	}
	else if(RT_Status==1&&RT_EN_Status==0)//��ˮ
	{
		RT_PastMode = RT_NowMode;RT_NowMode = Mode1_Status;
		if(RT_NowMode==RT_PastMode)
		{
			RT_ActMode=0;
		}
		else
		{
			RT_ActMode=RT_NowMode;
		}
	}
	else if(RT_Status==1&&RT_EN_Status==1)//����
	{
		RT_PastMode = RT_NowMode;RT_NowMode = Mode2_Status;
		if(RT_NowMode==RT_PastMode)
		{
			RT_ActMode=0;
		}
		else
		{
			RT_ActMode=RT_NowMode;
		}
	}
	RT_Mode_Act();
}
