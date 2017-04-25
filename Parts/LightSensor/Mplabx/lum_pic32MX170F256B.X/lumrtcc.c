/*
 * Reading a simple analog input from the LDR
 * at x time set by the clock/timer
 */
#include <xc.h>
#include <sys/attribs.h>
#include "lumrtcc.h"
/*
 * PIC used : PIC32MX170F256B
 * LDR pin  : VREF+/CVREF+/AN0/C3INC/RPA0/CTED1/RA0
 */

int 	ldr_value = 0;

void    init()
{
        // SET INITIAL STATE FOR :
//PIN
    TRISAbits.TRISA0 = 1;           //GPIO RA0 INPUT
//  TRISFbits.TRISF1 = 0;           //GPIO R1 OUTPUT
//  LATFbits.LATF1 = 0;             //LED OFF
//ADC
//  AD1PCFGbits.PCFG0 = 0;          //RA0 ANALOG
    AD1CHSbits.CH0SA0 = 1;          //SELECTED PIN
    AD1CON1 = 0;                    //[ON|FRZ|SIDL|FORM|SSRC|CLRASAM|ASAM|SAMP|DONE]
    AD1CON2 = 0;                    //[VCFG|OFFCAL|CSCNA|BUFS|SMPI|BUFM|ALTS]
    AD1CON3 = 0x02;                 //[ADRC|SAMC|ADCS = 0b10]
    AD1CSSL = 0;                    //SKIP ANx input scan
    AD1CON1bits.ON = 1;             //Enable ADC
//TIMER
    T4CONbits.ON = 0;               //DISABLE TIMER FOR CONFIGURATION
    TMR4 = 0;                       //SET THE START TO 0
    T4CONbits.TCKPS = 0b00;         //SET THE PRESCALE TO 1
//  T4CONbits.ON = 1;               //ENABLE TIMER
}

void            init_rtcc(void)
{
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
}

void	init_interrupt()
{
    	//SET INITIAL INTERRUPT STATE FOR :
    __asm ("di");
//  RTCC INTERRUPTION
//    IFS0bits.RTCCIF = 0;            // SET FLAG TO 0
//    IPC6bits.RTCCIP = 2;            // PRIORITY TO 2
//    IPC6bits.RTCCIS = 1;            // SUBPRIORITY TO 1
//    IEC0bits.RTCCIE = 1;            // ENABLE RTCC INTERRUPT
//  ENABLE MULTI-VECTOR
    INTCONbits.MVEC = 1;
//  ENABLE INTERRUPTIONS
    __asm ("ei");                   //Check this
}

static void    delay_us(u16 t)
{
    T4CONbits.ON = 1;
    TMR4 = 0;
    while (TMR4 <= t);
    T4CONbits.ON = 0;
}

static int     read_ldr()
{
    AD1CON1bits.SAMP = 1;           //START SAMPLING
    delay_us(100);                     //WAIT FOR SAMPLING
    AD1CON1bits.SAMP = 0;           //STOP SAMPLING/START CONVERSION
    while (!(AD1CON1bits.DONE));    //WAIT FOR CONVERSION DONE
    return (ADC1BUF0);
}

void    __ISR(_RTCC_VECTOR, IPL2AUTO)           Rtcc_Interrupt(void)
{
    // /!\ Code for example ! Must change for better use
//  LATFbits.LATF1 ^= 1;            //Toggle led;
    // /!\ End example
    RTCALRMbits.ARPT = 1;           //re-repeat Twice
    IFS0bits.RTCCIF = 0;            //Clear flag
}

int	main()
{
    int     tmp;
    
    init();
//  init_rtcc();
    init_interrupt();
    while(1)
    {
        tmp = ldr_value;                //Stock ldr_value;
        ldr_value = read_ldr();         //Read and set ldr_value
        if (ldr_value - tmp > 100)      //Diff is bigger than 100 ?
        {
//          LATFbits.LATF1 ^= 1;        //Toggle Led action
        }
        WDTCONbits.WDTCLR = 0x01;
    }
    return (1);
}