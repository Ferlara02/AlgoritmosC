#ifndef _WEATHER_UTILS
#define _WEATHER_UTILS

#include <stdio.h>
#include "weather_table.h"

int temp_min(WeatherTable med);
void temp_max_year(WeatherTable med, int output[YEARS]);
void month_max_prec (WeatherTable med, int output[YEARS]);


#endif