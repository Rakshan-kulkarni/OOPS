#include <iostream>

const int MAX_ROWS = 10; // Maximum number of rows allowed

// Function to calculate exponentiation
int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

// Function to calculate the minor of an element in a matrix
int minor(const int matrix[][MAX_ROWS], int row, int col, int size) {
    if (size == 1) {
        return matrix[0][0];
    }

    int subMatrix[MAX_ROWS][MAX_ROWS];
    int k = 0, l = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i != row && j != col) {
                subMatrix[k][l] = matrix[i][j];
                l++;
                if (l >= size - 1) {
                    l = 0;
                    k++;
                }
            }
        }
    }
    // Calculate determinant of the sub-matrix recursively
    return power(-1, row + col) * minor(subMatrix, 0, 0, size - 1);
}

// Function to calculate the determinant of a matrix
int determinant(const int matrix[][MAX_ROWS], int size) {
    if (size == 1) {
        return matrix[0][0];
    }

    int det = 0;
    for (int j = 0; j < size; j++) {
        det += matrix[0][j] * minor(matrix, 0, j, size);
    }
    return det;
}

// Function to calculate the transpose of a matrix
void transpose(const int matrix[][MAX_ROWS], int rows, int cols, int transpose[][MAX_ROWS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// Function to calculate the cofactor of an element in a matrix
int cofactor(const int matrix[][MAX_ROWS], int row, int col, int size) {
    return minor(matrix, row, col, size) * power(-1, row + col);
}

// Function to calculate the adjoint of a matrix
void adjoint(const int matrix[][MAX_ROWS], int rows, int cols, int adjoint[][MAX_ROWS]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            adjoint[i][j] = cofactor(matrix, i, j, rows);
        }
    }
}

// Function to check if a matrix is invertible (non-zero determinant)
bool isInvertible(const int matrix[][MAX_ROWS], int size) {
    return determinant(matrix, size) != 0;
}

// Function to calculate the inverse of a matrix
bool inverse(const int matrix[][MAX_ROWS], int size, double inverse[][MAX_ROWS]) {
    // Check if matrix is invertible
    if (!isInvertible(matrix, size)) {
        std::cerr << "Error: Matrix is not invertible (determinant is zero)." << std::endl;
        return false;
    }

    // Calculate adjoint
    int adjointMatrix[MAX_ROWS][MAX_ROWS];
    adjoint(matrix, size, size, adjointMatrix);

    // Calculate determinant (already done in isInvertible)
    double det = determinant(matrix, size);

    // Calculate inverse (adjoint divided by determinant)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            inverse[i][j] = adjointMatrix[i][j] / det;
        }
    }
    return true;
}

int main() {
    int matrix[MAX_ROWS][MAX_ROWS], rows, cols;

    // Get matrix dimensions
    std::cout << "Enter the number of rows and columns for the matrix: ";
    std::cin >> rows >> cols;

    // Check for square matrix (required for inverse)
    if (rows != cols) {
        std::cerr << "Error: Inverse can only be calculated for square matrices." << std::endl;
        return 1;
    }

    // Get elements of the matrix
    std::cout << "Enter the elements of the matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Check if the matrix is invertible
    if (!isInvertible(matrix, rows)) {
        std::cerr << "Error: Matrix is not invertible (determinant is zero)." << std::endl;
        return 1;
    }

    // Calculate and print the inverse matrix
    double inverseMatrix[MAX_ROWS][MAX_ROWS];
    if (inverse(matrix, rows, inverseMatrix)) {
        std::cout << "Inverse of the matrix:" << std::endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << inverseMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cerr << "Error occurred while calculating inverse." << std::endl;
        return 1;
    }

    return 0;
}
