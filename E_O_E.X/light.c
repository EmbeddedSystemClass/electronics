#include "header.h"
#include <sys/attribs.h>

extern uint16_t lum_p;

void		init_light(void)
{
	TRISAbits.TRISA0 = 1;       //RA0 Input
	display_write_str("L", 0, 5);
}

void            foo()
{
    //Do Routine
}

//check light level and fill display_buffer with the measured value.
void   		check_light(void)
{
        AD1CHSbits.CH0SA = 0;       //Select channel 0
        init_auto_adc();
        display_write_str("    ", 0, 6);
	display_write_dec(lum_p, 0, 6);
}

uint32_t	get_light_manual(void)
{
	init_manual_adc();

	AD1CHSbits.CH0SA = 0;       //Select channel 0
	AD1CON1bits.SAMP = 1;       //START SAMPLING
	delay_micro(100);           //WAIT FOR SAMPLING
	AD1CON1bits.SAMP = 0;       //STOP SAMPLING/START CONVERSION
	while (!(AD1CON1bits.DONE));//WAIT FOR CONVERSION DONE
	lum_p = ADC1BUF0;

        display_write_str("    ", 0, 6);
	display_write_dec(lum_p, 0, 6);
	
	return (lum_p);
}
