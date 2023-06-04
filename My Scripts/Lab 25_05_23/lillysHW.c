#include <stdio.h>

void swap(int* a1, int* a2){
    int temp = *(a1);
    *(a1) = *(a2);
    *a2 = temp;
}
int lilysHomework(int arr_count, int* arr) {
    int key, j;
    int count=0;

    int originalArray[arr_count];
    for(int i=0;i<arr_count;i++){
        originalArray[i] = *(arr+i);
    }

    for(int i=1;i<arr_count;i++){
        key = *(arr+i);
        j = i-1;
        while(j>=0 && *(arr+j)>key){
            swap(arr+j+1, arr+j);
            j--;
        }
    }

    for(int i=0;i<arr_count;i++){
        if(originalArray[i]!=*(arr+i))count++;
    }

    return count/2;   
}

int myArr[] = {1,3,2,4,6,5,7,8,10,9};

int main(void){
    int c = lilysHomework(10,myArr);
    //swap(myArr, &myArr[3]);
    
    for(int i=0;i<10;i++){
        printf("%d \t", myArr[i]);
    }    
    
    printf("Counts is %d", c);
    return 0;
}

/*
procedure insertionSort(arr):
    for i = 1 to n-1
        key = arr[i]
        j = i-1
        while j >= 0 and arr[j] > key
            swap arr[j+1] with arr[j]
            j = j - 1
        end while
    end for
end function
*/