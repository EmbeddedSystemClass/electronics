/*
 *  Light_sensor attempt
 *  GPIO => VREF+/CVREF+/AN0/C3INC/RPA0/CTED1/RA0
 */

#include <xc.h>
#include <sys/attribs.h>
#include "light_sensor.h"

void        init()
{
        /* Secure gpio */
    ANSELA = 0;
    ANSELB = 0;
    LATA = 0;
    LATB = 0;
    TRISA = 0;
    TRISB = 0;
        /* End Secure */
        /* Start Init */
    // GPIO
    TRISAbits.TRISA0 = 1;       //RA0 Input
    // ADC
    AD1CON1 = 0;                //[ON|FRZ|SIDL|FORM|SSRC|CLRASAM|ASAM|SAMP|DONE]
    AD1CON2 = 0;                //[VCFG|OFFCAL|CSCNA|BUFS|SMPI|BUFM|ALTS]
    AD1CON3 = 1;                //[ADRC|SAMC|ADCS = 0b10]
    AD1CSSL = 0;                //SKIP ANx input scan
    AD1CHSbits.CH0SA = 0;       //Select channel 0
    AD1CON1bits.ON = 1;         //Enable ADC
    // TIMER
    T4CONbits.ON = 0;           //DISABLE TIMER FOR CONFIGURATION
    TMR4 = 0;                   //SET THE START TO 0
    T4CONbits.TCKPS = 0b00;     //SET THE PRESCALE TO 1
}

void	init_interrupt()
{
    __asm ("di");               //Disable Interruption
//  init_rtcc_interrupt();
//  ENABLE MULTI-VECTOR
    INTCONbits.MVEC = 1;        //Multi-Vector
//  ENABLE INTERRUPTIONS
    __asm ("ei");               //Enable Interruption
}

static void    delay_us(u16 t)
{
    T4CONbits.ON = 1;           //Enable TMR4
    TMR4 = 0;                   //Set Start
    while (TMR4 <= t);          //While...
    T4CONbits.ON = 0;           //Disable TMR4
}

static int     read_ldr()
{
    AD1CHSbits.CH0SA = 0;       //Select channel 0
    AD1CON1bits.SAMP = 1;       //START SAMPLING
    delay_us(100);              //WAIT FOR SAMPLING
    AD1CON1bits.SAMP = 0;       //STOP SAMPLING/START CONVERSION
    while (!(AD1CON1bits.DONE));//WAIT FOR CONVERSION DONE
    return (ADC1BUF0);
}

int	main()
{
    int     tmp;
    int     ldr_value = 0;
    
    init();
    init_interrupt();
    while(1)
    {
        tmp = ldr_value;                //Stock ldr_value;
        ldr_value = read_ldr();         //Read and set ldr_value
        WDTCONbits.WDTCLR = 0x1;
    }
    return (1);
}