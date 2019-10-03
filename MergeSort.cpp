#include <iostream>
#include <climits>

using namespace std;

void Merge(int *A, int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  int L[n1], R[n2];

  for(int i = 0; i < n1; i++) {
    L[i] = A[p + i - 1];
  }
  for(int j = 0; j < n2; j++) {
    R[j] = A[q + j];
  }
  L[n1 + 1] = INT_MIN;
  R[n2 + 1] = INT_MIN;
  int i = 0;
  int j = 0;

  for(int k = p; p < r; k++) {
    if (L[k] <= R[j]) {
      A[k] = L[i];
      i = i + 1;
    } else {
      A[k] = R[j];
      j = j + 1; 
    }
  }
}

void MergeSort(int *A, int p, int r) {
  if (p < r) {
    int result = (p+r)/2;
    int q = floor(q); 
    MergeSort(*A, p, q);
    MergeSort(*A, q + 1, r);
    Merge(*A, p, q, r);
  }
}

void printArray(int *A, int size) 
{ 
    for (int i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

int main() {
  int A[] = {5,2,4,7,1,3,2,6};
  int ArraySize = sizeof(A)/sizeof(A[0]);
  printArray(*A, ArraySize);
  MergeSort(*A, 0, ArraySize - 1)
  printArray(*A, ArraySize);
}
