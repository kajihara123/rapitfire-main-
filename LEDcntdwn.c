include"iodefine.h"

int main(void)
{
    int cnt = 3;                    /*カウントダウンと時間計測用変数*/
	char y = 0x07;                  /*LED用変数*/
	int weight = 0;                 /*タイマカウンタ用ウェイト*/
	PORTJ.PDR.BIT.B3 = 1; 
	PORTJ.PODR.BIT.B3 = 1;
	
	PORTE.PDR.BYTE = 0xFF;
	PORTE.PODR.BYTE = 0x00;

    PORTE.PODR.BYTE = y;
    for(i = 3; i > 0; i++){
        for(weight = 0; weight < 10000; weight++){}
        PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;

    }
}
