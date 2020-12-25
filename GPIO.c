/*
 * GPIO.c
 *
 *  Created on: 2019-9-27
 *      Author: charles_cai
 */
#include "main.h"

#ifndef GPIO_C_
#define GPIO_C_
/***********************************
*���ܣ���̿����ó���������ģʽ���ⲿ����ܽ�����Ϊ�������롣�������е�IO�ڶ���ʼ��Ϊ����͵�ƽ��
*�����������
*���أ���
*************************************/
void Init_GPIO()
{
	TR0 = 0xC7;	//P00-RST��P01-SPDAT��P02-SPCLK��P06-OSC��P07-OSC ����Ϊ����
	P0LR =0;	//P0�����ģʽ�Ĺܽţ�����͵�ƽ
	ANS0 =0;	//�ر�ģ�⹦��
	PUR0 =0;	//ȡ����������

	TR1 = 0;	//ȫ���ܽ�����Ϊ���
	P1LR =0;	//����͵�ƽ
	ANS1 =0;	//�ر�ģ�⹦��
	PUR1 =0;	//ȡ����������

	TR2 = 0;	//ȫ���ܽ�����Ϊ���
	P2LR =0;	//����͵�ƽ
	ANS2 =0;	//�ر�ģ�⹦��
	PUR2 =0;	//ȡ����������

	TR3 = 0;	//ȫ���ܽ�����Ϊ���
	P3LR =0;	//����͵�ƽ
	ANS3 =0;	//�ر�ģ�⹦��
	PUR3 =0;	//ȡ����������

	TR4 = 0xC;	//ȫ���ܽ�����Ϊ���
	P4LR =0;	//����͵�ƽ
	ANS4 =0;	//�ر�ģ�⹦��
	PUR4 =0;	//ȡ����������

	TR5 = 0;	//ȫ���ܽ�����Ϊ���
	P5LR =0;	//����͵�ƽ
	ANS5 =0;	//�ر�ģ�⹦��
	PUR5 =0;	//ȡ����������

	TR6 = 0;	//ȫ���ܽ�����Ϊ���
	P6LR =0;	//����͵�ƽ
	ANS6 =0;	//�ر�ģ�⹦��
	PUR6 =0;	//ȡ����������

	TR7 = 0;	//ȫ���ܽ�����Ϊ���
	P7LR =0;	//����͵�ƽ
	ANS7 =0;	//�ر�ģ�⹦��
	PUR7 =0;	//ȡ����������

	TR8 = 0;	//ȫ���ܽ�����Ϊ���
	P8LR =0;	//����͵�ƽ
	ANS8 =0;	//�ر�ģ�⹦��
	PUR8 =0;	//ȡ����������

	TR9 = 1;	//ȫ���ܽ�����Ϊ���
	P9LR =0;	//����͵�ƽ
	ANS9 =0;	//�ر�ģ�⹦��
	PUR9 =0;	//ȡ����������

	TRA = 0;	//ȫ���ܽ�����Ϊ���
	PALR =0;	//����͵�ƽ
	ANSA =0;	//�ر�ģ�⹦��
	PURA =0;	//ȡ����������

	TRB = 0;	//ȫ���ܽ�����Ϊ���
	PBLR =0;	//����͵�ƽ
	ANSB =0;	//�ر�ģ�⹦��
	PURB =0;	//ȡ����������
}

#endif /* GPIO_C_ */