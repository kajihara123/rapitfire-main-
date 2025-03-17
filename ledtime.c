#include"iodefine.h"

void main(void)
{
    int cnt =0;                    /*カウントダウンと時間計測用変数*/
	char y = 0x07;                  /*LED用変数*/
	int weight = 0;                 /*タイマカウンタ用ウェイト*/
	PORTJ.PDR.BIT.B3 = 1; 
	PORTJ.PODR.BIT.B3 = 1;
	
	PORTE.PDR.BYTE = 0xFF;
	PORTE.PODR.BYTE = 0x00;

    	PORTE.PODR.BYTE = y;
    	for(cnt = 0; cnt < 3; cnt++){
        	for(weight = 0; weight < 31500; weight++){}
        	PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;
   	}	

    	for (cnt = 0, PORTE.PODR.BYTE = 0xFF; cnt < 8; cnt++)
    	{
        	for(weight = 0; weight < 78750; weight++){}
        	PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;
	}
}
