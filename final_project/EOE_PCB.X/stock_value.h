/* 
 * File:   stock_value.h
 * Author: bocal
 *
 * Created on June 23, 2017, 12:40 PM
 */

#ifndef STOCK_VALUE_H
#define	STOCK_VALUE_H
#include "header.h"

typedef struct s_save
{
    uint32_t    Heure;
    uint32_t    Date;
    uint32_t    time;
    uint32_t    date;
    uint32_t    Bat_save;
    uint16_t    Lum_save;               //luminosity value while sleeping (thresold wake up)
    uint16_t    H_save;
    int16_t     T_save;
    uint8_t     Lvl_save;
    uint8_t     send;
}               t_save;

void    save_data();

#define save_tab_size 336

#endif	/* STOCK_VALUE_H */

