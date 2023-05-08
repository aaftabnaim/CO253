#include <stdio.h>

#define BUFSIZE 100

// Function declarations
int getch(void);
void ungetch(int c);
int getop(void);

// Internal static variable
/*
This behaves like an extern too. But the scope is 
limited to this file only. Therefore any variable
called lastChar outside this file is not th same as this
*/
static int lastChar = '\0';  // Stores the last character read by getch

int main() {
    int c;
    while ((c = getop()) != EOF) {
        printf("Next token: %c\n", c);
    }
    return 0;
}

int getch(void) {
    // Internal static variable
    /*  this variable is initialized only once at the 
        very first function call. This behaves almost like a 
        extern variable. the difference is that it is visible
        only within the function */
    static char buf[BUFSIZE];  // Buffer for ungetch
    static int bufp = 0;       // Next free position in buf

    if (lastChar != '\0') {
        int temp = lastChar;
        lastChar = '\0';
        return temp;
    } else {
        return getchar();
    }
}

void ungetch(int c) {
    if (lastChar != '\0') {
        printf("Error: ungetch buffer full\n");
    } else {
        lastChar = c;
    }
}

int getop(void) {
    // Use internal static variable
    // this variable is initialized only once at the 
    // very first function call
    static int isPreviousToken = 0;  // Flag to check if the previous token is available

    if (isPreviousToken) {
        isPreviousToken = 0;
        return lastChar;
    }

    // Implementation of getop function
    // ...
}
