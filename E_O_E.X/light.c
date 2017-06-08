#include <xc.h>
#include "header.h"
#include "lcd_char_codes.h"
#include "light.h"
#include <sys/attribs.h>

#define THRESHOLD 100

uint16_t        lum_p = 0;     //Global variable to get lum at time -P-

void		init_light(void)
{
	TRISAbits.TRISA0 = 1;       //RA0 Input
        AD1CHSbits.CH0SA = 0;       //Select channel 0
	display_write_str("L", 0, 5);
}

void            init_auto_adc(void)
{
	// ADC
	AD1CON1 = 0;                //[ON|FRZ|SIDL|FORM|SSRC|CLRASAM|ASAM|SAMP|DONE].
        AD1CON1bits.SSRC = 0b111;   //Internal counter ends sampling and starts conversion (auto convert)
        AD1CON1bits.ASAM = 1;       //Stop conversions when the first ADC interrupt is generated.
        AD1CON2 = 0;                //[VCFG|OFFCAL|CSCNA|BUFS|SMPI|BUFM|ALTS]
        AD1CON2bits.SMPI = 0b1110;  //Interrupts every 15th sample/conversion
        AD1CON3 = 1;                //[ADRC|SAMC|ADCS = 0b10]
        AD1CON3bits.ADRC = 1;       //ADC Internal ARDC Use for sleep mode
        AD1CON3bits.SAMC = 0b11111;  //Auto-sample Time bits 30
        AD1CON3bits.ADCS = 0b11111;  //Auto-convert Time bits 30
        AD1CSSL = 0;                //SKIP ANx input scan
        // ADC1 Interrupt
        IFS0bits.AD1IF = 0;
        IPC5bits.AD1IP = 4;
        IEC0bits.AD1IE = 1;
	// Activate ADC	
        AD1CON1bits.ON = 1;
}

void            init_manual_adc(void)
{
	//ADC
        AD1CON1 = 0;                //[ON|FRZ|SIDL|FORM|SSRC|CLRASAM|ASAM|SAMP|DONE]
	AD1CON2 = 0;                //[VCFG|OFFCAL|CSCNA|BUFS|SMPI|BUFM|ALTS]
	AD1CON3 = 1;                //[ADRC|SAMC|ADCS = 0b10]
	AD1CSSL = 0;                //SKIP ANx input scan
	// ADC1 Interrupt
        IFS0bits.AD1IF = 0;		
        IPC5bits.AD1IP = 4;
        IEC0bits.AD1IE = 0;
	// Activate ADC	
        AD1CON1bits.ON = 1;
}

void            foo()
{
    //Do Routine
}

void    	__ISR(_ADC_VECTOR, IPL4AUTO)  ADC1_Interrupt()
{
        AD1CON1bits.ON = 0;                     //Disable ADC
        uint16_t    lum_t;                
        
        lum_t = (uint16_t)ADC1BUF0;       //Get ADC1BUF0
        if ((lum_p - lum_t) > THRESHOLD)    //Diff for Screen Activation
        {
            foo();                              //Function for Screen Active
        }
        lum_p = lum_t;               //Save Lum
        IFS0bits.AD1IF = 0;                     //Clear Flags
        AD1CON1bits.ON = 1;                     //Enable ADC
}

//check light level and fill display_buffer with the measured value.
void   		check_light(void)
{
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
	
	init_auto_adc();
	return (lum_p);
}
