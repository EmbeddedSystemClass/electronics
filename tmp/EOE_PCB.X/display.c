#include "header.h"

#define line_nb 2
#define char_per_line 16
#define	lcd_char_nb  line_nb * char_per_line
#define second_line_ddram_addr

/*
 *	Put your chars in the buffer at the desired place with display_write().
 *	Then refresh the lcd_display with display_update().
 *	See lcd_char_codes.h for codes alias.
 */



//buffer holding characteres to write
uint8_t	display_buff[lcd_char_nb];

//Refresh display with the new display_buffer
void	display_update()
{
	lcd_home();
	int index = 0;
	while (index < char_per_line)
	{
		lcd_write(display_buff[index], 1);
		index++;
	}
        lcd_set_DDRAM_addr(40); //second line start addr
	while (index < 2 * char_per_line)
	{
		lcd_write(display_buff[index], 1);
		index++;
	}
}

//Write to the display buffer the charactere code at the desired line and position
void	display_write(int charactere, int line, int column)
{
    uint8_t index = column + 16 * line;
    if (index < lcd_char_nb)
    {
        display_buff[index] = charactere;
    }
}


//print nb(int) in decimal, from line(uchar) and pos(uchar)
//!! dont forget to erase where digits will be printed. !!
uint8_t	display_write_dec(int32_t nb, uint8_t line,uint8_t index)
{
	//Negative nb
	if(nb < 0)
	{
		display_write(0x2d, line, index++);
		nb = -nb;
	}

	//More than 1 digit left
	if (nb > 9)
	{
		index = display_write_dec(nb/10, line, index);
		display_write(nb%10 + CHAR_0, line, index);
		return(index + 1);
	}
	else	//Less than 1 digit left
	{
		display_write(nb%10 + CHAR_0, line, index);
		return(index + 1);
	}
}

//Print str(char *) on lcd starting at line(uint8_t) and pos(uint8_t)
void	display_write_str(char	*str, uint8_t line,uint8_t index)
{
	while(*str)
	{
		display_write(*str, line, index);	//put char
		index++;				//shift cursor
		str++;					//shift char addr
	}
}

void	init_display()
{
	lcd_clear();

	//CLear display buffer with spaces
	uint8_t i;
	for (i = 0; i <= lcd_char_nb; i++)
		display_buff[i] = CHAR_SPACE;
        //Custom bat_char
            //char 0/ [
        lcd_set_DDRAM_addr(0);
        lcd_set_CGRAM_addr(0x00);
        lcd_write(0b11111, 1);
                lcd_set_CGRAM_addr(0x01);
        lcd_write(0b10000, 1);
                lcd_set_CGRAM_addr(0x02);
        lcd_write(0b10000, 1);
                lcd_set_CGRAM_addr(0x03);
        lcd_write(0b10000, 1);
                lcd_set_CGRAM_addr(0x04);
        lcd_write(0b10000, 1);
                lcd_set_CGRAM_addr(0x05);
        lcd_write(0b10000, 1);
                lcd_set_CGRAM_addr(0x06);
        lcd_write(0b11111, 1);
                lcd_set_CGRAM_addr(0x07);
        lcd_write(0b00000, 1);

         //char 1/ [|
        lcd_set_DDRAM_addr(0x01);
        lcd_set_CGRAM_addr(0x08);
        lcd_write(0x1f, 1);
                lcd_set_CGRAM_addr(0x09);
        lcd_write(0x10, 1);
                lcd_set_CGRAM_addr(0x0a);
        lcd_write(0x13, 1);
                lcd_set_CGRAM_addr(0x0b);
        lcd_write(0x13, 1);
                lcd_set_CGRAM_addr(0x0c);
        lcd_write(0x13, 1);
                lcd_set_CGRAM_addr(0x0d);
        lcd_write(0x10, 1);
                lcd_set_CGRAM_addr(0x0e);
        lcd_write(0x1f, 1);
                lcd_set_CGRAM_addr(0x0f);
        lcd_write(0x00, 1);
        // char 2/ -
        //         -
        lcd_set_DDRAM_addr(0x02);
        lcd_set_CGRAM_addr(0x10);
        lcd_write(0x1f, 1);
                lcd_set_CGRAM_addr(0x11);
        lcd_write(0x00, 1);
                lcd_set_CGRAM_addr(0x12);
        lcd_write(0x00, 1);
                lcd_set_CGRAM_addr(0x13);
        lcd_write(0x00, 1);
                lcd_set_CGRAM_addr(0x14);
        lcd_write(0x00, 1);
                lcd_set_CGRAM_addr(0x15);
        lcd_write(0x00, 1);
                lcd_set_CGRAM_addr(0x16);
        lcd_write(0x1f, 1);
                lcd_set_CGRAM_addr(0x17);
        lcd_write(0x00, 1);
        // char 3/ ||
        lcd_set_DDRAM_addr(0x03);
        lcd_set_CGRAM_addr(0x18);
        lcd_write(0x1f, 1);
                lcd_set_CGRAM_addr(0x19);
        lcd_write(0x00, 1);
                lcd_set_CGRAM_addr(0x1a);
        lcd_write(0x13, 1);
                lcd_set_CGRAM_addr(0x1b);
        lcd_write(0x13, 1);
                lcd_set_CGRAM_addr(0x1c);
        lcd_write(0x13, 1);
                lcd_set_CGRAM_addr(0x1d);
        lcd_write(0x00, 1);
                lcd_set_CGRAM_addr(0x1e);
        lcd_write(0x1f, 1);
                lcd_set_CGRAM_addr(0x1f);
        lcd_write(0x00, 1);
        // char 4/ || ||
        lcd_set_DDRAM_addr(0x04);
        lcd_set_CGRAM_addr(0x20);
        lcd_write(0x1f, 1);
                lcd_set_CGRAM_addr(0x21);
        lcd_write(0x00, 1);
                lcd_set_CGRAM_addr(0x22);
        lcd_write(0x1b, 1);
                lcd_set_CGRAM_addr(0x23);
        lcd_write(0x1b, 1);
                lcd_set_CGRAM_addr(0x24);
        lcd_write(0x1b, 1);
                lcd_set_CGRAM_addr(0x25);
        lcd_write(0x00, 1);
                lcd_set_CGRAM_addr(0x26);
        lcd_write(0x1f, 1);
                lcd_set_CGRAM_addr(0x27);
        lcd_write(0x00, 1);
                // char 5/ ]-
        lcd_set_DDRAM_addr(0x05);
        lcd_set_CGRAM_addr(0x28);
        lcd_write(0x18, 1);
                lcd_set_CGRAM_addr(0x29);
        lcd_write(0x08, 1);
                lcd_set_CGRAM_addr(0x2a);
        lcd_write(0x0e, 1);
                lcd_set_CGRAM_addr(0x2b);
        lcd_write(0x0e, 1);
                lcd_set_CGRAM_addr(0x2c);
        lcd_write(0x0e, 1);
                lcd_set_CGRAM_addr(0x2d);
        lcd_write(0x08, 1);
                lcd_set_CGRAM_addr(0x2e);
        lcd_write(0x18, 1);
                lcd_set_CGRAM_addr(0x2f);
        lcd_write(0x00, 1);
}

//Plant status smileys
void	lcd_frimousse_0(void)
{
	//(x_x)
	display_write(0x28, 1, 11);
	display_write(0x78, 1, 12);
	display_write(0x5f, 1, 13);
	display_write(0x78, 1, 14);
	display_write(0x29, 1, 15);
}

void	lcd_frimousse_1(void)
{
	//(o_O)
	display_write(0x28, 1, 11);
	display_write(0x6f, 1, 12);
	display_write(0x5f, 1, 13);
	display_write(0x4f, 1, 14);
	display_write(0x29, 1, 15);
}

void	lcd_frimousse_2(void)
{
	//(T_T)
	display_write(0x28, 1, 11);
	display_write(0x54, 1, 12);
	display_write(0x5f, 1, 13);
	display_write(0x54, 1, 14);
	display_write(0x29, 1, 15);
}

void	lcd_frimousse_3(void)
{
	//(-_-)
	display_write(0x28, 1, 11);
	display_write(0x2d, 1, 12);
	display_write(0x5f, 1, 13);
	display_write(0x2d, 1, 14);
	display_write(0x29, 1, 15);
}

void	lcd_frimousse_4(void)
{
	//(^_^)
	display_write(0x28, 1, 11);
	display_write(0x5e, 1, 12);
	display_write(0x5f, 1, 13);
	display_write(0x5e, 1, 14);
	display_write(0x29, 1, 15);
}

void	lcd_frimousse_5(void)
{
	//(^o^)
	display_write(0x28, 1, 11);
	display_write(0x5e, 1, 12);
	display_write(0x6f, 1, 13);
	display_write(0x5e, 1, 14);
	display_write(0x29, 1, 15);
}

//Never call this hazardous func!
void	unicorn()
{

//	\
//	 \ji
//	 /.(((
//	(,/"(((__,--.
//	    \  ) _( /{
//	    !|| " :||
//	    !||   :||
//	    '''   '''

}