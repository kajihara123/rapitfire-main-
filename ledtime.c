#include"iodefine.h"

void ledTime(void)
{
	int cnt =0;                    	/*カウントダウンと時間計測用変数*/
	int weight = 0;                 /*タイマカウンタ用ウェイト*/
	PORTJ.PDR.BIT.B3 = 1; 
	PORTJ.PODR.BIT.B3 = 1;
	
	PORTE.PDR.BYTE = 0xFF;
	PORTE.PODR.BYTE = 0x00;

    PORTE.PODR.BYTE = 0x07;	
	cnt++;

	/*--------------------------------------
	開始前カウントダウン
	--------------------------------------*/
	if(g_gameMode == 1 && cnt % 31500 == 0){
		
		PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;
		ゲーム状態ステータスを2に
		cnt = 0;
	}


	/*---------------------------------------
	ゲーム中カウントダウン
	---------------------------------------*/
	if(cnt % 78750 == 0){
		LEDシフト
		LEDが全消灯したらゲーム終了ステータスを3に
	}
}
