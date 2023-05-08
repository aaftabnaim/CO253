#include <stdio.h>

#define DEBUG

#ifdef DEBUG
    #define DEBUG_MODE_ENABLED
#endif

#define VERSION 2

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

