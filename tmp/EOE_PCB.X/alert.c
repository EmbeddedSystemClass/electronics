
#include "header.h"

uint8_t      bat_seuil          = 15;
uint16_t     lum_seuil_bas      = 600;
uint16_t     lum_seuil_haut     = 950;
float        temp_seuil_bas     = 20;
float        temp_seuil_haut    = 29;
uint8_t      level_seuil        = 1;
/*
 * low bat = rouge
 * reservoir vide = vert
 * froid = bleu
 * chaud = violet
 * trop soleil = jaune
 * trop nuit = cyan
 */
void check_alerts(void)
{
    led_alert(0);

//    if (battery <= battery_seuil)
//    {
//        led_alert(RED_BIT);
//        return;
//    }
//    if (level <= level_seuil)
//    {
//        led_alert(GRE_BIT);
//        return;
//    }
    if (temp_average <= temp_seuil_bas)
    {
        led_alert(BLU_BIT);
        return;
    }
    if (temp_average >= temp_seuil_haut)
    {
        led_alert(BLU_BIT | RED_BIT);
        return;
    }
    if (lum_average <= lum_seuil_bas)
    {
        led_alert(BLU_BIT | GRE_BIT);
        return;
    }
    if (lum_average >= lum_seuil_haut)
    {
        led_alert(GRE_BIT | RED_BIT);
        return;
    }
    led_alert(0);
}