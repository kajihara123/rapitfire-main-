/*=====================================================
Project		: Renda game
File		: ledCtl.c
Function	: 勝敗時のled制御
Revision	: 1.00 2025/03/17
Copyright(c):
=====================================================*/
#include	"iodefine.h"
#include	"renda.h"
#include	"ledCtl.h"

/*=====================================================
Func Name	: ledRes
Function	: ゲームの勝敗判定によってLEDの点灯位置を制御する
Param Input	: None
Param Output: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

void ledRes(void)
{
	portSwitch();

	if(decision == -1) {
		decision = win_or_lose();
	}

	/*判定結果によってLEDの点灯場所を管理*/
	switch(decision) {
		case 0:
			PORTE.PODR.BYTE = 0x00;
			break;
		case 1:
			PORTE.PODR.BYTE = 0xFF;
			break;
		case 2:
			PORTE.PODR.BYTE = 0xF0;
			break;
		default:
		break;
		}
}

/*=====================================================
Func Name	: win_or_lose
Function	: ゲームの勝敗判定を行う
Param Input	: None
Param Output: decision
Return Val	: 0 = 負け, 1 = 勝ち, 2 = 引き分け
Input Inf	: g_myDate, g_pairDate
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

int win_or_lose(void)
{
	int res;
	
	if(g_myData < g_pairData) {				//g_myDataがg_pairDataより小さい場合
		res = 0;							//負け
	}else if(g_pairData < g_myData) {		//g_pairDataがg_myDataより小さい場合
		res = 1;							//勝ち
	}else if(g_myData == g_pairData) {		//g_myDataとg_pairDataの数値が同じ場合
		res = 2;							//引き分け
	}
	return res;
}

/*=====================================================
Func Name	: portSwitch
Function	: ポートの設定を行う
Param Input	: None
Param Output: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		: None
Revision	: 1.00 2025/03/17
=====================================================*/

/*7SEG使用時にLEDの出力を切られているので再設定*/

/*
void portSwitch(void)
{
	PORTD.PDR.BYTE   = 0x00;			
	
	PORTJ.PDR.BIT.B3  	= 1;			
	PORTE.PDR.BYTE 		= 0xFF;
	
	PORTJ.PODR.BIT.B3 	= 1;
	PORTE.PODR.BYTE 	= 0x00;
}
*/