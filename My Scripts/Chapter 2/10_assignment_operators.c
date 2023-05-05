#include <stdio.h>
/*
Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit 
in x. Explain why. Use this observation to write a faster version of bitcount
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

 int bitcount2(unsigned x);


int main(void){
    /*
    If i += ++i were evaluated as i = i + (++i), 
    the behavior would be undefined because i
    would be modified twice between sequence points. 
    However, since i is computed only once in i += ++i, 
    the behavior is well-defined: i is incremented to 1,
    and then added to itself, resulting in i being 2 after 
    the expression is evaluated.
    */
    int i = 3;
    i += ++i;
    printf("i is %d",i);

    int j = 3;
    j = j + j++;
    //j += j++;
    printf("\nj is %d",j);

    printf("\nExcersice 2.9 = ");
    int in = 0b0110101;
    print_binary(bitcount2(in));
    printf("\t %d %u", bitcount(in), bitcount2(in));
//  return 0;

}


/* bitcount: count 1 bits in x */ 
 int bitcount(unsigned x) 
 { 
 int b; 
 for (b = 0; x != 0; x >>= 1) 
 if (x & 01) 
 b++; 
 return b; 
 } 

 int bitcount2(unsigned x){
    int count=0;
    while(x!=0){
    x&= (x-1);
    count++;
    }

    return count;
 }