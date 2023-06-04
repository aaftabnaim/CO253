#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* cipher(int k, char* s) {
    int n = strlen(s);
    char* t = (char*)malloc(sizeof(char) * (n + k - 1));
    int* r = (int*)malloc(sizeof(int) * n);

    // Copy s to t, shifting the characters by k - 1 positions
    for (int i = 0; i < k - 1; i++) {
        t[i] = '0';
    }
    for (int i = 0; i < n; i++) {
        t[i + k - 1] = s[i];
    }

    r[0] = t[0] - '0';
    for (int i = 1; i < k; i++) {
        r[i] = (t[i - 1] - '0') ^ (t[i] - '0');
    }

    for (int i = k; i < n; i++) {
        r[i] = r[i - k] ^ (t[i - 1] - '0') ^ (t[i] - '0');
    }

    for (int i = 0; i < k; i++) {
        r[n - 1 - i] = (t[n + k - 2 - i] - '0') ^ (t[n + k - i - 1] - '0');
    }

    // Convert the result array r back to a string
    char* result = (char*)malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) {
        printf("%d", r[i]);
        result[i] = r[i] + '0';
    }
    result[n] = '\0';
    printf("\n");
    free(t);
    free(r);

    return result;
}

int main() {
    int k = 4;
    char s[] = "1110101001";

    char* encrypted = cipher(k, s);
    printf("Encrypted: %s\n", encrypted);
    
    free(encrypted);

    return 0;
}
