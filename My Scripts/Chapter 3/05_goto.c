#include <stdio.h>
/*
Pay close attention to the scope of i,j when they are initialized in the 
for loop


*/

int f1(void);
int f(void);

int main(void){
    //f1();
    f1(); //try f1 without the braces
}
/*
Try this

int f1(void){
    //int i, j;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 5 && j == 5) {
                goto exit_loop;
            }
        }
    }
    exit_loop:
    //printf("Exited loop at i = %d and j = %d\n", i, j);

    
    return 0;
}

*/
int f1(void){
    int i, j;
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (i == 5 && j == 5) {
                goto exit_loop;
            }
        }
    }
    exit_loop:
    printf("Exited loop at i = %d and j = %d\n", i, j);

    
    return 0;
}

int f2(void){
    int found = 0;
    int i,j;

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (i == 5 && j == 5) {
                found = 1;
                if(found) break;
            }
        }
        if(found) break;
        printf("%d", i);
    }

    if (found) {
    printf("Exited loop at i = %d and j = %d\n", i, j);
    } else {
    printf("Value not found in loop\n");
    }

}