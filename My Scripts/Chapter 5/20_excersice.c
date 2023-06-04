#include <stdio.h>

char *names[] = {"aaftab", "naim", "rozani", "azeem"};

char names2[4][10] = {"aaftab", "naim", "rozani", "azeem"};

/* echo command-line arguments; 2nd version */
int main(int argc, char *argv[])
{
    char *p = names;
    char *q = names2[0];
    //p+=3;
    //q+=1;
    char x = *p;
    printf("%s \t %s", *p, q);
    return 0;
}
