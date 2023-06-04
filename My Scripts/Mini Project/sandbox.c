#include <stdio.h>
int atoi(char s[]) 
 { 
 int i, n, sign; 
 for (i = 0; s[i]==' '; i++) /* skip white space */ 
 ; 
 sign = (s[i] == '-') ? -1 : 1; 
 if (s[i] == '+' || s[i] == '-') /* skip sign */ 
 i++; 
 for (n = 0; s[i]>='0' && s[i]<='9'; i++) 
 n = 10 * n + (s[i] - '0'); 
 return sign * n; 
 } 

int main() {

    printf("%d\n", atoi("0984"));
    return 0;
}
