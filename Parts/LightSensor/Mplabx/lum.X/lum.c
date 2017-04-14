/*
 * Reading a simple analog input from the LDR
 * at x time set by the clock/timer
 */
#include <xc.h>
#include <sys/attribs.h>
#include "lum.h"
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
    TRISBbits.TRISB2 = 1;	//GPIO B2 INPUT
    TRISFbits.TRISF1 = 0;   //GPIO R1 OUTPUT
    LATFbits.LATF1 = 0;     //LED OFF
//ADC
    AD1PCFGbits.PCFG2 = 0;      //RB2 ANALOG
    AD1CHSbits.CH0SA1 = 1;	//SELECTED PIN
    AD1CON1 = 0;		//[ON|FRZ|SIDL|FORM|SSRC|CLRASAM|ASAM|SAMP|DONE]
    AD1CON2 = 0;		//[VCFG|OFFCAL|CSCNA|BUFS|SMPI|BUFM|ALTS]
    AD1CON3 = 0x02;		//[ADRC|SAMC|ADCS = 0b10]
    AD1CSSL = 0;		//SKIP ANx input scan
    AD1CON1bits.ON = 1;		//Enable ADC
//TIMER
    T1CONbits.ON = 0;           // DISABLE TIMER FOR CONFIGURATION
    TMR1 = 0;                   // SET THE START TO 0
    T1CONbits.TCKPS = 0b11; 	// SET THE PRESCALE TO 256
    PR1 = 390;                 // GET 1 SECOND INTERRUPTION
    T1CONbits.ON = 1;           // ENABLE TIMER
}

void    delay(u16 t)
{
    TMR1 = 0;
    while (TMR1 != t);
}

int     read_ldr()
{
    AD1CON1bits.SAMP = 1;	//START SAMPLING
    delay(100);        //WAIT FOR SAMPLING
    AD1CON1bits.SAMP = 0;	//STOP SAMPLING/START CONVERSION
    while (!(AD1CON1bits.DONE));//WAIT FOR CONVERSION DONE
    return (ADC1BUF0);
}

void	init_interrupt()
{
    	//SET INITIAL INTERRUPT STATE FOR :
//TIMER 1 INTERUPTION
    IFS0bits.T1IF = 0;          // SET FLAG TO 0
    IPC1bits.T1IP = 1;      	// PRIORITY TO 1
    IEC0bits.T1IE = 1;      	// ENABLE T1 INTERRUPT
//ENABLE MULTI-VECTOR
    INTCONbits.MVEC = 1;
//ENABLE INTERRUPTIONS
    __asm ("ei");
}

void	__ISR(_TIMER_1_VECTOR, IPL1AUTO)	T1_Interrupt(void)
{
    int tmp = ldr_value;
    ldr_value = read_ldr();
    if (ldr_value - tmp > 250)
    {
        LATFbits.LATF1 ^= 1;
    }
    IFS0bits.T1IF = 0;          //RESET INTERRUPTION FLAG
}

int	main()
{
    init();
    init_interrupt();
    while(1)
    {
        WDTCONbits.WDTCLR = 0x01;
    }
    return (1);
}
