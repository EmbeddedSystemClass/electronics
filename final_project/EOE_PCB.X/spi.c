/*Perform the following steps to set up the SPI module for the Master mode of operation*/
/*
 *  1. Disable the SPI interrupts in the respective IEC0/1 register.
 *  2. Stop and reset the SPI module by clearing the ON bit.
 *  3. Clear the receive buffer.
 *  4. If SPI interrupts are not going to be used, skip this step and continue to step 5. Otherwise
 *     the following additional steps are performed:
 *      a) Clear the SPIx interrupt flags/events in the respective IFS0/1 register.
 *      b) Set the SPIx interrupt enable bits in the respective IEC0/1 register.
 *      c) Write the SPIx interrupt priority and subpriority bits in the respective IPC5/7 register.
 *  5. Write the Baud Rate register, SPIxBRG.
 *  6. Clear the SPIROV bit (SPIxSTAT<6>).
 *  7. Write the desired settings to the SPIxCON register with MSTEN (SPIxCON<5>) = 1.
 *  8. Enable SPI operation by setting the ON bit (SPIxCON<15>).
 *  9. Write the data to be transmitted to the SPIxBUF register. Transmission (and reception) will
 *     start as soon as data is written to the SPIxBUF register.
 */

#include <sys/attribs.h>
#include "header.h"

/*              SPI NRF24L01                */
/*
 * RB6  =>  PGEC3/RPB6/PMD6/RB6                                 CE
 * RB11 =>  PGEC2/TMS/RPB11/PMD1/RB11                           MISO    SDI
 * RB13 =>  AN11/RPB13/CTPLS/PMRD/RB13                          MOSI    SDO
 * RB14 =>  CVREFOUT/AN10/C3INB/RPB14/SCK1/CTED5/PMWR/RB14      SCK1
 * RB15 =>  AN9/C3INA/RPB15/SCK2/CTED6/PMCS1/RB15               CSN     SS
 * RB1  =>  PGEC1/AN3/C1INC/C2INA/RPB1/CTED12/RB1               IRQ
 *
 */

void        init_spi()
{
    int     data;

    // Remappable GPIO :
    SDI1R = 0b0011;             // SDI  for RB11
    RPB13R = 0b0011;            // SDO  for RB13

    SPI1CONbits.ON = 0;         // Stop and reset the SPI module
    data = SPI1BUF;             // Clear SPI1BUF
    SPI1BRG = 5;                // Fpb / 5 clock frequency = 10Mhz/5 -> 2Mhz
    SPI1STAT = 0;               // Clear All Status on SPI
    // Desired Setting
    SPI1CONbits.MCLKSEL = 0;    //  Select PBCLK
    SPI1CONbits.FRMPOL = 1;     //  Active high frame pulse
    SPI1CONbits.MSSEN = 0;      //  Slave Select SPI support disable
    SPI1CONbits.MODE32 = 0;     //  |-> ||| 8       |||
    SPI1CONbits.MODE16 = 0;     //  |-> ||| bits !  |||
    SPI1CON2bits.AUDEN = 0;     //  |-> ||| Disable ||| (Audio codec)
    SPI1CONbits.SMP = 0;        //  disable sample at the end of output
    SPI1CONbits.MSTEN = 1;      //  Master !
    SPI1CONbits.CKE = 1;        //  Serial output data changes on transition from active clock state to Idle clock state
    SPI1CONbits.CKP = 0;        //  !(Idle state for clock is a high level; active state is a low level)
    SPI1CONbits.ON = 1;         //  Enable SPI module
    // GPIO Settings
    TRISBbits.TRISB11 = 1;      // Input    for RB11
    TRISBbits.TRISB13 = 0;      // Output   for RB13
    TRISBbits.TRISB14 = 0;      // Output   for RB14
    TRISBbits.TRISB15 = 0;      // Output   for RB15
    TRISBbits.TRISB6 = 0;       // Output   for RB6

    LATBbits.LATB15 = 1;        // CSN kept hight for active low || chip select enable
    LATBbits.LATB6 = 1;         // CE Low

}

int        spi_transfer(int send)
{
    SPI1BUF = send;                 // write to register to begin transmission
    TMR3 = 0;
    while(SPI1STATbits.SPIBUSY) // wait for transfer to complete
    {
        T3CONbits.ON = 1;
       
        if (TMR3 > 10000)
            break;
    }
//    delay_micro(1000);
    return SPI1BUF;                 // read the shift register value
}