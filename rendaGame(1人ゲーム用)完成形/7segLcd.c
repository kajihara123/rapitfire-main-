/*=====================================================
Project		: 連打ゲーム
File		: 7segLcd.c
Function	: 7segの初期設定と出力設定
Revision	: 1.00 2025/03/17
		: 1.01 2025/03/19
Copyright(c):
=====================================================*/

#include	"iodefine.h"
#include	<stdio.h>
#include	"7segLcd.h"
#include	"renda.h"
#include	"CMT.h"

/*=====================================================
Func Name	: init7SEG
Function	: 7SEGの初期設定をする
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

void init7SEG(void)
{
	PORTE.PODR.BYTE   = 0x00;	/* PE0-PE7 OFF                     */
	PORTE.PDR.BYTE    = 0xFF;	/* PE0-PE7 出力ポート設定          */
	PORTJ.PODR.BIT.B3 = 0;
	
//	PORTD.PODR.BYTE &= 0x07;	/* PD3-7   OFF                     */
//	PORTD.PDR.BYTE  |= 0xF8;	/* PD3-7   出力ポート設定          */
	PORTD.PODR.BYTE = 0x00;
	PORTD.PDR.BYTE 	= 0xFB;
	
}

/*=====================================================
Func Name	: displayHits
Function	: 7segの出力設定
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: g_pos
		  g_hexNum[]
		  g_digit[]
		  
Output Inf	: g_pos++
		  g_pos = 0
Note		:
Revision	: 1.00 2025/03/17
		: 1.01 2025/03/19
=====================================================*/

void displayHits(void)
{
	processHits();
	
	preparat7seg();
	
	if (g_pos < 4) {
		PORTD.PODR.BYTE |= 0x40 >> g_pos;
	}
	
	PORTE.PODR.BYTE = g_arrhexNum[g_arrdigit[g_pos]];	/* processHitsで保管した値を使い7seg点灯*/
		
	g_pos++;
	if (g_pos > 3) {
		g_pos = 0;
	}
	//waitCmt0();
}

/*=====================================================
Func Name	: processHits
Function	: 7segの出力設定
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: g_hits
		  g_myData
		  g_digit[]
		  
Output Inf	: g_hits = g_myData
		: g_digit[0] = g_hits / 1000
		  g_hits %= 1000
		: g_digit[1] = g_hits / 100
		  g_hits %= 100
		: g_digit[2] = g_hits / 10
		  g_hits %= 10
		: g_digit[3] = g_hits
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

void processHits(void)
{
	g_hits = g_myData;
	
	/* g_hitsの値を配列に保管*/
	
	g_arrdigit[0] = g_hits / 1000;	
	g_hits %= 1000;
	
	g_arrdigit[1] = g_hits / 100;	
	g_hits %= 100;
	
	g_arrdigit[2] = g_hits / 10;	
	g_hits %= 10;
	
	g_arrdigit[3] = g_hits;		
}

/*=====================================================
Func Name	: preparat7seg
Function	: LEDから7segに出力を切り替える
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

void preparat7seg(void)
{
	PORTE.PODR.BYTE   = 0x00;
	PORTJ.PODR.BIT.B3 = 0;
	
	PORTD.PODR.BYTE = 0x00; 
		
}	

/*=====================================================
Func Name	: displayError
Function	: エラー用7segの出力設定(対戦ゲーム用に考えた設定)
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

/*
void displayError(void)
{
	static int pos = 0;
	
	preparat7seg();
	
	if (pos < 3) {
		PORTD.PODR.BYTE |= 0x20 >> pos;
	}
	
	if(pos < 3){
	PORTE.PODR.BYTE = g_errorHex[pos];
	}
	
	pos++;
	if (pos > 2) {
		pos = 0;
	}
}
*/