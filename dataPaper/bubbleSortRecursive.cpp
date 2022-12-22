// Question
// Here is a recursive implementation of the bubble sort algorithm in C++:


#include <iostream>
#include <algorithm>
using namespace std;

void bubble_sort(int arr[], int n) {
  // Base case: if the length of the array is 1 or 0, it is already sorted
  if (n <= 1) {
    return;
  }

  // Perform a single pass of bubble sort
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      // Swap the elements if they are out of order
      std::swap(arr[i], arr[i + 1]);
    }
  }

  // Recursively sort the tail of the array
  bubble_sort(arr, n - 1);
}
