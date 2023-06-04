#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** processLogs(int logs_count, char** logs, int threshold, int* result_count);

char** processLogs(int logs_count, char** logs, int threshold, int* result_count) {
    // Step 1: Create a dictionary to store the transaction count for each user
    int MAX_USERS = 100000; // Maximum number of users
    int* userCount = (int*)calloc(MAX_USERS, sizeof(int));

    // Step 2: Iterate through the logs and split each entry
    for (int i = 0; i < logs_count; i++) {
        char* log = logs[i];
        char* sender = strtok(log, " ");
        char* recipient = strtok(NULL, " ");
        strtok(NULL, " "); // Skipping the amount

        int senderId = atoi(sender);
        int recipientId = atoi(recipient);

        // Increment the transaction count for both sender and recipient
        userCount[senderId]++;
        userCount[recipientId]++;
    }

    // Step 3: Find suspicious users who have at least the threshold number of transactions
    char** result = (char**)malloc(MAX_USERS * sizeof(char*));
    int resultIndex = 0;

    for (int i = 0; i < MAX_USERS; i++) {
        if (userCount[i] >= threshold) {
            // Convert the user id to a string and add it to the result array
            char* userId = (char*)malloc(10 * sizeof(char)); // Assuming user id can have at most 10 digits
            sprintf(userId, "%d", i);
            result[resultIndex] = userId;
            resultIndex++;
        }
    }

    // Step 4: Sort the result array in ascending order
    *result_count = resultIndex;
    for (int i = 0; i < resultIndex - 1; i++) {
        for (int j = 0; j < resultIndex - i - 1; j++) {
            int userId1 = atoi(result[j]);
            int userId2 = atoi(result[j + 1]);
            if (userId1 > userId2) {
                char* temp = result[j];
                result[j] = result[j + 1];
                result[j + 1] = temp;
            }
        }
    }

    free(userCount);
    return result;
}

int main(void) {
    char* logs[] = {"88 99 200", "88 99 300", "99 32 100", "12 12 15"};
    int threshold = 2;

    int result_count = 0;
    char** result = processLogs(4, logs, threshold, &result_count);
    printf("Suspicious Users: ");
    for (int k = 0; k < result_count; k++) {
        printf("%s ", result[k]);
        free(result[k]);
    }
    printf("\n");

    free(result);

    return 0;
}
