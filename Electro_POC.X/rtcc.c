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
#include "light_sensor.h"


void            init_rtcc(void)
{
    __asm("di");
    // /!\ Critical system
    SYSKEY = 0xaa996655;            // First key system
    SYSKEY = 0x556699aa;            // Second key system
    RTCCONSET = 0x8;                // Enable writing on wrten
    // /!\ Critical sytem end

//  Secondary oscillator
    OSCCONbits.SOSCEN = 1;          //Enable secondary Oscillator
    while (!(OSCCONbits.SOSCRDY));  //Waiting for Sosc to run !
//  Rtcc
    u32 time = 0x04153300;          //Random time
    u32 date = 0x0602705;           //Random date

    RTCCONbits.ON = 0;              //DISABLE RTCC FOR CONFIG
    while(RTCCONbits.RTCSYNC);      //Waiting fo shutdown
    RTCTIME = time;                 //Set time
    RTCDATE = date;                 //Set date
//  Rtcc Alarm
    RTCALRM = 0;                    //DISABLE RTCALRM FOR CONFIG
    RTCALRMbits.AMASK = 0b10;       //Every 10 seconds
    RTCALRMbits.ARPT = 0x1;         //Repeat twice;
    ALRMTIME = 0x04154600;          //Random date
    ALRMDATE = 0x00002705;          //Random time + ~2 sec
    RTCALRMbits.ALRMEN = 1;         //Enable Alarm
    RTCCONbits.ON = 1;              //Enable RTCC to run !
    
    INTCON = 0x00001000;		//Set multi_vectors
	__asm("ei");			//Enable CPU interrupts	
}

void            init_rtcc_interrupt()
{
//  RTCC INTERRUPTION
    IFS0bits.RTCCIF = 0;            // SET FLAG TO 0
    IPC6bits.RTCCIP = 2;            // PRIORITY TO 2
    IPC6bits.RTCCIS = 1;            // SUBPRIORITY TO 1
    IEC0bits.RTCCIE = 1;            // ENABLE RTCC INTERRUPT
}

void    __ISR(_RTCC_VECTOR, IPL2AUTO)           Rtcc_Interrupt(void)
{
    // /!\ Code for example ! Must change for better use
    //LATFbits.LATF1 ^= 1;          //Toggle led;
    // /!\ End example
    RTCALRMbits.ARPT = 1;           //re-repeat Twice
    IFS0bits.RTCCIF = 0;            //Clear flag
}
