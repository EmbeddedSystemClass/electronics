#include "header.h"

extern t_save tab_data[];

void    init_save_tab(void)
{
    int i = 0;

    while (i < save_tab_size)
    {
        tab_data[i].send = 1;
        i++;
    }
}

void    save_data()
{
//  *(save_data + nb_save).H_save = humidity; autre maniere d'ecrire
    tab_data[nb_save].H_save = humidity; //save humidity
    tab_data[nb_save].Lum_save = lum_manual; //save lum
    tab_data[nb_save].Lvl_save = level; //save lvl
    tab_data[nb_save].T_save = Temperature; //save temp
    tab_data[nb_save].Date = RTCDATE; //save date [A][M][J][0]
    tab_data[nb_save].Heure = RTCTIME; // save hour [H][Min][Sec][0]
    tab_data[nb_save].Bat_save = bat_level;
    tab_data[nb_save].send = 0;
    nb_save++;
//    if (nb_save % 8 == 0)

//    int tab_size = sizeof(tab_data[0]);

    radio_send_values();

    if (nb_save >= save_tab_size)      // Stock sur 7 * 48
    {
        nb_save = 0;
    }
}