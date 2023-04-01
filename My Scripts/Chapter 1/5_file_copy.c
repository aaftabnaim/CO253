#include <stdio.h> 
 /* copy input to output; 1st version */ 
 int main() 
 { 
    int c; 
    printf("Your exit code is %d \n", EOF);

    while ((c = getchar()) != EOF) {  // can replace this line with while((c=getchar()) != EOF)
        putchar(c);
    } 
    printf(" This is the EOF character %d \n", c);

    return 0;
 } 