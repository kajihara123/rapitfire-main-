/*=====================================================
Project		: 連打ゲーム
File		: renda.c
Function	: メイン処理部分、グローバル変数にする変数の宣言部分
Revision	: 1.00 2025/03/17
Copyright(c):
=====================================================*/

#include	"iodefine.h"
#include	"ledTime.h"
#include	"renda.h"
#include	"initBASE.h"
#include	"7segLcd.h"
#include	"switchData3.h"

signed char g_gameMode 	= 0; 		/* ゲーム状態ステータス */
int g_myData 		= 0;		/* 自分の連打数 */
int g_cnt 		= 0;		/* ledTimeで使う変数 */
int g_ver		= 0;		/* ledTimeで使う変数 */
int g_timeCnt 		= 0;		/* ledTimeで使う変数 */
int g_timeCntDown 	= 0;		/* ledTimeで使う変数 */
int g_pos 		= 0;		/* 7segLcdで使う変数 */
int g_hits		= 0;		/* 7segLcdで使う変数 */

char g_arrhexNum[10] 	= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};	/* 0~9の7セグ表示用16進数 */
char g_arrdigit[4];									/* 連打数の各桁格納配列 */
//char g_arrerrorHex[3]	= {0x79, 0x50, 0x50};						/* Errの7セグ表示用16進数 */

/*=====================================================
Func Name	: main
Function	: メイン処理部分
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: g_gameMode
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
		: 1.01 2025/03/19
=====================================================*/

int main(void)
{
	initBASE();
	initLEDs();
	initCMT0();
	initSWs();
	init7SEG();
	initIRQ();
	
	while(g_gameMode == 0) {		/* ゲーム開始操作待ち */
		waitCmt0();
	}
	
	while(g_gameMode == 1) {
		waitCmt0();
		ledTime();			/* 開始カウントダウン */
	}
	
	while(g_gameMode == 2) {
		waitCmt0();
		ledTime();			/* LEDカウントダウン */
		displayHits();			/* 7セグ表示 */
	}
	
	while(g_gameMode == 3) {
		waitCmt0();
		displayHits();			/* 7セグ表示 */
	}
}