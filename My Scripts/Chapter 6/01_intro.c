#include <stdio.h>
 struct point { 
 int x; 
 int y; 
 }; 

 struct { 
 int x; 
 int y; 
 } a, b, c; 

int main(void){
    //generally accepted way. point(structure tag) is optional
    struct point s1;
    s1.x = 10;
    s1.y = 11;
    printf("x= %d \t y= %d\n", s1.x, s1.y);

    // alternate way to declare structs
    a.x = 10;
    a.y = 11;
    printf("x= %d \t y= %d", a.x, a.y);
}