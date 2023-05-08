// File: file2.c

/*
    val[11] = 10.0;
    printf("%d", val[11]);

    the output is 0. this is because the type conflict
    printf expects an int while the actual variable is a double
*/
#include "06_file1.c"
#include <stdio.h>

extern int sp;             // External variable declaration for sp
extern double val[];       // External variable declaration for val

int main() {
    // Access and manipulate sp and val here
    /*
    Even though the code below works the behaviour you are seeing is 
    undefined. C doen't do any bound checks on its arrays.
    */
    val[5] = 10.0;
    printf("   %g\n   ", val[0]);
    printf("%g\n   ", val[1]);
    printf("%g\n   ", val[2]);
    printf("%g\n   ", val[3]);
    printf("%g\n   ", val[4]);
    printf("%g\n   ", val[5]);
    printf("%g\n   ", val[6]);
    return 0;
}
