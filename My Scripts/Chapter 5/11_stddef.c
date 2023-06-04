/*
ptrdiff_t:

ptrdiff_t is a signed integer type that is capable of holding the difference between two pointers.
It is typically used to represent the result of pointer arithmetic, such as subtracting one pointer from another.
The type ptrdiff_t is defined in the <stddef.h> header.

size_t:

size_t is an unsigned integer type that is used to represent the sizes of objects.
It is commonly used as the return type of the sizeof operator and various memory-related functions, such as strlen.
The type size_t is defined in several standard headers, including <stddef.h>.
*/
#include <stdio.h>
#include <stddef.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr1 = &arr[2];
    int *ptr2 = &arr[4];

    ptrdiff_t diff = ptr2 - ptr1;
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Pointer Difference: %td \n", diff);
    printf("Array Size: %zu\n", size);

    return 0;
}
