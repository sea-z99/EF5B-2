/*
 * music.c
 *
 *  Created on: 2021-1-11
 *      Author: Rick
 */
#include"main.h"
#include"PinConfig.h"
#include "SoftSpi.h"
#include "work.h"
#include "led.h"
#include "music.h"
#include "music_led.h"

extern uint32_t Music_Counter;
//uint8_t SAOMIAO[11]={OUT8,OUT9,OUT10,OUT11,OUT1,OUT2,OUT3,OUT4,OUT5,OUT6,OUT7};
uint8_t LED_List[12]={OUT7,OUT6,OUT5,OUT4,OUT8,OUT9,OUT10,OUT11,OUT12,OUT13,OUT14,OUT15};

void OUTx_PWM(uint8_t device,uint8_t channel,uint8_t pwm)
{
	if(device==U2)
	{
		U2_SPI_Write_2Byte(channel, pwm);
		U2_SPI_Write_2Byte(0x37,0x00);//update
	}
	if(device==U6)
	{
		U6_SPI_Write_2Byte(channel, pwm);
		U6_SPI_Write_2Byte(0x37,0x00);//update
	}
}
void OUTx_Flash(uint8_t device,uint8_t channel)
{
	OUTx_PWM(device,channel,0xFF);
	delay_ms(10);
	OUTx_PWM(device,channel,0x00);
}
void All_LED_PWM(uint8_t pwm)
{
	uint8_t i;

//	for(i=OUT1;i<=OUT11;i++)
//	{
//		U6_SPI_Write_2Byte(i, pwm);
//	}
//
//	for(i=OUT1;i<=OUT16;i++)
//	{
//		U8_SPI_Write_2Byte(i, pwm);
//	}
//	U6_SPI_Write_2Byte(0x37,0x00);//update
//	U8_SPI_Write_2Byte(0x37,0x00);//update
	for(i=OUT1;i<=OUT15;i++)
	{
		U2_SPI_Write_2Byte(i, pwm);
	}
	U2_SPI_Write_2Byte(0x37,0x00);//update
}
void All_STOP_PWM(uint8_t pwm)
{
	uint8_t i;
//	for(i=OUT8;i<=OUT16;i++)
//	{
//		U8_SPI_Write_2Byte(i, pwm);
//	}
//	U8_SPI_Write_2Byte(0x37,0x00);//update
	for(i=OUT1;i<=OUT15;i++)
	{
		U2_SPI_Write_2Byte(i, pwm);
	}
	U2_SPI_Write_2Byte(0x37,0x00);//update

}
void BASE_PWM(uint8_t pwm)
{
	uint8_t i;
//	for(i=OUT8;i<=OUT11;i++)
//	{
//		U6_SPI_Write_2Byte(i, pwm);
//	}
//
//	for(i=OUT1;i<=OUT7;i++)
//	{
//		U8_SPI_Write_2Byte(i, pwm);
//	}
//
//	U6_SPI_Write_2Byte(0x37,0x00);//update
//	U8_SPI_Write_2Byte(0x37,0x00);//update
	for(i=OUT4;i<=OUT15;i++)
	{
		U2_SPI_Write_2Byte(i, pwm);
	}
	U2_SPI_Write_2Byte(0x37,0x00);//update
}
void Step2(void) //
{
	uint8_t i;

//	for(i=OUT8;i<=OUT11;i++)
//	{
//		U6_SPI_Write_2Byte(i, 0xFF);
//	}
//	for(i=OUT1;i<=OUT3;i++)
//	{
//		U8_SPI_Write_2Byte(i, 0xFF);
//	}
//	U6_SPI_Write_2Byte(0x37,0x00);//update
//	U8_SPI_Write_2Byte(0x37,0x00);//update
//	Delayms(10);
//	for(i=OUT8;i<=OUT11;i++)
//	{
//		U6_SPI_Write_2Byte(i, 0x00);
//	}
//	for(i=OUT1;i<=OUT3;i++)
//	{
//		U8_SPI_Write_2Byte(i, 0x00);
//	}
//	U6_SPI_Write_2Byte(0x37,0x00);//update
//	U8_SPI_Write_2Byte(0x37,0x00);//update
	for(i=OUT4;i<=OUT11;i++)
	{
		U2_SPI_Write_2Byte(i, 0xFF);
	}
	U2_SPI_Write_2Byte(0x37,0x00);//update
	Delayms(10);
	for(i=OUT4;i<=OUT11;i++)
	{
		U2_SPI_Write_2Byte(i, 0x00);
	}
	U2_SPI_Write_2Byte(0x37,0x00);//update
}
void Step3(void)
{
	uint8_t i;
//	for(i=OUT4;i<=OUT7;i++)
//	{
//		U8_SPI_Write_2Byte(i, 0xFF);
//	}
//	U8_SPI_Write_2Byte(0x37,0x00);//update
//	Delayms(10);
//	for(i=OUT4;i<=OUT7;i++)
//	{
//		U8_SPI_Write_2Byte(i, 0x00);
//	}
//	U8_SPI_Write_2Byte(0x37,0x00);//update
	for(i=OUT12;i<=OUT15;i++)
	{
		U2_SPI_Write_2Byte(i, 0xFF);
	}
	U2_SPI_Write_2Byte(0x37,0x00);//update
	Delayms(10);
	for(i=OUT12;i<=OUT15;i++)
	{
		U2_SPI_Write_2Byte(i, 0x00);
	}
	U2_SPI_Write_2Byte(0x37,0x00);//update
}

void Piano_flash(uint8_t device,uint8_t ch1)
{
	if(device==U2)
	{
		U2_SPI_Write_2Byte(ch1, 0xFF);
		U2_SPI_Write_2Byte(0x37,0x00);//update
		Delayms(10);
		U2_SPI_Write_2Byte(ch1, 0x00);
		U2_SPI_Write_2Byte(0x37,0x00);//update

	}
	if(device==U6)
	{
		U6_SPI_Write_2Byte(ch1, 0xFF);
		U6_SPI_Write_2Byte(0x37,0x00);//update
		Delayms(10);
		U6_SPI_Write_2Byte(ch1, 0x00);
		U6_SPI_Write_2Byte(0x37,0x00);//update
	}
}

void SCAN(uint16_t t)
{
	uint8_t i;
//	for(i=OUT1;i<=OUT7;i++)
//	{
//		U8_SPI_Write_2Byte(i, 0x20);
//	}
//	for(i=OUT8;i<=OUT11;i++)
//	{
//		U6_SPI_Write_2Byte(i, 0x20);
//	}
//	U6_SPI_Write_2Byte(0x37,0x00);//update
//	U8_SPI_Write_2Byte(0x37,0x00);//update
//
//	Delayms(7*t);
//
//	for(i=OUT8;i<=OUT11;i++)
//	{
//		U6_SPI_Write_2Byte(i, 0x00);
//		U6_SPI_Write_2Byte(0x37,0x00);//update
//		Delayms(t);
//	}
//	for(i=OUT1;i<=OUT7;i++)
//	{
//		U8_SPI_Write_2Byte(i, 0x00);
//		U8_SPI_Write_2Byte(0x37,0x00);//update
//		Delayms(t);
//	}
	for(i=OUT4;i<=OUT15;i++)
	{
		U2_SPI_Write_2Byte(i, 0x20);
	}
	U2_SPI_Write_2Byte(0x37,0x00);//update

	Delayms(7*t);

	for(i=OUT7;i>=OUT4;i--)
	{
		U2_SPI_Write_2Byte(i, 0x00);
		U2_SPI_Write_2Byte(0x37,0x00);//update
		Delayms(t);
	}
	for(i=OUT8;i<=OUT15;i++)
	{
		U2_SPI_Write_2Byte(i, 0x00);
		U2_SPI_Write_2Byte(0x37,0x00);//update
		Delayms(t);
	}
}

void SCAN_BACK(uint16_t t)
{
	uint8_t i;
//	for(i=OUT7;i>=OUT1;i--)
//	{
//		U8_SPI_Write_2Byte(i, 0x05);
//		U8_SPI_Write_2Byte(0x37,0x00);//update
//		Delayms(t);
//	}
//	for(i=OUT11;i>=OUT8;i--)
//	{
//		U6_SPI_Write_2Byte(i, 0x05);
//		U6_SPI_Write_2Byte(0x37,0x00);//update
//		Delayms(t);
//	}
	for(i=OUT15;i>=OUT8;i--)
	{
		U2_SPI_Write_2Byte(i, 0x05);
		U2_SPI_Write_2Byte(0x37,0x00);//update
		Delayms(t);
	}
	for(i=OUT4;i<=OUT7;i++)
	{
		U2_SPI_Write_2Byte(i, 0x05);
		U2_SPI_Write_2Byte(0x37,0x00);//update
		Delayms(t);
	}

}
void LIUSHUI(void)
{
	uint32_t differ;
	uint8_t status,i,t;
//	for(t=0;t<5;t++)
//	{
//		for(status = 0; status < (11 + 8); status++)   //ÐèÒª¾­¹ý num+length ¸ö×´Ì¬
//		{
//			All_LED_PWM(0x00);
//			for(i = 0; i < 8; i++)  //ÓÐÊý¾ÝµÄµÆ¸²¸ÇÖ®Ç°µÄ0£¬Ã»ÓÐÊý¾ÝµÄ¼ÌÐøÎªÃð
//			{
//				differ = status - i;
//				if((differ > 0) && (differ < 11))  //differ·¶Î§Îª 0 ~ num-1
//				{
//					if(differ<4)
//					{
//						U6_SPI_Write_2Byte(SAOMIAO[differ], 0xFF);
//					}
//					else
//					{
//						U8_SPI_Write_2Byte(SAOMIAO[differ], 0xFF);
//					}
//				}
//			}
//			U6_SPI_Write_2Byte(0x37, 0x00);  //update
//			U8_SPI_Write_2Byte(0x37, 0x00);  //update
//			Delayms(6);
//		}
//	}
	for(t=0;t<5;t++)
	{
		for(status = 0; status < (12 + 8); status++)   //ÐèÒª¾­¹ý num+length ¸ö×´Ì¬
		{
			All_LED_PWM(0x00);
			for(i = 0; i < 8; i++)  //ÓÐÊý¾ÝµÄµÆ¸²¸ÇÖ®Ç°µÄ0£¬Ã»ÓÐÊý¾ÝµÄ¼ÌÐøÎªÃð
			{
				differ = status - i;
				if((differ > 0) && (differ < 12))  //differ·¶Î§Îª 0 ~ num-1
				{
					U2_SPI_Write_2Byte(LED_List[differ], 0xFF);
				}
			}
			U2_SPI_Write_2Byte(0x37, 0x00);  //update
			Delayms(6);
		}
	}
}
void Side_flash(uint8_t pwm) //
{
	uint8_t i;

//	for(i=OUT1;i<=OUT7;i++)
//	{
//		U6_SPI_Write_2Byte(i, pwm);
//	}
//
//	for(i=OUT8;i<=OUT16;i++)
//	{
//		U8_SPI_Write_2Byte(i, pwm);
//	}
//
//	U6_SPI_Write_2Byte(0x37,0x00);//update
//	U8_SPI_Write_2Byte(0x37,0x00);//update
//	Delayms(10);
//
//	for(i=OUT1;i<=OUT7;i++)
//	{
//		U6_SPI_Write_2Byte(i, 0x00);
//	}
//
//	for(i=OUT8;i<=OUT16;i++)
//	{
//		U8_SPI_Write_2Byte(i, 0x00);
//	}
//	U6_SPI_Write_2Byte(0x37,0x00);//update
//	U8_SPI_Write_2Byte(0x37,0x00);//update
	for(i=OUT1;i<=OUT3;i++)
	{
		U2_SPI_Write_2Byte(i, pwm);
	}
	U2_SPI_Write_2Byte(0x37,0x00);//update

	Delayms(10);

	for(i=OUT1;i<=OUT3;i++)
	{
		U2_SPI_Write_2Byte(i, 0);
	}
	U2_SPI_Write_2Byte(0x37,0x00);//update
}


void Side_Liushui(uint8_t h)
{
	int differ;
	uint8_t status,i,t;
//	for(t=0;t<h;t++)
//	{
//	    for(status = 0; status < (11 + 8); status++)   //ÐèÒª¾­¹ý num+length ¸ö×´Ì¬
//	    {
//	    	All_LED_PWM(0x00);
//
//	    	for(i = 0; i < 8; i++)  //ÓÐÊý¾ÝµÄµÆ¸²¸ÇÖ®Ç°µÄ0£¬Ã»ÓÐÊý¾ÝµÄ¼ÌÐøÎªÃð
//			{
//				differ = status - i;
//				if((differ > -1) && (differ < 11))  //differ·¶Î§Îª 0 ~ num-1
//				{
//					if(differ<4)
//					{
//						U6_SPI_Write_2Byte(SAOMIAO[differ], 0xFF);
//					}
//					else
//					{
//						U8_SPI_Write_2Byte(SAOMIAO[differ], 0xFF);
//					}
//				}
//			}
//			U6_SPI_Write_2Byte(0x37, 0x00);  //update
//			U8_SPI_Write_2Byte(0x37, 0x00);  //update
//			Delayms(6);
//		}
//	}
	for(t=0;t<h;t++)
	{
	    for(status = 0; status < (12 + 8); status++)   //ÐèÒª¾­¹ý num+length ¸ö×´Ì¬
	    {
	    	All_LED_PWM(0x00);

	    	for(i = 0; i < 8; i++)  //ÓÐÊý¾ÝµÄµÆ¸²¸ÇÖ®Ç°µÄ0£¬Ã»ÓÐÊý¾ÝµÄ¼ÌÐøÎªÃð
			{
				differ = status - i;
				if((differ > -1) && (differ < 12))  //differ·¶Î§Îª 0 ~ num-1
				{
					U2_SPI_Write_2Byte(LED_List[differ], 0xFF);
				}
			}
	    	U2_SPI_Write_2Byte(0x37, 0x00);  //update
			Delayms(6);
		}
	}
}


void Gangqin_Flash(uint8_t device,uint8_t channel)
{
	OUTx_PWM(device,channel,0xFF);
	Delayms(10);
	OUTx_PWM(device,channel,0x05);
}
