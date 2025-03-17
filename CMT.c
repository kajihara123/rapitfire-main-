#include	<machine.h>
#include	"iodefine.h"
#include	"CMT.h"


void initCMT0(void)
{
	SYSTEM.PRCR.WORD = 0xA502;	/* プロテクト解除			*/
	MSTP(CMT0) = 0;			/* CMT0 モジュールストップ状態解除	*/
	SYSTEM.PRCR.WORD = 0xA500;	/* プロテクト設定			*/

	CMT0.CMCR.WORD = 0x00C2;	/* CMT0 カウントクロック PCLK/128 CMIE許可	*/
	CMT0.CMCNT = 0;			/* CMT0 CMCNT タイマカウンタ初期化	*/
	CMT0.CMCOR = 375 - 1; 		/* CMT0 CMCOR 設定 48000000/128/1000-1	*/

	IR(CMT0, CMI0)	= 0;		/* CMT0 CMI0 割り込みステータスフラグクリア*/
	IPR(CMT0, CMI0) = 1; 	/* CMT0 CMI0割込み優先レベル設定	*/
	IEN(CMT0, CMI0) = 1; 	/* CMT0 CMI0割込み要求許可		*/

	CMT.CMSTR0.BIT.STR0 = 1;	/* CMT0カウント動作開始			*/
}



void initCMT1(void)
{
	
	SYSTEM.PRCR.WORD = 0xA502;	/* プロテクト解除 */
	MSTP(CMT1) = 0;				/* CMT0 モジュールストップ状態解除 */
	SYSTEM.PRCR.WORD = 0xA500;	/* プロテクト設定 */

	CMT1.CMCR.WORD = 0x00C2;	/* CMT0 カウントクロック PCLK/128 CMIE許可 */

	CMT1.CMCNT = 0;			/* CMT0 CMCNT タイマカウンタ初期化 */
	
	CMT1.CMCOR = 375-1; 		/* CMT0 CMCOR 設定 48000000/128/1000-1 */
	
	IR(CMT1, CMI1)	= 0;		/* CMT1 CMI1 割り込みステータスフラグクリア */
	IPR(CMT1, CMI1) = 1;		/* CMT1 CMI1割込み優先レベル設定	*/
	IEN(CMT1, CMI1) = 1;		/* CMT1 CMI1割込み要求許可		*/

	CMT.CMSTR0.BIT.STR1 = 0;	/* CMT1カウント */
}
