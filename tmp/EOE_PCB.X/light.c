#include "header.h"
#include <sys/attribs.h>

//dependances: adc, display delay
extern uint8_t I_can_display;
extern uint16_t lum_manual;     //luminosity value

void		init_light(void)
{
	TRISAbits.TRISA0 = 1;           //RA0 Input
	display_write_str("L", 0, 5);
}

void	get_light_manual(void)
{
        //get value
	AD1CHSbits.CH0SA = 0;       //Select channel 0
	AD1CON1bits.SAMP = 1;       //START SAMPLING
	delay_micro(100);           //WAIT FOR SAMPLING
	AD1CON1bits.SAMP = 0;       //STOP SAMPLING/START CONVERSION
	while (!(AD1CON1bits.DONE));//WAIT FOR CONVERSION DONE
	lum_manual = ADC1BUF0;

        //display value
//        if (I_can_display == 1)
//        {
            display_write_str("    ", 0, 6);
            display_write_dec(lum_manual, 0, 6);
//        }
}