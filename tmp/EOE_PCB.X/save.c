#include "stock_value.h"
#include "header.h"

 uint16_t    lum_manual;             //luminosity value
extern float   Temperature;
extern uint16_t    humidity;               //current hum val
extern uint16_t     nb_save;             //index tab_save
extern uint8_t level;
extern t_save tab_data[];

void    save_data()
{
//    *(save_data + nb_save).H_save = humidity; autre maniere d'ecrire
    tab_data[nb_save].H_save = humidity; //save humidity
    tab_data[nb_save].Lum_save = lum_manual; //save lum
    tab_data[nb_save].Lvl_save = level; //save lvl
    tab_data[nb_save].T_save = Temperature; //save temp
    tab_data[nb_save].Date = RTCDATE; //save date [A][M][J][0]
    tab_data[nb_save].Heure = RTCTIME; // save hour [H][Min][Sec][0]
    nb_save++;
    if (nb_save > 336)
    {
        nb_save = 0;
    }
}