/*
 * Capacitive Soil Sensor
 * using CTMU
 */
/*
#include <sys/attribs.h>
#include "Soil_sensor.h"
#include <xc.h>

void    init_cal()
{
//SOIL SENSOR GPIO 26 RB15 CDTED6 AN 9
    TRISBbits.TRISB15 = 1;          //SET PIN at INPUT
    
//CTMU 1
    CTMUCON = 0;                    // RESET all
    CTMUCONbits.TGEN = 1;           // (not sure) Enable direct output for AN9
    CTMUCONbits.IRNG = 0b11;        // Current source trim at 55uA (I)

//ADC
    AD1CON2 = 0;                    // [VCFG|OFFCAL|CSCNA|BUFS|SMPI|BUFM|ALTS]
    AD1CON3 = 1;                    // ADCS = 4  [ADRC|SAMC|ADCS]
    AD1CSSL = 0;                    // No Chanel scan
    //AD1CSSLbits.CSSL13 = 1; // Select CTMU input for scan
    AD1CHSbits.CH0SA = 9;           // Select chanel AN9
    ANSELA = 0x0000;                // No ADC pin
    ANSELB = 1<<15;                 // RB15 connected to sensor
    ANSELC = 0x0000;                // No ADC pin
    AD1CON1bits.ON = 1;             // Turn On ADC
    
    
//TIMER
    T1CONbits.ON = 1;               // Enable Timer
    TMR1 = 0;                       // Set Start to 0
    T1CONbits.TCKPS = 0;            // Set Prescale to 1
    PR1 = 10;                       // 10uSec

//INTERRUPT
    //TIMER1
    //ADC
    IEC0bits.AD1IE = 0;             // Disable ADC interrupt
    
    //CTMU
    //Enable Multi-Vector and interruptions
    INTCONbits.MVEC = 1;
    __asm("ei");
}
 */