#include <stdio.h>

/* Function prototypes */
int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);


/* daytab: number of days in each month */
static int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) 
{
    int leap;
    int *p;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    p = &daytab[leap][1];

    while (--month)
        day += *++p;

    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) 
{
    int leap;
    int *p;

    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    p = &daytab[leap][1];

    while (yearday > *p) {
        yearday -= *p;
        p++;
    }

    *pmonth = p - *(daytab + leap);
    *pday = yearday;
}


/* main function to test day_of_year and month_day */
int main(void) 
{
    int month, day;

    printf("Day of Year: %d\n", day_of_year(2023, 5, 11));
    month_day(2023, 131, &month, &day);
    printf("Month: %d, Day: %d\n", month, day);

    return 0;
}
