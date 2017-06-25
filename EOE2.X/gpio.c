#include "header.h"

/*GPIO*/
//Set all GPIOs to DIGITAL OUTPUT LOW by default. (Safer for unused pins)

void init_gpio(void)
{
	LATA  = 0;             //low
	TRISA = 0;             //output
	ANSELA = 0;            //digital
	LATB  = 0;
	TRISB = 0;
	ANSELB = 0;
}
