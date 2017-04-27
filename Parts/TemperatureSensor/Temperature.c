// PIC32MX340F512H Configuration Bit Settings

// 'C' source line config statements

// DEVCFG3
// USERID = No Setting

// DEVCFG2
#pragma config FPLLIDIV = DIV_12        // PLL Input Divider (12x Divider)
#pragma config FPLLMUL = MUL_24         // PLL Multiplier (24x Multiplier)
#pragma config FPLLODIV = DIV_256       // System PLL Output Clock Divider (PLL Divide by 256)

// DEVCFG1
#pragma config FNOSC = FRC              // Oscillator Selection Bits (Fast RC Osc (FRC))
#pragma config FSOSCEN = ON             // Secondary Oscillator Enable (Enabled)
#pragma config IESO = ON                // Internal/External Switch Over (Enabled)
#pragma config POSCMOD = OFF            // Primary Oscillator Configuration (Primary osc disabled)
#pragma config OSCIOFNC = ON            // CLKO Output Signal Active on the OSCO Pin (Enabled)
#pragma config FPBDIV = DIV_8           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk/8)
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor Selection (Clock Switch Disable, FSCM Disabled)
#pragma config WDTPS = PS1048576        // Watchdog Timer Postscaler (1:1048576)
#pragma config FWDTEN = ON              // Watchdog Timer Enable (WDT Enabled)

// DEVCFG0
#pragma config DEBUG = OFF              // Background Debugger Enable (Debugger is disabled)
#pragma config ICESEL = ICS_PGx2        // ICE/ICD Comm Channel Select (ICE EMUC2/EMUD2 pins shared with PGC2/PGD2)
#pragma config PWP = OFF                // Program Flash Write Protect (Disable)
#pragma config BWP = OFF                // Boot Flash Write Protect bit (Protection Disabled)
#pragma config CP = OFF                 // Code Protect (Protection Disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>


//ECRAN LCD


#define uint8_t unsigned char

uint8_t Presence = 0;
uint8_t LSB = 0x00;
uint8_t MSB = 0x00;
float   Temperature;
    
//#define BusLOW LATBbits.LATB0 = 1 //drain open
//#define BusHIGH LATBbits.LATB0 = 0 //drain close

#define OW_bus(state) LATBbits.LATB0 = state

void	init()
{
// set port to Digital input
    AD1PCFGbits.PCFG0 = 1; 

 // set timer 1
    T1CONbits.TCKPS = 0; // set prescale to 1
    T1CONbits.ON = 1; // enable timer 1 (LAT1=1) open drain
//set port
    TRISBbits.TRISB0 = 0; // output
    OW_bus(1); //define OW high
    ODCBbits.ODCB0 = 1; //enable open drain on RB0
}

int	reset()
{
    Presence = 0;
    //drive bus low for 480us
    OW_bus(0); //OW low (open drain)
   // LATBbits.LATB0 = 0; // drive bus low
    TMR1 = 0; // reset timer 1
    while (TMR1 < 480) // 480us (reset pulse)
    {}
	//LATBbits.LATB0 = 1; // release bus
	OW_bus(1); // release OW
    while (TMR1 < 600); //attendre 70us recommandé
//sample bus
    if (PORTBbits.RB0 == 0) //480 + 60us (presence pulse)
    {
        Presence = 1;
    }
    else
    {
        Presence = 0;
    }
    while (TMR1 < 960); //attendre 410us recommandé
    return (Presence);
}

void    WriteBit(uint8_t bit)
{
    TRISBbits.TRISB0 = 0; //pin output
    if (bit == 1)
    {
        //write 1
        TMR1 = 0;
        OW_bus(0); //drive OW low
        while (TMR1 < 1)
        {}
        OW_bus(1); //release OW
        while (TMR1 < 60)
        {}
    }
    else
    {
        //write 0
        TMR1 = 0;
        OW_bus(0); //drive OW low
        while (TMR1 < 60)
        {}   
        OW_bus(1); //release OW
    }
}

void    WriteData(uint8_t data)
{
    int i = 0;
    uint8_t  bitmask = 0x01;
    
    while (i < 8)
    {
        if ((bitmask & data) > 0)
        {
            WriteBit(1);
        }
        else
        {
            WriteBit(0);
        }
        bitmask = bitmask << 1;
        i++;
    }
    
}

uint8_t    Readbit()
{
    uint8_t i;
    
    TMR1 = 0;
    OW_bus(0); //drive OW low
    while (TMR1 < 1);
    OW_bus(1);
    TRISBbits.TRISB0 = 1; //set input
    while (TMR1 < 10)
    {}
    if (PORTBbits.RB0 == 0)
    {
        i = 0;
    }
    else
    {
        i = 1;
    }
    while (TMR1 < 60)
    {}
    //OW_bus(1);
    TRISBbits.TRISB0 = 0; // pin output
    return i;
}

uint8_t ReadData()
{
    uint8_t i = 0;
    uint8_t data = 0x00;
    uint8_t bitmask = 0x01;
    
    while (i < 8)
    {
        if (Readbit() == 1)
        {
            data = data | bitmask;
        }
        bitmask = bitmask << 1;
        i++;
    }
    return (data);
}

void    skipROM()
{
    WriteData(0xCC); //skip ROM
}

uint8_t    convertTmp()
{
    if (reset() == 0)
    {
        return(0);
    }
    skipROM();
    WriteData(0x44); //convert temperature (96ms))
    while (Readbit() == 0); // CF datasheet en mode normale, le capteur retourne 0 sur le OW si operation en cou, et 1 une foisla convertion fini
}
    
void    SampleTmp()
{
    while(reset() == 0);
    skipROM();
    WriteData(0xBE); //read scratchpad command
    LSB = ReadData();
    MSB = ReadData();
}

void    readrom()
{
    while (reset() == 0);
    WriteData(0x33);
    LSB = ReadData();
    MSB = ReadData();
}

void    read_power_supply()
{
    while (reset() == 0);
    skipROM();
    WriteData(0xB4);
    test = Readbit();
}

void    copy_to_eeprom()
{
    while (reset() == 0);
    skipROM();
    WriteData(48);
}

void    write_scratchpad()
{
    while (reset() == 0);
    skipROM();
    WriteData(4E); //set config
    // Envois des 3 octets
    WriteData(0xFF); //Th
    WriteData(0x00); //Tl
    WriteData(0x1F); //Resolution 9bits
    // Copy Scratchpad to EEPROM
    copy_to_eeprom();
}

void    main()
{
    init();
    //while(1)
    //{
     //   TMR1 = 0;
        //reset();
      //  WriteData(0b00001111);
       // while(TMR1 < 2000);
    //}
    //read_power_supply();
    write_scratchpad();
    convertTmp();
    SampleTmp();
    LSB = LSB & 0b11111000;
    Temperature = ((MSB << 8) + LSB) * 0.5;
    while (1)
    {
    }
}
//ROM command




// Function command
// 0x1F = controle register byte Resolution = 9bits
// Th = 0xFF
// Tl = 0x00