#include <stdio.h>

#define MAX 10

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]); // Print each element in the row
        }
        printf("\n"); // Move to the next line after each row
    }
}

// Function to multiply two matrices
void multiplyMatrices(int firstMatrix[MAX][MAX], int secondMatrix[MAX][MAX], int result[MAX][MAX], int rowFirst, int colFirst, int rowSecond, int colSecond) {
    for (int i = 0; i < rowFirst; i++) {
        for (int j = 0; j < colSecond; j++) {
            result[i][j] = 0; // Initialize result matrix element to 0
            for (int k = 0; k < colFirst; k++) {
                // Multiply elements of the first matrix with corresponding elements of the second matrix and accumulate the sum
                result[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

int main() {
    // Define the first matrix
    int firstMatrix[MAX][MAX] = {
        {1, 2, 3},
        {0, 1, 0},
        {0, 0, 1}
    };

    // Define the second matrix
    int secondMatrix[MAX][MAX] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    // int secondMatrix[MAX][MAX] = {
    //     {1},
    //     {2},
    //     {3}
    // };

    int result[MAX][MAX]; // Resultant matrix
    int rowFirst = 3, colFirst = 3, rowSecond = 3, colSecond = 1; // Dimensions of matrices

    // Check if matrix multiplication is possible
    if (colFirst != rowSecond) {
        printf("Error! column of first matrix not equal to row of second.\n");
        return -1;
    }

    // Multiply the matrices
    multiplyMatrices(firstMatrix, secondMatrix, result, rowFirst, colFirst, rowSecond, colSecond);

    // Print the resultant matrix
    printf("Resultant matrix:\n");
    printMatrix(result, rowFirst, colSecond);

    return 0;
}