#include"iodefine.h"

void main(void)
{
    int cnt =0;                    /*�J�E���g�_�E���Ǝ��Ԍv���p�ϐ�*/
	char y = 0x07;                  /*LED�p�ϐ�*/
	int weight = 0;                 /*�^�C�}�J�E���^�p�E�F�C�g*/
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
