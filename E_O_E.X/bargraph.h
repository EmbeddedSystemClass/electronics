#ifndef BARGRAPH_H
#define BARGRAPH_H

/*Bargraph*/
#define SER_PIN   0x0002	//RA1  data input
#define RCLK_PIN  0x0004	//RA2  output latch
#define SRCLK_PIN 0x0008	//RA3  shift data
#define bargraph_howmuchpins    20

void init_bargraph(void);
static void bargraph_srclk_pulse(void);
static void bargraph_rclk_pulse(void);
void bargraph_write(uint32_t value);

#endif