#include <stdio.h>

int main() {
    int x = 10;
    int* p = &x; // Pointer p holds the address of variable x
    int** pp = &p; // Pointer pp holds the address of pointer p
    
    printf("Value of x: %d\n", **pp); // Output: 10
    return 0;
}
