//
//
//
//                                                         ,/
//                                                        //
//                                                      ,//
//                                          ___   /|   |//
//                                      `__/\_ --(/|___/-/
//                                   \|\_-\___ __-_`- /-/ \.
//                                  |\_-___,-\_____--/_)' ) \
//                                   \ -_ /     __ \( `( __`\|
//                                   `\__|      |\)\ ) /(/|
//           ,._____.,            ',--//-|      \  |  '   /
//          /     __. \,          / /,---|       \       /
//         / /    _. \  \        `/`_/ _,'        |     |
//        |  | ( (  \   |      ,/\'__/'/          |     |
//        |  \  \`--, `_/_------______/           \(   )/
//        | | \  \_. \,                            \___/\
//        | |  \_   \  \                                 \
//        \ \    \_ \   \   /                             \
//         \ \  \._  \__ \_|       |                       \
//          \ \___  \      \       |                        \
//           \__ \__ \  \_ |       \                         |
//           |  \_____ \  ____      |                        |
//           | \  \__ ---' .__\     |        |               |
//           \  \__ ---   /   )     |        \              /
//            \   \____/ / ()(      \          `---_       /|
//             \__________/(,--__    \_________.    |    ./ |
//               |     \ \  `---_\--,           \   \_,./   |
//               |      \  \_ ` \    /`---_______-\   \\    /
//                \      \.___,`|   /              \   \\   \
//                 \     |  \_ \|   \              (   |:    |
//                  \    \      \    |             /  / |    ;
//                   \    \      \    \          ( `_'   \  |
//                    \.   \      \.   \          `__/   |  |
//                      \   \       \.  \                |  |
//                       \   \        \  \               (  )
//                        \   |        \  |              |  |
//                         |  \         \ \              I  `
//                         ( __;        ( _;            ('-_';
//                         |___\        \___:            \___:
//
//FOR PONNYLAND!!!


/*
 * Capacitive Soil Sensor
 * using CTMU
 */

#include "header.h"

extern uint16_t humidity;

void    init_moisture()
{
//OLD SOIL SENSOR GPIO 26 RB15 CDTED6 AN 9
//SOIL SENSOR GPIO 23 RB12 AN 12
    TRISBbits.TRISB12 = 1;          //SET PIN at INPUT
    
//CTMU 1
    CTMUCON = 0;                    // RESET all
    CTMUCONbits.IRNG = 0b11;        // Current source trim at 55uA (I)
    
//TIMER
    T1CONbits.ON = 1;               // Enable Timer
    TMR1 = 0;                       // Set Start to 0
    T1CONbits.TCKPS = 0;            // Set Prescale to 1
    PR1 = 10000;                    // 1mSec
    
    //Enable Multi-Vector and interruptions
    //INTCONbits.MVEC = 1;
    //__asm("ei");
    display_write_str("H", 0, 10);
}

uint16_t get_moisture()
{
    uint16_t vctmu;
    uint16_t cap;

    vctmu = 0;
    TMR1 = 0;
    AD1CHSbits.CH0SA = 12;          // Select chanel AN12
    while (vctmu == 0)
    {
        CTMUCONbits.ON = 1;         // Turn On CTMU
        while (TMR1 < PR1);         // wait 1ms
        AD1CON1bits.SAMP = 1;       // Begin manual sampling ADC
        CTMUCONbits.IDISSEN = 1;    // Discharge the connected circuit
        while (TMR1 < PR1);         // wait 1ms
        CTMUCONbits.IDISSEN = 0;    // Stop manual sampling
        CTMUCONbits.EDG1STAT = 1;   // Begin charging circuit
        while (TMR1 < 10);          // wait 1us (66% max charge)
        AD1CON1bits.SAMP = 0;       // End Sampling begin conversion
        CTMUCONbits.EDG1STAT = 0;   // Stop charging circuit
        while(!AD1CON1bits.DONE);   // wait ADC is done
        AD1CON1bits.DONE = 0;       // Clear flag
        vctmu = ADC1BUF0;           // get value from ADC
    }
    CTMUCONbits.ON = 0;             // CTMU off
    return (vctmu);
}

void check_moisture()
{
    init_manual_adc();
    ANSELA = 0x0000;                // No ADC pin
    ANSELB = 1<<12;                 // RB12 connected to sensor
    uint16_t ctmu_ret = get_moisture();
    
    humidity = 100 - ((ctmu_ret - min_ctmu) * 100 / max_ctmu) - min_ctmu;
    display_write_str("  ", 0, 11);
    display_write_dec(humidity, 0, 11);
}