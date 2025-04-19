#include <stdlib.h>
#include "weather_utils.h"
#include "weather_table.h"
#include <limits.h>

int temp_min(WeatherTable med) {
    int min = med[0][0][0]._min_temp;
    for (int year = 0; year < YEARS; year++)
    {
        for (int month = 0; month < MONTHS; month++)
        {
            for (int day = 0; day < DAYS; day++)
            {
                if (min>= med[year][month][day]._min_temp)
                {
                    min = med[year][month][day]._min_temp;
                }
                
            }
            
        }
        
    }
    return min;
}


void temp_max_year(WeatherTable med, int output[YEARS]) {
    int max_temp = INT_MIN;
    for (int year = 0; year < YEARS; year++)
    {
        for (int month = 0; month < MONTHS; month++)
        {
            for (int day = 0; day < DAYS; day++)
            {
                if(max_temp <= med[year][month][day]._max_temp) {
                    max_temp = med[year][month][day]._max_temp;
                }
            }
        }
        output[year] = max_temp;
        max_temp = INT_MIN;
    }
}

void month_max_prec (WeatherTable med, int output[YEARS]) {
    int prec_month;
    month_t max_month;
    int max_prec;
    for (int year = 0; year < YEARS; year++)
    {
        max_month = january;
        max_prec = 0;
        for (month_t month = january; month <= december; month++) {
            prec_month =  0;
            for (int day = 0; day < DAYS; day++) {
                prec_month = prec_month + med[year][month][day]._rainfall;
            }
            if(prec_month > max_prec) {
                max_month = month;
                max_prec = prec_month;
            }
        }
        output[year] = max_month;
    }
}
