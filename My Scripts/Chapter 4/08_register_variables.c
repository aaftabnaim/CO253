#include <stdio.h>

int main() {
    /*
    The register keyword is used to decalre variables that are 
    expected to be used heavily. These variables are stored in machine registers 
    making the code faster and smaller.
    Register variables can be used only to automatic variables and the formal parameters of a 
    function. 
    The address of a register variable cannot be accessed 
    */
    register int x = 10;  // Register declaration for variable x
    register char c;  // Register declaration for variable c

    // Excess register declarations are harmless
    register int i;  // Excess register declaration

    // Assign values to the register variables
    x = 10;
    c = 'A';

    // Print the values of the register variables
    printf("x: %d\n", x);
    printf("c: %c\n", c);

    // Attempt to take the address of a register variable (not allowed)
    // int* ptr = &x;  // Uncommenting this line will result in a compilation error,
    // error: address of register variable 'x' requested

    return 0;
}
