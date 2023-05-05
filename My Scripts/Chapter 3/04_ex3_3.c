#include <stdio.h>

void expand(char s1[], char s2[]) {
    int i, j, k;
    char c;

    i = j = 0;
    while ((c = s1[i++]) != '\0') {
        if (s1[i] == '-' && s1[i+1] >= c) {
            i++;
            while (c < s1[i])
                s2[j++] = c++;
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = '\0';
}

int main() {
    char s1[] = "a-z0-9A-Z";
    char s2[100];
    expand(s1, s2);
    printf("%s\n", s2);  // prints "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    return 0;
}
