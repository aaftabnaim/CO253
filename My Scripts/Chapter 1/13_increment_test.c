#include<stdio.h>

main(){
    int i = 0;
    printf("For the i++\nI is now :\t%d\n", i);
    i = i++;
    printf("I is now :\t%d\n", i);
    int j = 0;
    printf("For the ++j \nJ is now :\t%d\n", j);
    j = ++j ;
    printf("J is now :\t%d\n", j);
}