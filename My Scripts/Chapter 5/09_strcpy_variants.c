#include <stdio.h>

/* strcpy: copy t to s; array subscript version */
void strcpy_version1(char *s, char *t) {
    int i = 0;
    while ((s[i] = t[i]) != '\0') {
        i++;
    }
}

/* strcpy: copy t to s; pointer version */
void strcpy_version2(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

/* strcpy: copy t to s; pointer version 2 */
void strcpy_version3(char *s, char *t) {
    while ((*s++ = *t++)!='\0' ) {
        ;
    }
}

/* 
The loop in strcpy_version3 continues until the expression (*s++ = *t++) evaluates to zero. 
In C, the expression (*s++ = *t++) first assigns the value of *t to *s and then increments both s and t. 
After the assignment, the value of *s is checked for zero (i.e., the null character '\0').

In C, the value of an assignment expression is the value being assigned. So, in the case of (*s++ = *t++), 
the expression evaluates to the value of *t before t is incremented. Since the null character '\0' has a value of zero, 
the loop will terminate when the null character is encountered.

When the null character is assigned to *s, it is also the value of the expression (*s++ = *t++), which is zero. 
This causes the loop condition to become false, and the loop terminates. Hence, 
there is no chance for the loop to continue beyond the null character.

In the case of a string, the null character acts as the terminating character, indicating the end of the string.
So, when strcpy_version3 encounters the null character in the source string t, it is copied to the destination string s,
and the loop terminates immediately.

Therefore, the code ensures that the loop stops precisely at the null character, copying the complete string and guaranteeing
that the destination string will be properly terminated with the null character. 
*/
void strcpy_version4(char *s, char *t) {
    while ((*s++ = *t++) ) {
        ;
    }
} 


int main() {
    char source[] = "Hello, World!";
    char destination[20];

    // Test version 1
    strcpy_version1(destination, source);
    printf("Version 1: %s\n", destination);

    // Test version 2
    strcpy_version2(destination, source);
    printf("Version 2: %s\n", destination);

    // Test version 3
    strcpy_version3(destination, source);
    printf("Version 3: %s\n", destination);

    strcpy_version4(destination, source);
    printf("Version 4: %s\n", destination);

    return 0;
}
