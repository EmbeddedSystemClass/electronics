#include "stock_value.h"
#include "header.h"

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
    if (nb_save > 335)      // Stock sur 7 * 48
    {
        nb_save = 0;
    }
}