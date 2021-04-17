/*
 * Work.h
 *
 *  Created on: 2020-10-7
 *      Author: Rick
 */

#ifndef WORK_H_
#define WORK_H_
#include "main.h"
void Tail_Fog_Check_Input(void);
void Mode_Act(void);
void RT_Check_Input(void);
void RT_Mode_Act(void);
void Led_Hello_Check(uint8_t Flag);
void Init_42ms(void);
void Init_1ms(void);
void Timer1_Start(void);
void Timer1_Stop(void);
uint8_t Get_Music(void);
void InitPwmInit(void);
void PwmFromInteruppt(void);
void PwmDetect(void);
uint8_t SearchPwmFlag(void);
void Hello_Bye_Callback(void);
void Timer3_Init(void);
void Timer3_Start(void);
void Timer3_Stop(void);

#define Mode0_Status 1<<0
#define Mode1_Status 1<<1
#define Mode2_Status 1<<2
#define Mode3_Status 1<<3
#define Mode4_Status 1<<4
#define Mode5_Status 1<<5
#define Mode6_Status 1<<6

#endif /* WORK_H_ */
