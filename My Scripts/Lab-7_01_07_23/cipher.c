/*
Jack and Daniel are friends. They want to encrypt
their conversations so that they can save themselves
from interception by a detective agency so they
invent a new cipher.
Every message is encoded to its binary
representation. Then it is written down k times,
k-1 bits. Each of the columns
shifted by O, 1
is XQ_Red together to get the final encoded string.
If b = 1001011 and k = 4 it looks like so:

101011      shift O
01001011    shift 1
001001011   shift 2
0001001011  shift 3
1110110100  <- XORed/encoded string s

Now we have to decode the message. We know that
k = 4. The first digit in s = 1 so our output string is
gojng to start with 1. The next two digits are also 1,
so they must have been XORed with O. We know the
first digit of our 4th shifted string is a 1 as well. Since
the 4th digit of s is O, we XOR that with our 1 and
now know there is a 1 in the 4th position of the
original string. Continue with that logic until the end.

Then the encoded message s and the key k are sent
to Daniel.
Jack is using this encoding algorithm and asks Daniel
to implement a decoding algorithm. Can you help
Daniel implement this?
Function Description
Complete the cipher function in the editor below. It
should return the decoded string.
cipher has the following parameter(s):
• k an integer that represents the number of times
the string is shifted
• s. an encoded stnng of binary digits

Input Format
The first line contains two integers n and k, the
length of the original decoded string and the
number of shifts.
The second line contains the encoded string s
consisting of n+k-l ones and zeros.
*/

char* cipher(int k, char* s){
    
    return decoded_string;
}

#include <stdio.h>
char* encStr = "111010101";
int str2bin(char* x);
int decode(int k, char* str);
void printB(unsigned int x);
int inv(int x);
int decode_(int k, char* x);

int main(void){
    int binNum = str2bin(encStr);
    binNum = inv(binNum);
    printB(binNum);
    return 0;
}


int str2bin(char* x){
    int num = 0;
    int j=0;
    while(x[j]!='\0'){
        num = num*2 + (x[j]-'0');
        j++;
    }
    return num;
}


int inv(int x){
    return ~x;
}


void printB(unsigned int x) {
    if (x == 0) {
        printf("0");
        return;
    }

    int flag = 0;  // Flag to track leading zeros

    for (int i = sizeof(x) * 8 - 1; i >= 0; i--) {
        unsigned int bit = (x >> i) & 1;
        if (bit == 1)
            flag = 1;  // Set flag when encountering the first 1

        if (flag == 1)
            printf("%d", bit);
    }
    printf("\n");
}

int decode_(int k, char* x){
    int num = 0;
    int j=k-2;
    // make a dynamic array that can be returned to main
    while(x[j]!='\0'){
        //invert 1's and 0's in x and make it a string
    }
    return num;
}
