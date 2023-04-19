#include<stdio.h>
#include <string.h>

int countDuplicate(int numbers_count, int* numbers) {

    int buckets[numbers_count];
    for (int i = 0; i <= numbers_count; i++) {
        buckets[i] = 0;
    }

    for(int i=0;i<=numbers_count;i++){
        int index = numbers[i];
        buckets[index]++;
    }
    
    int dupCount = 0;
    
    for(int j=0; j<=numbers_count;j++){

        if(buckets[j]>1){
            ++dupCount;
        } 
    }    

    printf("%d ", dupCount);
    return dupCount;
    
}

int main(){
    int numbers[] = {1,3,3,4,4};
    int n = 5;
    countDuplicate(n, numbers);
    return 0;
}