
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
    if(level <= 1)          // check level eau suffisant
        return;
    IEC0bits.RTCCIE = 0;    // desactive rtcc
    IEC0bits.T1IE = 0;      // desactive sleep mode
    while (humidity <= 25 && level > 0)
    {
        LATBbits.LATB0 = 1; //PUMP is ON
        check_moisture();   // check humidite
        get_level();
    }
    LATBbits.LATB0 = 0;     //turn off PUMP
    IEC0bits.RTCCIE = 1;    // rtcc on
    IEC0bits.T1IE = 1;      // sleep mode on
}
