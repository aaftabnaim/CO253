#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cipher(int k, char* s) {
    int n = strlen(s);
    char* result = malloc((n + 1) * sizeof(char));
    int sum = 0;
    int appendence = 0;

    for (int i = 0; i < n; i++) {
        appendence = (sum + (s[i] - '0')) & 1;
        result[i] = appendence + '0';
        int prev = i - k + 1;
        int remain = (prev < 0) ? 0 : (result[prev] - '0');
        sum = sum + appendence - remain;
    }

    result[n-(k-1)] = '\0';
    return result;
}

int main() {
    int k = 4;
    char s[] = "1110101001";

    char* encrypted = cipher(k, s);
    printf("Encrypted: %s\n", encrypted);
    free(encrypted);

    // Additional test cases
    k = 3;
    char s2[] = "101011";
    encrypted = cipher(k, s2);
    printf("Encrypted: %s\n", encrypted);
    free(encrypted);

    k = 2;
    char s3[] = "111111";
    encrypted = cipher(k, s3);
    printf("Encrypted: %s\n", encrypted);
    free(encrypted);

    return 0;
}
