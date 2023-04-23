/*
TODO: This coe has an error. The length of the line thats comming out is wrong. Try aand fix that

Variables we have been using thus far are private or local to main
Each local variable in a function comes into existance only when the function is called and
disappers after exiting the function. These variables are therefore called automatic 
variables. 

As an alternative to automatic variables, we can define variables that are external to all functions
They are globally accessible and they can be used instead of argument lists to communicate data between 
functions

int max;
int main(void){
    int len;

    extern int max = 0;
    extern char longest[];

Try and guess the problem in the above code snippet

We get an error

'variable' has both 'extern' and initializer

-----------------------------------
Guess whats special in the below code


char line[MAXLINE], longest[MAXLINE];
int max;

int main(void){
    int len;

    extern int max;
    extern char longest[];

    while((len=getline_(line, MAXLINE))>0)
        if(len>max){
            max= len;
            copy();
        }
    if(max>0)
        printf("%s fo length %d", longest, max);
    return 0;
}

A Decleration simply declares a variable or function. It says that the variable/ function 
exists somewhere in the program, but memory is not allocated to them.
It tells the variable type and for a function its going to say the data types of the arguments, 
their order and the return data type. 
*/

#include <stdio.h>
#define MAXLINE 20

int getline_(char line[], int maxline);

void copy();

char line[MAXLINE], longest[MAXLINE];
int max;

int main(void){
    int len;

    extern int max;
    extern char longest[];

    while((len=getline_(line, MAXLINE))>0)
        if(len>max){
            max= len;
            copy();
        }
    if(max>0)
        printf("%s fo length %d", longest, max);
    return 0;
}

void copy(){
    int i;
    i=0;
    while((longest[i]=line[i])!='\0') ++i;
}


int getline_(char s[], int lim){
    int c,i,j ;

    for(i=0; i< lim -1 && (c=getchar())!=EOF && c!='\n'; i++)
    {
        s[i] = c;
    }

    if(c!=EOF || c!='\n'){
        for(j=i; (c=getchar())!=EOF && c!='\n'; j++);
        s[i] = '\0';
        return i;
        return j;
    }

    if(c=='\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}


