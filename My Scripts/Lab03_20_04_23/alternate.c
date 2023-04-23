#include<stdio.h>

int minOperations(int arr_count, int* arr[]) {

    int fLowCount = 0;
    for(int i=1;i<arr_count;i++){
        if(i%2!=0){
            if(!(arr[i]<arr[i-1]))++fLowCount;
        }
        else if(i%2==0){
            if(!(arr[i]>arr[i-1]))++fLowCount;
        }
    }

    int fHighCount = 0;
    for(int i=1;i<arr_count;i++){
        if(i%2!=0){
            if((arr[i]<arr[i-1]))++fHighCount;
        }
        else if(i%2==0){
            if((arr[i]>arr[i-1]))++fHighCount;
        }
    }
    printf("%d vs %d\n", fLowCount, fHighCount);
    if(fLowCount>=fHighCount) return fHighCount;
    return fLowCount;

}

int main(void){
    int* arr[] = {2,1,2,3,4,5,2,9};
    printf("%d \n", minOperations(8, arr));
    return 0;
}
