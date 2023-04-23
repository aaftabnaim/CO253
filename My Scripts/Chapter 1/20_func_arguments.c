/*
In C when I pass a variable to a function a copy of that variable is made and that is what's
used later in the function. If we want to use that variable we have to use pointers.
For arrays the, whats passed to the functioin is the memory address of the array
*/
#include <stdio.h>

int addFive(int);

int main(void){
    int sigma = 10;
    int delta = addFive(sigma);
    printf("Sigma is %d and Delta is %d \n", sigma, delta);
    return 0;
}

int addFive(int x){
    return x+5;
}

