#include<stdio.h>

#define NEWLINE 1
#define TAB 1
#define blank 1

int main(){
    int c = 0;
    int out = 0;
    while((c=getchar())!=EOF){
        if(NEWLINE && c=='\n') ++out;
        if(TAB && c=='\t') ++out;
        if(blank && c==' ') ++out;
    }
    printf("%d \n", out);
    return 0;
}