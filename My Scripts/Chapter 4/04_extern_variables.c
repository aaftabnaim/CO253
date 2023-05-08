#include <stdio.h>
/*
On the other hand, if a variable or function is declared with the static keyword at the global scope,
it will have internal linkage. This means that it can only be accessed within the same source file, 
and it is not visible to other source files in the program.
*/
/* External variable declaration */
int count;

int sum;

void add(int num) {
    sum += num;
}

void subtract(int num) {
    sum -= num;
}


void function1() {
    count = 10;
}

void function2() {
    printf("%d", count); // Output: 10
}

int main() {
    function1();
    function2();

    sum = 0;
    add(5);
    subtract(3);
    printf("\nSum is %d", sum); // Output: 2
    return 0;
    
    }
