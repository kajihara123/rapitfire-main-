#include	"iodefine.h"
#include	"vect.h"

unsigned char sciBuff;	
int sendBuff = 1;

void initSCI2(void)
{
	/* === モジュールストップ解除 ============================================ */
	SYSTEM.PRCR.WORD = 0xA502;		/* プロテクト解除 */
	MSTP(SCI2) = 0;				/* モジュールスットプ解除 */
	SYSTEM.PRCR.WORD = 0xA500;		/* プロテクト設定 */

	/* === 端子機能の選択 ==================================================== */
	MPC.PWPR.BIT.B0WI = 0;			/* MPC書き込みプロテクトレジスタ書き込み許可 */
	MPC.PWPR.BIT.PFSWE = 1;			/* MPC書き込みプロテクトレジスタ書き込み許可 */
		
	MPC.P50PFS.BYTE = 0x0A;			/* P50:TXD2 */
	MPC.P52PFS.BYTE = 0x0A;			/* P52:RXD2 */
		
	MPC.PWPR.BIT.PFSWE = 0;			/* MPC書き込みプロテクトレジスタ書き込み禁止 */
	MPC.PWPR.BIT.B0WI = 1;			/* MPC書き込みプロテクトレジスタ書き込み禁止 */

	PORT5.PMR.BIT.B0 = 1;			/* P50端子は周辺機能(TXD2端子機能)で使用 */
	PORT5.PMR.BIT.B2 = 1;			/* P52端子は周辺機能(RXD2端子機能)使用 */

	/* === 送受信フォーマットの設定 =========================================== */
	SCI2.SMR.BYTE = 0x00;			/* 1ストップビット、パリティ無し、8ビット、調歩同期式 */

	/* === ビットレートの設定 ================================================= */
	SCI2.BRR = 155;					/* ボーレート9600bps(PCLK / ((64 * 2^(2n-1)) * baud)) - 1 */

	/* === 割り込み要求出力許可 =============================================== */
	SCI2.SCR.BIT.RIE = 1;			/* RXI2/ERI2割り込み要求出力:許可 */
	SCI2.SCR.BIT.TIE = 0;			/* TXI割り込み要求出力:禁止 */
	SCI2.SCR.BIT.TEIE = 0;			/* TEI割り込み要求出力:禁止 */

	IPR(SCI2,RXI2) = 1;			/* RXI2,TXI2,TEI2割り込み優先レベルの設定 */
	/* IPRはRXI2,TXI3,TEI2で共通の1領域を使用するので、次の2行は不要 */
/*	IPR(SCI2,TXI2) = 1;			   TXI2割り込み優先レベルの設定 */
/*	IPR(SCI2,TEI2) = 1;			   TEI2割り込み優先レベルの設定 */

	IEN(SCI2,RXI2) = 1;			/* RXI2割り込み:許可 */
	IEN(SCI2,TXI2) = 0;			/* TXI2割り込み:許可 */
	IEN(SCI2,TEI2) = 0;			/* TEI2割り込み:許可 */

	SCI2.SCR.BIT.RE = 1;			/* 受信動作許可 */
}


void Excep_SCI2_RXI2(void)
{	
	sciBuff = SCI2.RDR;/* 受信データを取得 */
	
	PORTJ.PDR.BIT.B3  	= 1;			
	PORTE.PDR.BYTE 		= 0xFF;
	
	PORTJ.PODR.BIT.B3 	= 1;
	PORTE.PODR.BYTE 	= sciBuff;

//	SCI2.SCR.BIT.TIE = 1;		/* TXI2割り込み要求出力:許可 */
//	SCI2.SCR.BIT.TE = 1;		/* 送信動作許可 */
}

void send(void)
{
	SCI2.SCR.BIT.TE = 1;
	SCI2.TDR = sendBuff;			/* 送信データを設定 */
	sendBuff++;

	SCI2.SCR.BIT.TIE = 0;			/* TXI2割り込み要求出力:禁止 */
	
	
	SCI2.SCR.BIT.TEIE = 1;			/* TEI2割り込み要求出力:許可 */
	
	while((SCI2.SCR.BYTE & 0x84) != 0x04){
		;				/* 書き換え完了待ち */
	}
	
	
	//IR(SCI2,TXI2) = 0;
	
	
	SCI2.SCR.BIT.TEIE = 0;
	
	SCI2.SCR.BIT.TE = 0;			/* 送信動作禁止 */

	while((SCI2.SCR.BYTE & 0x24) != 0x00){
		;				/* 書き換え完了待ち */
	}
	
}
