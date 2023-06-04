#include <stdio.h>

int bin2dec(char *dec_p){
    int dec = 0;
    while(*dec_p){
        //printf(". --> %d", (*dec_p-'0'));
        dec = dec*2 + (*dec_p-'0');
        dec_p++;
    }
    return dec;
}

int main(void){
    char binNum1[] = "00100111";
    char binNum2[] = "00110111";

    int decNum1 = bin2dec(binNum1);
    int decNum2 = bin2dec(binNum2);

    printf("%s in binary is %d in decimal\n",binNum1, decNum1);
    printf("%s in binary is %d in decimal\n",binNum2, decNum2);
    return 0;
}
