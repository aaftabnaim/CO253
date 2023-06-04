#include <stdio.h>

#define LEAP_YEAR 1
#define NON_LEAP_YEAR 0

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int is_leap_year(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = is_leap_year(year);
    
    // Error checking for invalid month
    if (month < 1 || month > 12)
        return -1;
    
    // Error checking for invalid day
    if (day < 1 || day > daytab[leap][month])
        return -1;
    
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = is_leap_year(year);
    
    // Error checking for invalid yearday
    if (yearday < 1 || yearday > (leap ? 366 : 365))
    {
        *pmonth = -1;
        *pday = -1;
        return;
    }
    
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    
    *pmonth = i;
    *pday = yearday;
}

int main()
{
    int year = 2000;
    int month = 9;
    int day = 4;
    
    int yearday = day_of_year(year, month, day);
    printf("%d/%d/%d is the %dth day of the year.\n", day, month, year, yearday);
    
    int m, d;
    month_day(year, yearday, &m, &d);
    printf("The %dth day of the year is %d/%d/%d.\n", yearday, d, m, year);
    
    return 0;
}
