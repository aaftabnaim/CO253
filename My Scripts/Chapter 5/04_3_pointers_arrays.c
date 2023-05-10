#include <stdio.h>

int main() {
    int a[5] = {1, 2, 3, 4, 5};  // Declare and initialize an array
    
    int *pa = &a[0];  // Pointer pa points to the first element of array a
    
    // Access array elements using array notation
    printf("Array elements using array notation:\n");
    for (int i = 0; i < 5; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    
    // Access array elements using pointer notation *(a+i)
    printf("\nArray elements using pointer notation *(a+i):\n");
    for (int i = 0; i < 5; i++) {
        printf("*(a+%d) = %d\n", i, *(a + i));
    }
    
    // Access array elements using pointer pa with array notation
    printf("\nArray elements using pointer pa with array notation:\n");
    for (int i = 0; i < 5; i++) {
        printf("pa[%d] = %d\n", i, pa[i]);
    }
    
    // Access array elements using pointer pa with pointer notation *(pa+i)
    printf("\nArray elements using pointer pa with pointer notation *(pa+i):\n");
    for (int i = 0; i < 5; i++) {
        printf("*(pa+%d) = %d\n", i, *(pa + i));
    }
    
    return 0;
}
