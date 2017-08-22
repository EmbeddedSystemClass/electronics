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
#include "battery.h"
#include "stock_value.h"



/*GLOBAL VARIABLES*/
uint8_t     I_can_check_sensors;        //lomg terme checking sensors
uint8_t     I_can_display;              //pour afficher 10 sec
uint8_t     g_mon_sleep;            //global monitor sleeping
uint16_t    lum_manual;                 //luminosity value
float       Temperature;
uint8_t     level;
int16_t     lum_sleep;                  //luminosity value while sleeping (thresold wake up)
uint16_t    humidity;                   //current hum val
t_save    tab_data[336];
uint16_t    nb_save;
uint8_t     SLEEPON;
uint16_t    led_color;
uint8_t     alert;
uint8_t     pump_status;
uint16_t    lum_average;
uint16_t    temp_average;
int16_t     day_time;
int32_t     bat_level;
int64_t      g_ret;
uint8_t      g_reception[22];

extern uint8_t      bat_seuil;
extern uint16_t     lum_seuil_bas;
extern uint16_t     lum_seuil_haut;
extern int16_t        temp_seuil_bas;
extern int16_t        temp_seuil_haut;
extern uint8_t      level_seuil;
extern uint8_t      seuil_pump;
extern int16_t      min_bat;
extern int16_t       max_bat;
extern uint8_t frequency;

/*Moisture sensor*/
#define max_ctmu 550
#define min_ctmu 0
#define MESURES  2  //nb mesures par jour default = 48 (30 min)
#define radio_delay 100000

//_______ADC_MANOUAL_C__________
void        init_manoual_adc();
//_______BARGRAPH_C_____________
void        init_bargraph(void);
static void bargraph_srclk_pulse(void);
static void bargraph_rclk_pulse(void);
void        bargraph_write(uint32_t value);
//_______BARGRAPH_C_____________
void        init_battery(void);
void        get_battery(void);
//_______DELAY_MICRO_C__________
void        init_delay(); //+interrupt;
void        delay_micro(uint32_t time_ms);
//_______DISPLAY_C______________
void	    display_write(int charactere, int line, int index);
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
void     get_level(void);
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
//________pump_c_______________
void    pump_on_off();
void    init_pump();
//_________RADIO_C______________
void    radio_reception();

extern uint8_t	I_can_check_sensors;
extern uint8_t  g_mon_sleep;

#endif