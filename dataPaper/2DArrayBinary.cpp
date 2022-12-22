//Question

// declare 2D integer array which should take input one binary number
//  in one row.print and count all N-bit binary numbers having more 1's
//  than 0's in all rows

#include <iostream>
using namespace std;

int main() {
  // Declare an empty 2D array with a specified number of rows and columns
  int M, N;
  int array[M][N];

  // Take input for each element of the array
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cin >> array[i][j];
    }
  }

  // Count and print the number of rows that have more 1's than 0's
  int count = 0;
  for (int i = 0; i < M; i++) {
    int ones = 0;
    int zeros = 0;
    for (int j = 0; j < N; j++) {
      if (array[i][j] == 1) {
        ones++;
      } else {
        zeros++;
      }
    }
    if (ones > zeros) {
      count++;
      for (int j = 0; j < N; j++) {
        cout << array[i][j] << " ";
      }
      cout << endl;
    }
  }
  cout << "Number of rows with more 1's than 0's: " << count << endl;
  return 0;
}

