#include "header.h"
#include "stock_value.h"

extern t_save   tab_data[];
//uint16_t        battery_average = 0;

void        calc_set_average()
{
    uint32_t    lum_stack = 0;
    uint32_t    temp_stack = 0;
    int16_t     i = nb_save;

    while(day_time >= 0)
    {
       if (i - day_time < 0)
       {
           i += 336;
       }
        lum_stack += tab_data[i - day_time].Lum_save;
        temp_stack += tab_data[i - day_time].T_save;
        day_time--;
    }
    lum_average = lum_stack / MESURES;
    temp_average = temp_stack / MESURES;
}