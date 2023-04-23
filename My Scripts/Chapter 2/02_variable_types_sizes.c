#include<stdio.h>
#include<limits.h>
#include<float.h>
/*
When a variable is declared as "unsigned," it means that its value can only be positive or zero. For example,
if we have an unsigned char variable, its value can range from 0 to 255 if chars are 8 bits in size. 
The arithmetic for unsigned numbers follows the laws of arithmetic modulo 2n, where n is the number of bits
in the type. This means that if an operation would result in a number greater than the maximum value
representable by the type, it wraps around to the minimum value.

On the other hand, when a variable is declared as "signed," it can take on both positive and negative values. 
If we have a signed char variable, its value can range from -128 to 127 in a two's complement machine. 
Two's complement is a method of representing signed integers using binary notation, where the leftmost 
bit represents the sign (0 for positive, 1 for negative) and the remaining bits represent the magnitude of the number.

Whether plain chars are signed or unsigned is machine-dependent, meaning it can vary depending on the
system being used. However, printable characters are always represented by positive values, regardless
of whether they are signed or unsigned.

*/

int main(void){
  printf("Value of UNIT_MAX  is %u \n", UINT_MAX);
  printf("Value of UINT_MAX+1  is %u \n", UINT_MAX+1);
  
  printf("Value of INT_MAX  is %d \n", INT_MAX);
  printf("Value of INT_MIN  is %d \n", INT_MIN);
  
  printf("Value of CHAR_MAX  is %d \n", CHAR_MAX);
  printf("Value of CHAR_MIN  is %d \n", CHAR_MIN);

  printf("Size of float: %lu bytes\n", (unsigned long) sizeof(float));
  printf("Size of double: %lu bytes\n", (unsigned long) sizeof(double));

  return 0;
}