
#ifndef HEADER_H
#define	HEADER_H


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


extern int	I_can_check_sensors;

#endif

