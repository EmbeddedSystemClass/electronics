#include "header.h"
#include <sys/attribs.h>

//dependances: adc, display delay
extern uint8_t I_can_display;
extern uint16_t lum_manual;     //luminosity value

void		init_light(void)
{
	TRISAbits.TRISA0 = 1;           //RA0 Input
}

void     get_light_manual(void)
{
    //find some reset
//    IEC0bits.T1IE = 0;
	AD1CHSbits.CH0SA = 0;       //Select channel 0
	AD1CON1bits.SAMP = 1;       //START SAMPLING
	delay_micro(100);           //WAIT FOR SAMPLING
	AD1CON1bits.SAMP = 0;       //STOP SAMPLING/START CONVERSION
	while (!(AD1CON1bits.DONE));//WAIT FOR CONVERSION DONE
	lum_manual = ADC1BUF0;
//    IEC0bits.T1IE = 1;
//    TMR1 = 0;


}