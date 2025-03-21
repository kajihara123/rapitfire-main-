/*=====================================================
Project		: 連打ゲーム
File		: switchdata3.h
Function	: switchdata3.cヘッダファイル
Revision	: 1.00 2025/03/17
Copyright(c):
=====================================================*/

#ifndef swicthdata3_H
#define switchdata3_H

/***** definition *****/
#define		C_TIME	10	

void initIRQ(void);
void sw3Clt(void);
void initSWs(void);
void initCMT0(void);
int getSWs(void);

#endif