#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMoveTime(char keypad[], char src, char dst) {
    int startIndex = strchr(keypad, src) - keypad;
    int destination = strchr(keypad, dst) - keypad;
    int startRow = startIndex / 3;
    int startColumn = startIndex % 3;
    int destRow = destination / 3;
    int destColumn = destination % 3;
    
    int rowDiff = abs(startRow - destRow);
    int colDiff = abs(startColumn - destColumn);
    int minMoves = rowDiff < colDiff ? colDiff : rowDiff;
    
    return minMoves;
}

int entryTime(char* s, char* keypad) {
    int total_time = 0;
    int string_length = strlen(s);
    
    for (int i = 0; i < string_length - 1; i++) {
        total_time += getMoveTime(keypad, s[i], s[i + 1]);
    }
    
    return total_time;
}

int main() {
    char s[] = "423692";
    char keypad[] = "923857614";
    
    int time = entryTime(s, keypad);
    printf("Total time: %d\n", time);
    
    return 0;
}
