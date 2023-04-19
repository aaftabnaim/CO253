#include<stdio.h>
main(){
    int c, nl;
    nl=0;

    while((c=getchar())!=EOF)
    if(c=='\n') ++nl;           // a character between single quotes represents an integer value
                                // equal to the numerical value of the character. it is called the dharacter constant
    printf("%d\n", nl);
}
