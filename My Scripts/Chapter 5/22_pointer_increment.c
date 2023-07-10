#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *p = arr;

    // Example: *p++
    printf("Example: *p++\n");

    // Print the values using *p++
    printf("%p \n", p);
    printf("%d \n", *p++);
    printf("%d \n", arr[0]);
    printf("%p ", p);

    printf("\n");

    // Reset p to the beginning of the array
    p = arr;

    // Example: (*p)++
    printf("Example: (*p)++\n");

    // Increment the values using (*p)++
    printf("%d ", (*p)++);
    printf("\n");

    // Print the modified array
    printf("%d ", arr[0]);
    printf("\n");

    return 0;
}
