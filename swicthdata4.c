#include "iodefine.h"
#include <stdio.h>
#include "switchdata4.h"


void sw4Clt(void){
	
    if (PORT0.PIDR.BIT.B7 == 0)
	{
		if (g_gameMode == 3)				/*ゲームステータスが３の時に以下の処理を行う*/
		{
		 if (g_pairData == -1)
		 {
		 	g_gameMode = -1; 				/*！ステータスを異常状態にする*/
		 }
			g_playerNum = 2;
		}
	}
}