#include"main.h"
#include"PinConfig.h"
#include "SoftSpi.h"
#include "work.h"
#include "led.h"
#include "music.h"
#include "music_led.h"
//������
uint8_t music_flag=0;
void main()
{
	Init_OSC(1); //��ϵͳʱ�ӳ�ʼ��Ϊ32M��ʹ���ⲿ����
	Init_GPIO();
	Timer3_Init();
	IS31FL3265B_Init();
	PUIE=1; //ʹ�������ж�
	AIE=1; //���жϿ���
	PwmDetect();
	Led_Hello_Check(SearchPwmFlag());
	while(1)
	{
        if(Get_Music()==0)
        {
            Music_Loop();
        }
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
	if(T2IE & T2IF) //1ms�ж�
	{
		T2IF=0;
		Hello_Bye_Callback();
	}
    if(T3IE & T3IF) //1ms�ж�
    {
            T3IF=0;
            //Stop_PWM();
    }
	if(INT0IE && INT0IF) //INT0�жϵ���Ӧ
	{
		INT0IF=0;
		PwmFromInteruppt();
	}
}


//�жϺ���1:0x14��ڵ�ַ
void int_fun1() __interrupt (1)
{

}
