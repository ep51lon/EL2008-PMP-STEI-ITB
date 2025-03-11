#include <stdio.h>

#define MAX 10

void printMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiplyMatrices(int firstMatrix[MAX][MAX], int secondMatrix[MAX][MAX], int result[MAX][MAX], int rowFirst, int colFirst, int rowSecond, int colSecond) {
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < colSecond; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colFirst; k++) {
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

int main() {
    int firstMatrix[MAX][MAX] = {
        {1, 2, 3},
        {0, 1, 0},
        {0, 0, 1}
    };
    // int secondMatrix[MAX][MAX] = {
    //     {9, 8, 7},
    //     {6, 5, 4},
    //     {3, 2, 1}
    // };
    int secondMatrix[MAX][MAX] = {
        {1},
        {2},
        {3}
    };
    int result[MAX][MAX];
    int rowFirst = 3, colFirst = 3, rowSecond = 3, colSecond = 3;

    if (colFirst != rowSecond) {
        printf("Error! column of first matrix not equal to row of second.\n");
        return -1;
    }

    multiplyMatrices(firstMatrix, secondMatrix, result, rowFirst, colFirst, rowSecond, colSecond);

    printf("Resultant matrix:\n");
    printMatrix(result, rowFirst, colSecond);

    return 0;
}
