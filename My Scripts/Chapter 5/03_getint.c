#include <ctype.h>
#include <stdio.h>

#define SIZE 5

int getch(void);
void ungetch(int);

/* getint: get next integer from input into *pn */
int getint(int *pn) {
    int c, sign;

    // Skip white space
    while (isspace(c = getch()))
        ;

    // Check if the input is not a number
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); /* Push the character back onto input */
        return 0;   /* Return 0 to indicate failure */
    }

    sign = (c == '-') ? -1 : 1; /* Determine the sign of the number */

    if (c == '+' || c == '-')
        c = getch();

    // Read the digits and calculate the integer value
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * (*pn) + (c - '0');

    *pn *= sign; /* Apply the sign to the number */

    if (c != EOF)
        ungetch(c); /* Push the character back onto input */

    return c; /* Return the next character read */
}



int main() {
    int n, array[SIZE];

    printf("Enter integers (up to %d):\n", SIZE);
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        printf("Recorded Number.\n");

    printf("Numbers entered: ");
    for (int i = 0; i < n; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}
