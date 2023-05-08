#include <stdio.h>

/* Function declaration */
void printd(int n);

/* Test case */
int main() {
    int number = -123;
    printf("Number: %d\n", number);
    printf("Printed as characters: ");
    printd(number);
    printf("\n");
    return 0;
}

/* Function definition */
void printd(int n) {
    /* If n is negative, print '-' and make n positive */
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    
    /* Recursive call: Divide n by 10 and call printd with the quotient */
    if (n / 10)
        printd(n / 10);
    
    /* Print the last digit by converting it to a character and adding '0' */
    putchar(n % 10 + '0');
}
