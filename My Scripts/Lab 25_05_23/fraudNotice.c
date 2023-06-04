#include <stdio.h>
float getmedian(int subArr[], int s){
    int key,j;

    for(int i=1;i<s;i++){
        key = subArr[i];
        j = i-1;
        while(j>=0 && subArr[j]>key){
            //swap
            int t = subArr[j+1];
            subArr[j+1]=subArr[j];
            subArr[j]=t;
            j--;
        }
    }
    for(int i=0;i<s;i++){
        printf("%d, ",subArr[i]);
    }
    
    printf("\n");
    if(s%2==0)return (float)(subArr[s/2-1]+subArr[s/2])/2;

    return subArr[s/2];
}

int activityNotification(int expenditure_count, int* expenditure, int d) {
/*
for last d days 

take median 

// if median > todays expenses increase notices
*/
    int notices=0;
    for(int k=d;k<expenditure_count;k++){
        printf("k id %d\n",k-1);
        int tempArray[d];
        for(int i=0;i<k;i++){
            tempArray[i] = *(expenditure+k-i-1);
        }
        float med = getmedian(tempArray,d);
        if(2*med<=*(expenditure+k)){
            printf("Med:%f \t Spent:%d\t Index:%d\n", 2*med, *(expenditure+k-1), k);
            notices++;
        }
    }
    return notices;
}

int main(void){
    int expenses[] = {2,3,4,2,3,6,8,4,5};
    int n = activityNotification(9,expenses, 5);
    /*
    int test[]={1,2,8,12};
    int ii=getmedian(test,4); 
    printf("%d",ii);   
    */
    printf("%d",n);   

    return 0;
}