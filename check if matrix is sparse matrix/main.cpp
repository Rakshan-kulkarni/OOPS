#include <iostream>

using namespace std;

// Function to check if a matrix is sparse
bool isSparseMatrix(int matrix[][10], int rows, int cols) {
    int zeroCount = 0;
    int totalElements = rows * cols;

    // Count the number of zero elements
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
    }

    // Define a threshold value
    double threshold = 0.5; // You can adjust this value as needed

    // Check if the ratio of zero elements to total elements exceeds the threshold
    return (static_cast<double>(zeroCount) / totalElements) > threshold;
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> rows >> cols;

    int matrix[10][10]; // Assuming maximum size of 10x10 matrix

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    if (isSparseMatrix(matrix, rows, cols)) {
        cout << "The matrix is a sparse matrix." << endl;
    } else {
        cout << "The matrix is not a sparse matrix." << endl;
    }

    return 0;
}
