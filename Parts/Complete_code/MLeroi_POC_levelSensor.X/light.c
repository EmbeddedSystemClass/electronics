#include <xc.h>
#include "header.h"
#include "lcd_char_codes.h"

void		init_light(void)
{
    TRISAbits.TRISA0 = 1;       //RA0 Input
    //ANSELAbits.ANSA0 = 1;
// ADC
    AD1CON1 = 0;                //[ON|FRZ|SIDL|FORM|SSRC|CLRASAM|ASAM|SAMP|DONE]
    AD1CON2 = 0;                //[VCFG|OFFCAL|CSCNA|BUFS|SMPI|BUFM|ALTS]
    AD1CON3 = 1;                //[ADRC|SAMC|ADCS = 0b10]
    AD1CSSL = 0;                //SKIP ANx input scan
  //  AD1CHSbits.CH0SA = 0;       //Select channel 0
    AD1CON1bits.ON = 1;         //Enable ADC

	display_write_str("L", 0, 5);
}

//check light level and fill display_buffer with the measured value.
void	check_light()
{
	uint32_t	light_level = get_light();
    
    display_write_str("    ", 0, 6);
	display_write_dec(light_level, 0, 6);
}

uint32_t	get_light(void)
{
    AD1CHSbits.CH0SA = 0;       //Select channel 0
    AD1CON1bits.SAMP = 1;       //START SAMPLING
    delay_micro(100);           //WAIT FOR SAMPLING
    AD1CON1bits.SAMP = 0;       //STOP SAMPLING/START CONVERSION
    while (!(AD1CON1bits.DONE));//WAIT FOR CONVERSION DONE
    return (ADC1BUF0);
}

