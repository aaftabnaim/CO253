#include <stdio.h>

#define DEBUG

#ifdef DEBUG
    #define DEBUG_MODE_ENABLED
#endif

#define VERSION 2

/*
When you use the macro function swap(float, a, b);, 
the preprocessor replaces this code with the corresponding macro expansion:
{ float temp = a; a = b; b = temp; }


Essentially, the macro function replaces the function call with the actual 
code it represents. In this case, the macro function swaps the values of the
variables a and b using a temporary variable temp.

During the preprocessing phase, the preprocessor scans the code and performs
textual substitutions. So, when the preprocessor encounters swap(float, a, b); 
in your code, it replaces it with the swap code block mentioned above.

As a result, the macro function swap doesn't actually create a function call; it
directly inserts the code in place of the function call. This allows the macro 
to access and modify the local variables a and b directly, just like any other 
code within the same block or scope.

After the preprocessor stage, the modified code is then compiled by the compiler, 
treating the macro-expanded code as part of the main program.

In summary, the macro function is able to change the values of the local variables 
a and b because it directly substitutes the code that performs the swapping operation 
at the location where the macro is used, effectively modifying the variables' values.

*/
#define swap(t, x, y) { t temp = x; x = y; y = temp; }


int main() {
    #ifdef DEBUG_MODE_ENABLED
        printf("Debug mode is enabled.\n");
        // Debug-related code goes here
    #endif

    #ifdef VERSION
        #if VERSION == 1
            printf("This is version 1.\n");
        #elif VERSION == 2
            printf("This is version 2.\n");
        #else
            printf("Unknown version.\n");
        #endif
    #endif

    float a = 10.5;
    float b = 20.9;

    printf("Before swapping: a = %g, b = %g\n", a, b);
    swap(float, a, b);
    printf("After swapping: a = %g, b = %g\n", a, b);

    return 0;
}

