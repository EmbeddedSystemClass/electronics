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
#include <xc.h>
#include "header.h"


extern uint8_t     I_can_check_sensors;    //hresold checking sensors

int             alarm_count = 0;    //count alarm thresolt (cf RTCC_MASK)

void            init_rtcc(void)
{
    __asm("di");
    // /!\ Critical system
    SYSKEY = 0xaa996655;            // First key system
    SYSKEY = 0x556699aa;            // Second key system
    RTCCONSET = 0x8;                // Enable writing on wrten
    // /!\ Critical sytem end

//  Secondary oscillator
//    OSCCONbits.SOSCEN = 1;          //Enable secondary Oscillator
    while (!(OSCCONbits.SOSCRDY));  //Waiting for Sosc to run !
//  Rtcc
    uint32_t time = 0x00;          //Random time
    uint32_t date = 0x00;           //Random date

    RTCCONbits.ON = 0;              //DISABLE RTCC FOR CONFIG
    while(RTCCONbits.RTCSYNC);      //Waiting fo shutdown
    RTCTIME = time;                 //Set time
    RTCDATE = date;                 //Set date
//  Rtcc Alarm
    RTCALRM = 0;                    //DISABLE RTCALRM FOR CONFIG
    RTCALRMbits.CHIME = 1;
    RTCALRMbits.AMASK = 0b10;     //Every 10 seconds || 0b0100 for 10mn
    RTCALRMbits.ARPT = 0xff;         //Repeat twice;
    ALRMTIME = 0x800;              //10 sec mask
    ALRMDATE = 0x00;                //Random date
    RTCALRMbits.ALRMEN = 1;         //Enable Alarm
    RTCCONbits.ON = 1;              //Enable RTCC to run !
    
//  RTCC INTERRUPTION
    IFS0bits.RTCCIF = 0;            // SET FLAG TO 0
    IPC6bits.RTCCIP = 2;            // PRIORITY TO 2
    IPC6bits.RTCCIS = 1;            // SUBPRIORITY TO 1
    IEC0bits.RTCCIE = 1;            // ENABLE RTCC INTERRUPT			//Enable CPU interrupts
    __asm("ei");
}

uint64_t     inside_rtcc = 0;

void    __ISR(_RTCC_VECTOR, IPL2AUTO)           Rtcc_Interrupt(void)
{
    IFS0bits.RTCCIF = 0;            //Clear flag
    alarm_count++;
    if (alarm_count == 1)
    {
        display_write_dec(inside_rtcc, 0, 0);
        inside_rtcc++;
        I_can_check_sensors = 1;
        alarm_count = 0;
    }
//    RTCALRMbits.ARPT = 1;           //re-repeat Twice
}
