#ifndef HEADER_H
#define	HEADER_H

//#define level_on_interrupt      //Enable gpio_ext interrupt to get level, else get level with timer

/*GENERAL*/
//#define FALSE 0
//#define TRUE  !FALSE

#include <xc.h>

enum {OFF, ON};

typedef enum{false, true} boolean;

typedef char                int8_t;
typedef short               int16_t;
typedef int                 int32_t;
typedef long long           int64_t;

typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned long long  uint64_t;

void init(void);

#include    "bargraph.h"
#include    "gpio_exp.h"
#include    "I2C_soft.h"
#include    "lcd.h"
#include    "led.h"
#include    "level.h"
#include    "display.h"
#include    "light.h"
#include    "radio.h"
#include    "adc.h"
#include    "rtcc.h"
#include    "sleep.h"
#include    "system.h"
#include "gpio_exp_soft.h"


/*Moisture sensor*/
#define max_ctmu 950
#define min_ctmu 0

//_______ADC_AUTO_C_____________
//void        init_auto_adc(void); // + interrupt;
//_______ADC_MANOUAL_C__________
void        init_manoual_adc();
//_______BARGRAPH_C_____________
void        init_bargraph(void);
static void bargraph_srclk_pulse(void);
static void bargraph_rclk_pulse(void);
void        bargraph_write(uint32_t value);
//_______DELAY_MICRO_C__________
void        init_delay(); //+interrupt;
void        delay_micro(uint32_t time_ms);
//_______DISPLAY_C______________
static void	display_write(int charactere, int line, int index);
uint8_t     display_write_dec(int32_t nb, uint8_t line,uint8_t index);
void        display_write_str(char	*str, uint8_t line,uint8_t index);
void        display_update();
void        init_display();
//_______GPIO_C_________________
void        init_gpio();
//_______GPIO_EXP_C_____________
void        gpio_exp_write_byte_to_reg(uint8_t register_addr, uint8_t data);
uint8_t     gpio_exp_read_byte_from_reg(uint8_t reg_addr);
void        init_gpio_exp(void);
//_______GPIO_EXP_SOFT_C________
void        gpio_exp_write_byte_to_reg_soft(uint8_t register_addr, uint8_t data);
uint8_t     gpio_exp_read_byte_from_reg_soft(uint8_t reg_addr);
void        init_gpio_exp_soft();
//_______I2C_C__________________
void        init_I2C(void);
uint8_t     gpio_exp_write_byte(uint8_t data_byte);
uint8_t     gpio_exp_read_byte(void);
void        gpio_exp_is_iddle(void);
void        gpio_exp_start();
void        gpio_exp_restart();
void        gpio_exp_stop();
void        gpio_exp_ack_master(uint8_t ack_data_bit);
uint8_t     gpio_exp_ack_slave(void);
//_______I2C_SOFT_C_____________
void        init_I2C_soft(void);
void        scl_pulse_high();
void        scl_pulse_low();
void        sda_pulse_hight();
void        sda_pulse_low();
void        gpio_exp_start_soft(void);
void        gpio_exp_stop_soft(void);
uint8_t     gpio_exp_write_byte_soft(uint8_t data_byte);
uint8_t     gpio_exp_read_byte_soft(void);
//_______INTERRUPT_C____________
void        init_interrupt();
void        disable_interrupt();
//_______LCD_C__________________
void        lcd_backlight_inv(void);
void        lcd_write(uint8_t data, uint8_t rs);
void        init_lcd();
void        lcd_clear();
void        lcd_home(void);
void        lcd_entry_mode(uint8_t id, uint8_t sh);
void        lcd_display_control(uint8_t d, uint8_t c, uint8_t b);
void    	lcd_cursor_display_shift(uint8_t sc, uint8_t rl);
void        lcd_function_set(uint8_t dl, uint8_t n, uint8_t f);
void        lcd_set_CGRAM_addr(uint8_t data);
void        lcd_set_DDRAM_addr(uint8_t data);
//______LED_C____________________
void        led_alert(uint16_t color_bits);
void        init_led(void);
//______LEVEL_C__________________
uint8_t     get_level(void);
void        init_level();
//______LIGHT_C__________________
void    	check_light();
void    	get_light_manual(void);
//______MOISTURE_C________________
void        init_moisture();
uint16_t    get_moisture();
void        check_moisture();
//______RTCC_C____________________
void        init_rtcc();
//______SAVE_C____________________
void        save_data();
//______SLEEP_C___________________
void        init_tmr1();    //+ interrupt;
void        init_tmr2();    //+ interrupt;
//______SYSTEM_C__________________
void        system_unlock();
void        system_lock();
void        init_sosco();
void        go_to_sleep();
//______TEMPERATURE_C_____________
void        init_temp();
void        delay_tmp();
uint8_t     reset();
void        WriteBit(uint8_t bitz);
void        WriteData(uint8_t data);
uint8_t     Readbit();
uint8_t     ReadData();
void        skipROM();
uint8_t     convertTmp();
uint8_t     check_crc(uint8_t* tab);
uint8_t     *SampleTmp(uint8_t* tab);
void        read_power_supply();
void        copy_to_eeprom();
uint8_t     write_scratchpad();
void        check_temp();
//________WATCHDOG_C___________
void        init_watchdog();

extern uint8_t	I_can_check_sensors;
extern uint8_t  g_mon_sleep;

#endif