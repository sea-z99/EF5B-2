#include"main.h"
#include"PinConfig.h"
#include "SoftSpi.h"
#include "work.h"
#include "led.h"
#include "music.h"
#include "music_led.h"
//������
void main()
{
	Init_OSC(2); //��ϵͳʱ�ӳ�ʼ��Ϊ32M��ʹ���ⲿ����
	Init_GPIO();
	IS31FL3265B_Init();
	PUIE=1; //ʹ�������ж�
	AIE=1; //���жϿ���
	Led_Hello_Check();
	while(1)
	{
		Tail_Fog_Check_Input();
		RT_Check_Input();
	}
}
//�жϺ���0:0X04��ڵ�ַ
void int_fun0() __interrupt (0)
{
	if(T1IE & T1IF) //1ms�ж�
	{
		T1IF=0;
		Time_Increase();
	}
}


//�жϺ���1:0x14��ڵ�ַ
void int_fun1() __interrupt (1)
{

}
