// strlen returns the length of a string excluding the \0 character
#include <stdio.h>
#include <string.h>

enum months {JAN =1.5 , FEB};

int main() {
  char str[] = "Hello, world!";  // define a string
  int len = strlen(str);  // get the length of the string using strlen()

  printf("The length of the string \"%s\" is %d.\n", str, len);  // print the length

  // checking how the enum works
  printf(" The value of FEB is %d \n", FEB);
  return 0;
}
