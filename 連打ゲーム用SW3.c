/*=======================================================================
プロジェクト名	: 
ファイル名	: 
機能		: 
機能説明	: 
		: 
修正履歴	: 
=======================================================================*/

/***** include *****/
#include	"iodefine.h"
#include	"initBASE.h"

/***** define *****/
#define		FOREVER	1

/***** prototype *****/
void main(void);
void Excep_ICU_IRQ13(void);
int getSW(int sw);
/*=======================================================================
関数名		: main関数
機能		: メイン関数
入力引数説明	: None
出力引数説明	: None
戻り値		: None 
入力情報	: None
出力情報	: None
特記事項	: 
修正履歴	: 
=======================================================================*/

void main(void)
{	
	int	d_sw3 = 1;				/* スイッチデータ */
	int	egf_sw3 = 0;				/* SW3 エッジ変化処理フラグ */
	int	g_myDate = 0;				/* 対戦中自分の連打回数を保管 */
							
	
	while (FOREVER) {
		
		d_sw3 = getSW(3);			/* スイッチ読み込み */
			
		if(d_sw3 == 0){				/* スイッチが押されているか？ 	*/
		    if(egf_sw3 == 0){			/* スイッチのエッジ変化処理が完了しているか？ */
		    	g_myDate = count++;			/* 押し下げ回数カウント*/
			PORTE.PODR.BYTE = g_myDate;	/* LED表示 			*/
			egf_sw3 = 1;			/* スイッチのエッジ変化処理フラグを完了に設定 */
		    }				
		}else{
			egf_sw3 = 0;			/* スイッチのエッジ変化処理フラグをクリア */							
								
	}
}
}

/*=======================================================================
関数名		: void Excep_ICU_IRQ13(void)
機能		: 指定したスイッチの状態(status) 取得
入力引数説明	: スイッチ番号
出力引数説明	: None
戻り値		: status 
入力情報	: None
出力情報	: None
特記事項	: 
修正履歴	: 
=======================================================================*/
void Excep_ICU_IRQ13(void)
{
	int	g_gameMode = 0;
	
	switch (g_gameMode) {
		case 0:
			ret = 
			break;
		case 1:
			ret = 
			break;
		case 2:
			ret = 
			break;
		case -1:
			ret = 
			break;
	}
	
	return ret;
}

/*=======================================================================
関数名		: int getSW(int sw)
機能		: 指定したスイッチの状態(status) 取得
入力引数説明	: スイッチ番号
出力引数説明	: None
戻り値		: status 
入力情報	: None
出力情報	: None
特記事項	: 
修正履歴	: 
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
