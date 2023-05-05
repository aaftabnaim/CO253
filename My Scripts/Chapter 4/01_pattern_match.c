#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /* pattern to search for */

int main() 
{
    char line[MAXLINE];
    int found = 0;

    /* read input line by line */
    while (getline(line, MAXLINE) > 0) {
        /* search for pattern */
        if (strindex(line, pattern) >= 0) {
            /* print line if pattern is found */
            printf("%s", line);
            found++;
        }
    }

    /* return number of lines that matched pattern */
    return found;
}

/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
    int c, i = 0;

    /* read characters until end of line or maximum length is reached */
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
        s[i++] = c;
    }

    /* add null terminator to string */
    s[i] = '\0';

    /* return length of line */
    return i;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
    int i, j, k;

    /* iterate through s */
    for (i = 0; s[i] != '\0'; i++) {
        /* compare s starting from i with t */
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            /* do nothing, just loop until end of t or s[j] is different from t[k] */
        }
        
        /* if entire t is found in s starting from i, return the index i */
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }

    /* t not found in s */
    return -1;
}
