#include <iostream>

using namespace std;

int main() {
  int rows, cols;
  cout << "Enter the number of rows and columns of the matrix: " << endl;
  cin >> rows >> cols;

  // Declare a 2D array to store the matrix
  int matrix[rows][cols];

  // Take input for the matrix
  cout << "Enter the elements of the matrix: ";
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> matrix[i][j];
    }
  }

  // Declare a 2D array to store the transpose of the matrix
  int transpose[cols][rows]; // Corrected declaration

  // Find the transpose of the matrix
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      transpose[i][j] = matrix[j][i];
    }
  }

  // Print the transpose of the matrix
  cout << "The transpose of the matrix is: " << endl;
  for (int i = 0; i < cols; i++) {
    for (int j = 0; j < rows; j++) {
      cout << transpose[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
