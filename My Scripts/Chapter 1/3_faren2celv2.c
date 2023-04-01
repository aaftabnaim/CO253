#include <stdio.h>

#define lower 0
#define NAME "Aaftab Naim"
/* Print the Farenheit to Celcius Table*/

void main(){
    float fahr, celcius;
    float upper, step; // lower was removed from here

    // lower = 0; /* LOWER LIMIT OF TEMP SCALE*/ we have replaced this line with a define statement
    upper = 300; /*UPPER LIMIT*/
    step = 20; /* step size */

    printf("Hi %s \n**Celcius to Farenheit Table**\n", NAME);
    fahr = lower;
    while(fahr<=upper){
        celcius = 5*(fahr-32)/9;
        printf("%3.0f\t%5.2f\n", fahr, celcius);
        fahr=fahr+step;

    }
    int count = 1;
    /* A single line while loop*/
    while(count <5)
        count ++;
    printf("Count is %d",count); 
}