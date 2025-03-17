#include"iodefine.h"

void ledTime(void)
{
    int cnt =0;                    	/*カウントダウンと時間計測用変数*/
	int weight = 0;                 /*タイマカウンタ用ウェイト*/
	PORTJ.PDR.BIT.B3 = 1; 
	PORTJ.PODR.BIT.B3 = 1;
	
	PORTE.PDR.BYTE = 0xFF;
	PORTE.PODR.BYTE = 0x00;

    	PORTE.PODR.BYTE = 0x07;									/*スタートの合図用に3つつける*/
    	for(cnt = 0; cnt < 3; cnt++){							
        	for(weight = 0; weight < 31500; weight++){}
        	PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;				/*約１秒ごとに１ビットシフト*/
   	}	

    	for (cnt = 0, PORTE.PODR.BYTE = 0xFF; cnt < 8; cnt++)	/*全点灯*/
    	{
        	for(weight = 0; weight < 78750; weight++){}
        	PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;				/*約2.5秒ごとに１ビットシフト*/
	}






	/*

	cnt++;

	--------------------------------------
	開始前カウントダウン
	--------------------------------------
	if(g_gameMode == 1 && cnt % 31500 == 0){
		LEDシフト
		ゲーム状態ステータスを2に
	}


	---------------------------------------
	ゲーム中カウントダウン
	-------------------------------------
	if(cnt % 78750 == 0){
		LEDシフト
		LEDが全消灯したらゲーム終了ステータスを2に
	}

	*/
}
