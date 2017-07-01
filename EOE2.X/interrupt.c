#include "header.h"

/*Interrupt list
 RTCC:  p2 s1


 */



//Global interrupt settings
void init_interrupt(void)
{
	INTCON = 0x00001000;		//Set multi_vectors
	__asm("ei");			//Enable CPU interrupts
}
