#include "header.h"
#include <sys/attribs.h>

extern uint16_t lum_p;

void            init_auto_adc(void)
{
        // ADC
	AD1CON1 = 0;                //[ON|FRZ|SIDL|FORM|SSRC|CLRASAM|ASAM|SAMP|DONE].
        AD1CON1bits.SSRC = 0b111;   //Internal counter ends sampling and starts conversion (auto convert)
        AD1CON1bits.ASAM = 1;       //Stop conversions when the first ADC interrupt is generated.
        AD1CON2 = 0;                //[VCFG|OFFCAL|CSCNA|BUFS|SMPI|BUFM|ALTS]
        AD1CON2bits.SMPI = 0b10;  //Interrupts every 0b10:2nd // 0b110:15th sample/conversion
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
