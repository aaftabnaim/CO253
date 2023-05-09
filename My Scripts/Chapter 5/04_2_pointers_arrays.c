

#include <stdio.h>

int main(void) 
{
  int a[] = {1, 2, 3, 4, 5};
  int *pa = 0;

  // Assigning the address of the first element to pointer pa
  pa = &a[0];

  // Accessing elements of the array using pointer arithmetic
  printf("Element 2: %d\n", *(pa + 1)); // Output: Element 2: 2
  printf("Element 4: %d\n", *(pa + 3)); // Output: Element 4: 4

  // Assigning the address of the first element directly to pointer pa
  pa = a;

  // Accessing elements of the array using array subscript
  printf("Element 3: %d\n", pa[2]); // Output: Element 3: 3
  printf("Element 5: %d\n", pa[4]); // Output: Element 5: 5

  return 0;
}
