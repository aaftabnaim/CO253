#include <stdio.h>
#include <stdlib.h>

void clearTerminal() {
    system("pause");
}

int main() {
    printf("This is some text.\n");
    clearTerminal();
    printf("Terminal cleared.\n");

    return 0;
}
