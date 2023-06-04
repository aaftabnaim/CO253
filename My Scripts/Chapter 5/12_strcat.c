#include <stdio.h>

/* strcat: concatenate t to end of s; pointer version */ 
void strcat_m(char *s, char *t) 
{ 
  while (*s) /* find end of s */ 
    s++; 
  while ((*s++ = *t++)) /* copy t */ 
    ; 
}

int main() {
  char s[50] = "Hello, ";
  char t[] = "world!";

  printf("Before strcat: %s\n", s);
  strcat_m(s, t);
  printf("After strcat: %s\n", s);

  return 0;
}
