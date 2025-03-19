#include "iodefine.h"
#include <stdio.h>
#include "switchdata3.h"
#include "renda.h"
#include "CMT.h"

void sw3Chatter(void)
{
	int	d_sw3 = 1;	/* スイッチデータ */
	int	egf_sw3 = 0;	/* SW3 エッジ変化処理フラグ */
	char	count = 0;	/* スイッチが押された回数 */
	int	c_time = 0;	/* チャタリング時間計測カウンタ */
	int	sw_now = 1;	/* スイッチデータ(最新） */
	int	sw_tmp = 1;	/* スイッチデータ(一時保存） */

	initBASE();				/* クロック初期化 	*/	
	initSWs();				/* SW初期化 		*/
	initCMT0();				/* CMT初期化 		*/

	while (FOREVER) {

		while (IR(CMT0,CMI0) == 0) ;			/* CMT0:[IR28.IR]割込み発生を待つ (1ms)   */
		
		IR(CMT0, CMI0) = 0;				/* CMT0:[IR28.IR]割込みフラグをクリア     */
		
		c_time++;						/* チャタリング時間計測カウンタ +1 */
		
		if (c_time >= C_TIME) {					/* チャタリング時間経過？ */
			
			c_time = 0;						/* チャタリング時間計測カウンタクリア */
			
			sw_now = getSW(3);					/* スイッチ読み込み */
			if(sw_tmp == sw_now){					/* 前回と同じスイッチ状態か？ */
				d_sw3 = sw_now; 				/* 前回と同じスイッチ状態なら確定データとする */
			} else {
				sw_tmp = sw_now;						
			}							/* 前回と同じスイッチ状態ではないなら一時保存 */
			if(d_sw3 == 0){						/* スイッチが押されているか？ 	*/
			if(egf_sw3 == 0){					/* スイッチのエッジ変化処理が完了しているか？ */
				count ++;					/* 押し下げ回数カウント 	*/
				PORTE.PODR.BYTE = count;			/* LED表示 			*/
				egf_sw3 = 1;					/* スイッチのエッジ変化処理フラグを完了に設定 */
			}							/* スイッチのエッジ変化処理フラグをクリア */
		} else {
			egf_sw3 = 0;
		}
			
		}		
	}

}	

void sw3Clt(void)
{
	
	if (PORT0.PIDR.BIT.B5 == 0){
		if (g_gameMode == 0){
			g_gameMode = 1;
		}
		if (g_gameMode == 2){
			g_myData = g_myData + 1;			
		}	
		if (g_gameMode == 3){
			g_playerNum = 1;	/*自分のプレーヤー番号の選択*/
		}		
	}
}
/*=======================================================================
関数名		: initSW関数
機能		: スイッチ入力ポート初期化
入力引数説明	: None
出力引数説明	: None
戻り値		: None 
入力情報	: None
出力情報	: None
特記事項	: 
修正履歴	: 1.00 2020/09/25 研修三郎　emTech21版
=======================================================================*/
void initSW(void)
{
	PORT0.PMR.BIT.B5 = 0;	/* PORT0 PMR B5 GPIOとして使用 */
	PORT0.PMR.BIT.B7 = 0;	/* PORT0 PMR B7 GPIOとして使用 */

}
/*void initSWs(void)
{
	PORT0.PDR.BIT.B5 = 0; P05 初期化  
	PORT0.PDR.BIT.B7 = 0; P07 初期化  
	
}*/
/*=======================================================================
関数名		: int getSW(int sw)
機能		: 指定したスイッチの状態(status) 取得
入力引数説明	: スイッチ番号
出力引数説明	: None
戻り値		: status 
入力情報	: None
出力情報	: None
特記事項	: 
修正履歴	: 1.00 2020/09/25 研修三郎
=======================================================================*/
int getSW(int sw)
{
	int	ret = -1;
	
	switch (sw) {
		case 3:
			ret = PORT0.PIDR.BIT.B5;
			break;
		case 4:
			ret = PORT0.PIDR.BIT.B7;
			break;
	}
	
	return ret;
}
