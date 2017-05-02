/*
 * Capacitive Soil Sensor
 * Calibration Capacitance
 * using CTMU
 */

/* 
#include <sys/attribs.h>
#include "Soil_sensor.h"
#include <xc.h>

u16 cap;

void    init_cal_c()
{
//SOIL SENSOR GPIO 7 RB3 AN 5
    TRISBbits.TRISB3 = 1;          //SET PIN at INPUT
    
//CTMU 1
    CTMUCON = 0;                    // RESET all
    CTMUCONbits.TGEN = 1;           // (not sure) Enable direct output for AN9
    CTMUCONbits.IRNG = 0b11;        // Current source trim at 55uA (I)

//ADC
    AD1CON2 = 0;                    // [VCFG|OFFCAL|CSCNA|BUFS|SMPI|BUFM|ALTS]
    AD1CON3 = 1;                    // ADCS = 4  [ADRC|SAMC|ADCS]
    AD1CSSL = 0;                    // No Chanel scan
    AD1CHSbits.CH0SA = 5;           // Select chanel AN5
    ANSELA = 0x0000;                // No ADC pin
    ANSELB = 1<<3;                  // RB3 connected to sensor
    AD1CON1bits.ON = 1;             // Turn On ADC
    
    
//TIMER
    T1CONbits.ON = 1;               // Enable Timer
    TMR1 = 0;                       // Set Start to 0
    T1CONbits.TCKPS = 0;            // Set Prescale to 1
    PR1 = 10000;                    // 1mSec

//INTERRUPT
    //TIMER1
    //ADC
    IEC0bits.AD1IE = 0;             // Disable ADC interrupt
    
    //CTMU
    //Enable Multi-Vector and interruptions
    //INTCONbits.MVEC = 1;
    //__asm("ei");
}

int cal_c()
{
    u32 adc_av;                    // Average of adc measurements
    u16 i_av;                      // index average
    u16 n_av = 1024;               // Number of average 2^10 (why?)
    u16 log_n_av = 10;             // 
    s16 i_trim = -31;              // index itrim from -31 to 32(I)
    u16 v_meas;                    // Measured voltage
    u16 v_av;                      // Average voltage
    
    init_cal_c();
    while (i_trim < 32)
    {
        CTMUCONbits.ITRIM = i_trim & 0b111111; // set i_trim on 6bits
        CTMUCONbits.ON = 1;         // CTMU ON
        while (TMR1 < PR1);         // wait 1ms
        adc_av = 0;
        for (i_av = 0 ; i_av < n_av ; i_av++)
        {
            AD1CON1bits.SAMP = 1;       // Begin manual sampling ADC
            CTMUCONbits.IDISSEN = 1;    // Discharge the connected circuit
            while (TMR1 < PR1);         // wait 1ms
            CTMUCONbits.IDISSEN = 0;    // Stop manual sampling
            CTMUCONbits.EDG1STAT = 1;   // Begin charging circuit
            _nop(); _nop(); _nop();
            _nop(); _nop(); _nop();     // wait 0.63us at 10MHz = 6NOP
            AD1CON1bits.SAMP = 0;       // End Sampling begin conversion
            CTMUCONbits.EDG1STAT = 0;   // Stop charging circuit
            while(!AD1CON1bits.DONE);   // wait ADC is done
            AD1CON1bits.DONE = 0;       // Clear flag
            v_meas = ADC1BUF0;          // Get the value
            adc_av += v_meas;           // Add value to average
        }
        CTMUCONbits.ON = 0;             // CTMU OFF
        v_av = adc_av >> (log_n_av - 6) // 2^10 << 6 = full scale
        i_trim ++;
    }
    volt = v_av;
    itrim = i_trim;
    return (0);
}
 */
