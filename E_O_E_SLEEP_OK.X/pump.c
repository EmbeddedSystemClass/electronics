
#include "header.h"

extern short humidity;

void    init_pump()
{
    LATBbits.LATB0 = 0;     // PUMP is off
    TRISBbits.TRISB0 = 0;   // RB0 is an output
}

void    pump_on_off()
{
    if (humidity >= 25)
    {
        LATBbits.LATB0 = 1; //PUMP is ON
    }
    else
    {
        LATBbits.LATB0 = 0;     //turn off PUMP
    }
}
