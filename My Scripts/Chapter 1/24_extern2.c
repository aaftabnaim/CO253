/*
when a is commented we get a warning for an uninitialized variable

when only line 3 is commented we get an error saying that a variable thats set is not used.

when 2, 3 are commented --> 24_extern2.c: In function ‘main’:
                            24_extern2.c:14:9: warning: unused variable ‘a’ [-Wunused-variable]
                            14 |     int a;                      //---------line 1
                                |         ^

when 1,2 are commented we get an error

when 1 is commented the program throws an error during compilation. var is declared but not defined anywhere.
esentially var is not allocated any memory and the program is trying to change its memory.

*/
#include <stdio.h>

//extern double b;	 // int var; -> declaration and definition
				 // extern int var; -> declaration.No memory is allocated. only the property of the variable is announced

extern float b;

int main()
{
    //float b;                 //---------line 1
    b = 0;                     //---------line 2
	printf("\n %f \n", b);     //---------line 3

return 0;
}
