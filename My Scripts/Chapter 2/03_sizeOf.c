#include<stdio.h>
#include<limits.h>

int i = 9;
int j = 011;
int y = INT_MAX+5;
float i_f = 1.8947;
int main(void){
// Notice how the program return 4 bytes as the answer for each of the below 3 prints
// Notice that the program returns warning for having %d in the printf and when the sizeof parameter returns an unsigned long int
printf("the data type of variable i is %d bytes \n", sizeof(i));
printf("the data type of variable y is %d bytes \n", sizeof(y));
printf("the data type of variable float i holding %f is %d bytes \n", i_f, sizeof(i_f));
int z = y+1;
printf("the data type of variable y+1 is %d bytes \n", sizeof(z));

//notice how the int wraps around itself in this case
printf("the data of variable y+1 is %d bytes \n", (z));
++z;
printf("the data of variable y+2 is %d bytes \n", z);

// to print the variable defined in octal
printf("the data of variable j is %d  \n", j);

//vertical tab
printf("**%c%c*", '\013', '\013');

//bell
printf("\n The bell character %c%c ", '\007', '\007');

// note how that printf prints the octal number
// also note how the compiler ignores everything after the null character
printf("\n In octal --> %d \0 \n In hexadecimal --> %d", '\042', '\x16');

}