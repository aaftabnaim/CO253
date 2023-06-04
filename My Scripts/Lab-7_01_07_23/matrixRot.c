#include <stdio.h>
#include <stdlib.h>

// Function to rotate the passed array by r elements clockwise
void rotate(int* lst, int length, int r) {
    r = r % length; // If r is more than length, take mod by the length of the array
    int* temp = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        int newIndex = (i + r) % length;
        temp[newIndex] = lst[i];
    }
    for (int i = 0; i < length; i++) {
        lst[i] = temp[i];
    }
    free(temp);
}

void matrixRotation(int matrix_rows, int matrix_columns, int** matrix, int r) {
    int pad = 0; // Variable for maintaining the padding
    int depth = (matrix_rows < matrix_columns) ? matrix_rows / 2 : matrix_columns / 2; // Number of layers

    // Array to store each rotated layer
    int** layers = (int**)malloc(depth * sizeof(int*));
    for (int i = 0; i < depth; i++) {
        layers[i] = (int*)malloc(((matrix_rows - pad * 2 + matrix_columns - pad * 2) * 2) * sizeof(int));
    }

    // For each depth, rotate and store the layer
    for (int index = 0; index < depth; index++) {
        int i = pad, j = pad;
        int* arr = layers[index];
        int pointer = 0;

        // Traverse down
        while (i < matrix_rows - pad) {
            arr[pointer++] = matrix[i][j];
            i++;
        }
        i--; // To keep 'i' in range
        j++; // To avoid taking same elements again

        // Traverse right
        while (j < matrix_columns - pad) {
            arr[pointer++] = matrix[i][j];
            j++;
        }
        j--; // To keep 'j' in range
        i--; // To avoid taking same elements again

        // Traverse up
        while (i >= pad) {
            arr[pointer++] = matrix[i][j];
            i--;
        }
        i++; // To keep 'i' in range
        j--; // To avoid taking same elements again

        // Traverse left
        while (j > pad) {
            arr[pointer++] = matrix[i][j];
            j--;
        }
        pad++;
        rotate(arr, pointer, r); // Rotate the layer
    }

    // Place the rotated elements back into the matrix
    pad = 0;
    for (int index = 0; index < depth; index++) {
        int i = pad, j = pad;
        int pointer = 0;

        // Traverse down
        while (i < matrix_rows - pad) {
            matrix[i][j] = layers[index][pointer++];
            i++;
        }
        i--;
        j++;

        // Traverse right
        while (j < matrix_columns - pad) {
            matrix[i][j] = layers[index][pointer++];
            j++;
        }
        j--;
        i--;

        // Traverse up
        while (i >= pad) {
            matrix[i][j] = layers[index][pointer++];
            i--;
        }
        i++;
        j--;

        // Traverse left
        while (j > pad) {
            matrix[i][j] = layers[index][pointer++];
            j--;
        }
        pad++;
    }

    // Print the resulting matrix
    for (int i = 0; i < matrix_rows; i++) {
        for (int j = 0; j < matrix_columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < depth; i++) {
        free(layers[i]);
    }
    free(layers);
}

int main() {
    int m, n, r;
    scanf("%d %d %d", &m, &n, &r);

    // Allocate memory for the matrix
    int** mat = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        mat[i] = (int*)malloc(n * sizeof(int));
    }

    // Read matrix elements from input
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    matrixRotation(m, n, mat, r);

    // Free memory
    for (int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
