
/*
 * Capacitive Soil Sensor
 * using CTMU
 */

#include <sys/attribs.h>
#include "Soil_sensor.h"
#include <xc.h>

void    init()
{
//SOIL SENSOR GPIO 26 RB15 CDTED6 AN 9
    TRISBbits.TRISB15 = 1;          //SET PIN at INPUT
    
//CTMU 1
    CTMUCON = 0;                    // RESET all
    CTMUCONbits.IRNG = 0b11;        // Current source trim at 55uA (I)

//ADC
    AD1CON2 = 0;                    // [VCFG|OFFCAL|CSCNA|BUFS|SMPI|BUFM|ALTS]
    AD1CON3 = 1;                    // ADCS = 4 . TPB  [ADRC|SAMC|ADCS]
    AD1CSSL = 0;                    // No Chanel scan
    AD1CHSbits.CH0SA = 9;           // Select chanel AN9
    ANSELA = 0x0000;                // No ADC pin
    ANSELB = 1<<15;                 // RB15 connected to sensor
    AD1CON1bits.ON = 1;             // Turn On ADC
    
//TIMER
    T1CONbits.ON = 1;               // Enable Timer
    TMR1 = 0;                       // Set Start to 0
    T1CONbits.TCKPS = 0;            // Set Prescale to 1
    PR1 = 1000;                     // 1mSec
    

//INTERRUPT
    //ADC
    IEC0bits.AD1IE = 0;             // Disable ADC interrupt
    
    //Enable Multi-Vector and interruptions
    INTCONbits.MVEC = 1;
    __asm("ei");
}

int main()
{
    u16 vctmu;
    u16 cap;
    
    vctmu = 0;
    init();
    while (vctmu == 0)
    {
        CTMUCONbits.ON = 1;         // Turn On CTMU
        while (TMR1 < PR1);         // wait 1ms
        AD1CON1bits.SAMP = 1;       // Begin manual sampling ADC
        CTMUCONbits.IDISSEN = 1;    // Discharge the connected circuit
        while (TMR1 < PR1);         // wait 1ms
        CTMUCONbits.IDISSEN = 0;    // Stop manual sampling
        CTMUCONbits.EDG1STAT = 1;   // Begin charging circuit
        while (TMR1 < 1);          // wait 25us
        AD1CON1bits.SAMP = 0;       // End Sampling begin conversion
        CTMUCONbits.EDG1STAT = 0;   // Stop charging circuit
        while(!AD1CON1bits.DONE);   // wait ADC is done
        AD1CON1bits.DONE = 0;       // Clear flag
        vctmu = ADC1BUF0;           // get value from ADC
    }
    CTMUCONbits.ON = 0;             // CTMU off
}