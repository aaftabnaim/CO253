#include <ctype.h> 
#include <stdio.h> 

int atoi(char s[]);

int main() {

    int test1[] = {5, 4, 3, 2, 1};
    shellsort(test1, 5);
    printf("Test 1 output: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", test1[i]);
    }
    printf("\n");
    
    int test2[] = {1, 3, 2, 4, 5};
    shellsort(test2, 5);
    printf("Test 2 output: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", test2[i]);
    }
    printf("\n");

    return 0;
}


/* atoi: convert s to integer; version 2 */ 
int atoi(char s[]) 
{ 
    int i, n, sign; 

    /* skip white space */
    for (i = 0; isspace(s[i]); i++) 
        ;

    /* set sign */
    sign = (s[i] == '-') ? -1 : 1; 

    /* skip sign */
    if (s[i] == '+' || s[i] == '-') 
        i++; 

    /* calculate integer value */
    for (n = 0; isdigit(s[i]); i++) 
        n = 10 * n + (s[i] - '0'); 

    return sign * n; 
}

/* 
    shellsort: sort v[0]...v[n-1] into increasing order 
    using the shell sort algorithm.
    shell sort is not stable
    butit is in place 
*/
void shellsort(int v[], int n) 
{ 
    int gap, i, j, temp; 

    // Loop over gaps of decreasing size until the gap is 0.
    for (gap = n/2; gap > 0; gap /= 2) {

        // Perform an insertion sort for the current gap size.
        for (i = gap; i < n; i++) {

            // Compare elements that are 'gap' distance apart and 
            // swap them if they are out of order.
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) { 
                temp = v[j]; 
                v[j] = v[j+gap]; 
                v[j+gap] = temp; 
            } 
        }
    }
}
