#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_results(char** results, int num) {
    printf("Results:\n");
    for (int i = 0; i < num; i++) {
        printf("%s ", results[i]);
    }
    printf("\n");
}

char** triangleOrNot(int a_count, int* a, int b_count, int* b, int c_count, int* c, int* result_count) {
    *result_count = a_count;
    char** results = malloc(a_count * sizeof(char*));
    
    for (int i = 0; i < a_count; i++) {
        if ((a[i] + b[i] > c[i]) && (a[i] + c[i] > b[i]) && (b[i] + c[i] > a[i])) {
            *(results + i) = "Yes";
        } else {
            *(results + i) = "No";
        }
    }
    
    return results;
}

void test_triangleOrNot() {
    int a[] = {3, 4, 5};
    int b[] = {4, 5, 6};
    int c[] = {5, 6, 7};
    int result_count;

    char** results = triangleOrNot(3, a, 3, b, 3, c, &result_count);
    
    if (result_count != 3) {
        printf("Test case 1 failed: Incorrect result count\n");
        return;
    }

    if (strcmp(results[0], "Yes") != 0 || strcmp(results[1], "Yes") != 0 || strcmp(results[2], "Yes") != 0) {
        printf("Test case 1 failed: Incorrect results\n");
        return;
    }
    
    printf("Test case 1 passed!\n");
    print_results(results, result_count);

    // Free the memory allocated for results
    for (int i = 0; i < result_count; i++) {
        free(results[i]);
    }
    free(results);
}

int main() {
    test_triangleOrNot();
    return 0;
}
