#include "header.h"

void    init_affichage()
{
        display_write_str("H=", 0, 0); //humidity
        display_write_str("T=", 1, 0);//temperature
        display_write_str("L=", 0, 6); //light
        display_write(0x01,0 , 12);
        display_write(0x04,0 , 13);
        display_write(0x04,0 , 14);
        display_write(0x05,0 , 15);
}

void    affichage()
{
    int16_t float_temp = 0;
    //LIGHT
        display_write_str("    ", 0, 8);
        display_write_dec(lum_manual, 0, 8);
    //TEMP
        display_write_str("  ", 1, 2);
        display_write_dec(Temperature, 1, 2);
        float_temp = (int)Temperature;
        if ((Temperature - (double)float_temp) != 0)
        {
            display_write_str(",", 1, 4);
            display_write_dec(5, 1, 5);
        }
        else
            display_write_str("  ", 1, 4); //temperature
    //MOISTURE
        display_write_str("   ", 0, 2);
        display_write_dec(humidity, 0, 2);
    //BATTERY

        // pour le debug
//        display_write_str("    ", 1, 7);
//        display_write_dec(day_time, 1, 7);

        if (bat_level >= 80)
        {
            display_write(0x01,0 , 12);
            display_write(0x04,0 , 13);
            display_write(0x04,0 , 14);
            display_write(0x05,0 , 15);
        }
        else if (bat_level < 80 && bat_level >= 60)
        {
            display_write(0x01,0 , 12);
            display_write(0x04,0 , 13);
            display_write(0x03,0 , 14);
            display_write(0x05,0 , 15);
        }
        else if (bat_level < 60 && bat_level >= 40)
        {
            display_write(0x01,0 , 12);
            display_write(0x04,0 , 13);
            display_write(0x02,0 , 14);
            display_write(0x05,0 , 15);
        }
        else if (bat_level < 40 && bat_level >= 20)
        {
            display_write(0x01,0 , 12);
            display_write(0x03,0 , 13);
            display_write(0x02,0 , 14);
            display_write(0x05,0 , 15);
        }
        else if (bat_level < 20 && bat_level >= 10)
        {
            display_write(0x01,0 , 12);
            display_write(0x02,0 , 13);
            display_write(0x02,0 , 14);
            display_write(0x05,0 , 15);
        }
        else
        {
            display_write(0x00,0 , 12);
            display_write(0x02,0 , 13);
            display_write(0x02,0 , 14);
            display_write(0x05,0 , 15);
        }

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