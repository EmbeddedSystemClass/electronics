
#include "header.h"

uint8_t      bat_seuil          = 15;
uint16_t     lum_seuil_bas      = 500;
uint16_t     lum_seuil_haut     = 1000;
int16_t      temp_seuil_bas     = 5 * 10;
int16_t      temp_seuil_haut    = 35 * 10;
uint8_t      level_seuil        = 1;

/*
 * low bat = rouge
 * reservoir vide = vert
 * froid = bleu
 * chaud = violet
 * trop soleil = jaune
 * trop nuit = cyan
 */
//void check_alerts(void)
//{
//    led_alert(0);
//
////    if (battery <= battery_seuil)
////    {
////        led_alert(RED_BIT);
////        return;
////    }
//    if (level <= level_seuil)
//    {
//        led_alert(GRE_BIT);
//        return;
//    }
//    if (temp_average <= temp_seuil_bas)
//    {
//        led_alert(BLU_BIT);
//        return;
//    }
//    if (temp_average >= temp_seuil_haut)
//    {
//        led_alert(BLU_BIT | RED_BIT);
//        return;
//    }
//    if (lum_average <= lum_seuil_bas)
//    {
//        led_alert(BLU_BIT | GRE_BIT);
//        return;
//    }
//    if (lum_average >= lum_seuil_haut)
//    {
//        led_alert(GRE_BIT | RED_BIT);
//        return;
//    }
//    led_alert(0);
//}


void check_alerts(void)
{
    led_alert(0);
    uint8_t i = 0;

    if (lum_average >= lum_seuil_haut)
    {
        led_alert(GRE_BIT | RED_BIT);
        i++;
    }
     if (lum_average <= lum_seuil_bas)
    {
        led_alert(BLU_BIT | GRE_BIT);
        i++;
    }
    if (temp_average >= temp_seuil_haut)
    {
        led_alert(BLU_BIT | RED_BIT);
        i++;
    }
    if (temp_average <= temp_seuil_bas)
    {
        led_alert(BLU_BIT);
        i++;
    }
     if (level <= level_seuil)
    {
        led_alert(GRE_BIT);
        i++;
    }
        if (bat_level <= bat_seuil)
    {
        led_alert(RED_BIT);
        i++;
    }
    if (i >= 4)
        lcd_frimousse_0();
    if (i == 3)
        lcd_frimousse_1();
    if (i == 2)
        lcd_frimousse_2();
    if (i == 1)
        lcd_frimousse_3();
    if (i == 0)
    {
        lcd_frimousse_5();
         led_alert(0);
    }
}