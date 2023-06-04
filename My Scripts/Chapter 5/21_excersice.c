#include <stdio.h>

int main() {
    // Array of Strings
    char strings[3][10];  // Array of 3 strings, each with a maximum length of 10 characters

    // Initialize the array of strings
    strcpy(strings[0], "John");
    strcpy(strings[1], "Mary");
    strcpy(strings[2], "Alice");


    // Print the array of strings
    printf("Array of Strings:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s\n", strings[i]);
    }
    printf("\n");

    // char *names[]
    char *names[] = {"John", "Mary", "Alice"};  // Array of pointers to character arrays

    char **x = names;
    // Print the char *names[]
    printf("char *names[]:\n");
    for (int i = 0; i < 3; i++, x++) {
        printf("%s\n", *(x));
    }

    return 0;
}
