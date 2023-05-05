#include <stdio.h>


int main(void){
   
    printf("%g", (0)? 3: 2.5f); // this expression has type double
    float x= 3.7f;
    printf("\n%d", (1)? 3: x); // this expression has type double
    return 0;
}


