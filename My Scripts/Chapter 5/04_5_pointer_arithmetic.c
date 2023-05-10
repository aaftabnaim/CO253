#include <stdio.h>

int x[] = {1,2,3,4};

int main(void){
    

    for(int i=0; i<4;i++){
        printf("Pointer at %p\t Val\t %d\n", &x[i], x[i]);
    }

    int *ip =  0;
    ip = x;
    int count = 0;
    for(; count<4;count++, ip+=1){
        printf("Pointer at %p\t Val\t %d\n", ip, *ip);
    }

    return 0;
}