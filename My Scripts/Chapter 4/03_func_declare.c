#include <stdio.h>

/*
when multiply is an int
(when commented)warning: implicit declaration of function 'multiply' [-Wimplicit-function-declaration]

error: conflicting types for 'multiply'
float multiply(int x, int y) {
       ^~~~~~~~
03_func_declare.c:6:16: note: previous implicit declaration of 'multiply' was here
   int result = multiply(3, 5);

If a name that has not been previously declared occurs in an expression and is followed by a 
left parentheses, it is declared by context to be a function name, the function is assumed to 
return an int, and nothing is assumed about its arguments.

*/

//int multiply(int x, int y);  



/*
when parameter checking is  turned off the 
int parameter_test();

int parameter_test(float a,float b){
    return a+b;
}

03_func_declare.c: At top level:
03_func_declare.c:50:5: error: conflicting types for 'parameter_test'
 int parameter_test(float a,float b){
     ^~~~~~~~~~~~~~
03_func_declare.c:50:1: note: an argument type that has a default promotion can't match an empty parameter name list declaration
 int parameter_test(float a,float b){
 ^~~
03_func_declare.c:21:5: note: previous declaration of 'parameter_test' was here
 int parameter_test();// works since empty () means parameter checking is turned off
     ^~~~~~~~~~~~~~

*/
int parameter_test();// works since empty () means parameter checking is turned off
//int parameter_test(int a);// throws an error: too many arguments to function 'parameter_test'
//int parameter_test(int a,int b); // works


int main() {
  int result = multiply(3, 5, 4); // any amount of paremeters can be passed
  printf("Result: %d\n", result);

  int r = parameter_test(1,2);
  printf("\n%d",r);
  return 0;
}

// Only a warning saying an implicit declearation was made
//when 3.0 and 5.0 were passed as arguments the function recieves 0 instead of 3
int multiply(int x, int y) {
    return x * y;
}

// error saying conflicting types were recieved
int multiply1(float x, float y) {
  return x * y;
}
// error saying conflicting types were recieved even when result is declared as a float
float multiply2(float x, float y) {
  return x * y;
}

int parameter_test(int a,int b){
    return a+b;
}