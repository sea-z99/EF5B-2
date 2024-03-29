/*
 * Led.c
 *
 *  Created on: 2020-10-9
 *      Author: Rick
 */
#include<KF8A200GQS.h>
#include "PinConfig.h"
#include "Work.h"
#include "Led.h"
#include "SoftSpi.h"
#include "main.h"

void Fog_Open(void)
{
	char i;
	for(i=OUT10;i<=OUT18;i++)
	{
		SPI_Write_2Byte(CS_U6,i,0xFF);
	}
	SPI_Write_2Byte(CS_U6,0x37,0x00);//update
}
void Fog_Close(void)
{
	char i;
	for(i=OUT10;i<=OUT18;i++)
	{
		SPI_Write_2Byte(CS_U6,i,0);
	}
	SPI_Write_2Byte(CS_U6,0x37,0x00);//update
}
void Led_RT_AllOpen(void)
{
	char i;
	for(i=OUT1;i<=OUT9;i++)
	{
		SPI_Write_2Byte(CS_U6,i,0xFF);
	}
	SPI_Write_2Byte(CS_U6,0x37,0x00);//update
}
void Led_RT_AllClose(void)
{
	char i;
	Timer5_Stop();
	for(i=OUT1;i<=OUT9;i++)
	{
		SPI_Write_Byte(CS_U6,i,0);
	}
	SPI_Write_Byte(CS_U6,0x37,0x00);//update
	TEST=0;
}
void Clear_RT(void)
{
	TEST=1;
	SPI_Read(CS_U6,0x15);
	SPI_Read(CS_U6,0x16);
	SPI_Read(CS_U6,0x17);
}

void Detect_RT(void)
{
	uint8_t dat1 = 0;
	uint8_t dat2 = 0;
	dat1 = SPI_Read(CS_U6,0x15);
	dat2 = SPI_Read(CS_U6,0x16);
	if(dat1>0||(dat2&0x07)>0)
	{
		Led_RT_AllClose();
		TEST=0;
	}
	else
	{
		TEST=1;
	}
}
void Led_Tail_AllOpen(void)
{
	char i;
	SPI_Write_2Byte(CS_U2,OUT1,0x80);//50%
	SPI_Write_2Byte(CS_U2,OUT2,0x99);//60%
	SPI_Write_2Byte(CS_U2,OUT3,0x99);//60%
	for(i=OUT4;i<=OUT7;i++)
	{
		SPI_Write_2Byte(CS_U2,i,0xCC);//80%
	}
	for(i=OUT8;i<=OUT15;i++)
	{
		SPI_Write_2Byte(CS_U2,i,0xCC);//80%
	}
	SPI_Write_2Byte(CS_U2,0x37,0x00);//update
}
void Led_Tail_AllClose(void)
{
	char i;
	SPI_Write_2Byte(CS_U2,OUT1,0);//0%
	SPI_Write_2Byte(CS_U2,OUT2,0);//0%
	SPI_Write_2Byte(CS_U2,OUT3,0);//0%
	for(i=OUT4;i<=OUT15;i++)
	{
		SPI_Write_2Byte(CS_U2,i,0);//0%
	}
	SPI_Write_2Byte(CS_U2,0x37,0x00);//update
}
uint8_t RT_Num = 0;
uint8_t RT_Water_Flag = 0;
void Led_RT_WaterOpen_Callback(void)
{
    RT_Water_Flag = 1;
}
void Led_RT_WaterOpen_Loop(void)
{
  if(RT_Water_Flag)
  {
    RT_Water_Flag = 0;
	if(RT_Num>=OUT2)
	{
	  SPI_Write_2Byte(CS_U6,RT_Num+1,0xFF);//91%
	  SPI_Write_2Byte(CS_U6,RT_Num,0xFF);//91%
	  SPI_Write_2Byte(CS_U6,RT_Num-1,0xFF);//91%
	  SPI_Write_2Byte(CS_U6,0x37,0x00);//update
	  RT_Num -= 3;
      delay_ms(1);
      Detect_RT();
	}
	else
	{
	  Timer5_Stop();
//	  Detect_RT();
	}
}
}
void Led_RT_WaterOpen(void)//转向流水开，50ms
{
//	char i;
//	for(i=OUT8;i>=OUT2;i-=3)
//	{
//		SPI_Write_2Byte(CS_U6,i+1,0xFF);//100%
//		SPI_Write_2Byte(CS_U6,i,0xFF);//100%
//		SPI_Write_2Byte(CS_U6,i-1,0xFF);//100%
//		SPI_Write_2Byte(CS_U6,0x37,0x00);//update
//		delay_ms(RT_Interval);
//	}
    RT_Num = OUT8;
    RT_Water_Flag = 1;
    Timer5_Start();
    Clear_RT();
}
void Led_RT_WaterClose(void)//转向流水关
{
	char i;
	for(i=OUT8;i>=OUT2;i-=3)
	{
		SPI_Write_2Byte(CS_U6,i+1,0);//100%
		SPI_Write_2Byte(CS_U6,i,0);//100%
		SPI_Write_2Byte(CS_U6,i-1,0);//100%
	}
	SPI_Write_2Byte(CS_U6,0x37,0x00);//update
}
void Led_Tail715_OpenMax(void)//位置流水开，50ms
{
	char i;
	for(i=OUT15;i>=OUT8;i--)
	{
		SPI_Write_2Byte(CS_U2,i,0xFF);//32%
		SPI_Write_2Byte(CS_U2,0x37,0x00);//update
		delay_ms(60);
	}
	for(i=OUT4;i<=OUT7;i++)
	{
		SPI_Write_2Byte(CS_U2,i,0xBF);//32%
		SPI_Write_2Byte(CS_U2,0x37,0x00);//update
		delay_ms(60);
	}
}
void Led_Tail715_WaterOpen(uint8_t pwm)//位置流水开，50ms
{
	char i;
	for(i=OUT15;i>=OUT8;i--)
	{
		SPI_Write_2Byte(CS_U2,i,pwm);//32%
		SPI_Write_2Byte(CS_U2,0x37,0x00);//update
		delay_ms(60);
	}
	for(i=OUT4;i<=OUT7;i++)
	{
		SPI_Write_2Byte(CS_U2,i,pwm);//32%
		SPI_Write_2Byte(CS_U2,0x37,0x00);//update
		delay_ms(60);
	}
}
void Led_Tail715_WaterClose(uint8_t pwm)//位置流水关
{
	char i;
	for(i=OUT7;i>=OUT4;i--)
	{
		SPI_Write_2Byte(CS_U2,i,pwm);//32%
		SPI_Write_2Byte(CS_U2,0x37,0x00);//update
		delay_ms(60);
	}
	for(i=OUT8;i<=OUT15;i++)
	{
		SPI_Write_2Byte(CS_U2,i,pwm);//32%
		SPI_Write_2Byte(CS_U2,0x37,0x00);//update
		delay_ms(60);
	}

}
void test1(void)
{
	static uint8_t i;
	for(i=0;i<0x55;i++)
	{
		SPI_Write_2Byte(CS_U2,OUT2,i);
		SPI_Write_2Byte(CS_U2,OUT3,i);
		SPI_Write_2Byte(CS_U2,0x37,0x00);//update
		delay_ms(1);
	}
	for(i=0x55;i<0xFF;i++)
	{
		delay_ms(1);
	}
}
void test2(void)
{
	static uint8_t i;
	for(i=0;i<0x3F;i++)
	{
		SPI_Write_2Byte(CS_U2,OUT1,i);
		SPI_Write_2Byte(CS_U2,0x37,0x00);//update
		delay_ms(1);
	}
	for(i=0x3F;i<0xFF;i++)
	{
		delay_ms(1);
	}
}
void Led_Tail23_BreathOpen(void)//位置呼吸开
{
	static uint8_t i;
	for(i=0;i<0x55;i++)
	{
		SPI_Write_2Byte(CS_U2,OUT2,i);
		SPI_Write_2Byte(CS_U2,OUT3,i);
		SPI_Write_2Byte(CS_U2,0x37,0x00);//update
		delay_ms(1);
	}
	for(i=0x55;i<0xFF;i++)
	{
		delay_ms(1);
	}

	for(i=0;i<0x3F;i++)
	{
		SPI_Write_2Byte(CS_U2,OUT1,i);
		SPI_Write_2Byte(CS_U2,0x37,0x00);//update
		delay_ms(1);
	}
	for(i=0x3F;i<0xFF;i++)
	{
		delay_ms(1);
	}
}
void Led_Tail23_BreathClose(void)//位置呼吸关
{
	static uint8_t i;
	for(i=0xFF;i>0;i--)
	{
		SPI_Write_2Byte(CS_U2,OUT2,i);
		SPI_Write_2Byte(CS_U2,OUT3,i);
		SPI_Write_2Byte(CS_U2,0x37,0x00);//update
		delay_ms(1);
	}
	SPI_Write_2Byte(CS_U2,OUT2,0);
	SPI_Write_2Byte(CS_U2,OUT3,0);
	SPI_Write_2Byte(CS_U2,0x37,0x00);//update
}

void Led_Tail1_BreathOpen(void)
{
	static uint8_t i;
	for(i=0;i<0x3F;i++)
	{
		SPI_Write_2Byte(CS_U2,OUT1,i);
		SPI_Write_2Byte(CS_U2,0x37,0x00);//update
		delay_ms(1);
	}
	for(i=0x3F;i<0xFF;i++)
	{
		delay_ms(1);
	}
}
void Led_Tail1_BreathClose(void)
{
	static uint8_t i;
	for(i=0xFF;i>0;i--)
	{
		SPI_Write_2Byte(CS_U2,OUT1,i);
		SPI_Write_2Byte(CS_U2,0x37,0x00);//update
		delay_ms(1);
	}
	SPI_Write_2Byte(CS_U2,OUT1,0);
	SPI_Write_2Byte(CS_U2,0x37,0x00);//update
}
void breath_1(void)
{
	static uint8_t i;
	for(i=0xFF;i>0;i--)
	{
		SPI_Write_2Byte(CS_U2,OUT2,i);
		SPI_Write_2Byte(CS_U2,OUT3,i);
		SPI_Write_2Byte(CS_U2,0x37,0x00);//update
		delay_ms(1);
	}
	SPI_Write_2Byte(CS_U2,OUT2,0);
	SPI_Write_2Byte(CS_U2,OUT3,0);
	SPI_Write_2Byte(CS_U2,0x37,0x00);//update
}
void LED_All_Open(void)
{
	char i;
	SPI_Write_2Byte(CS_U2,OUT1,0xFF);//25%
	SPI_Write_2Byte(CS_U2,OUT2,0xFF);//25%
	SPI_Write_2Byte(CS_U2,OUT3,0xFF);//25%
	for(i=OUT4;i<=OUT15;i++)
	{
		SPI_Write_2Byte(CS_U2,i,0xFF);//25%
	}
	SPI_Write_2Byte(CS_U2,0x37,0x00);//update
}
