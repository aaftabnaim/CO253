#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int getCharVal(char x){

switch(x) {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    default:
        return 0;
}
}

int romanToInt(const char *s) {

    int result = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int curr = getCharVal(s[i]);
        int prev = i > 0 ? getCharVal(s[i - 1]) : 0;
        if (prev < curr) {
            result += curr - 2 * prev;
        } else {
            result += curr;
        }
    }
    return result;
}


int compare(const void *a, const void *b) {
    char *nameA = *(char **)a;
    char *nameB = *(char **)b;
    char *spaceA = strchr(nameA, ' ');
    char *spaceB = strchr(nameB, ' ');
    int cmp = strncmp(nameA, nameB, spaceA - nameA);
    if (cmp != 0) {
        return cmp;
    }
    return romanToInt(spaceA + 1) - romanToInt(spaceB + 1);
}
char** sortRoman(int names_count, char** names, int* result_count) {
    qsort(names, names_count, sizeof(char *), compare);
    *result_count = names_count;
    return names;
}


int cmp(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;

    int cmp_names = strcmp(str1, str2);
    if (cmp_names != 0) {
        return cmp_names;
    }

    int num1 = 0, num2 = 0, i;
    for (i = 0; i < strlen(str1) && str1[i] != ' '; i++) {
        switch (str1[i]) {
            case 'I':
                num1 += 1;
                break;
            case 'V':
                if (i > 0 && str1[i - 1] == 'I') {
                    num1 += 3;
                } else {
                    num1 += 5;
                }
                break;
            case 'X':
                if (i > 0 && str1[i - 1] == 'I') {
                    num1 += 8;
                } else {
                    num1 += 10;
                }
                break;
            case 'L':
                if (i > 0 && str1[i - 1] == 'X') {
                    num1 += 30;
                } else {
                    num1 += 50;
                }
                break;
        }
    }
    for (i = 0; i < strlen(str2) && str2[i] != ' '; i++) {
        switch (str2[i]) {
            case 'I':
                num2 += 1;
                break;
            case 'V':
                if (i > 0 && str2[i - 1] == 'I') {
                    num2 += 3;
                } else {
                    num2 += 5;
                }
                break;
            case 'X':
                if (i > 0 && str2[i - 1] == 'I') {
                    num2 += 8;
                } else {
                    num2 += 10;
                }
                break;
            case 'L':
                if (i > 0 && str2[i - 1] == 'X') {
                    num2 += 30;
                } else {
                    num2 += 50;
                }
                break;
        }
    }

    return num1 - num2;
}

void quicksort(char **arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot_index = (left + right) / 2;
    char *pivot_value = arr[pivot_index];

    int i = left, j = right;
    while (i <= j) {
        while (cmp(&arr[i], &pivot_value) < 0) {
            i++;
        }
        while (cmp(&arr[j], &pivot_value) > 0) {
            j--;
        }
        if (i <= j) {
            char *tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    quicksort(arr, left, j);
    quicksort(arr, i, right);
}



int main(void){
    
    printf("%d",romanToInt("XXV"));
}