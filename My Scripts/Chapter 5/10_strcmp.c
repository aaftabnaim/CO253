#include <stdio.h>
#include <string.h>

// Function to compare two strings lexicographically
// Returns <0 if s < t, 0 if s == t, >0 if s > t
int my_strcmp(char *s, char *t) {
    for (; *s == *t; s++, t++) {
        if (*s == '\0') {
            return 0; // Strings are equal
        }
    }
    return *s - *t; // Return the difference between the differing characters
}

int main() {
    char str1[] = "Hello";
    char str2[] = "Hello";
    char str3[] = "World";

    // Demonstrating strcpy
    char dest[10];
    strcpy(dest, str1); // Copy str1 into dest
    printf("Copied string: %s\n", dest);

    // Demonstrating strcmp
    int comparison1 = my_strcmp(str1, str2);
    int comparison2 = my_strcmp(str1, str3);
    
    printf("Comparison result 1: %d\n", comparison1); // Should be 0 (equal strings)
    printf("Comparison result 2: %d\n", comparison2); // Should be negative (str1 < str3)

    // Demonstrating pointer operations
    char stack[5]; // Stack of characters
    char *p = stack; // Pointer to the top of the stack

    *p++ = 'A'; // Push 'A' onto the stack
    *p++ = 'B'; // Push 'B' onto the stack

    char val = *--p; // Pop the top of the stack into val
    printf("Popped value: %c\n", val); // Should be 'B'

    return 0;
}
