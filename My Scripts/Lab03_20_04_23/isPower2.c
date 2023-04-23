#include <stdio.h>

char** isPower(int arr_count, int* arr, int* result_count) {
    int tempResult[arr_count];
    
    for(int i=0; i<arr_count;i++){
        tempResult[i] = divBy2(arr[i]);
    }
    
    char** out_ = malloc(sizeof(char*) * arr_count);
    for (int i = 0; i < arr_count; i++) {
        if (tempResult[i] == 1) {
            out_[i] =  strdup("1");
        } else {
            out_[i] =  strdup("0");
        }
    }

    return out_;

}

int divBy2(int num){
    int k = 0;
    int base = num;
    do{
        k = base%2;
        if(k==0) base = base/2;
    }while(k==0 && base!=1);
    if(base==1) {return 1;}
    return 0;
}

int main() {

    int result[5];
    int arr[5] = {1,3,8,12,16};

    char** x = isPower(5,arr,result);
    for(int j=0;j<5;j++){
        printf("%s ", x[j]);
    }
    printf("\n");
    return 0;
}
