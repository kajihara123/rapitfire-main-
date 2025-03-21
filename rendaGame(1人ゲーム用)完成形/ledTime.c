/*=====================================================
Project		: 連打ゲーム
File		: ledTime.c
Function	: ゲームスタート時の合図と時間計測
Revision	: 1.00 2025/03/17
Copyright(c):
=====================================================*/

#include 	"iodefine.h"
#include 	"ledTime.h"
#include 	"renda.h"

/*=====================================================
Func Name	: initLEDs
Function	: LEDの初期設定を行う
Param Input	: None
Param Output: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

void initLEDs(void)
{
	PORTJ.PDR.BIT.B3 = 1;
	PORTJ.PODR.BIT.B3 = 1;
	    
	PORTE.PDR.BYTE = 0xFF;          /*ポートEを出力に設定*/
	PORTE.PODR.BYTE = 0x00;         /*初期状態: LEDは全て消灯*/
	PORTE.PODR.BYTE = 0x0F;     	/*カウントダウン前の状態にする*/
}

/*=====================================================
Func Name	: ledTime
Function	: ゲーム状態ステータスに応じて合図と計測を行う
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: g_gameMode
		  g_timeCntDown
		  g_cnt
		  g_ver
		  g_timeCnt
		  
Output Inf	: g_gameMode = 2
		  g_gameMode = 3
		  g_timeCntDown++
		  g_timeCnt++
Note		:
Revision	: 1.00 2025/03/17
		: 1.01 2025/03/19
=====================================================*/

void ledTime(void)
{
	PORTJ.PODR.BIT.B3 = 1;
	PORTD.PODR.BYTE = 0x00;
	PORTE.PODR.BYTE = 0x00;
 
	/*ゲーム開始前のカウントダウン（g_gameMode == 1）*/
	if (g_gameMode == 1) {
		PORTE.PODR.BYTE = 0x0F >> g_timeCntDown; 		/*LEDカウントダウンのビットシフト*/
		
        	if (g_cnt % 1000 == 0) {  				/*cntが10000回進んだらLEDをシフト*/
           		g_timeCntDown++;
			
			if (PORTE.PIDR.BYTE == 0x01) {          	/*カウントダウンが終わったら次に進む*/
				g_gameMode = 2;                    	/*ゲームモードを2に変更*/
                		PORTE.PODR.BYTE = 0xFF;           	/*全LED点灯*/
            		}
       		}
    	}

// ゲーム中(g_gameMode == 2)
	if (g_gameMode == 2) {
	
		PORTE.PODR.BYTE = 0xFF>>g_timeCnt;			/*LEDをg_timeCnt分ビットシフト*/
		
        	if(g_ver > 0){                                 		/*２回目以降2.5秒ごとに1ビットシフト*/
			if (g_cnt % 1250 == 0) {  
				g_timeCnt++;
				
                		if (g_timeCnt > 7) {          		/*LEDのシフトが終わったら、次に進む*/
                    			g_gameMode = 3;                 /*ゲームモードを3に変更*/
                		}
            		}
        	}
	
	g_ver++;
	waitCmt0();
	}

	g_cnt++;  							/*カウントアップ*/
}
