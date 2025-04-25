#include <stdio.h>
#include <stdlib.h>

int** sloshenie_matrix(int** m_1, int** m_2, int rows, int cols) {
    int** result = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        result[i] = (int*)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            result[i][j] = m_1[i][j] + m_2[i][j];
        }
    }
    return result;
}

void Matrix(int** matrix, int rows) {
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

    int** C = sloshenie_matrix(A, B, rows, cols);

    printf("Результат:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    Matrix(A, rows);
    Matrix(B, rows);
    Matrix(C, rows);

    return 0;
}
