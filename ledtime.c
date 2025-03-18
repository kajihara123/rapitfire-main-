/*=====================================================
Project		: Renda game
File		: ledTime.c
Function	: ゲームスタート時の合図と時間計測
Revision	: 1.00 2025/03/17
Copyright(c):
=====================================================*/

#include "iodefine.h"
#include "renda.h"
#include "ledCtl.h"

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

void initLEDs(void){

    PORTJ.PDR.BIT.B3 = 1; 
    PORTJ.PODR.BIT.B3 = 1;

    PORTD.PDR.BYTE   = 0x00;			
    
    PORTE.PDR.BYTE = 0xFF;          /*ポートEを出力に設定*/
    PORTE.PODR.BYTE = 0x00;         /*初期状態: LEDは全て消灯*/
    PORTE.PODR.BYTE = 0x0F;     /*カウントダウン前の状態にする*/

}

/*=====================================================
Func Name	: ledTime
Function	: ゲーム状態ステータスに応じて合図と計測を行う
Param Input	: None
Param Output: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

void ledTime(void)
{
    PORTJ.PODR.BIT.B3 = 1;

    /*ゲーム開始前のカウントダウン（g_gameMode == 1）*/
    if (g_gameMode == 1) {                     
        if (cnt % 100 == 0) {                      /*cntが10000回進んだらLEDをシフト*/
            PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;   /*LEDを1ビットシフト*/
            if (PORTE.PIDR.BYTE == 0x00) {          /*カウントダウンが終わったら次に進む*/
                g_gameMode = 2;                     /*ゲームモードを2に変更*/
                PORTE.PODR.BYTE = 0xFF;             /*全LED点灯*/
            }
        }
    }

    // ゲーム中（g_gameMode == 2）
    if (g_gameMode == 2) {
        if(ver == 0){}                                /*１回目のループは無視*/
        if(ver > 0){                                  /*２回目以降2.5秒ごとに1ビットシフト*/
            if (cnt % 250 == 0) {                 
                PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;   /*LEDを1ビットシフト*/
                if (PORTE.PIDR.BYTE == 0x00) {          /*LEDのシフトが終わったら、次に進む*/
                    g_gameMode = 3;                     /*ゲームモードを3に変更*/
                }
            }
        }
        ver++;
    }

    cnt++;  /*カウントアップ*/
}

