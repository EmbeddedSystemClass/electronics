#include "header.h"

//watchdog setting

void init_watchdog()
{
	WDTCONSET = 0x8000;		//Enable
}
