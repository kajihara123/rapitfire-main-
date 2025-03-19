#include <vect.h>
#include "initBASE.h"
#include "iodefine.h"
#include "7segLcd.h"
//#include "CMT.h"
#include "renda.h"




signed char g_gameMode = 1; //�Q�[����ԃX�e�[�^�X
int g_myData = 0;		//�����̘A�Ő�
int g_pairData = -1;		//����̘A�Ő�
char g_playerNum = 1;		//���݌����Ă���v���C���[
int cnt = 0;
int ver = 0;


char g_hexNum[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};	//0~9��7�Z�O�\���p16�i��
char	g_digit[4];							//�A�Ő��̊e���i�[�z��
char g_errorHex[3] = {0x79, 0x50, 0x50};				//Err��7�Z�O�\���p16�i��

int decision = -1;

/***** prototype *****/
void initCMT0(void);
void initCMT1(void);
void waitCmt0(void);
void waitCmt1(void);

void main(void)
{
	initBASE();
	initLEDs();
	initCMT0();
	initCMT1();
	initSWs();
	//init7SEG();
	
	
	while(g_gameMode == 0){
		waitCmt0();
		//sw3Clt();
		ledTime();		//�{�^����tSCI����		
	}
	
	while(g_gameMode == 1){
		waitCmt0();
		ledTime();		//�J�n�J�E���g�_�E��
	}
	
	while(g_gameMode == 2){
		
		waitCmt0();
		sw3Clt();		//�{�^����t�A�ŋL��
		ledTime();		//LED�J�E���g�_�E��
		displayHits();		//7�Z�O�\��					�@
	}
	
//	while(g_gameMode == 3){
		
//		//waitCmt0();
//					//�{�^����t�v���C���[�؂�ւ�
//					//LED���s����
//		  			//7�Z�O�\��
//	}
	
	while(g_gameMode == -1){
		
		waitCmt0();
		displayError();		//�G���[7�Z�O	
	}
}

