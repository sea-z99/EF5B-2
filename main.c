#include"main.h"
#include"PinConfig.h"
#include "SoftSpi.h"
#include "work.h"
#include "led.h"
//������
void main()
{
	Init_OSC(2); //��ϵͳʱ�ӳ�ʼ��Ϊ32M��ʹ���ⲿ����
	Init_GPIO();
	IS31FL3265B_Init();
	while(1)
	{
		Check_Input();
	}
}
//�жϺ���0:0X04��ڵ�ַ
void int_fun0() __interrupt (0)
{

}


//�жϺ���1:0x14��ڵ�ַ
void int_fun1() __interrupt (1)
{

}
