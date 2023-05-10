#include <stdio.h>
/*
If one is sure that the elements exist, it is also possible to
index backwards in an array; p[-1], p[-2], and so on are 
syntactically legal, and refer to the elements that 
immediately precede p[0]. Of course, it is illegal to refer
to objects that are not within the array bounds.
*/
int y[] = {1,23,443,1231};

int main(void){
    int *p = &y[3];
    printf("%d\n", *(p-1));
    printf("%d\n", *(p-2));
    printf("%d\n", *(p-3));
    return 0;
}