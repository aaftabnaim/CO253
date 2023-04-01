#include <stdio.h>


void fizzBuzz(int n) {
    for(int i=0; i<=n;i++){
        int div3 = i%3;
        int div5 = i%5;
                
        if(div3==0){
            printf("Fizz");
        }
        if(div5==0){
            printf("Buzz");
        }
        if(!(div3==0) && !(div5==0)){
            printf("%d",i);
        }
        printf("\n");
        
    }
}
int main()
{

    fizzBuzz(15);

    return 0;
}