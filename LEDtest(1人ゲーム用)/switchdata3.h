#ifndef swicthdata3_H
#define switchdata3_H

/***** definition *****/
#define	SW3	0x20
#define	SW4	0x80
#define	SW34	(SW3 | SW4)

void sw3Clt(void);
void initSWs(void);
int getSW(int bit);
int getSWs(void);

#endif