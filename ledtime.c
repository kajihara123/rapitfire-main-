#include"iodefine.h"

void ledTime(void)
{
	int cnt =0;                    	/*�J�E���g�_�E���Ǝ��Ԍv���p�ϐ�*/
	int weight = 0;                 /*�^�C�}�J�E���^�p�E�F�C�g*/
	PORTJ.PDR.BIT.B3 = 1; 
	PORTJ.PODR.BIT.B3 = 1;
	
	PORTE.PDR.BYTE = 0xFF;
	PORTE.PODR.BYTE = 0x00;

    PORTE.PODR.BYTE = 0x07;	
	cnt++;

	/*--------------------------------------
	�J�n�O�J�E���g�_�E��
	--------------------------------------*/
	if(g_gameMode == 1 && cnt % 31500 == 0){
		
		PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;
		�Q�[����ԃX�e�[�^�X��2��
		cnt = 0;
	}


	/*---------------------------------------
	�Q�[�����J�E���g�_�E��
	---------------------------------------*/
	if(cnt % 78750 == 0){
		LED�V�t�g
		LED���S����������Q�[���I���X�e�[�^�X��3��
	}
}
