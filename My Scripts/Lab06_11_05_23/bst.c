#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

bool isValidBST(int a_count, int* a, int min_val, int max_val, int* index) {
    if (*index == a_count)
        return true;

    int curr_val = a[*index];
    if (curr_val < min_val || curr_val > max_val)
        return false;

    (*index)++;

    bool left_valid = isValidBST(a_count, a, min_val, curr_val - 1, index);
    bool right_valid = isValidBST(a_count, a, curr_val + 1, max_val, index);

    return left_valid && right_valid;
}

char* isValid(int a_count, int* a) {
    int index = 0;
    return isValidBST(a_count, a, INT_MIN, INT_MAX, &index) ? "YES" : "NO";
}

int main() {
    int nodes[] = {2, 1, 3, 4, 5};
    int n = sizeof(nodes) / sizeof(nodes[0]);

    char* result = isValid(n, nodes);
    printf("%s\n", result);

    return 0;
}
