/*
 * Reading a simple analog input from the LDR
 * at x time set by the clock/timer
 */
#include <xc.h>
#include <sys/attribs.h>
#include "lumrtcc.h"
/*
 * PIC used : PIC32MX170F256B
 * LDR ->
 * OR
 * PIC used : PIC32MX340... [THIS]
 * LDR -> AN2/RB2
 */

int 	ldr_value = 0;

void    init()
{
        // SET INITIAL STATE FOR :
//PIN
    TRISBbits.TRISB2 = 1;           //GPIO B2 INPUT
    TRISFbits.TRISF1 = 0;           //GPIO R1 OUTPUT
    LATFbits.LATF1 = 0;             //LED OFF
//ADC
    AD1PCFGbits.PCFG2 = 0;          //RB2 ANALOG
    AD1CHSbits.CH0SA1 = 1;          //SELECTED PIN
    AD1CON1 = 0;                    //[ON|FRZ|SIDL|FORM|SSRC|CLRASAM|ASAM|SAMP|DONE]
    AD1CON2 = 0;                    //[VCFG|OFFCAL|CSCNA|BUFS|SMPI|BUFM|ALTS]
    AD1CON3 = 0x02;                 //[ADRC|SAMC|ADCS = 0b10]
    AD1CSSL = 0;                    //SKIP ANx input scan
    AD1CON1bits.ON = 1;             //Enable ADC
//TIMER
    T1CONbits.ON = 0;               //DISABLE TIMER FOR CONFIGURATION
    TMR1 = 0;                       //SET THE START TO 0
    T1CONbits.TCKPS = 0b11;         //SET THE PRESCALE TO 256
    PR1 = 390;                      //GET 1 SECOND INTERRUPTION
    T1CONbits.ON = 1;               //ENABLE TIMER
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

static void    delay(u16 t)
{
    TMR1 = 0;
    while (TMR1 != t);
}

static int     read_ldr()
{
    AD1CON1bits.SAMP = 1;           //START SAMPLING
    delay(100);                     //WAIT FOR SAMPLING
    AD1CON1bits.SAMP = 0;           //STOP SAMPLING/START CONVERSION
    while (!(AD1CON1bits.DONE));    //WAIT FOR CONVERSION DONE
    return (ADC1BUF0);
}

void	init_interrupt()
{
    	//SET INITIAL INTERRUPT STATE FOR :
//  TIMER 1 INTERUPTION
    IFS0bits.T1IF = 0;              // SET FLAG TO 0
    IPC1bits.T1IP = 1;              // PRIORITY TO 1
    IEC0bits.T1IE = 1;              // ENABLE T1 INTERRUPT
//  RTCC INTERRUPTION
    IFS1bits.RTCCIF = 0;            // SET FLAG TO 0
    IPC8bits.RTCCIP = 2;            // PRIORITY TO 2
    IPC8bits.RTCCIS = 1;            // SUBPRIORITY TO 1
    IEC1bits.RTCCIE = 1;            // ENABLE RTCC INTERRUPT
//  ENABLE MULTI-VECTOR
    INTCONbits.MVEC = 1;
//  ENABLE INTERRUPTIONS
    __asm ("ei");                   //Check this
}

void    __ISR(_RTCC_VECTOR, IPL2AUTO)           Rtcc_Interrupt(void)
{
    // /!\ Code for example ! Must change for better use
    LATFbits.LATF1 ^= 1;            //Toggle led;
    // /!\ End example
    RTCALRMbits.ARPT = 1;           //re-repeat Twice
    IFS1bits.RTCCIF = 0;            //Clear flag
}

void	__ISR(_TIMER_1_VECTOR, IPL1AUTO)	T1_Interrupt(void)
{
    int tmp = ldr_value;            //Stock ldr_value;
    ldr_value = read_ldr();         //Read and set ldr_value
    if (ldr_value - tmp > 100)      //Diff is bigger than 100 ?
        LATFbits.LATF1 ^= 1;        //Toggle Led
    IFS0bits.T1IF = 0;              //Clear flag
}

int	main()
{
    init();
    init_interrupt();
    init_rtcc();
    while(1)
    {
        WDTCONbits.WDTCLR = 0x01;
    }
    return (1);
}