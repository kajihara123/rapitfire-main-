/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c or Main.cpp                                    */
/*  DATE        :Mon, Mar 17, 2025                                     */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/

#include	"iodefine.h"

void main(void);
//int win_or_lose(void);
void portSwitch(void);

void ledCtl(void)
{
	int decision = 0;
	
	portSwitch();
	
	while(1) {
//		decision = win_or_lose();

		switch(decision) {
			case 0:
				PORTE.PODR.BYTE = 0x00;
				break;
			case 1:
				PORTE.PODR.BYTE = 0xFF;
				break;
			case 2:
				PORTE.PODR.BYTE = 0xF0;
				break;
		}
	}
	
}


int win_or_lose(void)
{
	int res;
	
	if(g_myDate < g_pairDate) {
		res = 0;
	}else if(g_pairDate < g_myDate) {
		res = 1;
	}else if(g_myDate == g_pairDate) {
		res = 2;
	}
}



void portSwitch(void)
{
	PORTD.PDR.BYTE   = 0x00;
	
	PORTJ.PDR.BIT.B3  	= 1;
	PORTE.PDR.BYTE 		= 0xFF;
	
	PORTJ.PODR.BIT.B3 	= 1;
	PORTE.PODR.BYTE 	= 0x00;
}
