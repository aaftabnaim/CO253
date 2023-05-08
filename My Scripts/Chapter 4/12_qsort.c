#include <stdio.h>

/*

Watch this to understand clearly :
https://www.youtube.com/watch?v=Hoixgm4-P4M&ab_channel=MichaelSambol

*/
/* Function declarations */
void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

/* Test case */
int main() {
    int array[] = {9, 2, 5, 1, 7, 4, 8, 3, 6};
    int size = sizeof(array) / sizeof(array[0]);
    
    printf("Before sorting: ");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
    
    /* Call qsort to sort the array */
    qsort(array, 0, size - 1);
    
    printf("After sorting: ");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
    
    return 0;
}

/* Recursive qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right) {
    int i, last;
    
    /* Base case: If array contains fewer than two elements, do nothing */
    if (left >= right)
        return;
    
    /* Move the partition element to the beginning of the subarray */
    swap(v, left, (left + right) / 2);
    last = left;
    
    /* Partition the subarray */
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left])
            swap(v, ++last, i);
    }
    
    /* Restore the partition element to its correct position */
    swap(v, left, last);
    
    /* Recursively sort the left and right subsets */
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
