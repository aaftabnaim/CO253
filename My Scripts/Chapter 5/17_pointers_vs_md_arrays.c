#include <stdio.h>

int main()
{
    int a[10][20];   // Two-dimensional array
    int *b[10];      // Array of pointers

    // Accessing elements in a two-dimensional array (a)
    a[3][4] = 42;    // Assigning value to a single int in a two-dimensional array
    int aValue = a[3][10];    // Accessing a single int in a two-dimensional array

    // Accessing elements in an array of pointers (b)
    int arr1[20] = {1, 2, 3, 4, 5};   // Example array with 20 elements
    int arr2[2] = {10, 20};           // Example array with 2 elements

    b[3] = arr1;    // Assigning a pointer to arr1 to b[3]
    b[4] = arr2;    // Assigning a pointer to arr2 to b[4]

    int bValue1 = b[3][10];   // Accessing a single int in the array pointed by b[3]
    int bValue2 = b[4][1];   // Accessing a single int in the array pointed by b[4]

    // Printing values to verify the results
    printf("a[3][4] = %d\n", aValue);
    printf("b[3][4] = %d\n", bValue1);
    printf("b[4][1] = %d\n", bValue2);

    return 0;
}
