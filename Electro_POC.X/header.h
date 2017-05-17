
#ifndef CONFIG_H
#define	CONFIG_H


//#define level_on_interrupt      //Enable gpio_ext interrupt to get level, else get level with timer

/*GENERAL*/
//#define FALSE 0
//#define TRUE  !FALSE

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

void bargraph_write(uint32_t value);
void bargraph_srclk_pulse(void);
void init_bargraph(void);
void init(void);


void    gpio_exp_is_iddle(void);
void    gpio_exp_start();


/*Alert LED*/
#define RED_BIT  0x0004		//RB2
#define GRE_BIT  0x0008		//RB3
#define BLU_BIT  0x0020		//RB5
#define LED_BITS 0x002c		//all colors bits

#define LED_OFF 39062		//1sec @ 10MHz
#define LED_ON  390     	//1:10 sec

/*Bargraph*/
#define SER_PIN   0x0002	//RA1  data input
#define RCLK_PIN  0x0004	//RA2  output latch
#define SRCLK_PIN 0x0008	//RA3  shift data
#define bargraph_howmuchpins    20

/*I2C*/
#define INTA_PIN 0x0080		//RB7
#define SCL_PIN  0x0100		//RB8
#define SDA_PIN  0x0200		//RB9

void    init_I2C(void);
uint8_t	gpio_exp_write_byte(uint8_t data_byte);		//send a single byte to the slave
uint8_t	gpio_exp_read_byte(void);                   //return the recieved byte

/*GPIO_exp*/
#define REG_IODIRA      0x00
#define REG_IPOLA       0x02
#define REG_GPINTENA	0x04
#define REG_DEFVALA     0x06
#define REG_INTCONA     0x08
#define REG_IOCONA      0x0a
#define REG_GPPUA       0x0c
#define REG_INTFA       0x0e
#define REG_INTCAPA     0x10
#define REG_GPIOA       0x12
#define REG_OLATA       0x14

#define REG_IODIRB      0x01
#define REG_IPOLB       0x03
#define REG_GPINTENB    0x05
#define REG_DEFVALB     0x07
#define REG_INTCONB     0x09
#define REG_IOCONB      0x0b
#define REG_GPPUB       0x0d
#define REG_INTFB       0x0f
#define REG_INTCAPB     0x11
#define REG_GPIOB       0x13
#define REG_OLATB       0x15

void	gpio_exp_write_byte_to_reg(uint8_t register_addr, uint8_t data);
uint8_t	gpio_exp_read_byte_from_reg(uint8_t reg_addr);
void    init_gpio_exp(void);


/*Level sensor*/
//PORTA
#define LEVEL_1_PIN	0x01
#define LEVEL_2_PIN	0x02
#define LEVEL_3_PIN	0x04
#define LEVEL_4_PIN	0x08
#define LEVEL_5_PIN	0x10
#define LEVEL_ALL_PINS 0x1f

/*LCD display*/
//PORTA
#define RS_PIN	0x80
#define EN_PIN	0x40
#define BL_PIN	0x20

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
void	lcd_clear();
void	lcd_home(void);
void	lcd_entry_mode(uint8_t id, uint8_t sh);
void	lcd_display_control(uint8_t d, uint8_t c, uint8_t b);
void	lcd_cursor_display_shift(uint8_t sc, uint8_t rl);
void	lcd_function_set(uint8_t dl, uint8_t n, uint8_t f);
void	lcd_set_CGRAM_addr(uint8_t data);
void	lcd_set_CGRAM_addr(uint8_t data);


extern int	I_can_check_sensors;


/*display*/
uint8_t	display_write_dec(int32_t nb, uint8_t line,uint8_t index);
void	display_write_str(char	*str, uint8_t line,uint8_t index);



/*LIGHT*/
void    	check_light();
uint32_t	get_light(void);
uint8_t		uchar_to_hex(uint8_t val);




#endif

