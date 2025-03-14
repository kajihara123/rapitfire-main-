
/*#include	"iodefine.h"


void main(void);

void main(void)
{
	int i = 0;
	int j = 0;
	PORTJ.PODR.BIT.B3 = 1;		
	PORTJ.PDR.BIT.B3  = 1;		
	
	PORTE.PODR.BIT.B0 = 0;		
	PORTE.PDR.BIT.B0  = 1;		
	
	PORTE.PODR.BIT.B1 = 0;
	PORTE.PDR.BIT.B1 = 1;		
	PORTE.PDR.BYTE = 0xFF;
	PORTE.PODR.BYTE = 0;
		
	while (1){
		for(j = 0; j <1000; j++){}
		i++;
		if(i % 2 == 0){
			PORTE.PODR.BIT.B0 = 1;		
			PORTE.PODR.BIT.B1  = 0;
			PORTE.PODR.BIT.B2 = 0;
			PORTE.PODR.BIT.B3 = 0;
			PORTE.PODR.BIT.B4 = 0;
			PORTE.PODR.BIT.B5 = 0;
			PORTE.PODR.BIT.B6 = 0;
			PORTE.PODR.BIT.B7 = 0;
			
		}else{
			PORTE.PODR.BIT.B0 = 0;		
			PORTE.PODR.BIT.B1  = 1;
			PORTE.PODR.BIT.B2 = 0;
			PORTE.PODR.BIT.B3 = 0;
			PORTE.PODR.BIT.B4 = 0;
			PORTE.PODR.BIT.B5 = 0;
			PORTE.PODR.BIT.B6 = 0;
			PORTE.PODR.BIT.B7 = 0;
		
		}
	}			
*/