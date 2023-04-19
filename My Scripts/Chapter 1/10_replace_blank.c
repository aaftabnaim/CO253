#include<stdio.h>

main(){
    int c;
    int lastCharSpace = 0;
    while((c = getchar())!=EOF){
        if(c==' ' && !lastCharSpace){
            putchar(c);
            lastCharSpace = 1;
        }
        else if(c==' ' && lastCharSpace){
            // do nothing 
        }
        else{
            putchar(c);
            lastCharSpace = 0;
        }
    }
}