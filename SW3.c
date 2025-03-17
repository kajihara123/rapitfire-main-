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
#include    <stdio.h>
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

// typedef struct {
//     signed char is_initialized : 0;  // �������ς݃t���O
//     signed char is_running : 2;      // ���s���t���O
//     signed char is_error : 3;        // �G���[�t���O
// } g_gameMode;




void main(void)
{	
	int	d_sw3 = 1;				/* �X�C�b�`�f�[�^ */
	int	egf_sw3 = 0;				/* SW3 �G�b�W�ω������t���O */
	int	myDate = 0;			/* �ΐ풆�����̘A�ŉ񐔂�ۊ� */
	signed char g_gameMode = 0;		/* �Q�[�����[�h*/		
	int	g_myDate = 0;				/* �ΐ풆�����̘A�ŉ񐔂�ۊ� */
	char g_playerNum = 0;
	
							
	
	while (FOREVER) {
		
		d_sw3 = getSW(3);			/* �X�C�b�`�ǂݍ��� */
			
		if(d_sw3 == 0){				/* �X�C�b�`��������Ă��邩�H 	*/
		    if(egf_sw3 == 0){			/* �X�C�b�`�̃G�b�W�ω��������������Ă��邩�H */
		    	g_myDate = count++;			/* ���������񐔃J�E���g*/
			/* PORTE.PODR.BYTE = g_myDate;	 LED�\�� 			*/
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
	int ret = 0;  // �߂�l�p�̕ϐ�
	
	switch (g_gameMode) {
        int ret = 0;  // �߂�l�p�̕ϐ�

		if ()
		{
			/* code */
		}
		
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
            // �X�C�b�`3�̏�Ԃ�ǂݎ��B
            ret = (SW3_PIN_STATUS == 0) ? 0 : 1;  // SW3��������Ă����0�A������Ă��Ȃ����1
            break;
        case 4:
            // �X�C�b�`4�̏�Ԃ�ǂݎ��B
            ret = (SW4_PIN_STATUS == 0) ? 0 : 1;  // SW4��������Ă����0�A������Ă��Ȃ����1
            break;
        default:
            break;
    }
	
	return ret;
}
