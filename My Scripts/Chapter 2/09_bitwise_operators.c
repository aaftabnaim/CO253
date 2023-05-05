#include <stdio.h>
/*
& bitwise AND
| bitwise inclusive OR
^ bitwise exclusive OR
<< left shift
>> right shift
~ one's complement

// Important observation, When you rightshift a number the leading bits are filled with 1's not zeros
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

unsigned setbits_gpt(unsigned x, int p, int n, unsigned y);

int main(void){

    //masking bits

    int n = 0b11010111;
    printf("Before : \t \n");
    print_binary(n);
        n = n & 0b00001111; // sets to zero all but the low-order 4 bits of n
                            // n is now equal to 0b00000111
    printf("\nAfter : \t \n");
    print_binary(n);


    //shifting and ones complement

    int c= 0b010;
    c=c<<1;
    printf("\nThe value of c is now %d",c);
    
    c=c>>1;
    printf("\nThe value of c is now %d\n",c);
    
    // ones complement
    // alsonote that the computer performs integer artimetic in twos complement
    print_binary(c);
    c=~c;
    printf("\nThe value of c is now %u\n",c);
    printf("\nThe value of c is now %d\n",c);
    print_binary(c);

    // size of int is 11111111111111111111111111111111
    //printf("\nThe size of int is %lu", sizeof(c));

    // Excersice 2.6
    printf("\nExcersice 2.6");
    short x1 = 31;
    short y1 = 12;
    printf("\n Input x = ");
    print_binary(x1);    
    printf(", y =");
    print_binary(y1);
    printf("\n");


    print_binary( setbits(x1, 27,3,y1));

    print_binary( setbits_gpt(x1, 27,3,y1));
/*
    Right shifting an unsigned quantity always fits the vacated bits with 
    zero. Right shifting a signed quantity will fill with bit signs (``arithmetic shift'') on some 
    machines and with 0-bits (``logical shift'') on others. 

    // Logical right shift of an unsigned integer
    unsigned int x12 = 0x8f;  // 10001111 binary
    printf("\nx12 is ");
    print_binary(x12);
    printf("\nAfter Shifting :");
    x12 = x12 >> 2;             // shift right by 2 bits
    print_binary(x12);// x is now 00100011 binary (0x23 hex)

    // Logical right shift of a signed integer
    int y12 = -115;           // 10001001 binary (assuming 8-bit two's complement)
    printf("\ny12 is ");
    print_binary(y12);
    printf("\nAfter Shifting :");
    y12 = y12 >> 2;             // shift right by 2 bits
    print_binary(y12);// y is now 11100010 binary (0xe2 hex)
*/

    return 0;
}

unsigned setbits_gpt(unsigned x, int p, int n, unsigned y) {
    unsigned mask = ~(~0 << n) << p;  // create mask to clear n bits at position p
    unsigned cleared_x = x & ~mask;  // clear the n bits in x
    unsigned shifted_y = (y & ~(~0 << n)) << p;  // extract rightmost n bits of y and shift to position p
    return cleared_x | shifted_y;  // OR the cleared x and shifted y to get final result
}


int setbits(x,p,n,y){
    /*
    int rightMask= 1<<(n-1);
    int rightY = y && rightMask;

    int totalSize = sizeof(y)*4;
    rightY = rightY<<(totalSize-n-p);   
    */
    int totalSize = sizeof(y)*8;
    unsigned int rightMask= ~0<<(totalSize-n); //there is a specific reason for using unsigned integers here.Refer ANSCII C pg 47
    //rightMask=~rightMask;
    rightMask = rightMask>>p;

    printf(" ** %u \n",totalSize);
    int out = y<<(totalSize-n);
    out = out>>p;
    return  x&(~rightMask | out);

}