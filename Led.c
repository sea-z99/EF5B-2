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

void Fog_Open(void)
{
	char i;
	for(i=0x28;i<=0x30;i++)
	{
		SPI_Write_2Byte(2,i,255);
	}
	SPI_Write_2Byte(2,0x37,0x00);//update
}
void Fog_Close(void)
{
	char i;
	for(i=0x28;i<=0x30;i++)
	{
		SPI_Write_2Byte(2,i,0);
	}
	SPI_Write_2Byte(2,0x37,0x00);//update
}
void Led_RT_AllOpen(void)
{
	char i;
	for(i=0x1F;i<=0x27;i++)
	{
		SPI_Write_2Byte(2,i,255);
	}
	SPI_Write_2Byte(2,0x37,0x00);//update
}
void Led_RT_AllClose(void)
{
	char i;
	for(i=0x1F;i<=0x27;i++)
	{
		SPI_Write_2Byte(2,i,0);
	}
	SPI_Write_2Byte(2,0x37,0x00);//update
}
void Led_Tail_AllOpen(void)
{
	char i;
	SPI_Write_2Byte(1,0x1F,0x3F);//25%
	SPI_Write_2Byte(1,0x20,0x55);//25%
	SPI_Write_2Byte(1,0x21,0x55);//25%
	for(i=0x22;i<=0x2D;i++)
	{
		SPI_Write_2Byte(1,i,0x3F);//25%
	}
	SPI_Write_2Byte(1,0x37,0x00);//update
}
void Led_Tail_AllClose(void)
{
	char i;
	SPI_Write_2Byte(1,0x1F,0);//25%
	SPI_Write_2Byte(1,0x20,0);//25%
	SPI_Write_2Byte(1,0x21,0);//25%
	for(i=0x22;i<=0x2D;i++)
	{
		SPI_Write_2Byte(1,i,0);//25%
	}
	SPI_Write_2Byte(1,0x37,0x00);//update
}
