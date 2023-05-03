#include <stdio.h>
/*
& bitwise AND
| bitwise inclusive OR
^ bitwise exclusive OR
<< left shift
>> right shift
~ one's complement
*/
void print_binary(unsigned int num) {
    int i;
    for (i = sizeof(num) * 8 - 1; i >= 0; i--) {
        if ((num >> i) & 1) {
            printf("1");
        } else {
            printf("0");
        }
    }
}

int main(void){

    int n = 0b11010111;
    printf("Before : \t \n");
    print_binary(n);
        n = n & 0b00001111; // sets to zero all but the low-order 4 bits of n
                            // n is now equal to 0b00000111
    printf("After : \t \n");
    print_binary(n);

    return 0;
}