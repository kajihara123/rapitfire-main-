#include "iodefine.h"
#include <stdio.h>
#include "SW4.h"

void sw4Clt(void);



void main(void)
{
	char g_playerNum = 0;			/*���݂̃v���C���[�ԍ�*/
	PORT0.PDR.BYTE = 0;
	PORTJ.PDR.BIT.B3 = 1;			/*�|�[�g�ǂݍ���*/
	PORTJ.PODR.BIT.B3 = 1;
	
	int g_pairDate = -1;			/*�����l���G���[��Ԃɂ���*/

	while(1){
		sw4Clt();
	}
}
void sw4Clt(void){

	/*����̃f�[�^��ǂݍ���*/

    if (PORT0.PIDR.BIT.B7 == 0)
	{
		if (g_pairDate == -1)
		{
			/*�X�e�[�^�X���ُ��Ԃɂ���*/
		}
		if (g_pairDate >= 0)
		{
			/*����̃f�[�^��7SEG�ɕ\������*/
		}
	
	}
}