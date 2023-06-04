#include <stdio.h>

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    int *ptr1 = array;
    int *ptr2 = array + 2;

    // 1. Assignment of pointers of the same type
    ptr1 = ptr2;

    // 2. Adding or subtracting a pointer and an integer
    ptr1 = array + 3;
    ptr1 = ptr1 - 1;

    // 3. Subtracting or comparing two pointers to members of the same array
    int diff = ptr2 - ptr1;
    printf("Difference: %d\n", diff);

    // 4. Assigning or comparing to zero
    if (ptr1 == NULL) {
        printf("Pointer is NULL.\n");
    }

    // 5. Illegal pointer operations
    // Uncommenting any of the following lines will result in compilation errors

    //ptr1 = (ptr1 + ptr2);      // Adding two pointers
    // ptr1 = ptr1 * 2;         // Multiplying a pointer
    // ptr1 = 0x123456;  // Assigning a pointer of one type to another without a cast

    return 0;
}
