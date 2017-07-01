#include "header.h"
#include <sys/attribs.h>

extern int16_t      lum_auto;
extern uint8_t     I_can_display;
#define THRESHOLD   40

//void            init_auto_adc(void)
//{
//        AD1CHSbits.CH0SA = 0;       //Select channel 0
//        // ADC
//	AD1CON1 = 0;                //[ON|FRZ|SIDL|FORM|SSRC|CLRASAM|ASAM|SAMP|DONE].
//        AD1CON1bits.SSRC = 0b111;   //Internal counter ends sampling and starts conversion (auto convert)
//        AD1CON1bits.ASAM = 1;       //Stop conversions when the first ADC interrupt is generated.
//        AD1CON2 = 0;                //[VCFG|OFFCAL|CSCNA|BUFS|SMPI|BUFM|ALTS]
//        AD1CON2bits.SMPI = 0b1110;  //Interrupts every 0b10:2nd -> 0b1110:15th sample/conversion
//        AD1CON3 = 1;                //[ADRC|SAMC|ADCS = 0b10]
//        AD1CON3bits.ADRC = 1;       //ADC Internal ARDC Use for sleep mode
//        AD1CON3bits.SAMC = 0b11111;  //Auto-sample Time bits 30
//        AD1CON3bits.ADCS = 0b11111;  //Auto-convert Time bits 30
//        AD1CSSL = 0;                //SKIP ANx input scan
//        // ADC1 Interrupt
//        IFS0bits.AD1IF = 0;
//        IPC5bits.AD1IP = 4;
//        IEC0bits.AD1IE = 1;
//	// Activate ADC
//        AD1CON1bits.ON = 1;
//}


//uint16_t     skip = 299;
//void    	__ISR(_ADC_VECTOR, IPL4AUTO)  ADC1_Interrupt()
//{
//        IFS0bits.AD1IF = 0;                     //Clear Flags
//        AD1CON1bits.ON = 0;                     //Disable ADC
//        int16_t    lum_t;
//
//        lum_t = (int16_t)ADC1BUF0;          //Get ADC1BUF0
//        if ((lum_auto - lum_t) > 70)            //Diff for Screen Activation
//        {
//            init_manual_adc();
//            lcd_backlight_inv();
//            TMR2 = 0;
//            T2CONbits.ON = 1;
//            I_can_display = 1;
//            g_mon_sleep = 0;
//            lum_auto = lum_t;                  //Save Lum
//        }
//        skip++;
//        if(skip == 300)
//        {
//            lum_auto = lum_t;                  //Save Lum
//            skip = 0;
//        }
//        AD1CON1bits.ON = 1;                 //Enable ADC
//}
