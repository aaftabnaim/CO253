#include <stdio.h>

/*
This script introduces arrays in C. We are going to count the number of occurences of individual digits, 
white spaces and all the other characters

in this coe if you call the variable nother without initializing it you get a random value. this is called a garbage value.
what it gives is the previous value that was stored in that memory address

a very interesting thing happens when you run this code in windows and linux
when CTRl+C is entered the program gives me the output of the first element on the array only
this is because the program terminates. why does it give the first element of the array and not execute the printf 
right below it is a problem though

when run on linux the program quits similarly when CTRL+C is pressed
however when CTRL+D is entered the EOF is emulated and the expected output is seen.

*/

int main(void){
    int c, i, nwhite = 0, nother = 0;
    int ndigit[10];

    for(i = 0; i<10;i++)
        ndigit[i] = 0;

    while((c=getchar())!=EOF){
        if(c>='0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c==' '||c=='\n'||c=='\t')
            ++nwhite;
        else
            ++nother;
    }
    //printf(" %d ", nother);
    printf("digits = ");

    for(i=0;i<10;i++) 
        printf(" For %d -> %d \t ",i, ndigit[i]);
    
    printf("\n white space = %d, other = %d \n", nwhite, nother);

    return 0;
}