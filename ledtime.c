#include "iodefine.h"

int ledTime(void)
{
    static int cnt = 0;               /* カウントダウンと時間計測用変数 */
    static int value = 0;      // カウントダウン用の変数
    static int ledShift = 0x0F;  // LEDの初期状態（3つのLEDが点灯）
    PORTJ.PDR.BIT.B3 = 1; 
    PORTJ.PODR.BIT.B3 = 1;
    
    PORTE.PDR.BYTE = 0xFF;    // ポートEを出力に設定
    PORTE.PODR.BYTE = 0x00;   // 初期状態: LEDは全て消灯
    PORTE.PODR.BYTE = ledShift;

    while(1){

    // ゲーム開始前のカウントダウン（g_gameMode == 1）
    if (g_gameMode == 1) {
        // cntが10000回進んだらLEDをシフト
        if (cnt % 10000 == 0) {
            // 3, 2, 1 カウントダウン
//            PORTE.PODR.BYTE = ledShift;  // LEDの状態を変更
            PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;  // LEDを1ビットシフト

            // カウントダウンが終わったら次に進む
            if (PORTE.PIDR.BYTE == 0x00) {  
                g_gameMode = 2;  // ゲームモードを2に変更
                PORTE.PODR.BYTE = 0xFF;  // 全LED点灯
            }
        }
    }

    // ゲーム中（g_gameMode == 2）
    if (g_gameMode == 2) {
        // 約2.5秒ごとにLEDをシフト
        if (cnt % 10000 == 0) {
            PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;  // LEDを1ビットシフト

            // LEDのシフトが終わったら、次に進む
            if (PORTE.PIDR.BYTE == 0x00) {
                g_gameMode = 3;  // ゲームモードを3に変更（終了）
            }
        }
    }

    cnt++;  // カウントアップ
    }
}

	/*

	cnt++;

	--------------------------------------
	開始前カウントダウン
	--------------------------------------
	if(g_gameMode == 1 && cnt % 31500 == 0){

        PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;
		cnt = 0;
	}


	---------------------------------------
	ゲーム中カウントダウン
	-------------------------------------
	if(cnt % 78750 == 0){
		PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;
		cnt = 0;
	}

	g_gamemode = 3;
	*/

