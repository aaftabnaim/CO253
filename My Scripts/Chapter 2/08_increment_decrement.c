#include <stdio.h>

void prefix_postfix_loop();

int main(void){
    
    int n = 5;
    int x = n++; // x is 5, n is 6
    // now n is 6 and x is 5 because the postfix operator used the old value 
    // of n (5) in the expression where it was used, and then incremented n to 6
    printf("%d vs %d", x, n);

    x = ++n; // x is 7, n is 7
    // now n is 7 and x is also 7 because the prefix operator incremented n 
    // before using its new value
    printf("%d vs %d", x, n);

    prefix_postfix_loop();

    char name[] = "Aaftab";
    char remove[] = "ab";
    squeeze_alt(name, remove);
    printf("%s", name);
    return 0;
}

void prefix_postfix_loop(){
    int i = 0;
    int j = 0;
    while (i < 10) {
    printf("Prefix: %d, Postfix: %d\n", ++i, j++);
    }
}

void copy_array(int* src, int* dest, int len) {
int i = 0;
while (i < len) {
dest[i] = src[i++];
}
}

// Excersice 2.4
/* squeeze_alt: delete all c from s1 that matches any character in s2 */
void squeeze_alt(char s1[], char s2[]) {
    int i, j, k;
    for (i = j = 0; s1[i] != '\0'; i++) {
        for (k = 0; s2[k] != '\0' && s1[i] != s2[k]; k++) {
            // Check if current character in s1 matches any character in s2
        }
        if (s2[k] == '\0') {
            // No match found, copy current character to new position
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

/* any: find first occurrence of any character in s2 in s1 */
int any(char s1[], char s2[]) {
    int i, j;
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
}

