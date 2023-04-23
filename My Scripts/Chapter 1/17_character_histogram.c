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
    int charSize = ('z'-'a'+1)+('9'-'0'+1);
    int charBucket[charSize];

    for(int i=0;i<charSize;i++){
        charBucket[i] = 0;
    }
    while((c  = getchar())!= EOF){
        if(c>='0' && c<='9')
        ++charBucket[c-'0'];
        
        if(c>='a' && c<='z')
        ++charBucket[c-('a'-('9'-'0'))+1];

        if(c>='A' && c<='Z')
        ++charBucket[(c-32)-('a'-('9'-'0'))+1];
    }

    // after CTRL+D is pressed
    #ifdef horizontal
    #TODO
    for(int j=0; j<20;j++){
    printf("%d\t--> ",j);
    for(int k=0;k<word_lengths[j];k++)
        printf("*");
    printf("\n");
    }
    #else
    int maxWordLen = charSize;
    int maxOccur = 50;
    int outMatrix[maxWordLen][maxOccur];
    for(int r=0;r<maxWordLen;r++){
        for(int c=0;c<maxOccur;c++){
            if(c<charBucket[r])
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

    int start0 = '0';
    for(int r=start0;r<='9';r++)
    printf("%c\t",r);

    int startA = 'a';
    for(int r=startA;r<='z';r++)
    printf("%c\t",r);   

    printf("\n");
    #endif
    return 0;
}