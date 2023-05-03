#include <ctype.h>
#include <stdio.h>

int htoi(char s[]) {
    int i = 0;
    if (s[i] == '0' && (s[i+1] == 'x' || s[i+1] == 'X')) {
        i += 2;
    }
    int n = 0;
    while (s[i] != '\0') {
        if (isdigit(s[i])) {
            n = n * 16 + (s[i] - '0');
        } else if (isxdigit(s[i])) {
            n = n * 16 + (tolower(s[i]) - 'a' + 10);
        } else {
            break;
        }
        i++;
    }
    return n;
}

int main() {
    char hex1[] = "0xA";
    char hex2[] = "1B";
    printf("%d\n", htoi(hex1)); // Output: 10
    printf("%d\n", htoi(hex2)); // Output: 27
    return 0;
}
