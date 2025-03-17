#include	<machine.h>
#include	"iodefine.h"
#include	"CMT.h"


void initCMT0(void)
{
	SYSTEM.PRCR.WORD = 0xA502;	/* �v���e�N�g����			*/
	MSTP(CMT0) = 0;			/* CMT0 ���W���[���X�g�b�v��ԉ���	*/
	SYSTEM.PRCR.WORD = 0xA500;	/* �v���e�N�g�ݒ�			*/

	CMT0.CMCR.WORD = 0x00C2;	/* CMT0 �J�E���g�N���b�N PCLK/128 CMIE����	*/
	CMT0.CMCNT = 0;			/* CMT0 CMCNT �^�C�}�J�E���^������	*/
	CMT0.CMCOR = 375 - 1; 		/* CMT0 CMCOR �ݒ� 48000000/128/1000-1	*/

	IR(CMT0, CMI0)	= 0;		/* CMT0 CMI0 ���荞�݃X�e�[�^�X�t���O�N���A*/
	IPR(CMT0, CMI0) = 1; 	/* CMT0 CMI0�����ݗD�惌�x���ݒ�	*/
	IEN(CMT0, CMI0) = 1; 	/* CMT0 CMI0�����ݗv������		*/

	CMT.CMSTR0.BIT.STR0 = 1;	/* CMT0�J�E���g����J�n			*/
}



void initCMT1(void)
{
	
	SYSTEM.PRCR.WORD = 0xA502;	/* �v���e�N�g���� */
	MSTP(CMT1) = 0;				/* CMT0 ���W���[���X�g�b�v��ԉ��� */
	SYSTEM.PRCR.WORD = 0xA500;	/* �v���e�N�g�ݒ� */

	CMT1.CMCR.WORD = 0x00C2;	/* CMT0 �J�E���g�N���b�N PCLK/128 CMIE���� */

	CMT1.CMCNT = 0;			/* CMT0 CMCNT �^�C�}�J�E���^������ */
	
	CMT1.CMCOR = 375-1; 		/* CMT0 CMCOR �ݒ� 48000000/128/1000-1 */
	
	IR(CMT1, CMI1)	= 0;		/* CMT1 CMI1 ���荞�݃X�e�[�^�X�t���O�N���A */
	IPR(CMT1, CMI1) = 1;		/* CMT1 CMI1�����ݗD�惌�x���ݒ�	*/
	IEN(CMT1, CMI1) = 1;		/* CMT1 CMI1�����ݗv������		*/

	CMT.CMSTR0.BIT.STR1 = 0;	/* CMT1�J�E���g */
}
