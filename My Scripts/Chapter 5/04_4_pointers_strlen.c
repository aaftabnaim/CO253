#include <stdio.h>

// Function to compute the length of a string
int strlen_(char *s) {
    int n = 0;
    
    // Iterate until the null terminator '\0' is encountered
    while (*s != '\0') {
        n++;
        printf("Pointer is at %p\n", s);
        s++;  // Increment the pointer to the next character
    }
    
    return n;
}

int main() {
    char str1[] = "hello, world";  // Character array
    char *str2 = "h";          // Character pointer to a string constant
    
    // Calling strlen with a string constant
    int len1 = strlen_("he");
    printf("Length of string constant: %d\n", len1);
    
    // Calling strlen with a character array
    //int len2 = strlen(str1); // the same as passing &str1[0]
    //printf("Length of character array: %d\n", len2);
    
    // Calling strlen with a character pointer
    //int len3 = strlen(str2);
    //printf("Length of character pointer: %d\n", len3);
    
    return 0;
}
