/*=====================================================
Project		: Renda game
File		: ledCtl.c
Function	: ���s����led����
Revision	: 1.00 2025/03/17
Copyright(c):
=====================================================*/
#include	"iodefine.h"
#include	"renda.h"
#include	"ledCtl.h"

/*=====================================================
Func Name	: ledRes
Function	: �Q�[���̏��s����ɂ����LED�̓_���ʒu�𐧌䂷��
Param Input	: None
Param Output: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

void ledRes(void)
{
	portSwitch();

	if(decision == -1) {
		decision = win_or_lose();
	}

	/*���茋�ʂɂ����LED�̓_���ꏊ���Ǘ�*/
	switch(decision) {
		case 0:
			PORTE.PODR.BYTE = 0x00;
			break;
		case 1:
			PORTE.PODR.BYTE = 0xFF;
			break;
		case 2:
			PORTE.PODR.BYTE = 0xF0;
			break;
		default:
		break;
		}
}

/*=====================================================
Func Name	: win_or_lose
Function	: �Q�[���̏��s������s��
Param Input	: None
Param Output: decision
Return Val	: 0 = ����, 1 = ����, 2 = ��������
Input Inf	: g_myDate, g_pairDate
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
=====================================================*/

int win_or_lose(void)
{
	int res;
	
	if(g_myData < g_pairData) {				//g_myData��g_pairData��菬�����ꍇ
		res = 0;							//����
	}else if(g_pairData < g_myData) {		//g_pairData��g_myData��菬�����ꍇ
		res = 1;							//����
	}else if(g_myData == g_pairData) {		//g_myData��g_pairData�̐��l�������ꍇ
		res = 2;							//��������
	}
	return res;
}

/*=====================================================
Func Name	: portSwitch
Function	: �|�[�g�̐ݒ���s��
Param Input	: None
Param Output: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		: None
Revision	: 1.00 2025/03/17
=====================================================*/

/*7SEG�g�p����LED�̏o�͂�؂��Ă���̂ōĐݒ�*/

/*
void portSwitch(void)
{
	PORTD.PDR.BYTE   = 0x00;			
	
	PORTJ.PDR.BIT.B3  	= 1;			
	PORTE.PDR.BYTE 		= 0xFF;
	
	PORTJ.PODR.BIT.B3 	= 1;
	PORTE.PODR.BYTE 	= 0x00;
}
*/