#include <stdio.h>

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
