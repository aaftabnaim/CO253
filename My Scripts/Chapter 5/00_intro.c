/*
In a computer, we have a special place called memory 
where we can store and manipulate information. Think 
of memory as a big container with numbered slots. Each 
slot can hold a small piece of information, like a 
number or a letter.

Now, imagine we have a variable called "c" that represents 
a single letter or character. We also have another variable 
called "p," which is a special kind of variable called a 
pointer. A pointer can hold the address of another variable 
in memory, which means it can point to where that variable is stored.

To represent this situation, we can imagine "c" as a box with a 
letter inside, and "p" as a signpost that points to that box.

To make "p" point to "c," we use the "&" symbol, which gives us 
the address of "c." So the line of code "p = &c;" means we're 
assigning the address of "c" to the variable "p." Now "p" is pointing to "c."

To access the value of "c" using the pointer "p," we use the "*" symbol. 
It's like following the signpost to reach the box. So the line of code "y = *ip;"
means we're taking the value inside the box that "p" is pointing to and storing it in the variable "y." In this case, the value inside "c" is 1, so now "y" becomes 1.

We can also change the value of "c" using the pointer "p." The line of code
"*ip = 0;" means we're going to the box that "p" is pointing to ("c") and
changing the value inside it to 0. So now "c" becomes 0.

Lastly, we can make the pointer "p" point to a different variable.
For example, if we have an array called "z," which is a collection
of several variables, we can make "p" point to the first variable
in that array. The line of code "ip = &z[0];" means we're assigning
the address of the first variable in the array "z" to the variable
"p." Now "p" is pointing to "z[0]."
*/

int x = 1, y = 2, z[10];   // Declare some variables: x, y, and z

// Declare a pointer variable called "ip" that can hold the address of an int
// * is called the indirection or dereferencing operator
// when applied to a pointer it accesses the object the pointer points to 
int *ip;                   



int main(void){
    // & is called the address of operator
    ip = &x;                   // Make "ip" point to the variable "x"
    printf("x:%d \t y:%d\n", x, y);

    y = *ip;                   // Get the value inside the variable "x" through the pointer "ip" and store it in "y"
    printf("x:%d \t y:%d\n", x, y);

    *ip = 0;                   // Change the value inside the variable "x" to 0 through the pointer "ip"
    printf("x:%d \t y:%d\n", x, y);

    ip = &z[0];                // Make "ip" point to the first variable in the array "z"
    printf("x:%d \t y:%d\n", x, y);

    return 0;
}

/*
Explanation: Here, we declare a pointer variable called dp using 
the syntax double *dp;. This means that dp is a pointer to a double 
(double). We also declare a function called atof that takes a pointer 
to a char (char *) as an argument and returns a double value. 
So, the declaration atof(char *) states that atof is a function that 
takes a char pointer as an argument and returns a double value. 
The declaration of dp and atof are separate, and the syntax shows 
the return type of atof and the type that dp points to.

*/
double *dp, atof(char *);   // Declare a pointer variable dp and a function atof

