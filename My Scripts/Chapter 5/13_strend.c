#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/* strend: return 1 if t occurs at the end of s, 0 otherwise */
int strend(char *s, char *t)
{
  int slen = strlen(s);
  int tlen = strlen(t);
  
  if (tlen > slen) /* t is longer than s */
    return 0;
    
  s += slen - tlen; /* move s to the end of t in s */
  
  while (*s && *t) /* compare s and t */
    if (*s++ != *t++)
      return 0;
      
  //return 1;
  return (*t == '\0'); /* t matches the end of s */
}

int main() {
  char s1[] = "Hello, world!";
  char t1[] = "world!";
  printf("Test Case 1: %d\n", strend(s1, t1)); // Output: 1

  char s2[] = "OpenAI";
  char t2[] = "AI";
  printf("Test Case 2: %d\n", strend(s2, t2)); // Output: 1

  char s3[] = "Hello";
  char t3[] = "world";
  printf("Test Case 3: %d\n", strend(s3, t3)); // Output: 0

  char s4[] = "Hello";
  char t4[] = "lo";
  printf("Test Case 4: %d\n", strend(s4, t4)); // Output: 1

  char s5[] = "";
  char t5[] = "";
  printf("Test Case 5: %d\n", strend(s5, t5)); // Output: 1

  return 0;
}
