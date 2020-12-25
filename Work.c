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

int PastMode=0;
int NowMode=0;
int ActMode=0;

volatile unsigned char RT_Status,FOG_Status,TAIL_Status=0;

void Check_Input(void)
{
	RT_Status = RT;//90ת��
	FOG_Status = FOG;//42�ƶ�
	TAIL_Status = TAIL;//43λ��

	if(RT_Status==0&&FOG_Status==0&&TAIL_Status==0)//ȫ��
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
	else if(RT_Status==0&&FOG_Status==0&&TAIL_Status==1)//λ��
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
	else if(RT_Status==0&&FOG_Status==1&&TAIL_Status==0)//���
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
	else if(RT_Status==0&&FOG_Status==1&&TAIL_Status==1)//λ��+���
	{
		PastMode = NowMode;NowMode = Mode4_Status;
		if(NowMode==PastMode)
		{
			ActMode=0;
		}
		else
		{
			ActMode=NowMode;
		}
	}
	else if(RT_Status==1&&FOG_Status==0&&TAIL_Status==0)//ת��
	{
		PastMode = NowMode;NowMode = Mode5_Status;
		if(NowMode==PastMode)
		{
			ActMode=0;
		}
		else
		{
			ActMode=NowMode;
		}
	}
	else if(RT_Status==1&&FOG_Status==0&&TAIL_Status==1)//ת��+λ��
	{
		PastMode = NowMode;NowMode = Mode6_Status;
		if(NowMode==PastMode)
		{
			ActMode=0;
		}
		else
		{
			ActMode=NowMode;
		}
	}
	else if(RT_Status==1&&FOG_Status==1&&TAIL_Status==0)//ת��+���
	{
		PastMode = NowMode;NowMode = Mode7_Status;
		if(NowMode==PastMode)
		{
			ActMode=0;
		}
		else
		{
			ActMode=NowMode;
		}
	}
	else if(RT_Status==1&&FOG_Status==1&&TAIL_Status==1)//ȫ��
	{
		PastMode = NowMode;NowMode = Mode8_Status;
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
	case Mode1_Status:
		Led_Tail_AllClose();	//λ�õ�ȫ�ر�
		Fog_Close();			//�ƶ���ȫ�ر�
		Led_RT_AllClose();		//ת���ȫ�ر�
		break;
	case Mode2_Status:
		Led_Tail_AllOpen();		//λ�õ�ȫ����
		Fog_Close();			//�ƶ���ȫ�ر�
		Led_RT_AllClose();		//ת���ȫ�ر�
		break;
	case Mode3_Status:
		Fog_Open();			//�ƶ���ȫ����
		Led_RT_AllClose();		//ת���ȫ�ر�
		Led_Tail_AllClose();	//λ�õ�ȫ�ر�
		break;
	case Mode4_Status:
		Led_Tail_AllOpen();		//λ�õ�ȫ����
		Fog_Open();			//�ƶ���ȫ����
		Led_RT_AllClose();		//ת���ȫ�ر�
		break;
	case Mode5_Status:
		Led_RT_AllOpen();		//ת���ȫ����
		Led_Tail_AllClose();	//λ�õ�ȫ�ر�
		Fog_Close();			//�ƶ���ȫ�ر�
		break;
	case Mode6_Status:
		Led_RT_AllOpen();		//ת���ȫ����
		Led_Tail_AllOpen();		//λ�õ�ȫ����
		Fog_Close();			//�ƶ���ȫ�ر�
		break;
	case Mode7_Status:
		Led_RT_AllOpen();		//ת���ȫ����
		Fog_Open();			//�ƶ���ȫ����
		Led_Tail_AllClose();	//λ�õ�ȫ�ر�
		break;
	case Mode8_Status:
		Led_Tail_AllOpen();		//λ�õ�ȫ����
		Led_RT_AllOpen();		//ת���ȫ����
		Fog_Open();			//�ƶ���ȫ����
		break;
	default:break;
	}
}
