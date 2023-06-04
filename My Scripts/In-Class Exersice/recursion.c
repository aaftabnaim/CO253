#include <stdio.h>

int factorial(int n){
    // base case
    if(n==1)return 1;
    // do recursion
    return n*factorial(n-1);
}

long fib(int n){
    //base case
    if(n==1) return 1;
    if(n==0) return 0;
    // recursion
    return fib(n-1)+fib(n-2);
    return 0;
}

int main(void){
    int x = factorial(5);
    int y = fib(50);
    printf("%d", y);
    return 0;
}