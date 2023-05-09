#include <stdio.h>

int main() {
    int a[10];         // Declare an array of size 10
    int *pa;           // Declare a pointer to an integer

    printf("Before a[0]: %d\n", a[0]);     // Before Assignment

    pa = &a[0];        // Set pa to point to the first element of a (a[0])

    *pa = 42;          // Assign 42 to the first element of a

    printf("a[0]: %d\n", a[0]);     // Output: a[0]: 42
    printf("*pa: %d\n", *pa);       // Output: *pa: 42

    printf("Before a[1]: %d\n", a[1]);    // Before Assignment

    *(pa + 1) = 24;    // Assign 24 to the second element of a (a[1])

    printf("a[1]: %d\n", a[1]);     // Output: a[1]: 24
    printf("*(pa + 1): %d\n", *(pa + 1));   // Output: *(pa + 1): 24

    return 0;
}
