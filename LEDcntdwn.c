include"iodefine.h"

int main(void)
{
    int cnt = 3;                    /*�J�E���g�_�E���Ǝ��Ԍv���p�ϐ�*/
	char y = 0x07;                  /*LED�p�ϐ�*/
	int weight = 0;                 /*�^�C�}�J�E���^�p�E�F�C�g*/
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
