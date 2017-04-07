/*
 * Reading a simple analog input from the LDR
 * at x time set by the clock/timer
 */
#include <xc.h>
#include <sys/attribs.h>
#include "LumSensor.h"
/*
 * PIC used : PIC32MX170F256B
 * GPIO USED :
 * LDR -> AN5/C1INA/C2INC/RTCC/RPB3/SCL2/RB3 [Pin 5]
 */

u16		ldr_value;

void	init()
{
	//SET INITIAL STATE FOR :
    //	ANALOG 5
    TRISBbits.TRISB3 = 1;	// SET RB3/AN5 TO INPUT
    PORTBbits.RB3 = 0;		// SET THE LINE TO 0 ?

    //	ADC
    AD1CON1bits.ON = 0;		// DISABLE ADC1 FOR CONFIGURATION
    AD1PCFGbits.PCFG5 = 0;	// /!\ SET TO ANALOG RB3
    //AD1CON1bits.ASAM = 0;	// AUTOMATIC SAMPLING
    AD1CON1bits.FORM = 0x0;	// SET DATA OUTPUT FORMAT TO INTEGER
    AD1CHSbits.CH0SB3 = 1;	// SELECT CHANEL B3
	AD1CON1bits.SSRC = 0b111;	// SELECT SAMPLE CLOCK SOURCE TO INTERNAL (AUTO)
	AD1CON2 = 0;			// ALL AD1CON2 to 0;
	AD1CSSL = 0;			// Skip Scanner
	AD1CON3bits.SAMC = 0b11111;	// SET 31 TAD for SAMPLING

    //	TIMER
    T1CONbits.ON = 0;		// DISABLE TIMER FOR CONFIGURATION
    TMR1 = 0;			// SET THE START TO 0
    T1CONbits.TCKPS = 0b11;	// SET THE PRESCALE TO 256
    PR1 = 3906;			// GET 1 SECOND INTERRUPTION
    T1CONbits.ON = 1;		// ENABLE TIMER
}

void	init_interrupt()
{
	//SET INITIAL INTERRUPT STATE FOR :
    // TIMER 1 INTERUPTION
    IFS0bits.T1IF = 0;		// SET FLAG TO 0
    IPC1bits.T1IP = 1;		// PRIORITY TO 1
    IEC0bits.T1IE = 1;		// ENABLE T1 INTERRUPT
    // ENABLE MULTI-VECTOR AND INTERRUPTION
    INTCONbits.MVEC = 1;
    __asm ("ei");
}

void	__ISR(12, IPL1AUTO)		T3_Interrupt(void)
{
	AD1CON1bits.ON = 1;
	AD1CON1CLR = 0x0002;	// CLEAR SAMP AND START THE CONVERSION PROCESS
	while (!(AD1CON1 & 0x0001)); // WHILE PROCESS IS RUNNING
	ldr_value = ADC1BUF0;
	AD1CON1bits.ON = 0;
	IFS0bits.T1IF = 0;
}

int	main()
{
    init();
    while(1)
    {
		WDTCONbits.WDTCLR = 0x01;
    }
    return (1);
}
