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
#include <xc.h>
#include "nrf24l01_radio.h"

/*              SPI NRF24L01                */
/*
 * Spi_cifique :
 * RB6  =>  PGEC3/RPB6/PMD6/RB6                                 CE      
 * RB11 =>  PGEC2/TMS/RPB11/PMD1/RB11                           MISO    SDI
 * RB13 =>  AN11/RPB13/CTPLS/PMRD/RB13                          MOSI    SDO              
 * RB14 =>  CVREFOUT/AN10/C3INB/RPB14/SCK1/CTED5/PMWR/RB14      SCK1
 * RB15 =>  AN9/C3INA/RPB15/SCK2/CTED6/PMCS1/RB15               CSN     SS
 */

/*              SPI Commands                */
#define R_REGISTER(addr) (0b00000000 | addr)        //0b000A AAAA (A = address)
#define W_REGISTER(addr) (0b00100000 | addr)        //0b001A AAAA (A = address)
#define W_ACK_PAYLOAD(pip) (0b10101000 | pip)     //P = Pipe
#define R_RX_PAYLOAD 0b01100001                     //Read payload
#define W_TX_PAYLOAD 0b10100000                     //Write payload
#define FLUSH_TX 0b11100001                         //Flush TX
#define FLUSH_RX 0b11100010                         //FLush RX
#define REUSE_TX_PL 0b11100011                      //
#define ACTIVATE 0b01010000                         //
#define R_RX_PL_WID 0b01100000                      //
#define W_TX_PAYLOAD_NO_ACK 0b1011000               //
#define NOP 0b11111111                              //NOP

void        init_spi()
{
    int     data;
    
    SPI1CONbits.ON = 0;         // Stop and reset the SPI module
    data = SPI1BUF;             // Clear BUF
    
    //SPI1BRG = 32;              // Fpb / 32 clock frequency = 10Mhz/32 -> 312.500KHz
    
    SPI1BRG = 5;                //Fpb / 5 clock frequency = 10Mhz/5 -> 2Mhz
    SPI1STAT = 0;
    SPI1STATbits.SPIROV = 0;    // Clear Overflow
    
    /*Set the pin as usual*/
    SPI1CONbits.FRMPOL = 1;     // Active high frame pulse
    SPI1CONbits.MSSEN = 0;
    SPI1CONbits.MODE32 = 0;     //|-> ||| 8     |||
    SPI1CONbits.MODE16 = 0;     //|-> ||| bits !|||
    SPI1CON2bits.AUDEN = 0;     //|-> |||Disable||| Audio codec
    SPI1CONbits.MSTEN = 1;      // Master !
    SPI1CONbits.ON = 1;         // Enable SPI module
}

void        init()
{
    int rdata;
        /* Secure gpio */
    ANSELA = 0;
    ANSELB = 0;
    LATA = 0;
    LATB = 0;
    TRISA = 0;
    TRISB = 0;
        /* End Secure */
    /*  Initialisation    */
    //Remap GPIO
    SDI1R = 0b0011;         // SDI  for RB11
    RPB13R = 0b0011;        // SDO  for RB13
    RPB15R = 0b0011;        // SS   for RB15
    
    //timer for test
    T4CONbits.ON = 1;
    // GPIO
    TRISBbits.TRISB11 = 1;  // Input    for RB11
    TRISBbits.TRISB13 = 0;  // Output   for RB13
    TRISBbits.TRISB14 = 0;  // Output   for RB14
    TRISBbits.TRISB15 = 0;  // Output   for RB15
    TRISBbits.TRISB6 = 0;   // OUtput   for RB6
    LATBbits.LATB15 = 1;    // CSN kept hight for active low
    LATBbits.LATB6 = 0;     // CE Low
    
    // SPI
    init_spi();
}

void        init_interrupt()
{
    __asm("di");
    INTCONbits.MVEC = 1;    //Enable Multi-Vector
    __asm("ei");
}

char        SPI1_transfer(int send)
{
    SPI1BUF = send;                 // write to shift register to begin transmission
    while(SPI1STATbits.SPIBUSY);    // wait for transfer to complete
    return SPI1BUF;                 // read the shift register value
}

int         read_register()
{
    int         this;
    
    TRISBbits.TRISB15 = 0;      //Set CSN low
    SPI1_transfer(0b00000000);  //read register 0x10
    this = SPI1_transfer(0);           // Dummie data
    this = SPI1_transfer(0);
    this = SPI1_transfer(0);
    this = SPI1_transfer(0);
    this = SPI1_transfer(0);
    TRISBbits.TRISB15 = 1;      //CSN to high
    return SPI1BUF;
}

int         main()
{
    int     ret;
    init();
    init_interrupt();
    while (1)
    {
        ret = read_register();
        WDTCONbits.WDTCLR = 1;      //Reset Watchdog
    }
    return (1);
}