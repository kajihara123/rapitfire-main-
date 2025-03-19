#include "iodefine.h"
#include <stdio.h>
#include "switchdata3.h"
#include "renda.h"
#include "CMT.h"

void sw3Clt(void)
{
	if (PORT0.PIDR.BIT.B5 == 0){
		if (g_gameMode == 0){
			g_gameMode = 1;
		}
		if (g_gameMode == 2){
			g_myData = g_myData + 1;			
		}	
		if (g_gameMode == 3){
			g_playerNum = 1;	/*�����̃v���[���[�ԍ��̑I��*/
		}		
	}
}
/*=======================================================================
�֐���		: initSW�֐�
�@�\		: �X�C�b�`���̓|�[�g������
���͈�������	: None
�o�͈�������	: None
�߂�l		: None 
���͏��	: None
�o�͏��	: None
���L����	: 
�C������	: 1.00 2020/09/25 ���C�O�Y�@emTech21��
=======================================================================*/
void initSW(void)
{
	PORT0.PMR.BIT.B5 = 0;	/* PORT0 PMR B5 GPIO�Ƃ��Ďg�p */
	PORT0.PMR.BIT.B7 = 0;	/* PORT0 PMR B7 GPIO�Ƃ��Ďg�p */

	PORT0.PDR.BIT.B5 = 0;	/* PORT0 PDR B5 ���̓s���Ƃ��Ďg�p */
	PORT0.PDR.BIT.B7 = 0;	/* PORT0 PDR B7 ���̓s���Ƃ��Ďg�p */
}
/*void initSWs(void)
{
	PORT0.PDR.BIT.B5 = 0; P05 ������  
	PORT0.PDR.BIT.B7 = 0; P07 ������  
	
}*/

/*=======================================================================
�֐���		: getSW�֐�
�@�\		: �ʃX�C�b�`�ǂݎ��
���͈�������	: int bit SW�ɑΉ�����r�b�g�ԍ�
�o�͈�������	: None
�߂�l		: SW������ԁi0:����^1:�����j 
���͏��	: None
�o�͏��	: None
���L����	: ���_���Ȃ̂Ř_�����]���ĕԂ�
�C������	: 1.00 2020/09/25 ���C�O�Y�@emTech21��
=======================================================================*/
int getSW(int bit)
{
	int	ret = 0;

	if ( bit == 5 ) {
		ret = !PORT0.PIDR.BIT.B5;	/* SW �_�����] */
	} else if ( bit == 7 ) {
		ret = !PORT0.PIDR.BIT.B7;	/* SW �_�����] */
	}

	return ret;
}

/*=======================================================================
�֐���		: getSWs�֐�
�@�\		: �X�C�b�`�ꊇ�ǂݎ��
���͈�������	: None
�o�͈�������	: None
�߂�l		: �r�b�g�Ή� SW������ԁi0:����^1:�����j 
���͏��	: None
�o�͏��	: None
���L����	: ���_���Ȃ̂Ř_�����]���ĕԂ�
�C������	: 1.00 2020/09/25 ���C�O�Y�@emTech21��
=======================================================================*/
int getSWs(void)
{
	int ret = 0;

	ret = ~PORT0.PIDR.BYTE & 0xa0;

	return ret;
}