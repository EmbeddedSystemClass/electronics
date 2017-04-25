/*
 * Capacitive Soil Sensor
 * using CTMU
 */
/*
#include <sys/attribs.h>
#include "Soil_sensor.h"
#include <xc.h>

#define I 55
#define T 1000
void	init()
{
//SOIL SENSOR GPIO 26 RB15 CTED6
    TRISBbits.TRISB15 = 1; // INPUT

//ADC
    //AD1PCFGbits.PCFG2 = 0; // Set as analog
    AD1CHSbits.CH0SA = 0b1111;
    //AD1CHSbits.CH0SB = 0b1111; //0b1111 Set Chanel for CTMU capacitive
    AD1CON1 = 0xA000; //ADC module is operating but stop in idle mode
    AD1CON2 = 0;	// [VCFG|OFFCAL|CSCNA|BUFS|SMPI|BUFM|ALTS]
//AD1CON1bits.SAMP = 1; //Manual sampling start
    AD1CON3 = 1;	// ADCS = 4  [ADRC|SAMC|ADCS]
    AD1CSSL = 0 ;
    //AD1CSSLbits.CSSL13 ; //select CTMU input for scan
    //AD1CON1bits.SSRC = 0b011 CTMU ends sampling and start conversion
    
//TIMER1
    T1CONbits.ON = 1; // Enable Timer
    TMR1 = 0; //Set Start to 0
    T1CONbits.TCKPS = 0b10; //Set prescale to 64
    PR1 = 15625; //1 second

// CTMU
//CTMUCON
    CTMUCON = 0; // Reset all
    CTMUCONbits.IRNG = 0b11; //Current source trim at 55uA
    CTMUCONbits.EDG1SEL = 0b0111; //Select Edge 1 = CTED6
    CTMUCONbits.EDG2SEL = 0b1100; //Select Edge 2 = PBCLK
    CTMUCONbits.EDG1POL = 1; //Polarity EDG1 +
    CTMUCONbits.EDG2POL = 1; //Polarity EDG2 +
    CTMUCONbits.TGEN = 0; //Disable pulse generation mode
    CTMUCONbits.IDISSEN = 1; //Discharge the connected circuit
    while (TMR1 <= 15)
    {}
    CTMUCONbits.IDISSEN = 0; //Clear
    CTMUCONbits.ON = 0; //Disable the module
    CTMUCONbits.EDG2STAT = 0; //Clear the edge status bits edge 2
    CTMUCONbits.EDG1STAT = 0; //Clear the edge status bits edge 1
    CTMUCONbits.EDGEN = 1; //0 : edge blocked || 1 : edge not blocked
    CTMUCONbits.ON = 1;	//Enable the module
    //EDG1STAT != EDG2STAT
//INTERRUPT
    //TIMER1
    //IFS0bits.T1IF = 0; //Set flags to 0
    //IPC1bits.T1IP = 1; //Priority to 1
    //IEC0bits.T1IE = 1; //Enable T1 Interrupt

    //ADC
    IEC0bits.AD1IE = 0; //Disable ADC interrupts
    //CTMU
    //IRQ 59, Vector 39, IFS1 <27>, IEC1 <27>, IPC9

    //Enable Multi-Vector and interruptions
    INTCONbits.MVEC = 1;
    __asm ("ei");

//PMD
    //CTMU
    //CTMUMD PMD1<8>
}

//void	__ISR(_CTMU_VECTOR, IPC9AUTO)	CTMU_Interrupt(void)
//    CTMUCONbits.EDG1STAT = 0; // Clear Edge 1
//   AD1CON1bits.SSRC = 0b011; // CTMU ends sampling and start conversion here or in init ??

int	main()
{
    u16 vctmu;
    u16 cap;

    init();
    AD1CON1bits.SAMP = 1; // begin samp adc
    CTMUCONbits.EDG1STAT = 1; // Begin Charging circuit
    while (TMR1 <= 15){} // wait delay for charging
   // AD1CON1bits.SAMP = 0; // END samp ADC
    TMR1 = 0;
    AD1CON1bits.SSRC = 0b011;
    CTMUCONbits.EDG1STAT = 0; // Stop charging
    while (TMR1 <= 15){} // wait the conversion is done
    TMR1 = 0;
 //   AD1CON1bits.DONE = 1; // Clear flag
    vctmu = ADC1BUF0; // Get value from ADC
    cap = I * T / vctmu; // calc capacitance value
    while (1)
    {
        WDTCONSET = 1;
    }
}
*/