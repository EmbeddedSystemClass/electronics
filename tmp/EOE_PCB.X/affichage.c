#include "header.h"

/*Global variables*/
extern uint16_t    lum_manual;                 //luminosity value
extern float       Temperature;
extern uint8_t     level;
extern uint16_t    humidity;                   //current hum val

void    init_affichage()
{
        display_write_str("H=", 1, 6); //humidity
        display_write_str("T=", 0, 6);//temperature
        display_write_str("L=", 1, 0); //light
}

void    affichage()
{
    int16_t float_temp = 0;
    //LIGHT
        display_write_str("    ", 1, 2);
        display_write_dec(lum_manual, 1, 2);
    //TEMP
        display_write_str("  ", 0, 8);
        display_write_dec(Temperature, 0, 8);
        float_temp = (int)Temperature;
        if ((Temperature - (double)float_temp) != 0)
        {
            display_write_str(",", 0, 10);
            display_write_dec(5, 0, 11);
        }
        else
            display_write_str("  ", 0, 10);
    //MOISTURE
        display_write_str("   ", 1, 8);
        display_write_dec(humidity, 1, 8);
    //LEVEL
        switch (level)
	{
		case 0:
			bargraph_write(0b00000000000000000001);
//			lcd_frimousse_0();
			break;
		case 1:
                         bargraph_write(0b00100000000000000111);
//			lcd_frimousse_1();
			break;
		case 2:
                        bargraph_write(0b00110000000000001111);
//			lcd_frimousse_2();
			break;
		case 3:
                        bargraph_write(0b00111100000000001111);
//			lcd_frimousse_3();
			break;
		case 4:
                        bargraph_write(0b11111110000000000111);
//			lcd_frimousse_4();
			break;
		case 5:
                        bargraph_write(0b11111111110000000000);
//			lcd_frimousse_5();
	}
}