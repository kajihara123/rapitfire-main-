/*=====================================================
Project		: �A�ŃQ�[��
File		: renda.c
Function	: ���C�����������A�O���[�o���ϐ��ɂ���ϐ��̐錾����
Revision	: 1.00 2025/03/17
Copyright(c):
=====================================================*/

#include	"iodefine.h"
#include	"ledTime.h"
#include	"renda.h"
#include	"initBASE.h"
#include	"7segLcd.h"
#include	"switchData3.h"

signed char g_gameMode 	= 0; 		/* �Q�[����ԃX�e�[�^�X */
int g_myData 		= 0;		/* �����̘A�Ő� */
int g_cnt 		= 0;		/* ledTime�Ŏg���ϐ� */
int g_ver		= 0;		/* ledTime�Ŏg���ϐ� */
int g_timeCnt 		= 0;		/* ledTime�Ŏg���ϐ� */
int g_timeCntDown 	= 0;		/* ledTime�Ŏg���ϐ� */
int g_pos 		= 0;		/* 7segLcd�Ŏg���ϐ� */
int g_hits		= 0;		/* 7segLcd�Ŏg���ϐ� */

char g_arrhexNum[10] 	= {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};	/* 0~9��7�Z�O�\���p16�i�� */
char g_arrdigit[4];									/* �A�Ő��̊e���i�[�z�� */
//char g_arrerrorHex[3]	= {0x79, 0x50, 0x50};						/* Err��7�Z�O�\���p16�i�� */

/*=====================================================
Func Name	: main
Function	: ���C����������
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: g_gameMode
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
		: 1.01 2025/03/19
=====================================================*/

int main(void)
{
	initBASE();
	initLEDs();
	initCMT0();
	initSWs();
	init7SEG();
	initIRQ();
	
	while(g_gameMode == 0) {		/* �Q�[���J�n����҂� */
		waitCmt0();
	}
	
	while(g_gameMode == 1) {
		waitCmt0();
		ledTime();			/* �J�n�J�E���g�_�E�� */
	}
	
	while(g_gameMode == 2) {
		waitCmt0();
		ledTime();			/* LED�J�E���g�_�E�� */
		displayHits();			/* 7�Z�O�\�� */
	}
	
	while(g_gameMode == 3) {
		waitCmt0();
		displayHits();			/* 7�Z�O�\�� */
	}
}