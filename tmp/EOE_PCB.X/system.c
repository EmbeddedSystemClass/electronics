
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
//    CFGCONbits.PMDLOCK = 0;       //Unlock PMD
//    CFGCONbits.PMDLOCK = 1;       //Lock PMD
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
//
//rappel utilisation
//
//    uint8_t      bat_seuil          = 15;
//    uint8_t      level_seuil        = 1;
//    uint8_t      seuil_pump = 25;
//    uint16_t     lum_seuil_bas      = 600;
//    uint16_t     lum_seuil_haut     = 950;
//    uint16_t     temp_seuil_bas     = 20;
//    uint16_t     temp_seuil_haut    = 29;
//    uint8_t       min_bat;
//    uint8_t       max_bat;


void    parameter_change()
{
    uint8_t commande = 0;
    uint8_t variable = 0;

    variable = (uint8_t)((g_ret >> 16) & 0x00ff);
    if ((commande = (uint8_t)(g_ret >> 24 )) == 42) // alert config
    {
        if (variable == 0) // alerte bat_seuil
        {
            bat_seuil = (uint8_t)g_ret;
        }
         if (variable == 1) // alerte level_seuil
        {
            level_seuil = (uint8_t)g_ret;
        }
         if (variable == 2) // alerte seuil_pump
        {
            seuil_pump = (uint8_t)g_ret;
        }
         if (variable == 3) // alerte lum_seuil_bas
        {
            lum_seuil_bas = (uint16_t)g_ret;
        }
        if (variable == 4) // alerte lum_seuil_haut
        {
            lum_seuil_haut = (uint16_t)g_ret;
        }
        if (variable == 5) // alerte temp_seuil_bas
        {
            temp_seuil_bas = (uint16_t)g_ret;
        }
        if (variable == 6) // alerte temp_seuil_haut
        {
            temp_seuil_haut = (uint16_t)g_ret;
        }
        if (variable == 7) // alerte min_bat
        {
            min_bat = (uint8_t)g_ret;
        }
        if (variable == 8) // alerte max_bat
        {
            max_bat = (uint8_t)g_ret;
        }
    }
    else if (commande == 69) // rtcc time config
    {
        if (variable == 1)
            RTCALRMbits.AMASK = 0b01;        // Every 1sec // Valeur Test
        if (variable == 2)
            RTCALRMbits.AMASK = 0b10;        // Every 10min // Valeur Test
        if (variable == 3)
        {
            if ((uint8_t)g_ret != 0)
                frequency = (uint8_t)g_ret;      //frequence de meusure
        }
    }
}