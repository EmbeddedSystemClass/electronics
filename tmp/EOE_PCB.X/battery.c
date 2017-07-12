#include "header.h"
#define MIN_BAT 740 //+-10
#define MAX_BAT 970//  (8.4V)

//void init_battery(void)
//{
//    TRISBbits.TRISB1 = 1;       //Set b1 to 1
//}

void init_battery(void)
{
    TRISAbits.TRISA0 = 1; //input
    AD1CON1 = 0;
    AD1CHSbits.CH0SA0 = 0;
    AD1CON1bits.ON = 1;
}

//void    get_battery(void)
//{
//    //adc bla bla bla
//    AD1CHSbits.CH0SA = 3;       //AN3   Channel
//    AD1CON1bits.SAMP = 1;       //START SAMPLING
//    delay_micro(100);           //WAIT FOR SAMPLING
//    AD1CON1bits.SAMP = 0;       //STOP SAMPLING/START CONVERSION
//    while (!(AD1CON1bits.DONE));//WAIT FOR CONVERSION DONE
//    bat_level = ((ADC1BUF0 * 100) / 1024); //mv;
//}

void    get_battery(void)
{
    char    i = 0;
    int bat_tab[10];

    bat_level = 0;
    while (i < 10)
    {
        AD1CON1bits.SAMP = 1;
        delay_micro(100);
        AD1CON1bits.SAMP = 0;
        while (AD1CON1bits.DONE != 1);
        bat_level += (ADC1BUF0);
        bat_tab[i] = ADC1BUF0;
        i++;
        delay_micro(100);
    }
    bat_level /= 10;
    bat_level = (bat_level - MIN_BAT) * 100 / (MAX_BAT - MIN_BAT);
}
