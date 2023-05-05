#include<stdio.h>

int* getCount(int arr_count, int* arr, int* result_count) {
    int* result = (int*)malloc(arr_count * sizeof(int));
    *result_count = arr_count;

    for (int i = 0; i < arr_count; i++) {
        int count = 0;

        for (int j = 0; j < arr_count; j++) {
            if (i != j && (arr[i] % arr[j] == 0 || arr[j] % arr[i] == 0)) {
                count++;
            }
        }

        result[i] = count;
    }

    return result;
}

int main(void){

    
    return 0;
}