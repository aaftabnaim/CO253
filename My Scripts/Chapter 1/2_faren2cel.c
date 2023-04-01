#include <stdio.h>

/* Print the Farenheit to Celcius Table*/

void main(){
    int fahr, celcius;
    int lower, upper, step;

    lower = 0; /* LOWER LIMIT OF TEMP SCALE*/
    upper = 300; /*UPPER LIMIT*/
    step = 20; /* step size */

    fahr = lower;
    while(fahr<=upper){
        celcius = 5*(fahr-32)/9;
        printf("%d\t%d\n", fahr, celcius);
        fahr=fahr+step;

    }
    /* A single line while loop*/
    int count = 1;
    while(count <5)
        count ++;
    printf("Count is %d",count); 
}