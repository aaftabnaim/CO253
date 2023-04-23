/*
previously i had defined a function as int getline() and i got the following error

conflicting types for 'getline'; have 'int()'

what was wrong with this is that in C getline is a standard library function 


Note the while loop in the main function.
It has no {} to guard it and has an entire if statement inside it

Notice how the getline function adds the '\0'(null character, whose value is zero) at the end of the array 
it is creating, to mark the end of the string characters
This conversion is used in standard C. The %s format specification in printf expects an array of characters 
containing the characters in this form.

another important point is how the array is accessed in the function. From this it is clear that the value 
passed to the function is the locatio nor the address of the beginning of the array- there is no copyin gof array 
elements

*/

#include <stdio.h>
#define MAXLINE 25

int getline_(char line[], int maxline);
void copy(char to[], char from[]);

int main(void){
    int len, max;
    char line[MAXLINE], longest[MAXLINE];

    max = 0;
    

    while((len=getline_(line, MAXLINE))>0)
        if(len>max){
            max= len;
            copy(longest, line);
        }
    if(max>0)
        printf("%s\n", longest);
    return 0;
}

void copy(char to[], char from[]){
    int i;
    i=0;
    while((to[i]=from[i])!='\0') ++i;
}

int getline_(char s[], int lim){
    int c,i;

    for(i=0; i< lim -1 && (c=getchar())!=EOF && c!='\n'; i++)
    s[i] = c;
    // why is this here??
    
    if(c=='\n'){
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';
    return i;
}


