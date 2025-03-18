#include "iodefine.h"
#include <stdio.h>
#include "switchdate4.h"


void sw4Clt(void){

	/*相手のデータを読み込む*/

    if (PORT0.PIDR.BIT.B7 == 0)
	{
		if (g_gameMode == 3)				/*ゲームステータスが３の時に以下の処理を行う*/
		{
		 if (g_pairDate == -1)
		 {
		 	g_gameMode = -1; 				/*！ステータスを異常状態にする*/
		 }
			g_playerNum = 2;
		}
	}
}