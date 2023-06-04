#include <stdio.h>

#define RECURSION

#ifdef RECURSION
int fib(int n){
    // base case
    if(n==1) return 1;
    if(n==0) return 0;
    //Recursion
    return n+fib(n-1);
}

#else
int fib(int n){
    int result = 0;
    while(n>0){
        result+= n--;
    }
    return result;
}
#endif

int main(void){


    int f;
    for(int i=0;i<15;i+=2){
        f = fib(i);
        printf("\nFibonacci of %d is %d\n",i, f);
    }

}