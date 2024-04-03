#include <iostream>

using namespace std;

// Function to calculate the determinant of a 2x2 matrix
int determinant2x2(int matrix[2][2]) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

// Function to calculate the determinant of a 3x3 matrix
int determinant3x3(int matrix[3][3]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

// Function to check if a square matrix is invertible
bool isMatrixInvertible(int matrix[][3], int size) {
    if (size == 2) {
        int matrix2x2[2][2] = {{matrix[0][0], matrix[0][1]}, {matrix[1][0], matrix[1][1]}};
        return determinant2x2(matrix2x2) != 0;
    } else if (size == 3) {
        return determinant3x3(matrix) != 0;
    } else {
        cout << "Error: Inversion for matrices of size greater than 3 is not supported." << endl;
        return false;
    }
}

int main() {
    int size;
    cout << "Enter the size of the square matrix: ";
    cin >> size;

    if (size <= 0 || size > 3) {
        cout << "Error: Matrix size must be between 1 and 3." << endl;
        return 1;
    }

    int matrix[3][3]; // Assuming maximum size of 3x3 matrix for demonstration

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cin >> matrix[i][j];
        }
    }

    if (isMatrixInvertible(matrix, size)) {
        cout << "The matrix is invertible." << endl;
    } else {
        cout << "The matrix is not invertible." << endl;
    }

    return 0;
}
