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
<<<<<<< HEAD
	int	gameMode = 0;			/* ゲームモード*/		
=======
	signed char g_gameMode = 0;		/* ゲームモード*/		
>>>>>>> b8958f8e512552f344ea817f4f40ccbe5f2e767b
	int	g_myDate = 0;				/* 対戦中自分の連打回数を保管 */
	char g_playerNum = 0;
	
							
	
	while (FOREVER) {
		
		g_gameMode = Excep_ICU_IRQ13();
		d_sw3 = getSW(3);			/* スイッチ読み込み */
			
		if(d_sw3 == 0){				/* スイッチが押されているか？ 	*/
		    if(egf_sw3 == 0){			/* スイッチのエッジ変化処理が完了しているか？ */
		    	g_myDate = count++;			/* 押し下げ回数カウント*/
<<<<<<< HEAD
			PORTE.PODR.BYTE = g_myDate;	/* LED表示 			*/
=======
			/* PORTE.PODR.BYTE = g_myDate;	 LED表示 			*/
>>>>>>> b8958f8e512552f344ea817f4f40ccbe5f2e767b
			egf_sw3 = 1;			/* スイッチのエッジ変化処理フラグを完了に設定 */
			}
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
<<<<<<< HEAD
	signed char	gameMode = 0;
	
	switch (gameMode) {
		case 0:
			ret = 
			break;
		case 1:
			ret = 
			break;
		case 2:
			ret = 
			break;
		default:
			ret = 
			break;
	}
=======
	
	switch (g_gameMode) {
        int ret = 0;  // 戻り値用の変数

		if ()
		{
			/* code */
		}
		
    }
>>>>>>> b8958f8e512552f344ea817f4f40ccbe5f2e767b
	
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
            // スイッチ3の状態を読み取る。
            ret = (SW3_PIN_STATUS == 0) ? 0 : 1;  // SW3が押されていれば0、押されていなければ1
            break;
        case 4:
            // スイッチ4の状態を読み取る。
            ret = (SW4_PIN_STATUS == 0) ? 0 : 1;  // SW4が押されていれば0、押されていなければ1
            break;
        default:
            break;
    }
	
	return ret;
}
