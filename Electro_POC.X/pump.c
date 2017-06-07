
#include "config.h"
#include <xc.h>

void    init_pump()
{
    LATBbits.LATB0 = 0;     // PUMP is off
    TRISBbits.TRISB0 = 0;   // RB0 is an output
}

void    pump_on_off()
{
    init_pump();
    
    while (humidity <= 25)
    {
        LATBbits.LATB0 = 1; //PUMP is ON
        get_moisture();     //get moisture value
        check_moisture();   //get humidity value
    }
    LATBbits.LATB0 = 0;     //turn off PUMP
}
