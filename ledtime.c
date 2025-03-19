/*=====================================================
Project		: Renda game
File		: ledTime.c
Function	: �Q�[���X�^�[�g���̍��}�Ǝ��Ԍv��
Revision	: 1.00 2025/03/17
Copyright(c):
=====================================================*/

#include "iodefine.h"
#include "renda.h"
#include "ledCtl.h"

/*=====================================================
Func Name	: initLEDs
Function	: LED�̏����ݒ���s��
Param Input	: None
Param Output: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

void initLEDs(void){

    PORTJ.PDR.BIT.B3 = 1; 
    PORTJ.PODR.BIT.B3 = 1;

    PORTD.PDR.BYTE   = 0x00;			
    
    PORTE.PDR.BYTE = 0xFF;          /*�|�[�gE���o�͂ɐݒ�*/
    PORTE.PODR.BYTE = 0x00;         /*�������: LED�͑S�ď���*/
    PORTE.PODR.BYTE = 0x0F;     /*�J�E���g�_�E���O�̏�Ԃɂ���*/

}

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
    PORTJ.PODR.BIT.B3 = 1;

    /*�Q�[���J�n�O�̃J�E���g�_�E���ig_gameMode == 1�j*/
    if (g_gameMode == 1) {                     
        if (cnt % 100 == 0) {                      /*cnt��10000��i�񂾂�LED���V�t�g*/
            PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;   /*LED��1�r�b�g�V�t�g*/
            if (PORTE.PIDR.BYTE == 0x00) {          /*�J�E���g�_�E�����I������玟�ɐi��*/
                g_gameMode = 2;                     /*�Q�[�����[�h��2�ɕύX*/
                PORTE.PODR.BYTE = 0xFF;             /*�SLED�_��*/
            }
        }
    }

    // �Q�[�����ig_gameMode == 2�j
    if (g_gameMode == 2) {
        if(ver == 0){}                                /*�P��ڂ̃��[�v�͖���*/
        if(ver > 0){                                  /*�Q��ڈȍ~2.5�b���Ƃ�1�r�b�g�V�t�g*/
            if (cnt % 250 == 0) {                 
                PORTE.PODR.BYTE = PORTE.PIDR.BYTE>>1;   /*LED��1�r�b�g�V�t�g*/
                if (PORTE.PIDR.BYTE == 0x00) {          /*LED�̃V�t�g���I�������A���ɐi��*/
                    g_gameMode = 3;                     /*�Q�[�����[�h��3�ɕύX*/
                }
            }
        }
        ver++;
    }

    cnt++;  /*�J�E���g�A�b�v*/
}

