#include<stdio.h>

void check_palindrome(long number) {

    long reversed = 0;
    long original = number;

    if(!(number>0)){
        printf("INVALID INPUT\n");
    }
    else{
        while (original != 0) {
            //printf("Num : % \t original : %d \t reversed : %d \n",number,original,reversed);
            reversed = reversed * 10 + original % 10;
            original /= 10;
        }

        //printf("Num : %d \t original : %d \t reversed : %d \n",number,original,reversed);

        if(number==reversed){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }


}

int main(void){
    check_palindrome(-3223);
    return 0;
}