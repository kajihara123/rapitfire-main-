/*=====================================================
Project		: Renda game
File		: ledTime.c
Function	: �Q�[���X�^�[�g���̍��}�Ǝ��Ԍv��
Revision	: 1.00 2025/03/17
Copyright(c):
=====================================================*/

#include "iodefine.h"

/*=====================================================
Func Name	: ledTime
Function	: �Q�[����ԃX�e�[�^�X�ɉ����č��}�ƌv�����s��
Param Input	: None
Param Output: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

void ledTime(void)
{
    static int cnt = 0;               /* �J�E���g�_�E���Ǝ��Ԍv���p�ϐ� */
    static int value = 0;      // �J�E���g�_�E���p�̕ϐ�
    static int ledShift = 0x0F;  // LED�̏�����ԁi3��LED���_���j
    PORTJ.PDR.BIT.B3 = 1; 
    PORTJ.PODR.BIT.B3 = 1;
    
    PORTE.PDR.BYTE = 0xFF;    // �|�[�gE���o�͂ɐݒ�
    PORTE.PODR.BYTE = 0x00;   // �������: LED�͑S�ď���
    PORTE.PODR.BYTE = ledShift;

    // �Q�[���J�n�O�̃J�E���g�_�E���ig_gameMode == 1�j
    if (g_gameMode == 1) {
        // cnt��10000��i�񂾂�LED���V�t�g
        if (cnt % 5000 == 0) {
            // 3, 2, 1 �J�E���g�_�E��
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
        if(value == 0){}
        if(value > 0){
            if (cnt % 12000 == 0) {
                PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;  // LED��1�r�b�g�V�t�g

                // LED�̃V�t�g���I�������A���ɐi��
                if (PORTE.PIDR.BYTE == 0x00) {
                    g_gameMode = 3;  // �Q�[�����[�h��3�ɕύX
                }
            }
        }
        value++;
    }

    cnt++;  // �J�E���g�A�b�v
}
