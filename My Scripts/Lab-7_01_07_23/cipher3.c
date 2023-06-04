#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* cipher(int k, char* s) {
    int length = strlen(s);
    char* decoded_string = (char*)malloc(length - k + 2);
    decoded_string[length - k + 1] = '\0';

    // Initialize the decoded string with the first character of s
    decoded_string[0] = s[0];

    int i, j;
    for (i = 1; i <= k; i++) {
        for (j = i - 1; j < length; j += k) {
            if (s[j] == '1')
                decoded_string[j / k + 1] = (decoded_string[j / k + 1] == '1') ? '0' : '1';
            else
                decoded_string[j / k + 1] = decoded_string[j / k];
        }
    }

    return decoded_string;
}

int main() {
    int n, k;
    

    char s[n + k];
    scanf("%s", s);

    char* decoded_string = cipher(k, s);
    printf("Decoded String: %s\n", decoded_string);

    free(decoded_string);
    return 0;
}
