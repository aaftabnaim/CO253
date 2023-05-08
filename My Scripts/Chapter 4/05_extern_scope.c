#include <stdio.h>

/*
05_extern_scope.c:8:12: warning: 'val' initialized and declared 'extern'

the "author" of the warning believed that extern specifier should be reserved 
for non-defining declarations. In this case the presence of initializer = 0 turns 
the declaration into a definition (and thus formally makes that extern optional). 

Please note that in the following code ,

extern int val = 0;
val = 2;

the second sentence val = 2 redefines the extenal variable into an int
by automatic decleartion
*/

extern float val = 0.5;
// val = 5; this behaves like a seperate declaration

/*
05_extern_scope.c:20:1: warning: data definition has no type or storage class
 val = 5;
 ^~~
*/

int main(){

    printf("%f", val);
    //val = 2.0;
    testCase();
    return 0;
}

/*
if declared here the external variable is visible only  to the functions below it
*/
//extern int val = 10;



void testCase(){
    val = 10.0;
    printf("\ntestCase says %f", val);
}


