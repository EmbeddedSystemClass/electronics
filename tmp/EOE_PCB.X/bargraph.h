#ifndef BARGRAPH_H
#define BARGRAPH_H

/*Bargraph*/
#define SER_PIN   LATAbits.LATA1	//RA1  data input
#define RCLK_PIN  LATAbits.LATA3	//RA3  output latch
#define SRCLK_PIN LATAbits.LATA2	//RA2  shift data
#define bargraph_howmuchpins    20

void init_bargraph(void);
static void bargraph_srclk_pulse(void);
static void bargraph_rclk_pulse(void);
void bargraph_write(uint32_t value);

#endif