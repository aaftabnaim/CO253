/*Definition as an array (amessage):
In this case, amessage is declared as an array of characters (char[]). It is initialized with the string "now is the time", including the null character ('\0') at the end. The size of the array is automatically determined based on the length of the initializer string.

The key point is that amessage is an array with a fixed size and the initializer string is copied into that array. You can modify individual characters within the array, such as changing 'n' to 'N' or 'i' to 'I', as shown in the code example. However, you cannot change the size or the memory location that amessage refers to.

Definition as a pointer (pmessage):
In this case, pmessage is declared as a pointer to a character (char*). It is initialized to point to a string constant "now is the time". The string constant is typically stored in read-only memory and cannot be modified.

The key difference here is that pmessage is a pointer that points to a string constant, and attempting to modify the characters pointed to by pmessage results in undefined behavior. In the code example, the line pmessage[0] = 'N'; is commented out because it would lead to undefined behavior if uncommented.

In summary, when a string is declared as an array (like amessage), the memory for the string is allocated, and you can modify the individual characters within that array. However, when a string is declared as a pointer (like pmessage), it points to a string constant, and attempting to modify the string contents results in undefined behavior.

Note: It is always important to be cautious when modifying string literals or string constants, as it can lead to unexpected results.*/

#include <stdio.h>

int main() {
    int a[] = {1,2,3};
    char amessage[] = "now is the time";    // Definition as an array
    char *pmessage = "now is the time";     // Definition as a pointer

    // Modifying the characters within the array
    amessage[0] = 'N';
    amessage[4] = 'I';

    // Trying to modify the characters pointed to by the pointer (undefined behavior)
    //pmessage[0] = 'N';  // Uncommenting this line will result in undefined behavior

    *amessage = 'w';
    printf("Array message: %s\n", amessage);
    printf("Pointer message: %s\n", pmessage);

    *(a+2) = 10;
    printf("%d", a[2]);
    return 0;
}
