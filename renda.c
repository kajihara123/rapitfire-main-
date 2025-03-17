#include "7segLcd.h"
#include "CMT.h"
#include "initBASE.h"

void main(void)
{
	initBASE();
	
	while(g_gameMode == 0){
		waitCmt0();
		//ボタン受付SCI処理		
	}
	
	while(g_gameMode == 1){
		waitCmt0();
		//開始カウントダウン
	}
	
	while(g_gameMode == 2){
		
		waitCmt0();
		/*ボタン受付連打記憶
		  LEDカウントダウン
		  7セグ表示*/
					　
	}
	
	
	//SCI通信処理
	
	while(g_gameMode == 3){
		/*ボタン受付プレイヤー切り替え
		  LED勝敗判定
		  7セグ表示*/
	}
	
	while(g_gameMode == -1){
		//エラー7セグ	
	}
}

