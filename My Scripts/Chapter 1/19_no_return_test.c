#include <stdio.h>

/*
As you can see when a non-void function is defined with no return value and called in main, it returns a random value.
Where that value comes from, idk?

GCC warnings says
'''
-Wreturn-type
Warn whenever a function is defined with a return type that defaults to int. Also warn about any return statement with no return value in a function whose return type is not void (falling off the end of the function body is considered returning without a value).

For C only, warn about a return statement with an expression in a function whose return type is void, unless the expression type is also void. As a GNU extension, the latter case is accepted without a warning unless -Wpedantic is used. Attempting to use the return value of a non-void function other than main that flows off the end by reaching the closing curly brace that terminates the function is undefined.

Unlike in C, in C++, flowing off the end of a non-void function other than main results in undefined behavior even when the value of the function is not used.

This warning is enabled by default in C++ and by -Wall otherwise.
'''
*/


int kaushitha();
int machang();

int main(void){

    kaushitha();
    printf("Machang Gives %d \n", machang());

    return 0;
}

int kaushitha(){
    return 20;
}

int machang(){
     
}