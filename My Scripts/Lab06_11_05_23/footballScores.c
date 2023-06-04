#include <stdio.h>

int* counts(int teamA_count, int* teamA, int teamB_count, int* teamB, int* result_count) {
    int count;
    int t_res[teamB_count] = {0};

    for(int k=0;k<teamB_count;k++){
        int teamB_val = *(teamB+k);
        count = 0;
        for(int j=0;j<teamA_count;j++){
            count += *(teamA+j);
            if(count>=teamB_val) break;
        }
        t_res[k] = count;
    }
    
    *result_count = teamB_count;
 
    int *a = malloc(teamB_count * sizeof(int));

    for (int i = 0; i < 5; i++) {
        *(a + i) = t_res[i];
    }
 
    return a;
    
}

int* counts(int teamA_count, int* teamA, int teamB_count, int* teamB, int* result_count) {
    int* result = (int*)malloc(teamB_count * sizeof(int));
    for (int i = 0; i < teamB_count; i++) {
        int count = 0;
        for (int j = 0; j < teamA_count; j++) {
            if (teamA[j] <= teamB[i]) {
                count++;
            }
        }
        result[i] = count;
    }
    *result_count = teamB_count;
    return result;
}

int main(void){
    int teamA[] = {1, 2, 3}
    int teamB[] = {2, 4};
    return 0;
}