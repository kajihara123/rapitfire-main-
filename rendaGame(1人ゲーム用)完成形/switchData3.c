/*=====================================================
Project		: 連打ゲーム
File		: switchdata3.c
Function	: sw3の初期設定や割り込み設定
Revision	: 1.00 2025/03/17
Copyright(c):
=====================================================*/

#include "iodefine.h"
#include <stdio.h>
#include "switchData3.h"
#include "renda.h"
#include "CMT.h"
#include "vect.h"	/* 割込みベクター定義 */

/*sw3割り込み初期設定*/
void initIRQ(void)
{

	MPC.PWPR.BIT.B0WI	= 0;		/* MPC書き込みプロテクトレジスタ書き込み許可 */
	MPC.PWPR.BIT.PFSWE	= 1;		/* MPC書き込みプロテクトレジスタ書き込み許可 */

	MPC.P05PFS.BIT.ISEL = 1;		/* P05 ISELを設定、IRQ13入力端子とする */
	MPC.P07PFS.BIT.ISEL = 1;		/* P07 ISELを設定、IRQ15入力端子とする */

	MPC.PWPR.BIT.PFSWE	= 0;		/* MPC書き込みプロテクトレジスタ書き込み禁止 */
	MPC.PWPR.BIT.B0WI	= 1;		/* MPC書き込みプロテクトレジスタ書き込み禁止 */

	ICU.IRQCR[13].BIT.IRQMD = 1;		/* IRQ13検出 1:立ち下がり 2:立ち上がり 3:両エッジ */

	ICU.IRQCR[15].BIT.IRQMD = 1;		/* IRQ15検出 1:立ち下がり 2:立ち上がり 3:両エッジ */

	IR(ICU, IRQ13)	= 0;			/* IRQ13のIR をクリア */
	IPR(ICU, IRQ13) = 1;			/* IRQ13割込み優先度設定 */
	IEN(ICU, IRQ13) = 1;			/* IRQ13割込み要求許可 */

	IR(ICU, IRQ15)	= 0;			/* IRQ15のIR をクリア */
	IPR(ICU, IRQ15) = 1;			/* IRQ15割込み優先度設定 */
	IEN(ICU, IRQ15) = 1;			/* IRQ15割込み要求許可 */

}

/*=====================================================
Func Name	: initSWs
Function	: sw3の初期設定
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.01 2025/03/19
=====================================================*/

void initSWs(void)
{
	PORT0.PDR.BIT.B5 = 0;	/* PORT0 PDR B5 入力ピンとして使用 */
//	PORT0.PDR.BIT.B7 = 0;	/* PORT0 PDR B7 入力ピンとして使用 */
	
//	PORT0.PDR.BIT.B5 = 0; /* P05 初期化  */
//	PORT0.PDR.BIT.B7 = 0; /* P07 初期化  */
}



/*=====================================================
Func Name	: Excep_ICU_IRQ13
Function	: sw3の割り込み処理
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: g_gameMode
		  g_myData
		
Output Inf	: g_gameMode = 1
		  g_myData = g_myData + 1
Note		:
Revision	: 1.01 2025/03/19
=====================================================*/

void Excep_ICU_IRQ13(void)					/* 割込み処理関数 */
{	
	if (g_gameMode == 0){
		g_gameMode = 1;
	}
	if (g_gameMode == 2){
		g_myData = g_myData + 1;			
	}
}



/*対戦用で考えていた割り込みを使わないsw3の設定*/

//void sw3Chatter(void)
//{
//	int	d_sw3 = 1;	/* スイッチデータ */
//	int	egf_sw3 = 0;	/* SW3 エッジ変化処理フラグ */
//	char	count = 0;	/* スイッチが押された回数 */
//	int	c_time = 0;	/* チャタリング時間計測カウンタ */
//	int	sw_now = 1;	/* スイッチデータ(最新） */
//	int	sw_tmp = 1;	/* スイッチデータ(一時保存） */

//	initBASE();				/* クロック初期化 	*/	
//	initSWs();				/* SW初期化 		*/
//	initCMT0();				/* CMT初期化 		*/

//	while (FOREVER) {

//		while (IR(CMT0,CMI0) == 0) ;			/* CMT0:[IR28.IR]割込み発生を待つ (1ms)   */
		
//		IR(CMT0, CMI0) = 0;				/* CMT0:[IR28.IR]割込みフラグをクリア     */
		
//		c_time++;						/* チャタリング時間計測カウンタ +1 */
		
//		if (c_time >= C_TIME) {					/* チャタリング時間経過？ */
			
//			c_time = 0;						/* チャタリング時間計測カウンタクリア */
			
//			sw_now = getSW(3);					/* スイッチ読み込み */
//			if(sw_tmp == sw_now){					/* 前回と同じスイッチ状態か？ */
//				d_sw3 = sw_now; 				/* 前回と同じスイッチ状態なら確定データとする */
//			} else {
//				sw_tmp = sw_now;						
//			}							/* 前回と同じスイッチ状態ではないなら一時保存 */
//			if(d_sw3 == 0){						/* スイッチが押されているか？ 	*/
//			if(egf_sw3 == 0){					/* スイッチのエッジ変化処理が完了しているか？ */
//				count ++;					/* 押し下げ回数カウント 	*/
//				PORTE.PODR.BYTE = count;			/* LED表示 			*/
//				egf_sw3 = 1;					/* スイッチのエッジ変化処理フラグを完了に設定 */
//			}							/* スイッチのエッジ変化処理フラグをクリア */
//		} else {
//			egf_sw3 = 0;
//		}
			
//		}		
//	}

//}	

/*=====================================================
Func Name	: sw3Ctl
Function	: ゲーム状態ステータスに応じて処理をする
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
		: 1.01 2025/03/19
=====================================================*/

/*
void sw3Ctl(void)
{
	if (PORT0.PIDR.BIT.B5 == 0) {
		if (g_gameMode == 0) {
			g_gameMode = 1;
		}
		if (g_gameMode == 2) {
			g_myData = g_myData + 1;			
		}	
		if (g_gameMode == 3) {		対戦用の設定
			g_gameMode = 0;		自分のプレーヤー番号の選択
		}		
	}
}
*/