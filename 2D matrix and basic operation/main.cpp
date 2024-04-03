#include <iostream>

using namespace std;

const int MAX_ROWS = 10; // Maximum number of rows allowed
const int MAX_COLS = 10; // Maximum number of columns allowed

// Function to declare and initialize a 2D matrix
void initializeMatrix(int matrix[][MAX_COLS], int rows, int cols) {
  if (rows > MAX_ROWS || cols > MAX_COLS) {
    cout << "Error: Matrix size exceeds maximum allowed." << endl;
    return;
  }

  // Prompt user to enter elements
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << "Enter element for row " << i + 1 << ", column " << j + 1 << ": ";
      cin >> matrix[i][j];
    }
  }
}

// Function to print the matrix
void printMatrix(const int matrix[][MAX_COLS], int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}

// Function to add two matrices of the same size
void addMatrices(const int matrix1[][MAX_COLS], const int matrix2[][MAX_COLS], int result[][MAX_COLS], int rows, int cols) {
  if (rows > MAX_ROWS || cols > MAX_COLS) {
    cout << "Error: Matrix size exceeds maximum allowed." << endl;
    return;
  }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

int main() {
  int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];

  int rows1, cols1, rows2, cols2;

  // Get dimensions for matrix 1
  cout << "Enter the number of rows for matrix 1: ";
  cin >> rows1;
  cout << "Enter the number of columns for matrix 1: ";
  cin >> cols1;

  // Get dimensions for matrix 2
  cout << "Enter the number of rows for matrix 2: ";
  cin >> rows2;
  cout << "Enter the number of columns for matrix 2: ";
  cin >> cols2;

  // Check if matrices can be added (same dimensions)
  if (rows1 != rows2 || cols1 != cols2) {
    cout << "Error: Matrices must have the same dimensions for addition." << endl;
    return 1;
  }

  // Initialize matrices
  initializeMatrix(matrix1, rows1, cols1);
  initializeMatrix(matrix2, rows2, cols2);

  // Print original matrices
  cout << "Matrix 1:" << endl;
  printMatrix(matrix1, rows1, cols1);

  cout << "Matrix 2:" << endl;
  printMatrix(matrix2, rows2, cols2);

  // Add matrices
  addMatrices(matrix1, matrix2, result, rows1, cols1);

  // Print the sum
  cout << "Sum of matrices:" << endl;
  printMatrix(result, rows1, cols1);

  return 0;
}
