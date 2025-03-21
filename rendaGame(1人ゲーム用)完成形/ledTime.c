/*=====================================================
Project		: �A�ŃQ�[��
File		: ledTime.c
Function	: �Q�[���X�^�[�g���̍��}�Ǝ��Ԍv��
Revision	: 1.00 2025/03/17
Copyright(c):
=====================================================*/

#include 	"iodefine.h"
#include 	"ledTime.h"
#include 	"renda.h"

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

void initLEDs(void)
{
	PORTJ.PDR.BIT.B3 = 1;
	PORTJ.PODR.BIT.B3 = 1;
	    
	PORTE.PDR.BYTE = 0xFF;          /*�|�[�gE���o�͂ɐݒ�*/
	PORTE.PODR.BYTE = 0x00;         /*�������: LED�͑S�ď���*/
	PORTE.PODR.BYTE = 0x0F;     	/*�J�E���g�_�E���O�̏�Ԃɂ���*/
}

/*=====================================================
Func Name	: ledTime
Function	: �Q�[����ԃX�e�[�^�X�ɉ����č��}�ƌv�����s��
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: g_gameMode
		  g_timeCntDown
		  g_cnt
		  g_ver
		  g_timeCnt
		  
Output Inf	: g_gameMode = 2
		  g_gameMode = 3
		  g_timeCntDown++
		  g_timeCnt++
Note		:
Revision	: 1.00 2025/03/17
		: 1.01 2025/03/19
=====================================================*/

void ledTime(void)
{
	PORTJ.PODR.BIT.B3 = 1;
	PORTD.PODR.BYTE = 0x00;
	PORTE.PODR.BYTE = 0x00;
 
	/*�Q�[���J�n�O�̃J�E���g�_�E���ig_gameMode == 1�j*/
	if (g_gameMode == 1) {
		PORTE.PODR.BYTE = 0x0F >> g_timeCntDown; 		/*LED�J�E���g�_�E���̃r�b�g�V�t�g*/
		
        	if (g_cnt % 1000 == 0) {  				/*cnt��10000��i�񂾂�LED���V�t�g*/
           		g_timeCntDown++;
			
			if (PORTE.PIDR.BYTE == 0x01) {          	/*�J�E���g�_�E�����I������玟�ɐi��*/
				g_gameMode = 2;                    	/*�Q�[�����[�h��2�ɕύX*/
                		PORTE.PODR.BYTE = 0xFF;           	/*�SLED�_��*/
            		}
       		}
    	}

// �Q�[����(g_gameMode == 2)
	if (g_gameMode == 2) {
	
		PORTE.PODR.BYTE = 0xFF>>g_timeCnt;			/*LED��g_timeCnt���r�b�g�V�t�g*/
		
        	if(g_ver > 0){                                 		/*�Q��ڈȍ~2.5�b���Ƃ�1�r�b�g�V�t�g*/
			if (g_cnt % 1250 == 0) {  
				g_timeCnt++;
				
                		if (g_timeCnt > 7) {          		/*LED�̃V�t�g���I�������A���ɐi��*/
                    			g_gameMode = 3;                 /*�Q�[�����[�h��3�ɕύX*/
                		}
            		}
        	}
	
	g_ver++;
	waitCmt0();
	}

	g_cnt++;  							/*�J�E���g�A�b�v*/
}
