#include "header.h"

#define lum_threshold   30          //Sensibility threshold
#define seeker          500//32768       //Occurency for TMR1 Interrupt

extern uint8_t      I_can_check_sensors;             //global monitor sleeping
extern uint8_t      I_can_display;                   //To display or not to display...
extern uint8_t      g_mon_sleep;                     //global monitor sleeping
extern int16_t      lum_sleep;                       //Global keeping luminosity when sleep
extern uint16_t     lum_manual;     //luminosity value
extern uint8_t      SLEEPON;

void        init_sleep()
{
    system_unlock();
    OSCCONbits.SLPEN = 1;           //Enable Sleep mode
    CFGCONbits.PMDLOCK = 0;       //Unlock PMD
    PMD1bits.AD1MD = 1;
    PMD1bits.CTMUMD = 1;
    PMD1bits.CVRMD = 1;
    PMD2bits.CMP1MD = 1;
    PMD2bits.CMP2MD = 1;
    PMD2bits.CMP3MD = 1;
    PMD3bits.IC1MD = 1;
    PMD3bits.IC2MD = 1;
    PMD3bits.IC3MD = 1;
    PMD3bits.IC4MD = 1;
    PMD3bits.IC5MD = 1;
    PMD3bits.OC1MD = 1;
    PMD3bits.OC2MD = 1;
    PMD3bits.OC3MD = 1;
    PMD3bits.OC4MD = 1;
    PMD3bits.OC5MD = 1;
    PMD4bits.T1MD = 0;
    PMD4bits.T2MD = 1;
    PMD4bits.T3MD = 1;
    PMD4bits.T4MD = 1;
    PMD4bits.T5MD = 1;
    PMD5bits.I2C1MD = 1;
    PMD5bits.I2C2MD = 1;
    PMD5bits.SPI1MD = 1;
    PMD5bits.SPI2MD = 1;
    PMD5bits.U1MD = 1;
    PMD5bits.U2MD = 1;
    PMD6bits.PMPMD = 1;
    PMD6bits.REFOMD = 1;
    RTCCONbits.ON = 0;
    PMD6bits.RTCCMD = 0;          //Enable Rtcc when sleep
    CFGCONbits.PMDLOCK = 1;       //Lock PMD
    system_lock();

	/*TIMER 2*/
	T2CONbits.TCKPS = 0x07;		//1:256 postscaler
	PR2 = 39062;		//39062 for 1sec @ PBCLK = 10MHz
	T2CONbits.ON = 1;		//disable timer2

	/*TMR2 INTERUPTS*/
	IPC2bits.T2IP = 3;		//Prio = 5
	IPC2bits.T2IS = 0;		//Sub-prio = 0
	IFS0bits.T2IF = 0;		//Flag down
	IEC0bits.T2IE = 1;		//Enable on
}

void    init_tmr1()
{
    T1CONbits.ON = 0;
    PR1 = seeker;
    TMR1 = 0;
    
    T1CONbits.TCS = 1; // External clock from TxCKI pin
    T1CONbits.TSYNC = 0;
    IFS0bits.T1IF = 0; // set flag to 0
    IPC1bits.T1IP = 4; //set priority TMR1 to 5
    IEC0bits.T1IE = 1; //enable interupt TMR1
    T1CONbits.ON = 1;
}

void    wake()
{
    SLEEPON = 0;
    IEC0bits.T1IE = 0; //enable interupt TMR1
    //TIMER
    T1CONbits.ON = 1;               // Enable Timer
    TMR1 = 0;                       // Set Start to 0
    T1CONbits.TCKPS = 0;            // Set Prescale to 1

    PR1 = 10000;                    // 1mSec
}

void __attribute__ ((interrupt(IPL3AUTO), vector(8)))	go_to_sleep(void)
{
    static uint8_t  sec;

    IFS0bits.T2IF = 0;
    if (sec == 10)                      //skip second
    {
        T2CONbits.ON = 0;
        lcd_backlight_inv();
        I_can_display = 0;
        g_mon_sleep = 1;
        sec = 0;
    }
    sec++;
    TMR2 = 0;
}

void    __attribute__ ((interrupt(IPL4AUTO), vector(4))) wake_me_up(void)
{
    int16_t     go_llum;

    IFS0bits.T1IF = 0;                  //Clear Flags
    get_light_manual();
    go_llum = lum_manual;
    display_write_dec(RTCTIMEbits.SEC01, 0, 3);
    display_update();
    if (lum_sleep - go_llum > lum_threshold)
    {
        wake();
        lcd_backlight_inv();    //Light ON
        TMR2 = 0;               //
        T2CONbits.ON = 1;       //Enable TMR2
        I_can_display = 1;      //Display ok
        g_mon_sleep = 0;        //Sleep OFF
    }
    lum_sleep = go_llum;
}

