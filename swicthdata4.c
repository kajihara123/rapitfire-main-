#include "iodefine.h"
#include <stdio.h>
#include "switchdata4.h"


void sw4Clt(void){
	
    if (PORT0.PIDR.BIT.B7 == 0)
	{
		if (g_gameMode == 3)				/*�Q�[���X�e�[�^�X���R�̎��Ɉȉ��̏������s��*/
		{
		 if (g_pairData == -1)
		 {
		 	g_gameMode = -1; 				/*�I�X�e�[�^�X���ُ��Ԃɂ���*/
		 }
			g_playerNum = 2;
		}
	}
}