#include"iodefine.h"

void ledTime(void)
{
    int cnt =0;                    	/*�J�E���g�_�E���Ǝ��Ԍv���p�ϐ�*/
	int weight = 0;                 /*�^�C�}�J�E���^�p�E�F�C�g*/
	PORTJ.PDR.BIT.B3 = 1; 
	PORTJ.PODR.BIT.B3 = 1;
	
	PORTE.PDR.BYTE = 0xFF;
	PORTE.PODR.BYTE = 0x00;

    	PORTE.PODR.BYTE = 0x07;									/*�X�^�[�g�̍��}�p��3����*/
    	for(cnt = 0; cnt < 3; cnt++){							
        	for(weight = 0; weight < 31500; weight++){}
        	PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;				/*��P�b���ƂɂP�r�b�g�V�t�g*/
   	}	

    	for (cnt = 0, PORTE.PODR.BYTE = 0xFF; cnt < 8; cnt++)	/*�S�_��*/
    	{
        	for(weight = 0; weight < 78750; weight++){}
        	PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;				/*��2.5�b���ƂɂP�r�b�g�V�t�g*/
	}






	/*

	cnt++;

	--------------------------------------
	�J�n�O�J�E���g�_�E��
	--------------------------------------
	if(g_gameMode == 1 && cnt % 31500 == 0){
		LED�V�t�g
		�Q�[����ԃX�e�[�^�X��2��
	}


	---------------------------------------
	�Q�[�����J�E���g�_�E��
	-------------------------------------
	if(cnt % 78750 == 0){
		LED�V�t�g
		LED���S����������Q�[���I���X�e�[�^�X��2��
	}

	*/
}
