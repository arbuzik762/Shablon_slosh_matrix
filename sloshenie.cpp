#include <stdio.h>
#include <stdlib.h>

int** matrixAddition(int** matrix1, int** matrix2, int rows, int cols) {
    int** result = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        result[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int rows = 3, cols = 3;

    int** A = (int**)malloc(rows * sizeof(int*));
    int** B = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        A[i] = (int*)malloc(cols * sizeof(int));
        B[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            A[i][j] = i * cols + j + 1; 
            B[i][j] = 9 - (i * cols + j);
        }
    }

    int** C = matrixAddition(A, B, rows, cols);

    printf("Результат сложения:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    freeMatrix(A, rows);
    freeMatrix(B, rows);
    freeMatrix(C, rows);

    return 0;
}
