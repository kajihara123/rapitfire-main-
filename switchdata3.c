#include	"iodefine.h"
#include    <stdio.h>
#include    "switchdata3.h"
#include    "renda.h"

void sw3Clt(void)
{
	if (PORT0.PIDR.BIT.B5 == 0){
		if (g_gameMode == 2){
			g_myData = g_myData + 1;			
		}	
		if (g_gameMode == 3){
			g_playerNum = 1;	/*自分のプレーヤー番号の選択*/
		}		
	}
}
