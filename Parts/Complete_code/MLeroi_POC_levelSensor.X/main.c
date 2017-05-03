//
//                              .     @$* @$3
//                             '$Nueeed$$ed$$eeec$$
//          ,            4$Lze@*$C2$b* ed(he*rb$CC$*$bc@$r              
//    /@ |~~            .e$$"W$$B$B$**  ^$  e""##d?$Bd$$$Nc. ..      @\/~\ 
//    \==|         4$kd*Cr$6F#"`  **   .*==      # '"**F#$I$b$*       |   I
//       |         d$5N@$$"   ....eu$$$$$$N$*$zbeuu     #$d$$$$b.     / @/
//      @/     . z$Ted*"$P zue$*9d$$$@##  .  #W$e@B$$L.    "#@$E$b@N
//            #d$Id*P#  'Nd$$B$**"       .*,     "#*N$$b$c   $$$*$$c
//           .d#+C6J   @@$B$*"          -***-        "#$$$$c   *$$$#$u
//        ..u$l4@"^"zJ$7W*"              '*`            ^*$@$$$r "$$E$@B>
//        *@$l$P"+Rd$$N#"          *     /|\     *        '"$$$c.. ?E$*b
//        z$ "*.  .Jz$"           ***   / | \   ***         '*@N$b   d**N
//      .z$JBR^bs@$$#          *   *   /  |  \   *  *         "$l*9N "bN$Nee
//     4$$.C*   dB@"          ***    _/  /^\  \_   ***         '$$$z> 3$b$$#
//      $"$e$  @*$"        *   *     \\^|   |^//    *   *        $$$u.^*$N$c
//     JPd$%  @@d"        ***        ***********       ***       '$Ni$  $EP$
//   :e$"*$  :et$          *         ***********        *         ^$$E  4$N$be
//   ')$ud"  @6$                                                   9$$   $*@$"
//    @F*$   *4P                       ./                          '$m#   .$$.
// u*""""""""""""h                     ##=====                    e#""""""""""#
// E +e       ue. N                 ___##_______                 4F e=c     z*c
// #e$@e.. ..z6+6d"                #*************/               ^*cBe$u.  .$$@
//    $ ^"""" 4F"  ze=eu              ********              z***hc ^"$ ""*"" $
//    $       ^F :*    3r                                  @"  e "b  $       $
//  .e$        N $  'be$L...                            ...?be@F  $F $       9F
// 4" $        $ $.  zm$*****h.                      ue""""*h6   J$" $       4%
// $  $        $ $$u5e" .     "k                    d"       #$bu$F  $       4F
// "N $        $ ^d%P  dF      $  .            .e   $     -c  "N$F  .$       4F
//  #$$        $  $4*. "N.    zP  3r ..    ..  $c   *u     $  u$K$  4F       4L
//   ^N$e.     3  F$k*. "*C$$$# .z$" '$    4L  "$c. '#$eeedF  $$$9r JF       J$
//    $'"$$eu. 4  F3"K$ .e=*CB$$$$L .e$    '$bc.u$***hd6C""  4kF$4F $F     u@$F
//    $   '"*$*@u N'L$B*"z*""     "$F" 4k 4c '7$"      "*$eu 4'L$J" $   .e$*"4F
//    $      '"hC*$ "$#.P"          $me$"  #$*$       .  ^*INJL$"$  $e$$*#   4F
//    $         $b"h ".F     $"     ^F        $       9r   #L#$FJEd#C@"      4L
//   .$         $Jb   J"..  4b      uF        *k      J%    #c^ $" d$        4L
//  :"$         $k9   $ $%4c $Bme.ze$         '*$+eee@*$"  :r$    @L$        4$
//  $ $         $$Jr  $d" '$r "*==*"            "#**"" $r  4$3r  db$F        4F
//  $c$         $'*F  $"   '$            /\            $    *(L  $$$F         k
//  #i*e.       $ 4>  $  ue $         \`.||.'/         'L c  $$ .L$d         .$
//   "b."*e.    4 4   $  $%db=eL     `.<\||/>.'      e*+$/$r  $ '$"$       .d$$
//    $^#+cC*mu 4r4   4r:6@F  $$    -----++-----    <$. "N?N  F  $ $    ud$$* $
//    $    "*eJ"@L4   4k*3Ic.*"      .'</||\>`.      #*5.J$$..F  $ $ ue#2*"   $
//    $       "N."@r  4Fd" '$r        /.'||`.\        4$ '"N*d"  9.$#Ce*"     $
//    $         "e^"  'd" uz$%           \/           '$czr"k#"  4Pu@"        $
//
//			       DOORS OF DURIN, MORIA:
//		WELCOME TO THE DARK DEPTHS OF THE PIC32MX170F256B

/*~~Proof of concept: Level sensor~~
 * PURPOSE:  General proofs of concepts.
 *
 * HARDWARE:
 *              RA0:	AN0		Lumistance
 *              RA1:	GPIO		SER		(yellow)
 *              RA2:	GPIO		RCLK		(orange)
 *              RA3:	GPIO		SRCLK		(brown)
 *              RA4:	SOSCO		RTCC		(quartz 32.768kHz)
 *
 *              RB0:			ICD3
 *              RB1:	GPIO(CN)	IRQ		(red)
 *              RB2:	GPIO(ODC)	LED_R		(red)
 *              RB3:	GPIO(ODC)	LED_G		(green)
 *              RB4:	SOSCI		RTCC		(quartz 32.768kHz)
 *              RB5:	GPIO(ODC)	LED_B		(blue)
 *              RB6:	GPIO		CE		(brown)
 *              RB7:    INT0		INTA		(purple)
 *              RB8:    SCL1		I2C		(green)
 *              RB9:    SDA1		I2C		(blue)
 *              RB10:	GPIO		One-Wire
 *              RB11:	SDI1		SPI		(blue)
 *              RB12:	AN12		CTMU		(red)
 *              RB13:	SDO1		SPI		(green)
 *              RB14:	SCK1		SPI		(orange)
 *              RB15:	SS1		SPI		(yellow)
 *
 * SOFTWARE:
 *              TIMER1:		CTMU
 *              TIMER2:
 *              TIMER3:		Alert led blink
 *              TIMER4:		delay_micro_sec
 *              TIMER5:		General purpose timer
 */

/*TODO
 * redefinir tous les delais en fonction des valeurs recommandees
 * 
 * 
 * 
 */

// PIC32MX170F256B Configuration Bit Settings

// 'C' source line config statements

// DEVCFG3
// USERID = No Setting
#pragma config PMDL1WAY = ON            // Peripheral Module Disable Configuration (Allow only one reconfiguration)
#pragma config IOL1WAY = ON             // Peripheral Pin Select Configuration (Allow only one reconfiguration)

// DEVCFG2
#pragma config FPLLIDIV = DIV_2         // PLL Input Divider (2x Divider)
#pragma config FPLLMUL = MUL_20         // PLL Multiplier (20x Multiplier)
#pragma config FPLLODIV = DIV_2         // System PLL Output Clock Divider (PLL Divide by 2)

// DEVCFG1
#pragma config FNOSC = FRCPLL           // Oscillator Selection Bits (Fast RC Osc w/Div-by-N (FRCDIV))
#pragma config FSOSCEN = OFF            // Secondary Oscillator Enable (Enabled)
#pragma config IESO = OFF                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = OFF           // CLKO Output Signal Active on the OSCO Pin (Disabled)
#pragma config FPBDIV = DIV_4           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/8)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config WINDIS = OFF             // Watchdog Timer Window Enable (Watchdog Timer is in Non-Window Mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Enabled)
#pragma config FWDTWINSZ = WINSZ_25     // Watchdog Timer Window Size (Window Size is 25%)

// DEVCFG0
#pragma config JTAGEN = OFF             // JTAG Enable (JTAG Port Enabled)
#pragma config ICESEL = ICS_PGx1        // ICE/ICD Comm Channel Select (Communicate on PGEC1/PGED1)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include "header.h"

/*Global settings*/
void init(void)
{
	__asm("di");
	/*GPIO*/
	//Set all GPIOs to DIGITAL OUTPUT LOW by default. (Safer for unused pins)
	LATA  = 0;
	TRISA = 0;
	ANSELA = 0;
	LATB  = 0;
	TRISB = 0;
	ANSELB = 0;

	/*TIMER2 (chech_sensors)*/
//	T2CONbits.TCKPS = 0x07;		//1:256 postscaler
	PR2 = 39062 / 10;		//39062 for 1sec @ PBCLK = 10MHz

#ifdef level_on_interrupt
	T2CONbits.ON = 0;		//Enable timer2
#else
	T2CONbits.ON = 1;		//Enable timer2
#endif

	/*INTERUPTS*/
	/*TIMER2*/
	IPC2bits.T2IP = 5;		//Prio = 5
	IPC2bits.T2IS = 0;		//Sub-prio = 0
	IFS0bits.T2IF = 0;		//Flag down
	IEC0bits.T2IE = 1;		//Enable on

	/*GLOBAL*/
	INTCON = 0x00001000;		//Set multi_vectors
	__asm("ei");			//Enable CPU interrupts

	/*WATCHDOG*/
	WDTCONSET = 0x8000;		//Enable
}


/*
 * Check how much level probes are under water.
 * and show it on the lcd and bargraph.
 */
uint8_t level = 0;
uint8_t prev_lvl = 0xff;
void check_level(void)
{
#ifndef level_on_interrupt
	if ((level = get_level()) == prev_lvl){return;}
	prev_lvl = level;
#else
	level = get_level();
#endif
	switch (level)
	{
		case 0:
			led_alert(RED_BIT);		//blink led
			bargraph_write(0x00000);
			lcd_frimousse_0();
			break;
		case 1:
			led_alert(GRE_BIT);
			bargraph_write(0x00005);
			lcd_frimousse_1();
			break;
		case 2:
			led_alert(BLU_BIT);
			bargraph_write(0x000ff);
			lcd_frimousse_2();
			break;
		case 3:
			led_alert(RED_BIT | GRE_BIT);
			bargraph_write(0x00aaa);
			lcd_frimousse_3();
			break;
		case 4:
			led_alert(RED_BIT | BLU_BIT);
			bargraph_write(0x0aaaa);
			lcd_frimousse_4();
			break;
		case 5:
			led_alert(GRE_BIT | BLU_BIT);
			bargraph_write(0xaaaaa);
			lcd_frimousse_5();
	}
	IFS0bits.INT0IF = 0;		//CLR flag
}

int	I_can_check_sensors = 0;
/*Add sensors checks here*/
//T2 : Timer2 9 8 IFS0<9> IEC0<9> IPC2<4:2> IPC2<1:0>
void __attribute__ ((interrupt(IPL5AUTO), vector(8)))	check_sensors(void)
{
	TMR2 = 0;
	I_can_check_sensors = 1;
	IFS0bits.T2IF = 0;
}

int bar_value = 1;

int	count = 0;
void	main(void)
{
	init();
	init_delay();
	init_led();
	init_bargraph();
	init_I2C();
	init_gpio_exp();
	init_level();
	init_lcd();
	init_display();
	init_light();
    init_moisture();
    init_temp();
	led_alert(GRE_BIT | BLU_BIT);
		
	while(1)				//Main loop
	{
		if (I_can_check_sensors)		
		{
			check_level();
			check_light();
            check_moisture();
            check_temp();
			display_update();
			I_can_check_sensors = 0;
		}
		WDTCONSET = 0x0001;	//reset watchdog
	}
}
