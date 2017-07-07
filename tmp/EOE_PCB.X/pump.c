
#include "header.h"

extern uint8_t level;
extern short humidity;

void    init_pump()
{
    LATBbits.LATB0 = 0;     // PUMP is off
    TRISBbits.TRISB0 = 0;   // RB0 is an output
}

void    pump_on_off()
{
    if(level <= 1)
        return;
    IEC0bits.RTCCIE = 0;
    IEC0bits.T1IE = 0;
    while (humidity <= 25)
    {
        LATBbits.LATB0 = 1; //PUMP is ON
        check_moisture();
 //       check_level();
    }
    LATBbits.LATB0 = 0;     //turn off PUMP
    IEC0bits.RTCCIE = 1;
    IEC0bits.T1IE = 1;
}
