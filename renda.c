#include "7segLcd.h"
#include "CMT.h"
#include "initBASE.h"

void main(void)
{
	initBASE();
	
	while(g_gameMode == 0){
		waitCmt0();
		//�{�^����tSCI����		
	}
	
	while(g_gameMode == 1){
		waitCmt0();
		//�J�n�J�E���g�_�E��
	}
	
	while(g_gameMode == 2){
		
		waitCmt0();
		/*�{�^����t�A�ŋL��
		  LED�J�E���g�_�E��
		  7�Z�O�\��*/
					�@
	}
	
	
	//SCI�ʐM����
	
	while(g_gameMode == 3){
		/*�{�^����t�v���C���[�؂�ւ�
		  LED���s����
		  7�Z�O�\��*/
	}
	
	while(g_gameMode == -1){
		//�G���[7�Z�O	
	}
}

