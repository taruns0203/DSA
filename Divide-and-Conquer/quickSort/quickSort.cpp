#include <iostream>
using namespace std;
int partition(int arr[], int s, int e) {
  // step-1: choose pivotelement
  int pivotIndex = s;
  int pivotElement = arr[s];

  // step:2: find right position for pivot and place it there
  int count = 0;
  for (int i = s + 1; i <= e; i++) {
    if (arr[i] <= pivotElement) {
      count++;
    }
  }

  // we now have the right index for pivot
  int rightIndex = s + count;
  swap(arr[pivotIndex], arr[rightIndex]);
  pivotIndex = rightIndex;

  // left will have smaller and right will have larger elements
  int i = s;
  int j = e;

  while (i < pivotIndex && j > pivotIndex) {
    while (arr[i] <= pivotElement) {
      i++;
    }
    while (arr[j] > pivotElement) {
      j--;
    }   
    // We will have 2 cases
    // A - you found the elements to swap
    if (i < pivotIndex && j > pivotIndex) {
        swap(arr[i], arr[j]);
    }
  }
  // B- there is no need to swap
  return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
  // base case - if we have one element
  if (s >= e) {
    return;
  }

  // partition logic, return pivotIndex
  int p = partition(arr, s, e);

  // recursive calls
  // pivot element -> left
  quickSort(arr, s, p - 1);

  // pivot element -> right
  quickSort(arr, p + 1, e);
}
int main() {
  int arr[] = {8,20, 1, 3, 4, 20,1, 50,30};

  int n = 9;

  int s = 0;
  int e = n - 1;
  quickSort(arr, s, e);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }

  cout << endl;

  return 0;
}