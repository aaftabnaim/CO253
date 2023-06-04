#include <stdio.h>
/*
Louise and Richard have developed a numbers
game. They pick a number and check to see if it is a
power of 2. If it is, they divide it by 2. If not, they
reduce it by the next lower number which is a power
of 2. Whoever reduces the number to 1 wins the
game. Louise always starts.
Given an initial value, determine who wins the game.

Example
n = 132
It's Louise's turn first. She determines that 132 is not
a power of 2. The next lower power of 2 is 128, so
she subtracts that from 132 and passes 4 to Richard.
4 is a power of 2, so Richard divides it by 2 and
passes 2 to Louise. Likewise, 2 is a power so she
divides it by 2 and reaqhes 1. She wins the game.

Update If they initially set counter to 1, Richard
wins. Louise cannot make a move so she loses.
Function Description
Complete the counterGame function in the editor
below.
counterGame has the following parameter(s):
• int n: the initial game counter value
Returns
• string: either Richard or Louise
Input Format
The first line contains an integer t, the number of
testcases.
Each of the next t lines contains an integer n, the
initial value for each game.
Constraints

*/

const char* counterGame(int n);
int powerTwo(int p);
int r_powerTwo(int x);

int main(void){
    printf("%s", counterGame(140));
    return 0;
}

const char* counterGame(int n){

    char* strL = "Louise";
    char* strR = "Richard";
    int turn = 1;
    if(n==1) return strR;
    while(n!=1){
        if(powerTwo(n)){
            n/=2;
        }
        else
        {
            n = n-r_powerTwo(n);
        }
        turn = (turn+1)%2;
        //printf("%d", turn);
    }
    if(turn==1) return strR;
    return strL;

}


int powerTwo(int p){
    //printf("%d\n", p);
    if(p==0) return 0;
    while(p%2==0){
        p = p/2;
        if(p==1){
            return 1;
        }
    }
    return 0;
}

int r_powerTwo(int x){
    if(x==0) return 0;
    while(!powerTwo(x) && x!=0)x--;
    return x;
}