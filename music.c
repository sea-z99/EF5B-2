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
extern uint32_t Time_Counter;
void Music_Stop(void)
{
	Timer1_Stop();
}
void Music_Loop(void)
{
	delay_ms(10000);//�ӳ�10s����
	Init_42ms();
	Timer1_Start();
	while(1)
	{
		switch(Time_Counter)
		{
			case  2: Side_flash(0x10);while(Time_Counter==2); break;
			case  7: Side_flash(0x20);while(Time_Counter==7); break;
			case 12: Side_flash(0x40);while(Time_Counter==12); break;
			case 17: Side_flash(0x80);while(Time_Counter==17); break;
			case 22: Side_flash(0x80);SCAN(10);while(Time_Counter==22); break;
			case 55: while(Time_Counter==55);break; //1st piano start
			case 61: while(Time_Counter==61);break;
			case 67: while(Time_Counter==67);break;
			case 96: while(Time_Counter==96);break;
			case 101:Piano_flash(U2,OUT6);while(Time_Counter==101);break;
			case 107:Piano_flash(U2,OUT4);while(Time_Counter==107);break;
			case 117:Piano_flash(U2,OUT9);while(Time_Counter==117);break;
			case 121:Piano_flash(U2,OUT12);while(Time_Counter==121);break;
			case 127:Piano_flash(U2,OUT15);while(Time_Counter==127);break;
			case 137:Piano_flash(U2,OUT15);while(Time_Counter==137);break;
			case 142:Piano_flash(U2,OUT12);while(Time_Counter==142);break;
			case 147:Piano_flash(U2,OUT9);while(Time_Counter==147);break;
			case 157:Piano_flash(U2,OUT4);while(Time_Counter==157);break;
			case 162:Piano_flash(U2,OUT6);while(Time_Counter==162);break;
			case 167:while(Time_Counter==167);break;
			case 174:while(Time_Counter==174);break;
			case 181:while(Time_Counter==181);break;
			case 187:while(Time_Counter==187);break;   //1st piano end
			case 190:Side_flash(0x80);SCAN(20);SCAN_BACK(20);while(Time_Counter==190);break;
			case 237:while(Time_Counter==237);break; //2nd piano start
			case 250:while(Time_Counter==250);break;
			case 257:while(Time_Counter==257);break;
			case 264:while(Time_Counter==264);break;
			case 267:while(Time_Counter==267);break;
			case 270:while(Time_Counter==270);break;
			case 273:while(Time_Counter==273);break;
			case 277:Gangqin_Flash(U2,OUT7);break;
			case 280:Gangqin_Flash(U2,OUT6);break;
			case 282:Gangqin_Flash(U2,OUT5);break;
			case 286:Gangqin_Flash(U2,OUT4);break;
			case 288:Gangqin_Flash(U2,OUT8);break;
			case 290:Gangqin_Flash(U2,OUT9);break;
			case 293:Gangqin_Flash(U2,OUT10);break;
			case 299:Gangqin_Flash(U2,OUT11);break;
			case 302:Gangqin_Flash(U2,OUT13);break;
			case 306:Gangqin_Flash(U2,OUT15);break;
			case 307:Gangqin_Flash(U2,OUT15);break;
			case 310:Gangqin_Flash(U2,OUT13);break;
			case 312:Gangqin_Flash(U2,OUT11);break;
			case 314:Gangqin_Flash(U2,OUT10);break;
			case 316:Gangqin_Flash(U2,OUT9);break;
			case 319:Gangqin_Flash(U2,OUT8);break;
			case 322:Gangqin_Flash(U2,OUT4);break;
			case 325:Gangqin_Flash(U2,OUT5);break;
			case 327:Gangqin_Flash(U2,OUT6);break;
			case 330:Gangqin_Flash(U2,OUT7);break;
			case 332:while(Time_Counter==332);break;
			case 335:while(Time_Counter==335);break;
			case 339:while(Time_Counter==339);break;
			case 343:while(Time_Counter==343);break;
			case 346:while(Time_Counter==346);break;
			case 350:while(Time_Counter==350);break;
			case 354:while(Time_Counter==354);break;            //2nd pinao end
			case 364:BASE_PWM(0x00);Side_flash(0x80);while(Time_Counter==364);break;          ///////////////////
			case 377:Side_flash(0x80); while(Time_Counter==377);break; //Left side flash
			case 386:Side_flash(0x80);while(Time_Counter==386);break;  //Right side flash
			case 387:SCAN(20);while(Time_Counter==387);break;                                    //SCAN x 2
			case 454:Side_flash(0x80);while(Time_Counter==454);break;
			case 466:Side_flash(0x80);while(Time_Counter==466);break;                                                    //right side flash
			case 473:Side_flash(0x80);SCAN(20); while(Time_Counter==473);break; //Left side flash
			case 507:Side_flash(0x10);while(Time_Counter==507);break;
			case 512:Side_flash(0x10);while(Time_Counter==512);break;
			case 517:Side_flash(0x10);while(Time_Counter==517);break;
			case 522:Side_flash(0x20);while(Time_Counter==522);break;
			case 527:Side_flash(0x20);while(Time_Counter==527);break;
			case 531:Side_flash(0x20);while(Time_Counter==531);break;
			case 536:Side_flash(0x40);while(Time_Counter==536);break;
			case 539:Side_flash(0x40);while(Time_Counter==539);break;
			case 545:Side_flash(0x80);while(Time_Counter==545);break;
			case 550:Side_flash(0x80);while(Time_Counter==550);break;
			case 556:Side_Liushui(12);while(Time_Counter==556);break;   //side liushui start
			case 631:Side_flash(0x80);while(Time_Counter==631);break;
			case 639:Side_Liushui(12);while(Time_Counter==639);break;   //side liushui start
			case 712:Side_flash(0x80);while(Time_Counter==712);break;
			case 718:Side_Liushui(2);while(Time_Counter==718);break;   //side liushui start
			case 744:while(Time_Counter==744);break; // Right side flash
			case 748:Step2(); while(Time_Counter==748);break; //Left side flash
			case 753:Step3();Side_Liushui(2); while(Time_Counter==753);break; // Right side flash
			case 783:while(Time_Counter==783);break;  // Right side flash
			case 789:Step2();  while(Time_Counter==789);break;//Left side flash
			case 794:Step3();Side_Liushui(2); while(Time_Counter==794);break;
			case 823:while(Time_Counter==823);break; // Right side flash
			case 828:Step2();while(Time_Counter==828);break;//Left side flash
			case 834:Step3();while(Time_Counter==834);break; // Right side flash
			case 841:while(Time_Counter==841);break;
			case 843:while(Time_Counter==843);break; //left side
			case 846:while(Time_Counter==846);break;
			case 848:OUTx_Flash(U2,OUT5);   while(Time_Counter==848);break;  //right side
			case 851:OUTx_Flash(U2,OUT9);  while(Time_Counter==851);break;
			case 853:OUTx_Flash(U2,OUT12);  while(Time_Counter==853);break;
			case 856:OUTx_Flash(U2,OUT15); while(Time_Counter==856);break;
			case 858:while(Time_Counter==858);break;
			case 861:while(Time_Counter==861);break;
			case 863:while(Time_Counter==863);break;
			case 865:OUTx_Flash(U2,OUT5);  while(Time_Counter==865);break;  //right side
			case 867:OUTx_Flash(U2,OUT9);  while(Time_Counter==867);break;
			case 871:OUTx_Flash(U2,OUT12);  while(Time_Counter==871);break;
			case 872:OUTx_Flash(U2,OUT15);  while(Time_Counter==872);break;
			case 875:Side_flash(0x80);while(Time_Counter==875);break;
			case 876: SCAN(10);while(Time_Counter==876);break;
			case 907:while(Time_Counter==907);break; //left
			case 912:Step2();while(Time_Counter==912);break;
			case 916:Step3();while(Time_Counter==916);break; //right
			case 926:LIUSHUI();while(Time_Counter==926);break;    //violin start
			case 957:Side_flash(0x80);while(Time_Counter==957);break;
			case 965: SCAN(10);while(Time_Counter==965);break;
			case 987:while(Time_Counter==987);break; //left
			case 993:Step2(); while(Time_Counter==993);break;
			case 998:Step3(); while(Time_Counter==998);break; //right
			case 1007:LIUSHUI(); while(Time_Counter==1007);break;
			case 1038:Side_flash(0x80);while(Time_Counter==1038);break;
			case 1047: SCAN(10);while(Time_Counter==1047);break;
			case 1067:while(Time_Counter==1067);break; //left
			case 1073:Step2(); while(Time_Counter==1073);break;
			case 1078:Step3(); while(Time_Counter==1078);break; //right
			case 1088:LIUSHUI(); while(Time_Counter==1088);break;
			case 1120:Side_flash(0x80);while(Time_Counter==1120);break;
			case 1127:SCAN(10);while(Time_Counter==1127);break;
			case 1149:while(Time_Counter==1149);break; //left
			case 1155: Step2(); while(Time_Counter==1155);break;		// Middle
			case 1160: Step3(); while(Time_Counter==1160);break; //right
			case 1165: OUTx_Flash(U2,OUT15);while(Time_Counter==1165);break;
			case 1167: OUTx_Flash(U2,OUT14);while(Time_Counter==1167);break;
			case 1170: OUTx_Flash(U2,OUT12);while(Time_Counter==1170);break;
			case 1172: OUTx_Flash(U2,OUT10);while(Time_Counter==1172);break;
			case 1175: OUTx_Flash(U2,OUT8);while(Time_Counter==1175);break;
			case 1176: OUTx_Flash(U2,OUT4);while(Time_Counter==1176);break;
			case 1179: OUTx_Flash(U2,OUT6);while(Time_Counter==1179);break;

			case 1181:while(Time_Counter==1181);break;
			case 1184:while(Time_Counter==1184);break;
			case 1186:while(Time_Counter==1186);break;
			case 1189:while(Time_Counter==1189);break;
			case 1191:while(Time_Counter==1191);break;	//left

			case 1196:Step2();while(Time_Counter==1196);break; //right side flash
			case 1201:Step3();while(Time_Counter==1201);break;
			case 1243:Side_flash(0x80);while(Time_Counter==1243);break;
			case 1282:while(Time_Counter==1282);break;

			case 1303:Step2();while(Time_Counter==1303);break;
			case 1322:Step3();while(Time_Counter==1322);break;
			case 1334:while(Time_Counter==1334);break;

			case 1345:Step2();while(Time_Counter==1345);break;
			case 1354:Step3();while(Time_Counter==1354);break;
			case 1365:Side_flash(0x80);while(Time_Counter==1365);break;
			case 1385:while(Time_Counter==1385);break;
			case 1406:Step2(); while(Time_Counter==1406);break;
			case 1426:Step3(); while(Time_Counter==1426);break;
			case 1444:End();while(Time_Counter==1444);break;
			case 1485:Side_flash(0x80);SCAN(40);while(Time_Counter==1485);break;

			case 1500:Timer1_Stop();break; //disable Timer0
			default:break;
		}
	}
}
