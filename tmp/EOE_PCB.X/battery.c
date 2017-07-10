
#include "header.h"

uint32_t bat_level = 0;

void init_battery(void)
{
    TRISBbits.TRISB1 = 1;       //Set b1 to 1
}

void    get_battery(void)
{
    //adc bla bla bla
    AD1CHSbits.CH0SA = 3;       //AN3   Channel
    AD1CON1bits.SAMP = 1;       //START SAMPLING
    delay_micro(100);           //WAIT FOR SAMPLING
    AD1CON1bits.SAMP = 0;       //STOP SAMPLING/START CONVERSION
    while (!(AD1CON1bits.DONE));//WAIT FOR CONVERSION DONE
    bat_level = ADC1BUF0;
}