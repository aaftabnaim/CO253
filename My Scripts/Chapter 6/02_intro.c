#include <stdio.h>

struct point p1 = {5, 7};

void printPoint(struct point p) {
    printf("x: %d, y: %d\n", p.x, p.y);
}

int main() {
    
    printPoint(p1);
    return 0;
}
