#include <stdio.h>

float power(int , int ); // function prototype. parameter names need not correspond. 
                           // float power(int, int); also would have done the job
int main(void){
    
    printf("%d raised to %d is %f \n", 2, 4, power(2,4));

    return 0;
}


float power(int base, int n){
    int i, p;
    p=1;
    for(i=1;i<=n; ++i)
        p = base*p;
    return p;
}