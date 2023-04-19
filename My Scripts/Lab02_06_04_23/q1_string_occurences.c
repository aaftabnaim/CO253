#include<stdio.h>

void getDigitFrequency(char* num) {
    char letter='0';
    int stringSize = strlen(num);
    for(int i=0;i<10;i++){
        int counter = 0;
        //printf("Letter is %d ", letter);
        for(int j=0;j<stringSize;j++){
            if(letter==num[j]){
                counter++;
            }
        }
        printf("%d ", counter);
        letter++;
    }
}

int main()
{
    char* num = "lw4n88j12n1";


    getDigitFrequency(num);

    return 0;
}