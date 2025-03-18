#include "sciCtl.h"
#include "iodefine.h"
#include "sciZikken.h"

void main(void)

{	
	
	initBASE();
	initSCI2();
	
	while(1){
		if (PORT0.PIDR.BIT.B5 == 0){
			send();
		}
	}
}



void initBASE(void)
{
	int	i; 

	/* --- �N���b�N�p�[�q�ݒ� ----------------------------------------------------------------- */
	/* PORT3.PDR.BYTE &= ~0xC0; */			/* P37,P36����̓|�[�g�ɐݒ� <Default>				 */
	
	/* --- ���W�X�^���C�g�v���e�N�V�������� --------------------------------------------------------- */
	SYSTEM.PRCR.WORD = 0xA503;				/* PRC0:1 �N���b�N������H�֘A���W�X�^�ւ̏������݋���   */ 
											/* PRC1:1 ���샂�[�h�A����d�͒ጸ�@�\�A             */
											/* �\�t�g�E�F�A���Z�b�g�֘A���W�X�^�ւ̏������݋���         */

	/* --- ���U��E�F�C�g�R���g���[�� ------------------------------------------------------------- */
	SYSTEM.MOSCWTCR.BYTE = 0x0F;			/* ���C���N���b�N���U����ҋ@���Ԃ̐ݒ�i�ő�j			 */
	SYSTEM.SOSCWTCR.BYTE = 0x0F;			/* �T�u�N���b�N���U����ҋ@���Ԃ̐ݒ�i�ő�j			 */

	/* --- ���C���N���b�N����J�n --------------------------------------------------------------- */
	SYSTEM.MOSCCR.BYTE = 0x00;				/* ���C���N���b�N���U�퓮��							 */
	while(SYSTEM.MOSCCR.BYTE == 0x01);		/* ����ݒ肪���f���ꂽ��ʉ�						 */
	
	/* --- PLL�N���b�N�̐ݒ� ------------------------------------------------------------------- */
	SYSTEM.PLLCR.WORD  = 0x0F00;			/* PLL ���{�ݒ� �~16 ����1���� 					 */
											/* 12MHz �~ 16 = 192MHz							 */
	/* SYSTEM.PLLWTCR.BYTE = 0x0F; */		/* PLL�N���b�N���U����ҋ@����:4194304cycle(Default)	 */
	SYSTEM.PLLCR2.BYTE = 0x00;				/* PLL��H����J�n								 */
	for(i = 0; i < 200; i++) ;				/* PLL�N���b�N���U����҂�wait						 */
	
	/* --- �����N���b�N������̐ݒ� ------------------------------------------------------------- */
	SYSTEM.SCKCR.LONG  = 0x21C21211;		/* b31-b28 FCK[3:0] 	FCK:  1/4	48MHz		 */
											/* b27-b24 ICK[3:0] 	ICK:  1/2	96MHz		 */
											/* b23	PSTOP1			BCLK�[�q�o��: ��~		 */
											/* b22	PSTOP0 			SDCLK�[�q�o��:��~		 */
											/* b19-b16 BCK[3:0]		BCK:  1/4	48MHz		 */
											/* b15-b12 PCKA[3:0]	PCLKA:1/2	96MHz		 */
											/* b11-b8  PCKB[3:0]	PCLKB:1/4	48MHz		 */
	while( SYSTEM.SCKCR.LONG != 0x21C21211);/* �������������҂�								 */
	SYSTEM.SCKCR2.WORD = 0x0032;			/* b7-b4 UCK[3:0]		UCLK: 1/4	48MHz		 */
											/* b3-b0 IEBCK[3:0]		IEBCK:1/4	48MHz		 */
	SYSTEM.BCKCR.BYTE  = 0x01;				/* b0	BCLKDIV			BCLK: 1/2	24MHz		 */

	/* --- PLL��H�ڑ� ---------------------------------------------------------------------- */
	SYSTEM.SCKCR3.WORD = 0x0400;			/* �N���b�N�\�[�X:PLL��H��I��						 */
	while( SYSTEM.SCKCR3.WORD != 0x0400 );	/* �������������҂�								 */

	/* --- �s�v�ȃN���b�N�̒�~ ----------------------------------------------------------------- */
	SYSTEM.LOCOCR.BYTE = 0x01;				/* LOCO���U��~									 */

	/* --- ���W�X�^���C�g�v���e�N�V�����ݒ� ---------------------------------------------------------- */
	SYSTEM.PRCR.WORD = 0xA500;				/* �v���e�N�g�ݒ�									 */
	

}

