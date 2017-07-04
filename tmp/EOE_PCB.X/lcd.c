
#include "header.h"

/*	
 *	Usage:	lcd_write(data, rs);		
 *	Aim: 
 *	Arguments: 
 *		data(u8): data to send.(see lcd commands list in "header.h")
 *		rs(b): Register Select, select data or command mode.
 *                 
 */

//Toggle lcd back light.
uint8_t	backlight = 1;	//Backlight status holder
void	lcd_backlight_inv(void)
{	
	backlight ^= BL_PIN;
	gpio_exp_write_byte_to_reg(REG_OLATA, BL_PIN);	
}

//Send data to the lcd shield.
void	lcd_write(uint8_t data, uint8_t rs)
{
	gpio_exp_write_byte_to_reg(REG_OLATA, (0x80 * rs) | backlight);			//Set RS
	gpio_exp_write_byte_to_reg(REG_OLATB, data);					//Set DATA
	gpio_exp_write_byte_to_reg(REG_OLATA, (0b01000000 + 0x80 * rs) | backlight);	//EN pulse
	delay_micro(1);									//450ns pulse
	gpio_exp_write_byte_to_reg(REG_OLATA, (0x00) | backlight);			//SET RS
}

//Initialise the gpio expander pins as requiered by the lcd shield.
//Configure display.
void    init_lcd()
{
	delay_micro(40000);				//wait lcd power up (40ms)
	gpio_exp_write_byte_to_reg(REG_IODIRB, 0x00);	//set port B as OUTPUT	(data bus)
	gpio_exp_write_byte_to_reg(REG_IODIRA, 0x1f);	//set port A pins 5-7 as OUTPUT	(RS, EN, BL pins)
	lcd_backlight_inv();				//Set backlight ON
	lcd_function_set(1, 0, 0);			//8bits, 2lines, 5x7char
	lcd_display_control(1, 0, 0);			//Display ON, cursor OFF, cursor blink OFF
	lcd_entry_mode(1, 0);
	lcd_clear();
}

//Effacement
//Efface l'ecran et positionne le curseur à 0 (haut,gauche)
void	lcd_clear(void)
{
	lcd_write(d_clear_display, 0);
}

//**Retour Curseur**
//Positionne le curseur à 0 (haut,gauche)
void	lcd_home(void)
{
	lcd_write(d_return_home, 0);	
}

//**Mode de décalage**
//Définit la direction de déplacement du curseur et si le texte doit suivre le curseur 
//	ID : 1 = incremente adresse DD-RAM ; 0 = décremente 
//	S  : 1 = Décale l' affichage; 0 = ne décale pas 
void	lcd_entry_mode(uint8_t id, uint8_t sh)
{
	lcd_write(d_entry_mode_set + 0x02 * id + 0x01 * sh, 0);		
}

//**Afficheur On/Off, curseur et clignotement**
//D : 1 = Affichage On ; 0 = Affichage Off 
//C : 1 = Curseur en service ; 0 = Curseur Hors servic
//B : 1 = Curseur clignotant ; 0 = Curseur Fixe
void	lcd_display_control(uint8_t d, uint8_t c, uint8_t b)
{
	lcd_write(d_display_control + 0x04 * d + 0x02 * c + 0x01 * b, 0);		
}

//**Décalage Affichage et curseur**
//SC : 1 = Décale l' afficheur ; 0 = Décale le curseur 
//RL : 1 = Décalage à droite; 0 = Décalage à gauche 
void	lcd_cursor_display_shift(uint8_t sc, uint8_t rl)
{
	lcd_write(d_cursor_display_shift + 0x08 * sc + 0x04 * rl, 0);		
}

//**Initialisation**
//DL : 1 = Adressage 8 bits ; 0 = Adressage 4 Bits 
//N  : 1 = Afficheur 2 lignes ; 0 = Afficheur 1 ligne
//F  : 1 = Police de charactere 5X11 ; 0 = Police de charactere 5X8;
void	lcd_function_set(uint8_t dl, uint8_t n, uint8_t f)
{
	lcd_write(d_function_set + 0x10 * dl + 0x08 * n + 0x04 * f, 0);		
}

//**Adresse CG-RAM **
//Définit l' adresse de la CG-RAM dans le compteur d'adresse. (Custom char)
void	lcd_set_CGRAM_addr(uint8_t data)
{
	data &= 0x3f;
	lcd_write(d_set_CGRAM_addr + data, 0);		
}

//**Adresse DD-RAM **
//Définit l' adresse de la DD-RAM dans le compteur d'adresse.(position du curseur)
void	lcd_set_DDRAM_addr(uint8_t data)
{
	data &= 0x7f;
	lcd_write(d_set_DDRAM_addr + data, 0);		
}
