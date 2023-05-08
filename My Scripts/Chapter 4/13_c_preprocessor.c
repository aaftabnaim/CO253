/*
#include "filename": The file is searched for in the current directory or the specified paths.
#include <filename>: The file is searched for in implementation-defined locations.
*/

#include <stdio.h>  // Include the standard input/output header file

/*
#define name replacement_text

*/
#define PI 3.14159  // Simple substitution

#define max(A, B) ((A) > (B) ? (A) : (B))  // Macro with arguments

/*
#if: It evaluates a constant integer expression and includes 
subsequent lines if the expression is non-zero.

#ifdef: It checks if a name is defined and includes subsequent
 lines if the name is defined.

#ifndef: It checks if a name is not defined and includes 
subsequent lines if the name is not defined.
*/
#define SYSTEM BSD

#if SYSTEM == SYSV
    #define HDR "sysv.h"
#elif SYSTEM == BSD
    #define HDR "bsd.h"
#elif SYSTEM == MSDOS
    #define HDR "msdos.h"
#else
    #define HDR "default.h"
#endif

#include HDR

int main() {
    int x = 5;
    int y = 10;
    int result = max(x, y);  // Macro substitution

    printf("The maximum value is: %d\n", result);
    return 0;
}
