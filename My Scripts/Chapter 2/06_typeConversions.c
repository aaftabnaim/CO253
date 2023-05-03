#include<stdio.h>

 /* atoi: convert s to integer */ 
 int atoi(char s[]) 
 { 
 int i, n; 
 n = 0; 
 for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i) 
 n = 10 * n + (s[i] - '0'); 
 return n; 
 }

/* lower: convert c to lower case; ASCII only */ 
 int lower(int c) 
 { 
 if (c >= 'A' && c <= 'Z') 
 return c + 'a' - 'A'; 
 else 
 return c; 
 }

 

 int main(void){
   
    char str[] = "100";
    int o = atoi(str);
    printf("%d \n", o);

    printf("%d", 'a');

    int j = lower(67);
    printf("\nC lowered is --> %c", j);

    // i+f
    int jake = 9;
    float paul = 9.0;
    // running the below print will return an error
    // but notice the type of the product
    //printf(jake*paul);

    //error: array subscript is not an integer
    //str[1.0];
    float r = 5.9;
    int k = r; // no warning 

    /*
    Sign extension means that the leftmost bit of the char is 
    used to fill in the higher bits of the int. If the 
    leftmost bit of the char is 1, then the resulting int 
    will be negative due to the two's complement representation 
    of signed integers.

    Zero extension means that the higher bits of the resulting 
    int are filled with zeros. This will always produce a 
    non-negative int.

    In this code, we define a char variable c with the bit 
    pattern 0xff, which is equivalent to -1 in two's complement 
    representation. We then assign c to an int variable i, and 
    print the value of i.

    On a machine that performs sign extension, the output of 
    this program will be -1, because the leftmost bit of c is
    1 and is used to fill in the higher bits of i. On a
    machine that performs zero extension, the output of this 
    program will be 255, because the higher bits of i are 
    filled with zeros.

    */
    char c_ = 0x80; // try the values of 0x7f and 0x80. What do you notice.
    int i = c_;
    printf("\n \n %d Char to Int %d\n",c_,  i);
   
    /*
    when we use a floating-point value in an expression, 
    it will not be automatically promoted to double precision.
     Instead, it will remain as a float. This can lead to loss 
     of precision in calculations.
    */
    float a = 1.2;
    double b = 2.3;
    float c = a + b;
    //the type of c is float and there may be loss 
    //of precision due to this
    printf("[01] %f %lu", c, (unsigned long) sizeof(a+b)); // here (unsigned long) is a type casting

    float a_ = 1.2;
    double b_ = 2.3;
    //double c_ = (double)a_ + b_;
    //the type of c is float and there may be loss 
    //of precision due to this
    //printf("%f",(double)a_ + b_);

    }