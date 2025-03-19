#include "iodefine.h"
#include <stdio.h>
#include "switchdata4.h"
#include "renda.h"

void sw4Clt(void)
{
    if (PORT0.PIDR.BIT.B7 == 0){

		if (g_gameMode == 3){				/*ゲームステータスが３の時に以下の処理を行う*/
			g_playerNum = 2;
		}
	}
}