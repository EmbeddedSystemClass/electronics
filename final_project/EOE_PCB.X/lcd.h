#ifndef LCD_H
#define LCD_H

#include "lcd_char_codes.h"

/*LCD display*/
//PORTA
#define RS_PIN	0x20    //GPA5
#define EN_PIN	0x40    //GPA6
#define BL_PIN	0x80    //GPA7

//PORTB
#define DB0_PIN	0x01
#define DB1_PIN	0x02
#define DB2_PIN	0x04
#define DB3_PIN	0x08
#define DB4_PIN	0x10
#define DB5_PIN	0x20
#define DB6_PIN	0x40
#define DB7_PIN	0x80

//Commands codes                      // RS  RW  E   D7  D6  D5  D4  D3  D2  D1  D0   Delay
#define d_clear_display         0x01  //  0   0   1   0   0   0   0   0   0   0   1   1.53ms
#define d_return_home           0x02  //  0   0   1   0   0   0   0   0   0   1   -   1.53ms
#define d_entry_mode_set        0x04  //  0   0   1   0   0   0   0   0   1  I/D SH     39us
#define d_display_control       0x08  //  0   0   1   0   0   0   0   1   D   C   B     39us
#define d_cursor_display_shift  0x10  //  0   0   1   0   0   0   1  S/C R/L  -   -     39us
#define d_function_set          0x20  //  0   0   1   0   0   1   DL  N   F   -   -     39us
#define d_set_CGRAM_addr        0x40  //  0   0   1   0   1  AC5 AC4 AC3 AC2 AC1 AC0    39us
#define d_set_DDRAM_addr        0x80  //  0   0   1   1  AC6 AC5 AC4 AC3 AC2 AC1 AC0    39us
//data codes
#define d_read_busy_flag_and_addr     //  0   1   1   BF AC6 AC5 AC4 AC3 AC2 AC1 AC0     0us
#define d_write_data                  //  1   0   1   D7  D6  D5  D4  D3  D2  D1  D0    43us
#define d_read_data                   //  1   1   1   D7  D6  D5  D4  D3  D2  D1  D0    43us

//Functions

#endif