/*
3. Prime or Not
Given an integer, if the number is prime, return I . Otherwise return
its smallest divisor greater than 1.
Example
n = 24
The number 24 is not prime: its divisors are [1, 2, 3, 4, 6, 8, 12, 24].
The smallest divisor greater than 1 is 2.
Function Description
Complete the function isPrime in the editor below
isPrime has the following parameter(s):
long n:a long integer to test
Return
int: if the number is prime, return 1; otherwise returns the smallest
divisor greater than 1
Constraints : 2<=n<=1012
*/

int isPrime(long n) {
    int divisor = 2;
    int rem = 0;
    //printf("%d \n", n);
    
    if(n==2){
        return 1;
    }
    
    do{
        rem = n%divisor;
        divisor++;
        //printf("Divisor is %d,\tRemainder is %d \n", divisor, rem);
    } while((rem!=0) && (divisor<n));
    
    if (rem==0){
        //printf("Divisor is %d", divisor);
        return divisor-1;
    }
    
    return 1;
}