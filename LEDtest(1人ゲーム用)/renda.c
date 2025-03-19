#include "iodefine.h"
#include "ledTime.h"
#include "renda.h"
#include "initBASE.h"

signed char g_gameMode = 1; //ゲーム状態ステータス
int g_myDate = 0;		//自分の連打数;
int g_pairDate = -1;		//相手の連打数
char g_playerNum = 1;		//現在向いているプレイヤー
int cnt = 0;
int ver = 0;

char g_hexNum[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};	//0~9の7セグ表示用16進数
char	g_digit[4];							//連打数の各桁格納配列
char g_errorHex[3] = {0x79, 0x50, 0x50};				//Errの7セグ表示用16進数


int main(void)
{
	initBASE();
	initLEDs();
	initCMT0();
	initCMT1();
	

	while(g_gameMode == 1){
		waitCmt0();
		ledTime();	//開始カウントダウン
	}
	
	while(g_gameMode == 2){
		
		waitCmt0();
		ledTime();	//ボタン受付連打記憶
		  		//LEDカウントダウン
		  		//7セグ表示					　
	}
}