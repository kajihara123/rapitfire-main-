#include "iodefine.h"
#include <stdio.h>
#include "SW4.h"

void sw4Clt(void);



void main(void)
{
	char g_playerNum = 0;			/*現在のプレイヤー番号*/
	PORT0.PDR.BYTE = 0;
	PORTJ.PDR.BIT.B3 = 1;			/*ポート読み込み*/
	PORTJ.PODR.BIT.B3 = 1;
	
	int g_pairDate = -1;			/*初期値をエラー状態にする*/

	while(1){
		sw4Clt();
	}
}
void sw4Clt(void){

	/*相手のデータを読み込む*/

    if (PORT0.PIDR.BIT.B7 == 0)
	{
		if (g_pairDate == -1)
		{
			/*ステータスを異常状態にする*/
		}
		if (g_pairDate >= 0)
		{
			/*相手のデータを7SEGに表示する*/
		}
	
	}
}