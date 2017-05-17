#ifndef NRF24L01_H      /* Guard against multiple inclusion */
#define NRF24L01_H

typedef unsigned char   u8;
typedef unsigned short  u16;
typedef unsigned int    u32;

typedef char            s8;
typedef short           s16;
typedef int             s32;

void            init_rtcc();
void            init_rtcc_interrupt();

#endif /* NRF24L01_H */