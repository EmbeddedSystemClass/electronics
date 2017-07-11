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
    float       T_save;
    uint16_t    Lum_save;               //luminosity value while sleeping (thresold wake up)
    uint16_t    H_save;
    uint8_t     Lvl_save;
    uint32_t    Date;
    uint32_t    Heure;
    uint32_t    Bat_save;
}               t_save;

void    save_data();

#endif	/* STOCK_VALUE_H */

