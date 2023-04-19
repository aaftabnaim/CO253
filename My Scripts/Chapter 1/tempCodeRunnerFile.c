#include <stdio.h>

/*
This script introduces arrays in C. We are going to count the number of occurences of individual digits, 
white spaces and all the other characters

in this coe if you call nother without initializing it you get a random value. this is called a garbage value.
what it gives is the previous value that was stored in that memory address


*/

int main(void){
    int c, i, nwhite, nother;
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
    {
        printf(" A%d - %d",ndigit[i], i);
    }
    printf(", white space = %d, other = %d \n", nwhite, nother);

    return 0;
}