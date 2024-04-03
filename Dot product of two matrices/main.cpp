#include <iostream>

const int MAX_ROWS = 10; // Maximum number of rows allowed
const int MAX_COLS = 10; // Maximum number of columns allowed

// Function to calculate the dot product of corresponding rows in two matrices
void dotProductRows(const int matrix1[][MAX_COLS], int rows1, int cols1,
                    const int matrix2[][MAX_COLS], int rows2, int cols2,
                    int result[]) {
    if (cols1 != cols2) {
        std::cerr << "Error: Number of columns in both matrices must be equal." << std::endl;
        return;
    }

    for (int i = 0; i < rows1; ++i) {
        int sum = 0;
        for (int k = 0; k < cols1; ++k) {
            sum += matrix1[i][k] * matrix2[i][k]; // Use the same row index for both matrices
        }
        result[i] = sum;
    }
}

// Function to print the matrix
void printMatrix(const int matrix[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << matrix[i] << std::endl;
    }
}

int main() {
    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS];

    int rows1, cols1, rows2, cols2;

    // Get dimensions for matrix 1
    std::cout << "Enter the number of rows for matrix 1: ";
    std::cin >> rows1;
    std::cout << "Enter the number of columns for matrix 1: ";
    std::cin >> cols1;

    if (rows1 > MAX_ROWS || cols1 > MAX_COLS) {
        std::cerr << "Error: Matrix size exceeds maximum allowed." << std::endl;
        return 1;
    }

    // Get dimensions for matrix 2
    std::cout << "Enter the number of rows for matrix 2: ";
    std::cin >> rows2;
    std::cout << "Enter the number of columns for matrix 2: ";
    std::cin >> cols2;

    if (rows2 > MAX_ROWS || cols2 > MAX_COLS) {
        std::cerr << "Error: Matrix size exceeds maximum allowed." << std::endl;
        return 1;
    }

    if (cols1 != cols2) {
        std::cerr << "Error: Matrices must have the same number of columns for row-wise dot product." << std::endl;
        return 1;
    }

    // Initialize matrices (input from the user)
    std::cout << "Enter elements for matrix 1:" << std::endl;
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            std::cin >> matrix1[i][j];
        }
    }

    std::cout << "Enter elements for matrix 2:" << std::endl;
    for (int i = 0; i < rows2; ++i) {
        for (int j = 0; j < cols2; ++j) {
            std::cin >> matrix2[i][j];
        }
    }

    // Calculate and print the dot product of rows
    dotProductRows(matrix1, rows1, cols1, matrix2, rows2, cols2, result);

    std::cout << "Dot product of corresponding rows:" << std::endl;
    printMatrix(result, rows1);

    return 0;
}
