
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
}

//Plant status smileys
void	lcd_frimousse_0(void)
{
	//(x_x)
	display_write(0x28, 0, 0);
	display_write(0x78, 0, 1);
	display_write(0x5f, 0, 2);
	display_write(0x78, 0, 3);
	display_write(0x29, 0, 4);
}

void	lcd_frimousse_1(void)
{
	//(o_O)
	display_write(0x28, 0, 0);
	display_write(0x6f, 0, 1);
	display_write(0x5f, 0, 2);
	display_write(0x4f, 0, 3);
	display_write(0x29, 0, 4);
}

void	lcd_frimousse_2(void)
{
	//(T_T)
	display_write(0x28, 0, 0);
	display_write(0x54, 0, 1);
	display_write(0x5f, 0, 2);
	display_write(0x54, 0, 3);
	display_write(0x29, 0, 4);
}

void	lcd_frimousse_3(void)
{
	//(-_-)
	display_write(0x28, 0, 0);
	display_write(0x2d, 0, 1);
	display_write(0x5f, 0, 2);
	display_write(0x2d, 0, 3);
	display_write(0x29, 0, 4);
}

void	lcd_frimousse_4(void)
{
	//(^_^)
	display_write(0x28, 0, 0);
	display_write(0x5e, 0, 1);
	display_write(0x5f, 0, 2);
	display_write(0x5e, 0, 3);
	display_write(0x29, 0, 4);
}

void	lcd_frimousse_5(void)
{
	//(^o^)
	display_write(0x28, 0, 0);
	display_write(0x5e, 0, 1);
	display_write(0x6f, 0, 2);
	display_write(0x5e, 0, 3);
	display_write(0x29, 0, 4);
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