/*=======================================================================
�v���W�F�N�g��	: 
�t�@�C����	: 
�@�\		: 
�@�\����	: 
		: 
�C������	: 
=======================================================================*/

/***** include *****/
#include	"iodefine.h"
#include	"initBASE.h"

/***** define *****/
#define		FOREVER	1

/***** prototype *****/
void main(void);
void Excep_ICU_IRQ13(void);
int getSW(int sw);
/*=======================================================================
�֐���		: main�֐�
�@�\		: ���C���֐�
���͈�������	: None
�o�͈�������	: None
�߂�l		: None 
���͏��	: None
�o�͏��	: None
���L����	: 
�C������	: 
=======================================================================*/

void main(void)
{	
	int	d_sw3 = 1;				/* �X�C�b�`�f�[�^ */
	int	egf_sw3 = 0;				/* SW3 �G�b�W�ω������t���O */
	int	g_myDate = 0;				/* �ΐ풆�����̘A�ŉ񐔂�ۊ� */
							
	
	while (FOREVER) {
		
		d_sw3 = getSW(3);			/* �X�C�b�`�ǂݍ��� */
			
		if(d_sw3 == 0){				/* �X�C�b�`��������Ă��邩�H 	*/
		    if(egf_sw3 == 0){			/* �X�C�b�`�̃G�b�W�ω��������������Ă��邩�H */
		    	g_myDate = count++;			/* ���������񐔃J�E���g*/
			PORTE.PODR.BYTE = g_myDate;	/* LED�\�� 			*/
			egf_sw3 = 1;			/* �X�C�b�`�̃G�b�W�ω������t���O�������ɐݒ� */
		    }				
		}else{
			egf_sw3 = 0;			/* �X�C�b�`�̃G�b�W�ω������t���O���N���A */							
								
	}
}
}

/*=======================================================================
�֐���		: void Excep_ICU_IRQ13(void)
�@�\		: �w�肵���X�C�b�`�̏��(status) �擾
���͈�������	: �X�C�b�`�ԍ�
�o�͈�������	: None
�߂�l		: status 
���͏��	: None
�o�͏��	: None
���L����	: 
�C������	: 
=======================================================================*/
void Excep_ICU_IRQ13(void)
{
	int	g_gameMode = 0;
	
	switch (g_gameMode) {
		case 0:
			ret = 
			break;
		case 1:
			ret = 
			break;
		case 2:
			ret = 
			break;
		case -1:
			ret = 
			break;
	}
	
	return ret;
}

/*=======================================================================
�֐���		: int getSW(int sw)
�@�\		: �w�肵���X�C�b�`�̏��(status) �擾
���͈�������	: �X�C�b�`�ԍ�
�o�͈�������	: None
�߂�l		: status 
���͏��	: None
�o�͏��	: None
���L����	: 
�C������	: 
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
