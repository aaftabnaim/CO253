#include<stdio.h>

int optimalPoint(int magic_count, int* magic, int dist_count, int* dist) {
    int start = 0;  // initial starting point
    int total = 0;  // total magic - total distance

    int remaining = 0;  // remaining magic at current point

    for (int i = 0; i < magic_count; i++) {
        remaining += magic[i] - dist[i];  // add magic and subtract distance
        total += magic[i] - dist[i];

        if (remaining < 0) {  // not enough magic to reach next point
            start = i + 1;  // update starting point
            remaining = 0;  // reset remaining magic
        }
    }

    return (total >= 0) ? start : -1;  // check if a solution exists
}


int optimalPoint(int magic_count, int * magic, int dist_count, int * dist) {

return 0;
}

int main(void){

    
    return 0;
}