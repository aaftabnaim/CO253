#include <stdio.h>
#include <string.h>

#define MAXLINES 5000     // max #lines to be sorted
#define MAXLEN 1000       // max length of any input line

char *lineptr[MAXLINES];   // pointers to text lines
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
void swap(char *v[], int i, int j);
int my_getline(char *line, int maxline);

//#define BASIC
int main()
{
    
    #ifdef BASIC
    printf("Im here");
    int nlines;    // number of input lines read

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
    #else
    printf("Im here 2\n");
    int x = 10;
    int* p = &x; // Pointer p holds the address of variable x
    int** pp = &p; // Pointer pp holds the address of pointer p
    
    printf("Value of x: %d\n", **pp); // Output: 10
    return 0;
    #endif
}

int my_getline(char *line, int maxline)
{
    int c, i;
    
    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    
    if (c == '\n')
    {
        line[i] = c;
        i++;
    }
    
    line[i] = '\0';
    
    return i;
}


int readlines(char **lineptr, int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    nlines = 0;

    while ((len = my_getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || nlines >= MAXLINES) {
            return -1;
        } else {
            line[len - 1] = '\0';  // delete newline
            lineptr[nlines] = strdup(line);
            nlines++;
        }
    }

    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    for (int i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

void qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++) {
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }

    swap(v, left, last);

    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
