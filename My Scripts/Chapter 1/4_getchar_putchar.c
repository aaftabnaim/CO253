#include <stdio.h>

#define getchar_

int main() {
    #ifdef getchar_
    char c;
    printf("Enter a sentence: ");
    // Read input character by character using getchar()
    while ((c = getchar()) != EOF) {
        // Do something with each character
        putchar(c);
    }
    #else
    char c = 'a';
    int i;

    // Print the first 26 lowercase letters using putchar()
    for (i = 0; i < 26; i++) {
        putchar(c);
        c++;
    }
    #endif
    return 0;
}
