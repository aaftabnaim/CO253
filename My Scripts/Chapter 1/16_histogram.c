#include <stdio.h>
//#define horizontal
/*
This program prints a histogram of the lengths of words in its input. 
Input 1 - "Aaftab is the best Roboticist"
Output 1 -  0 
            1
            2 *
            3 *
*/
int main(void){

    int c = 0;
    int word_lengths[20];
    int current_length = 0;

    for(int i=0;i<20;i++){
        word_lengths[i] = 0;
    }
    while((c  = getchar())!= EOF){
        if((c==' '|| c=='\t' || c=='\n')){
            if(current_length!=0){
                ++word_lengths[current_length];
                current_length = 0;
                }
            }
        else{
            ++current_length;
        }
    }

    // after CTRL+D is pressed
    #ifdef horizontal
    for(int j=0; j<20;j++){
    printf("%d\t--> ",j);
    for(int k=0;k<word_lengths[j];k++)
        printf("*");
    printf("\n");
    }
    #else
    // for each row in the matrix 
    // for each column in 
    int maxWordLen = 20;
    int maxOccur = 20;
    int outMatrix[maxWordLen][maxOccur];
    for(int r=0;r<maxWordLen;r++){
        for(int c=0;c<maxOccur;c++){
            if(c<word_lengths[r])
            outMatrix[r][c] = 1;
            else
            outMatrix[r][c] = 0;
        }
    }
    

    for(int c=0;c<maxOccur;c++){
        for(int r=0;r<maxWordLen;r++){
            if(outMatrix[r][maxOccur-1-c]==1)
                printf("*\t");
            else
                printf(" \t");
        }
        printf("\n");
    }
    for(int r=0;r<maxWordLen;r++)
    printf("%d\t",r);
    printf("\n");
    #endif
    return 0;
}