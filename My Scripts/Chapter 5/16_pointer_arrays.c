#include <stdio.h>
#include <string.h>

/* month_name: return name of n-th month */
char month_name(int n) 
{ 
    static char name[13][100] = { 
        "Illegal month", 
        "January", "February", "March", 
        "April", "May", "June", 
        "July", "August", "September", 
        "October", "November", "December" 
    }; 
    return (n < 1 || n > 12) ? name[0] : name[n]; 
} 

/* main function to test month_name */
int main(void)
{
    int i;
    for (i = 0; i <= 12; i++) {
        printf("%c\n", month_name(i));
    }
    return 0;
}
