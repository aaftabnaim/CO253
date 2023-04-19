#include<stdio.h>

main(){
    int c, skipLine;
    skipLine = 0;
    while((c=getchar())!=EOF){
        if((c==' '||c=='\n'||c=='\t') && !skipLine){
            skipLine = 1;
            printf('\n');
        }
        else if(skipLine && !(c==' '||c=='\n'||c=='\t')){
            putchar(c);
            skipLine=0;
        }
    }
}