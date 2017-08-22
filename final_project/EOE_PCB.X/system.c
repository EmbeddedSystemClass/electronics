
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

void    parameter_change_all()
{
    int16_t    tmp = 0;

    tmp = (g_reception[0] + (g_reception[1] << 8));
    tmp = tmp > 100 ? 100 : tmp;
    tmp = tmp < 0 ? 0 : tmp;
    bat_seuil = (int8_t)tmp;
    tmp = (g_reception[2] + (g_reception[3] << 8));
    tmp = tmp > 5 ? 5 : tmp;
    tmp = tmp < 1 ? 1 : tmp;
    level_seuil = (int8_t)tmp;
    tmp = (g_reception[4] + (g_reception[5] << 8));
    tmp = tmp > 100 ? 100 : tmp;
    tmp = tmp < 0 ? 0 : tmp;
    seuil_pump = (int8_t)tmp;
    tmp = (g_reception[6] + (g_reception[7] << 8));
    tmp = tmp < 0 ? 0 : tmp;
    tmp = tmp > 1024 ? 1024 : tmp;
    lum_seuil_bas = tmp;
    tmp = (g_reception[8] + (g_reception[9] << 8));
    tmp = tmp < 0 ? 0 : tmp;
    tmp = tmp > 1024 ? 1024 : tmp;
    lum_seuil_haut = tmp;
    tmp = (g_reception[10] + (g_reception[11] << 8));
    tmp = tmp < -40 ? -40 : tmp;
    tmp = tmp > 80 ? 80 : tmp;
    temp_seuil_bas = tmp * 10;
    tmp = (g_reception[12] + (g_reception[13] << 8));
    tmp = tmp < -40 ? -40 : tmp;
    tmp = tmp > 80 ? 80 : tmp;
    temp_seuil_haut = tmp * 10;
    tmp = (g_reception[14] | (g_reception[15] << 8));
    tmp = tmp > 1024 ? 1024 : tmp;
    tmp = tmp < 0 ? 0 : tmp;
    min_bat = tmp;
    tmp = (g_reception[16] + (g_reception[17] << 8));
    tmp = tmp > 1024 ? 1024 : tmp;
    tmp = tmp < 0 ? 0 : tmp;
    max_bat = tmp;
    tmp = (g_reception[18] + (g_reception[19] << 8));
    tmp = tmp < 0 ? 0 : tmp;
    tmp = tmp > 10 ? 10 : tmp;
    frequency = (int8_t)tmp;      //frequence de meusure
    tmp = (g_reception[20] + (g_reception[21] << 8));
    tmp = tmp > 9 ? 9 : tmp;
    tmp = tmp < 0 ? 0 : tmp;
    RTCALRMbits.AMASK = tmp;        // Every 1sec // Valeur Test
    radio_flush_rx();
}
void    parameter_change()
{
    uint8_t commande = 0;
    uint8_t variable = 0;
    uint16_t tmp;

    variable = (uint8_t)((g_ret >> 16) & 0x00ff);
    if ((commande = (uint8_t)(g_ret >> 24 )) == 42) // alert config
    {
        if (variable == 0) // alerte bat_seuil
        {
            tmp = (uint8_t)g_ret;
            tmp = tmp > 100 ? 100 : tmp;
            bat_seuil = tmp;
        }
         if (variable == 1) // alerte level_seuil
        {
             tmp = (uint8_t)g_ret;
             tmp = tmp > 5 ? 5 : tmp;
             tmp = tmp < 1 ? 1 : tmp;
            level_seuil = tmp;
        }
         if (variable == 2) // alerte seuil_pump
        {
             tmp = (uint8_t)g_ret;
             tmp = tmp > 100 ? 100 : tmp;
            seuil_pump = tmp;
        }
         if (variable == 3) // alerte lum_seuil_bas
        {
             tmp = (uint16_t)g_ret;
             tmp = tmp < 10 ? 10 : tmp;
             tmp = tmp > 1028 ? 1028 : tmp;
            lum_seuil_bas = tmp;
        }
        if (variable == 4) // alerte lum_seuil_haut
        {
             tmp = (uint16_t)g_ret;
             tmp = tmp < 10 ? 10 : tmp;
             tmp = tmp > 1028 ? 1028 : tmp;
            lum_seuil_haut = tmp;
        }
        if (variable == 5) // alerte temp_seuil_bas
        {
            tmp = (uint16_t)g_ret;
            tmp = tmp < 1 ? 1 : tmp;
            tmp = tmp > 50 ? 50 : tmp;
            temp_seuil_bas = tmp;
        }
        if (variable == 6) // alerte temp_seuil_haut
        {
            tmp = (uint16_t)g_ret;
            tmp = tmp < 1 ? 1 : tmp;
            tmp = tmp > 50 ? 50 : tmp;
            temp_seuil_haut = tmp;
        }
        if (variable == 7) // alerte min_bat
        {
            tmp = (uint16_t)g_ret;
            tmp = tmp > 1028 ? 1028 : tmp;
            tmp = tmp < 10 ? 10 : tmp;
            min_bat = tmp;
        }
        if (variable == 8) // alerte max_bat
        {
            tmp = (uint16_t)g_ret;
            tmp = tmp > 1028 ? 1028 : tmp;
            tmp = tmp < 10 ? 10 : tmp;
            max_bat = tmp;
        }
        if (variable == 9)
        {
            RTCALRMbits.AMASK = RTCALRMbits.AMASK == 0b01 ? 0b100 : 0b01;        // Every 1sec // Valeur Test
        }
        if (variable == 10)
        {
            tmp = (uint8_t)g_ret;
            if (tmp != 0 && tmp <= 200)
                frequency = tmp;      //frequence de meusure
        }
        radio_flush_rx();
    }
//    else if (commande == 100) //cheack alert config //no ack recieve
//    {
//        IEC0bits.INT0IE = 0; //disable radio recive interrupt
//        IEC0bits.T1IE = 0; //disable TMR1 interrupt
//        IEC0bits.T2IE = 0;	//disable TMR2 interrupt
//        IEC0bits.RTCCIE = 0;  // disable RTCC interrupts
//        LATBCLR = CE_PIN;                               //CE LOW - Disable reception
//        radio_nop();
//        radio_send((bat_seuil) , 4);
//        delay_micro(radio_delay);
//        if (radio_ack() == -1)
//            return;
//        radio_send((level_seuil) , 4);
//        delay_micro(radio_delay);
//        if (radio_ack() == -1)
//            return;
//        radio_send((seuil_pump) , 4);
//        delay_micro(radio_delay);
//        if (radio_ack() == -1)
//            return;
//        radio_send((lum_seuil_bas) , 4);
//        delay_micro(radio_delay);
//        if (radio_ack() == -1)
//            return;
//        radio_send(lum_seuil_haut , 4);
//        delay_micro(radio_delay);
//        if (radio_ack() == -1)
//            return;
//        radio_send(temp_seuil_bas , 4);
//        delay_micro(radio_delay);
//        if (radio_ack() == -1)
//            return;
//        radio_send(temp_seuil_haut , 4);
//        delay_micro(radio_delay);
//        if (radio_ack() == -1)
//            return;
//        radio_send(min_bat , 4);
//        delay_micro(radio_delay);
//        if (radio_ack() == -1)
//            return;
//        radio_send(max_bat, 4);
//        delay_micro(radio_delay);
//        if (radio_ack() == -1)
//            return;
//        radio_rx_mode();
//        LATBSET = CE_PIN;        //CE HIGH - Enable reception
//        IEC0bits.T1IE = 1; //enable TMR1 interrupt
//        IEC0bits.T2IE = 1;	//enable TMR2 interrupt
//        IEC0bits.RTCCIE = 1; // enable RTCC interrupts
//        IEC0bits.INT0IE = 1; //enable radio iterrupt
//    }
}