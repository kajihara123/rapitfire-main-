#include	"iodefine.h"
#include    <stdio.h>
#include    "switchdata3.h"


void sw3Clt(void)
{
<<<<<<< HEAD
		if (PORT0.PIDR.BIT.B5 == 0){
			/*�Q�[���X�e�[�^�X��0�ɂ���*/
			if (g_gameMode == 2){
				g_myDate = g_myDate + 1;		
			/*�Q�[�����[�h��2�ɂ���*/	
			}	
			if (g_gameMode == 3){
				g_playerNum = 1;	/*�����̃v���[���[�ԍ��̑I��*/
			}		
=======
	if (PORT0.PIDR.BIT.B5 == 0){
		if (g_gameMode == 2){
			g_myData = g_myData + 1;			
		}	
		if (g_gameMode == 3){
			g_playerNum = 1;	/*�����̃v���[���[�ԍ��̑I��*/
		}		
>>>>>>> 05d3ad1080ec3a9fda1f021a420c11f5754d460f
	}
}
