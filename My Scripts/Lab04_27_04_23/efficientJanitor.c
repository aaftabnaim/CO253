#include <stdio.h>

int efficientJanitor(int weight_count, float* weight) {
    int trips = 0;
    int left = 0;
    int right = weight_count - 1;

    // sort the weights first
    for (int i = 0; i < weight_count - 1; i++) {
        for (int j = i + 1; j < weight_count; j++) {
            if (weight[i] > weight[j]) {
                float temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
            }
        }
    }

    while (left <= right) {
        if (weight[right] + weight[left] <= 3.0) {
            left++;
        }
        right--;
        trips++;
    }

    return trips;
}

int main(void) {
    int n = 5;
    float weight[5] = {1.01, 1.01, 1.01, 1.4, 2.4};

    printf("%d\n", efficientJanitor(n, weight));

    return 0;
}
