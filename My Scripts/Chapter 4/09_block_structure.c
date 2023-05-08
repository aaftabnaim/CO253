#include <stdio.h>

int x = 100;  // External variable x

void outerFunction() {
    // this variable takes a higher precedence inside the function

    int x = 10;  // Variable x in the outer function 

    if (x > 0) {
        int i;  // Declare a new i within the block
        for (i = 0; i < x; i++) {
            printf("Inner i: %d\n", i);
        }
    }
    
    // printf("Outer i: %d\n", i); // Error: The complier can't identify i (out of scope)
    printf("Inner  x: %d\n", x);  // Access the outer x variable

    /*
    In the printf below the x, the external variable x is lexically out of scope.
    This means that the external x cannot be accessed. In c++ we have the ::x
    operator which is called the scope resolution operator which allows us to directly access
    the external variables by its name
    */
    //printf("External x: %d\n", ::x);  // Access the external x variable
}

int main() {
    outerFunction();
    return 0;
}
