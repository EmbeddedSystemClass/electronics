
#include "header.h"

void        system_unlock(void)
{
    SYSKEY = 0x0;
    SYSKEY = 0xaa996655;
    SYSKEY = 0x556699aa;
}

void        system_lock(void)
{
    SYSKEY = 0x0;
}

void        go_to_sleep()
{
    system_unlock();
    //disable modules
    CFGCONbits.PMDLOCK = 0;       //Unlock PMD

    //PMD1bits.AD1MD = 0;
//    PMD1bits.CTMUMD = 1;
//    //PMD4bits.T1MD = 0;
//    PMD4bits.T2MD = 1;
//    PMD4bits.T3MD = 1;
//    //PMD4bits.T4MD = 0;
//    PMD4bits.T5MD = 1;
//    PMD5bits.I2C1MD = 1;
//    PMD5bits.I2C2MD = 1;
//    PMD5bits.SPI1MD = 1;
//    PMD5bits.SPI2MD = 1;
    //PMD6bits.RTCCMD = 0;          //Enable Rtcc when sleep

    CFGCONbits.PMDLOCK = 1;       //Lock PMD
    __asm volatile("wait");
    system_lock();
}


void        init_sosco()
{
    //SET GPIO
    LATBbits.LATB4 = 1;             //hight
    TRISAbits.TRISA4 = 1;           //Input
    system_unlock();
    OSCCONbits.SOSCEN = 1;
    while (!(OSCCONbits.SOSCRDY));
    system_lock();
}

void        init_sleep()
{
    system_unlock();
    OSCCONbits.SLPEN = 1;           //Enable Sleep mode
    CFGCONbits.PMDLOCK = 0;       //Unlock PMD
    PMD1bits.AD1MD = 0;
    PMD1bits.CTMUMD = 0;
    PMD1bits.CVRMD = 1;
    PMD2bits.CMP1MD = 1;
    PMD2bits.CMP2MD = 1;
    PMD2bits.CMP3MD = 1;
    PMD3bits.IC1MD = 1;
    PMD3bits.IC2MD = 1;
    PMD3bits.IC3MD = 1;
    PMD3bits.IC4MD = 1;
    PMD3bits.IC5MD = 1;
    PMD3bits.OC1MD = 1;
    PMD3bits.OC2MD = 1;
    PMD3bits.OC3MD = 1;
    PMD3bits.OC4MD = 1;
    PMD3bits.OC5MD = 1;
    PMD4bits.T1MD = 0;
    PMD4bits.T2MD = 0;
    PMD4bits.T3MD = 0;
    PMD4bits.T4MD = 0;
    PMD4bits.T5MD = 0;
    PMD5bits.I2C1MD = 0;
    PMD5bits.I2C2MD = 1;
    PMD5bits.SPI1MD = 0;
    PMD5bits.SPI2MD = 1;
    PMD5bits.U1MD = 1;
    PMD5bits.U2MD = 1;
    PMD6bits.PMPMD = 1;
    PMD6bits.REFOMD = 1;
    PMD6bits.RTCCMD = 0;          //Enable Rtcc when sleep
    CFGCONbits.PMDLOCK = 1;       //Lock PMD
    system_lock();
}
