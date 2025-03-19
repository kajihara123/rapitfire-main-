#include "iodefine.h"
#include <stdio.h>
#include "switchdata3.h"
#include "renda.h"
#include "CMT.h"

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

	PORT0.PDR.BIT.B5 = 0;	/* PORT0 PDR B5 入力ピンとして使用 */
	PORT0.PDR.BIT.B7 = 0;	/* PORT0 PDR B7 入力ピンとして使用 */
}
/*void initSWs(void)
{
	PORT0.PDR.BIT.B5 = 0; P05 初期化  
	PORT0.PDR.BIT.B7 = 0; P07 初期化  
	
}*/

/*=======================================================================
関数名		: getSW関数
機能		: 個別スイッチ読み取り
入力引数説明	: int bit SWに対応するビット番号
出力引数説明	: None
戻り値		: SW押下状態（0:解放／1:押下） 
入力情報	: None
出力情報	: None
特記事項	: 負論理なので論理反転して返す
修正履歴	: 1.00 2020/09/25 研修三郎　emTech21版
=======================================================================*/
int getSW(int bit)
{
	int	ret = 0;

	if ( bit == 5 ) {
		ret = !PORT0.PIDR.BIT.B5;	/* SW 論理反転 */
	} else if ( bit == 7 ) {
		ret = !PORT0.PIDR.BIT.B7;	/* SW 論理反転 */
	}

	return ret;
}

/*=======================================================================
関数名		: getSWs関数
機能		: スイッチ一括読み取り
入力引数説明	: None
出力引数説明	: None
戻り値		: ビット対応 SW押下状態（0:解放／1:押下） 
入力情報	: None
出力情報	: None
特記事項	: 負論理なので論理反転して返す
修正履歴	: 1.00 2020/09/25 研修三郎　emTech21版
=======================================================================*/
int getSWs(void)
{
	int ret = 0;

	ret = ~PORT0.PIDR.BYTE & 0xa0;

	return ret;
}