#include	"iodefine.h"
#include	<stdio.h>
#include	"7segLcd.h"
#include	"renda.h"


void init7SEG(void)
{
	PORTE.PODR.BYTE   = 0x00;	/* PE0-PE7 OFF                     */
	PORTE.PDR.BYTE    = 0xFF;	/* PE0-PE7 出力ポート設定          */

	
//	PORTD.PODR.BYTE &= 0x07;	/* PD3-7   OFF                     */
//	PORTD.PDR.BYTE  |= 0xF8;	/* PD3-7   出力ポート設定          */
	PORTD.PODR.BYTE = 0x00;
	PORTD.PDR.BYTE 	= 0xFB;
	
}

void displayHits(void)
{
	static int pos = 0;
	
	processHits();
	
	preparat7seg();
	

	if (pos < 4) {
		PORTD.PODR.BYTE |= 0x40 >> pos;
	}
	
	PORTE.PODR.BYTE = g_hexNum[g_digit[pos]];
		
	pos++;
	if (pos > 3) {
		pos = 0;
	}
}


void processHits(void)
{
	int hits;
	
	if(g_playerNum == 1){
		hits = g_myData;
	}else if(g_playerNum == 2){
		hits = g_pairData;
	}
		
	g_digit[0] = hits / 1000;	
	hits %= 1000;
	g_digit[1] = hits / 100;	
	hits %= 100;
	g_digit[2] = hits / 10;	
	hits %= 10;
	g_digit[3] = hits;		
}

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

void preparat7seg(void)
{
	PORTE.PODR.BYTE   = 0x00;
	PORTJ.PODR.BIT.B3 = 0;
	
	PORTD.PODR.BYTE = 0x00; 
		
}	
