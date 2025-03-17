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
#include    <stdio.h>

/***** define *****/
#define		FOREVER	1

/***** prototype *****/
void main(void);
void sw3Clt(void);
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

// typedef struct {
//     signed char is_initialized : 0;  // 初期化済みフラグ
//     signed char is_running : 2;      // 実行中フラグ
//     signed char is_error : 3;        // エラーフラグ
// } g_gameMode;




void main(void)
{	
	int	d_sw3 = 1;				/* スイッチデータ */
	int	egf_sw3 = 0;				/* SW3 エッジ変化処理フラグ */
	int	myDate = 0;			/* 対戦中自分の連打回数を保管 */
	signed char g_gameMode = 0;		/* ゲームモード*/		
	int	g_myDate = 0;				/* 対戦中自分の連打回数を保管 */
	char g_playerNum = 0;

	PORT0.PDR.BYTE = 0;
	PORTJ.PDR.BIT.B3 = 1;
	PORTJ.PODR.BIT.B3 = 1;
							
	
	while (FOREVER) {
		sw3Clt();
	}
}

/*=======================================================================
関数名		: void sw3Clt(void)
機能		: 指定したスイッチの状態(status) 取得
入力引数説明	: スイッチ番号
出力引数説明	: None
戻り値		: status 
入力情報	: None
出力情報	: None
特記事項	: 
修正履歴	: 
=======================================================================*/
void sw3Clt(void)
{
		if (PORT0.PIDR.BIT.B5 == 0){
			/*ゲームステータスを0にする*/
			if (g_gameMode == 2){
				g_myDate = g_myDate + 1;		
				/*ゲームモードを2にする*/	
			}	
			if (g_gameMode == 3){
				g_playerNum = 1;
			}		
	}
}


