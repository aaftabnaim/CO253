#include <stdio.h>

/*
Because the else part of an if-else is optional,there is an ambiguity when an else if omitted 
from a nested if sequence. This is resolved by associating the else with the closest previous 
else-less if

Important observation whenyou make an array without the braces like below you get

sorted_numbers = {12, 14, 16, 21, 30, 35, 64, 53, 100, 101};

warning: excess elements in scalar initializer
*/

int binsearch(int x, int v[], int n) ;

int main(void){
//colon_if();

int sorted_numbers[] = {12, 14, 16, 21, 30, 35, 64, 73, 100, 101};
int t = 46;
printf(" Found %d @ index %d",t, binsearch(t, sorted_numbers, 10));
}

void ambiguos_if(){
    int n = 3;
    int i;
    int s[] = {4,-3,21,32,-5};
    if (n > 0) 
        for (i = 0; i < n; i++) 
            if (s[i] > 0) { 
            printf("..."); 
            } 
    else 
        printf("error -- n is negative\n"); 
    
}

void colon_if(){
    int a =2;
    int b = 5;
    int z;
    if (a > b) 
        z = a;
    else 
        z = b; 
    printf("%d",z);

}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */ 
 int binsearch(int x, int v[], int n) 
 { 
    int low, high, mid; 
    low = 0; 
    high = n - 1; 
    while (low <= high) { 
        mid = (low+high)/2; 
        if (x < v[mid]) 
            high = mid - 1; 
        else if (x > v[mid]) 
            low = mid + 1; 
        else   
            return mid;
        printf("Mid is at %d\n", mid);
 
    } 
    return -1;   
 } 