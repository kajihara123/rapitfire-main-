/*=====================================================
Project		: �A�ŃQ�[��
File		: switchdata3.c
Function	: sw3�̏����ݒ�⊄�荞�ݐݒ�
Revision	: 1.00 2025/03/17
Copyright(c):
=====================================================*/

#include "iodefine.h"
#include <stdio.h>
#include "switchData3.h"
#include "renda.h"
#include "CMT.h"
#include "vect.h"	/* �����݃x�N�^�[��` */

/*sw3���荞�ݏ����ݒ�*/
void initIRQ(void)
{

	MPC.PWPR.BIT.B0WI	= 0;		/* MPC�������݃v���e�N�g���W�X�^�������݋��� */
	MPC.PWPR.BIT.PFSWE	= 1;		/* MPC�������݃v���e�N�g���W�X�^�������݋��� */

	MPC.P05PFS.BIT.ISEL = 1;		/* P05 ISEL��ݒ�AIRQ13���͒[�q�Ƃ��� */
	MPC.P07PFS.BIT.ISEL = 1;		/* P07 ISEL��ݒ�AIRQ15���͒[�q�Ƃ��� */

	MPC.PWPR.BIT.PFSWE	= 0;		/* MPC�������݃v���e�N�g���W�X�^�������݋֎~ */
	MPC.PWPR.BIT.B0WI	= 1;		/* MPC�������݃v���e�N�g���W�X�^�������݋֎~ */

	ICU.IRQCR[13].BIT.IRQMD = 1;		/* IRQ13���o 1:���������� 2:�����オ�� 3:���G�b�W */

	ICU.IRQCR[15].BIT.IRQMD = 1;		/* IRQ15���o 1:���������� 2:�����オ�� 3:���G�b�W */

	IR(ICU, IRQ13)	= 0;			/* IRQ13��IR ���N���A */
	IPR(ICU, IRQ13) = 1;			/* IRQ13�����ݗD��x�ݒ� */
	IEN(ICU, IRQ13) = 1;			/* IRQ13�����ݗv������ */

	IR(ICU, IRQ15)	= 0;			/* IRQ15��IR ���N���A */
	IPR(ICU, IRQ15) = 1;			/* IRQ15�����ݗD��x�ݒ� */
	IEN(ICU, IRQ15) = 1;			/* IRQ15�����ݗv������ */

}

/*=====================================================
Func Name	: initSWs
Function	: sw3�̏����ݒ�
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.01 2025/03/19
=====================================================*/

void initSWs(void)
{
	PORT0.PDR.BIT.B5 = 0;	/* PORT0 PDR B5 ���̓s���Ƃ��Ďg�p */
//	PORT0.PDR.BIT.B7 = 0;	/* PORT0 PDR B7 ���̓s���Ƃ��Ďg�p */
	
//	PORT0.PDR.BIT.B5 = 0; /* P05 ������  */
//	PORT0.PDR.BIT.B7 = 0; /* P07 ������  */
}



/*=====================================================
Func Name	: Excep_ICU_IRQ13
Function	: sw3�̊��荞�ݏ���
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: g_gameMode
		  g_myData
		
Output Inf	: g_gameMode = 1
		  g_myData = g_myData + 1
Note		:
Revision	: 1.01 2025/03/19
=====================================================*/

void Excep_ICU_IRQ13(void)					/* �����ݏ����֐� */
{	
	if (g_gameMode == 0){
		g_gameMode = 1;
	}
	if (g_gameMode == 2){
		g_myData = g_myData + 1;			
	}
}



/*�ΐ�p�ōl���Ă������荞�݂��g��Ȃ�sw3�̐ݒ�*/

//void sw3Chatter(void)
//{
//	int	d_sw3 = 1;	/* �X�C�b�`�f�[�^ */
//	int	egf_sw3 = 0;	/* SW3 �G�b�W�ω������t���O */
//	char	count = 0;	/* �X�C�b�`�������ꂽ�� */
//	int	c_time = 0;	/* �`���^�����O���Ԍv���J�E���^ */
//	int	sw_now = 1;	/* �X�C�b�`�f�[�^(�ŐV�j */
//	int	sw_tmp = 1;	/* �X�C�b�`�f�[�^(�ꎞ�ۑ��j */

//	initBASE();				/* �N���b�N������ 	*/	
//	initSWs();				/* SW������ 		*/
//	initCMT0();				/* CMT������ 		*/

//	while (FOREVER) {

//		while (IR(CMT0,CMI0) == 0) ;			/* CMT0:[IR28.IR]�����ݔ�����҂� (1ms)   */
		
//		IR(CMT0, CMI0) = 0;				/* CMT0:[IR28.IR]�����݃t���O���N���A     */
		
//		c_time++;						/* �`���^�����O���Ԍv���J�E���^ +1 */
		
//		if (c_time >= C_TIME) {					/* �`���^�����O���Ԍo�߁H */
			
//			c_time = 0;						/* �`���^�����O���Ԍv���J�E���^�N���A */
			
//			sw_now = getSW(3);					/* �X�C�b�`�ǂݍ��� */
//			if(sw_tmp == sw_now){					/* �O��Ɠ����X�C�b�`��Ԃ��H */
//				d_sw3 = sw_now; 				/* �O��Ɠ����X�C�b�`��ԂȂ�m��f�[�^�Ƃ��� */
//			} else {
//				sw_tmp = sw_now;						
//			}							/* �O��Ɠ����X�C�b�`��Ԃł͂Ȃ��Ȃ�ꎞ�ۑ� */
//			if(d_sw3 == 0){						/* �X�C�b�`��������Ă��邩�H 	*/
//			if(egf_sw3 == 0){					/* �X�C�b�`�̃G�b�W�ω��������������Ă��邩�H */
//				count ++;					/* ���������񐔃J�E���g 	*/
//				PORTE.PODR.BYTE = count;			/* LED�\�� 			*/
//				egf_sw3 = 1;					/* �X�C�b�`�̃G�b�W�ω������t���O�������ɐݒ� */
//			}							/* �X�C�b�`�̃G�b�W�ω������t���O���N���A */
//		} else {
//			egf_sw3 = 0;
//		}
			
//		}		
//	}

//}	

/*=====================================================
Func Name	: sw3Ctl
Function	: �Q�[����ԃX�e�[�^�X�ɉ����ď���������
Param Input	: None
Param Output	: None
Return Val	: None
Input Inf	: None
Output Inf	: None
Note		:
Revision	: 1.00 2025/03/17
		: 1.01 2025/03/19
=====================================================*/

/*
void sw3Ctl(void)
{
	if (PORT0.PIDR.BIT.B5 == 0) {
		if (g_gameMode == 0) {
			g_gameMode = 1;
		}
		if (g_gameMode == 2) {
			g_myData = g_myData + 1;			
		}	
		if (g_gameMode == 3) {		�ΐ�p�̐ݒ�
			g_gameMode = 0;		�����̃v���[���[�ԍ��̑I��
		}		
	}
}
*/