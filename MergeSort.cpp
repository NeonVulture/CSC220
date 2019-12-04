#include <iostream>
#include <climits>
#include <cmath>
#include <chrono>
#include <cstdlib>  // For srand() and rand()
#include <ctime>

using namespace std;
using namespace std::chrono;

void Merge(int A[], int p, int q, int r) {
  int n1 = q - p + 1; // length of LEFT subarray
  int n2 = r - q; // length of RIGHT subarray
  int L[n1], R[n2]; // Create LEFT & RIGHT subarrays
  
  for(int i = 0; i < n1; i++) { // Copies the subarray A[p...q] into L[1...n1]
    L[i] = A[p + i];
    //[i] = A[p + i - 1];
    
  }
  for(int j = 0; j < n2; j++) { // Copies the subarray A[q+1...r] into R[1...n2]
    R[j] = A[q + j + 1]; 
  }
  //L[n1 + 1] = INT_MIN;
  //R[n2 + 1] = INT_MIN;
  

  int i = 0; // First index such that L[0] contains the smallest element that has not been copies back to A
  int j = 0; // First index such that R[0] contains the smallest element that has not been copies back to A
  
  // Up to this point I diverge from TxtBook
    int k = p;
    while (i < n1 && j < n2) {
        
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++; 
        }
        k++;
    }
    
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int A[], int p, int r) {
  if (p < r) {
    int result = (p+r)/2;
    int q = floor(result);
    // q = p + (r-p)/2; 
    MergeSort(A, p, q);
    MergeSort(A, q + 1, r);
    Merge(A, p, q, r);
  }
}


void printArray(int A[], int size) 
{ 
    for (int i = 0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

int main() {
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;
  int A[n]; 
  srand(time(0));  // Initialize random number generator. 
  for (int i = 0; i < n; i++){
      A[i] = rand() % 100;
  }
 
  int ArraySize = sizeof(A)/sizeof(A[0]);
  //int ArraySize = 8;
  printArray(A, ArraySize);
  auto start = high_resolution_clock::now();
  MergeSort(A, 0, ArraySize - 1);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  printArray(A, ArraySize);
  cout << "\ntime taken by Mergesort: " << duration.count() << " microseconds." << endl;
  return 0;
}
