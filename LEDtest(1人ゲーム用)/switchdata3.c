#include "iodefine.h"
#include <stdio.h>
#include "switchdata3.h"
#include "renda.h"
#include "CMT.h"

void sw3Chatter(void)
{
	int	d_sw3 = 1;	/* �X�C�b�`�f�[�^ */
	int	egf_sw3 = 0;	/* SW3 �G�b�W�ω������t���O */
	char	count = 0;	/* �X�C�b�`�������ꂽ�� */
	int	c_time = 0;	/* �`���^�����O���Ԍv���J�E���^ */
	int	sw_now = 1;	/* �X�C�b�`�f�[�^(�ŐV�j */
	int	sw_tmp = 1;	/* �X�C�b�`�f�[�^(�ꎞ�ۑ��j */

	initBASE();				/* �N���b�N������ 	*/	
	initSWs();				/* SW������ 		*/
	initCMT0();				/* CMT������ 		*/

	while (FOREVER) {

		while (IR(CMT0,CMI0) == 0) ;			/* CMT0:[IR28.IR]�����ݔ�����҂� (1ms)   */
		
		IR(CMT0, CMI0) = 0;				/* CMT0:[IR28.IR]�����݃t���O���N���A     */
		
		c_time++;						/* �`���^�����O���Ԍv���J�E���^ +1 */
		
		if (c_time >= C_TIME) {					/* �`���^�����O���Ԍo�߁H */
			
			c_time = 0;						/* �`���^�����O���Ԍv���J�E���^�N���A */
			
			sw_now = getSW(3);					/* �X�C�b�`�ǂݍ��� */
			if(sw_tmp == sw_now){					/* �O��Ɠ����X�C�b�`��Ԃ��H */
				d_sw3 = sw_now; 				/* �O��Ɠ����X�C�b�`��ԂȂ�m��f�[�^�Ƃ��� */
			} else {
				sw_tmp = sw_now;						
			}							/* �O��Ɠ����X�C�b�`��Ԃł͂Ȃ��Ȃ�ꎞ�ۑ� */
			if(d_sw3 == 0){						/* �X�C�b�`��������Ă��邩�H 	*/
			if(egf_sw3 == 0){					/* �X�C�b�`�̃G�b�W�ω��������������Ă��邩�H */
				count ++;					/* ���������񐔃J�E���g 	*/
				PORTE.PODR.BYTE = count;			/* LED�\�� 			*/
				egf_sw3 = 1;					/* �X�C�b�`�̃G�b�W�ω������t���O�������ɐݒ� */
			}							/* �X�C�b�`�̃G�b�W�ω������t���O���N���A */
		} else {
			egf_sw3 = 0;
		}
			
		}		
	}

}	

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

}
/*void initSWs(void)
{
	PORT0.PDR.BIT.B5 = 0; P05 ������  
	PORT0.PDR.BIT.B7 = 0; P07 ������  
	
}*/
/*=======================================================================
�֐���		: int getSW(int sw)
�@�\		: �w�肵���X�C�b�`�̏��(status) �擾
���͈�������	: �X�C�b�`�ԍ�
�o�͈�������	: None
�߂�l		: status 
���͏��	: None
�o�͏��	: None
���L����	: 
�C������	: 1.00 2020/09/25 ���C�O�Y
=======================================================================*/
int getSW(int sw)
{
	int	ret = -1;
	
	switch (sw) {
		case 3:
			ret = PORT0.PIDR.BIT.B5;
			break;
		case 4:
			ret = PORT0.PIDR.BIT.B7;
			break;
	}
	
	return ret;
}
