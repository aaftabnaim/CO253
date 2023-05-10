#include <stdio.h>

#define MAXALLOC 1000

static char allocbuf[MAXALLOC];  // Storage space for alloc
static char *allocp = allocbuf;  // Next free position in allocbuf

// alloc: return pointer to n characters
char *alloc(int n) {
    if (allocbuf + MAXALLOC - allocp >= n) {  // Check if there's enough space
        char *p = allocp;
        allocp += n;
        return p;
    } else {
        return NULL;  // Not enough space
    }
}

// afree: release storage pointed to by p
void afree(char *p) {
    if (p >= allocbuf && p < allocbuf + MAXALLOC) {
        allocp = p;
    }
}

int main() {
    // Test cases
    char *ptr1 = alloc(10);  // Allocate 10 characters
    char *ptr2 = alloc(5);   // Allocate 5 characters

    if (ptr1 != NULL && ptr2 != NULL) {
        // Store characters in allocated memory
        for (int i = 0; i < 10; i++) {
            ptr1[i] = 'A' + i;
        }

        for (int i = 0; i < 5; i++) {
            ptr2[i] = 'a' + i;
        }

        // Print the stored characters
        printf("Characters in ptr1: ");
        for (int i = 0; i < 10; i++) {
            printf("%c ", ptr1[i]);
        }
        printf("\n");

        printf("Characters in ptr2: ");
        for (int i = 0; i < 5; i++) {
            printf("%c ", ptr2[i]);
        }
        printf("\n");

        // Release memory in reverse order
        afree(ptr2);
        afree(ptr1);
    }

    return 0;
}
