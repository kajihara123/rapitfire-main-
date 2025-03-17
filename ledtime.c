#include "iodefine.h"

int ledTime(void)
{
    static int cnt = 0;               /* �J�E���g�_�E���Ǝ��Ԍv���p�ϐ� */
    static int value = 0;      // �J�E���g�_�E���p�̕ϐ�
    static int ledShift = 0x0F;  // LED�̏�����ԁi3��LED���_���j
    PORTJ.PDR.BIT.B3 = 1; 
    PORTJ.PODR.BIT.B3 = 1;
    
    PORTE.PDR.BYTE = 0xFF;    // �|�[�gE���o�͂ɐݒ�
    PORTE.PODR.BYTE = 0x00;   // �������: LED�͑S�ď���
    PORTE.PODR.BYTE = ledShift;

    while(1){

    // �Q�[���J�n�O�̃J�E���g�_�E���ig_gameMode == 1�j
    if (g_gameMode == 1) {
        // cnt��10000��i�񂾂�LED���V�t�g
        if (cnt % 10000 == 0) {
            // 3, 2, 1 �J�E���g�_�E��
//            PORTE.PODR.BYTE = ledShift;  // LED�̏�Ԃ�ύX
            PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;  // LED��1�r�b�g�V�t�g

            // �J�E���g�_�E�����I������玟�ɐi��
            if (PORTE.PIDR.BYTE == 0x00) {  
                g_gameMode = 2;  // �Q�[�����[�h��2�ɕύX
                PORTE.PODR.BYTE = 0xFF;  // �SLED�_��
            }
        }
    }

    // �Q�[�����ig_gameMode == 2�j
    if (g_gameMode == 2) {
        // ��2.5�b���Ƃ�LED���V�t�g
        if (cnt % 10000 == 0) {
            PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;  // LED��1�r�b�g�V�t�g

            // LED�̃V�t�g���I�������A���ɐi��
            if (PORTE.PIDR.BYTE == 0x00) {
                g_gameMode = 3;  // �Q�[�����[�h��3�ɕύX�i�I���j
            }
        }
    }

    cnt++;  // �J�E���g�A�b�v
    }
}

	/*

	cnt++;

	--------------------------------------
	�J�n�O�J�E���g�_�E��
	--------------------------------------
	if(g_gameMode == 1 && cnt % 31500 == 0){

        PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;
		cnt = 0;
	}


	---------------------------------------
	�Q�[�����J�E���g�_�E��
	-------------------------------------
	if(cnt % 78750 == 0){
		PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;
		cnt = 0;
	}

	g_gamemode = 3;
	*/

