#include "header.h"

//void init_battery(void)
//{
//    TRISBbits.TRISB1 = 1;       //Set b1 to 1
//}

int32_t min_bat = 580; // +-10
int32_t max_bat = 792; // pour 8.4V

void init_battery(void)
{
    TRISBbits.TRISB1 = 1; //input
}

void    get_battery(void)
{
    char    i = 0;

    AD1CHSbits.CH0SA = 3;               //AN3   Channel

    bat_level = 0;
    while (i < 10)
    {
        AD1CON1bits.SAMP = 1;           //START SAMPLING
        delay_micro(100);               //WAIT FOR SAMPLING
        AD1CON1bits.SAMP = 0;           //STOP SAMPLING/START CONVERSION
        while (AD1CON1bits.DONE != 1);  //WAIT FOR CONVERSION DONE
            bat_level += (ADC1BUF0);
        i++;
        delay_micro(100);
    }
    bat_level /= 10;
    bat_level < min_bat ? bat_level = min_bat: 0;
    bat_level > max_bat ? bat_level = max_bat: 0;
    bat_level = ((bat_level - min_bat) * 100) / (max_bat - min_bat);
}
