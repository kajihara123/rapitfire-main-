#include	"iodefine.h"
#include	"vect.h"

unsigned char sciBuff;	
int sendBuff = 1;

void initSCI2(void)
{
	/* === ���W���[���X�g�b�v���� ============================================ */
	SYSTEM.PRCR.WORD = 0xA502;		/* �v���e�N�g���� */
	MSTP(SCI2) = 0;				/* ���W���[���X�b�g�v���� */
	SYSTEM.PRCR.WORD = 0xA500;		/* �v���e�N�g�ݒ� */

	/* === �[�q�@�\�̑I�� ==================================================== */
	MPC.PWPR.BIT.B0WI = 0;			/* MPC�������݃v���e�N�g���W�X�^�������݋��� */
	MPC.PWPR.BIT.PFSWE = 1;			/* MPC�������݃v���e�N�g���W�X�^�������݋��� */
		
	MPC.P50PFS.BYTE = 0x0A;			/* P50:TXD2 */
	MPC.P52PFS.BYTE = 0x0A;			/* P52:RXD2 */
		
	MPC.PWPR.BIT.PFSWE = 0;			/* MPC�������݃v���e�N�g���W�X�^�������݋֎~ */
	MPC.PWPR.BIT.B0WI = 1;			/* MPC�������݃v���e�N�g���W�X�^�������݋֎~ */

	PORT5.PMR.BIT.B0 = 1;			/* P50�[�q�͎��Ӌ@�\(TXD2�[�q�@�\)�Ŏg�p */
	PORT5.PMR.BIT.B2 = 1;			/* P52�[�q�͎��Ӌ@�\(RXD2�[�q�@�\)�g�p */

	/* === ����M�t�H�[�}�b�g�̐ݒ� =========================================== */
	SCI2.SMR.BYTE = 0x00;			/* 1�X�g�b�v�r�b�g�A�p���e�B�����A8�r�b�g�A���������� */

	/* === �r�b�g���[�g�̐ݒ� ================================================= */
	SCI2.BRR = 155;					/* �{�[���[�g9600bps(PCLK / ((64 * 2^(2n-1)) * baud)) - 1 */

	/* === ���荞�ݗv���o�͋��� =============================================== */
	SCI2.SCR.BIT.RIE = 1;			/* RXI2/ERI2���荞�ݗv���o��:���� */
	SCI2.SCR.BIT.TIE = 0;			/* TXI���荞�ݗv���o��:�֎~ */
	SCI2.SCR.BIT.TEIE = 0;			/* TEI���荞�ݗv���o��:�֎~ */

	IPR(SCI2,RXI2) = 1;			/* RXI2,TXI2,TEI2���荞�ݗD�惌�x���̐ݒ� */
	/* IPR��RXI2,TXI3,TEI2�ŋ��ʂ�1�̈���g�p����̂ŁA����2�s�͕s�v */
/*	IPR(SCI2,TXI2) = 1;			   TXI2���荞�ݗD�惌�x���̐ݒ� */
/*	IPR(SCI2,TEI2) = 1;			   TEI2���荞�ݗD�惌�x���̐ݒ� */

	IEN(SCI2,RXI2) = 1;			/* RXI2���荞��:���� */
	IEN(SCI2,TXI2) = 0;			/* TXI2���荞��:���� */
	IEN(SCI2,TEI2) = 0;			/* TEI2���荞��:���� */

	SCI2.SCR.BIT.RE = 1;			/* ��M���싖�� */
}


void Excep_SCI2_RXI2(void)
{	
	sciBuff = SCI2.RDR;/* ��M�f�[�^���擾 */
	
	PORTJ.PDR.BIT.B3  	= 1;			
	PORTE.PDR.BYTE 		= 0xFF;
	
	PORTJ.PODR.BIT.B3 	= 1;
	PORTE.PODR.BYTE 	= sciBuff;

//	SCI2.SCR.BIT.TIE = 1;		/* TXI2���荞�ݗv���o��:���� */
//	SCI2.SCR.BIT.TE = 1;		/* ���M���싖�� */
}

void send(void)
{
	SCI2.SCR.BIT.TE = 1;
	SCI2.TDR = sendBuff;			/* ���M�f�[�^��ݒ� */
	sendBuff++;

	SCI2.SCR.BIT.TIE = 0;			/* TXI2���荞�ݗv���o��:�֎~ */
	
	
	SCI2.SCR.BIT.TEIE = 1;			/* TEI2���荞�ݗv���o��:���� */
	
	while((SCI2.SCR.BYTE & 0x84) != 0x04){
		;				/* �������������҂� */
	}
	
	
	//IR(SCI2,TXI2) = 0;
	
	
	SCI2.SCR.BIT.TEIE = 0;
	
	SCI2.SCR.BIT.TE = 0;			/* ���M����֎~ */

	while((SCI2.SCR.BYTE & 0x24) != 0x00){
		;				/* �������������҂� */
	}
	
}
