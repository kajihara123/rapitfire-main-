/*=====================================================
Project		: 連打ゲーム
File		: CMT.c
Function	: CMTの初期設定とウェイトの設定
Revision	: 1.00 2025/03/17
Copyright(c):
=====================================================*/

#include	<machine.h>
#include	"iodefine.h"
#include	"CMT.h"

/*=====================================================
Func Name	: initCMT0
Function	: CMT0の初期設定
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

void initCMT0(void)
{
	SYSTEM.PRCR.WORD = 0xA502;	/* プロテクト解除			*/
	MSTP(CMT0) = 0;			/* CMT0 モジュールストップ状態解除	*/
	SYSTEM.PRCR.WORD = 0xA500;	/* プロテクト設定			*/

	CMT0.CMCR.WORD = 0x00C2;	/* CMT0 カウントクロック PCLK/128 CMIE許可	*/
	CMT0.CMCNT = 0;			/* CMT0 CMCNT タイマカウンタ初期化	*/
	CMT0.CMCOR = 375 - 1; 		/* CMT0 CMCOR 設定 48000000/128/100-1	*/

	IR(CMT0, CMI0)	= 0;		/* CMT0 CMI0 割り込みステータスフラグクリア*/
//	IPR(CMT0, CMI0) = 1; 		/* CMT0 CMI0割込み優先レベル設定	*/
//	IEN(CMT0, CMI0) = 1; 		/* CMT0 CMI0割込み要求許可		*/

	CMT.CMSTR0.BIT.STR0 = 1;	/* CMT0カウント動作開始			*/
}



/*=====================================================
Func Name	: waitCMT0
Function	: ウェイト用の設定
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

void waitCmt0(void)
{
	while (IR(CMT0,CMI0) == 0) ;	
		
	IR(CMT0, CMI0) = 0;		
}



/*=====================================================
Func Name	: initCMT1
Function	: CMT1の初期設定
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

//使わないためコメントアウト

//void initCMT1(void)
//{
	
//	SYSTEM.PRCR.WORD = 0xA502;	/*プロテクト解除 */
//	MSTP(CMT1) = 0;			/*CMT0 モジュールストップ状態解除 */
//	SYSTEM.PRCR.WORD = 0xA500;	/*プロテクト設定 */

//	CMT1.CMCR.WORD = 0x00C3;	/* CMT0 カウントクロック PCLK/512 CMIE許可 */

//	CMT1.CMCNT = 0;			/* CMT0 CMCNT タイマカウンタ初期化 */
	
//	CMT1.CMCOR = 46875 -1; 		//0.5秒
	
//	IR(CMT1, CMI1)	= 0;		/* CMT1 CMI1 割り込みステータスフラグクリア */
//	IPR(CMT1, CMI1) = 1;		/* CMT1 CMI1割込み優先レベル設定	*/
//	IEN(CMT1, CMI1) = 1;		/* CMT1 CMI1割込み要求許可		*/

//	CMT.CMSTR0.BIT.STR1 = 0;	/* CMT1カウント最初はストップ */
//}



/*=====================================================
Func Name	: waitCMT1
Function	: ウェイト用の設定
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

/*使わないのでコメントアウト

void waitCmt1(void)
{
	
	while (IR(CMT1,CMI1) == 0) ;	
		
	IR(CMT1, CMI1) = 0;		
}
*/