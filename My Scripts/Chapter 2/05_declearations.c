#include <stdio.h>

//Section A

/* Declaration of a variable */
extern int x;

/* Declaration and definition of a function */
int add(int a, int b) {
  return a + b;
}

/* Definition of a variable */
int x = 10;

//Section B

int a;
const int s[] = {1,2,3};
/* error: initializer element is not constant */
//int b = a;

int example_auto(){
    /*
    Try out the differebt initializations to see how the automatic and static
    variables behave
    */
    //int foo = 0;
    static int foo = 0;
    foo++;
    return foo;
}

int main(void){
    /* error: initializer element is not constant */
    //static int c =a;

    // only d is an automatic varible. Only automatic variables are allowed to 
    // be intializaed with another varible. External and static variables 
    // cannot be initialized with non-constant variables
    int d = a;
    ++d;
    printf("%d \t %d", a, d);
    
    // auto is there by default 
    auto int j = example_auto();
    int k = example_auto();

    printf("\n %d \t %d\n", j, k);

    /*
    notice how this print doesn't work. 
    foo is static and is intialized only once 
    but it isn't a global variable

    printf("\n %d \t %d \t %d\n", j, k, foo);
    */ 

   /*
   error: assignment of read-only location ‘s[2]’
   */
   //s[2] = 5;
   /*
   Unary operators --> -a, --b have a higher precedence
   than binary operators, 
   then comes the binary operators which go as
   * / %
   + -
   Operators withth same precedence are evaluated left to right
   
   */
    int sa = --k -2;
    printf("The value of sa is %d", sa);
    return 0;
}