/*
 * Functions related to rtcc
 * WARNING : 
 *  Due to a System writing 
 *  Please init RTCC before enabling interrupts
 *  In any case, Critical system procedure should not be interrupted.
 *  Beware of the mighty unknown.
 * 
 * Requirements: External 32.768 kHz clock crystal
 */

#include <sys/attribs.h>
#include "header.h"

void        init_rtcc(void)
{
    //SET RTCC
    system_unlock();
    RTCCONbits.RTCWREN = 1;         // WRTENable
    //Enable Secondary Oscillator
    IEC0bits.RTCCIE = 0;            // Clear RTCC Interrupt
    RTCCONbits.ON = 0;              // turn off the RTCC
    RTCCONbits.CAL = 0x0;           // N0 calibration
    while(RTCCONbits.RTCCLKON);     // wait for clock to be turned off
    //Interrupt controller
    IFS0bits.RTCCIF = 0;            // clear RTCC existing event
    IPC6bits.RTCCIP = 3;            // clear the priority
    IPC6bits.RTCCIS = 1;            // Set IPL=3, subpriority 1
    IEC0bits.RTCCIE = 1;            // Enable RTCC interrupts
    //Set time and data
    RTCTIME = 0x0;                  // safe to update time to 0 hr, 0 min, 0 sec
    RTCDATE = 0x0;                  // update the date
    //Set Alarm
    RTCALRMCLR = 0xCFFF;            // clear ALRMEN, CHIME, AMASK and ARPT;
    ALRMTIME = 0x1000;              // set alarm time to 0 hr, 0 min, 10 sec
    ALRMDATE = 0x0;                 // set alarm date to Friday 27 Oct 2006
    RTCALRMbits.CHIME = 1;          // Rollover
    RTCALRMbits.AMASK = 0b01;        // Every 1sec // Valeur Test
    //Enable All
    RTCALRMbits.ALRMEN = 1;         // Enable Alrm
    RTCCONbits.ON = 1;              // turn on the RTCC
    while(!(RTCCONbits.RTCCLKON));
    system_lock();
}

void    __ISR(_RTCC_VECTOR, IPL6AUTO)           Rtcc_Interrupt(void)
{
    IFS0bits.RTCCIF = 0;            //Clear flag
    static int  alarm_count = 0;    //alarm time multiplier
    alarm_count++;
    if (alarm_count == 1)
    {
        I_can_check_sensors = 1;
        alarm_count = 0;
    }
}
