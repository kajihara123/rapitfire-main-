#include "iodefine.h"
#include <stdio.h>
#include "switchdata3.h"
#include "renda.h"
#include "CMT.h"

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

void initSWs(void)
{
	PORT0.PDR.BIT.B5 = 0; /* P05 ������  */
	PORT0.PDR.BIT.B7 = 0; /* P07 ������  */
	
}