/*
 * music.h
 *
 *  Created on: 2021-1-11
 *      Author: Rick
 */

#ifndef MUSIC_H_
#define MUSIC_H_

#define OUT1 0x1F
#define OUT2 0x20
#define OUT3 0x21
#define OUT4 0x22
#define OUT5 0x23
#define OUT6 0x24
#define OUT7 0x25
#define OUT8 0x26
#define OUT9 0x27
#define OUT10 0x28
#define OUT11 0x29
#define OUT12 0x2A
#define OUT13 0x2B
#define OUT14 0x2C
#define OUT15 0x2D
#define OUT16 0x2E
#define OUT17 0x2F
#define OUT18 0x30

void Time_Increase(void);
void Time_Clear(void);
void Music_Loop(void);
void Music_Stop(void);

#endif /* MUSIC_H_ */
