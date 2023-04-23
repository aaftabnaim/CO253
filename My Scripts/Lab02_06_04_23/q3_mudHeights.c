#include<stdio.h>

int maxHeight(int wallPositions_count, int* wallPositions, int wallHeights_count, int* wallHeights) {
    
    for(int j =wallPositions_count-1;j>=0;j--){
        // check for missing wall index
        int currentWallIndex = wallPositions[j];
        if((currentWallIndex-wallPositions[j-1])!=1){
            return wallHeights[j]-1;
        }
        //get the height of the previous wall
    }
    return 0;
}

int main(){
    int wallPositions[] = {1,3,7};
    int wallHeights[] = {4,3,3};
    int x = maxHeight(3,wallPositions, 3, wallHeights);
    printf("%d ", x);
    return 0;
}