#include <iostream>
#include <climits>
#include <cmath>
#include <chrono>
#include <cstdlib>  // For srand() and rand()
#include <ctime>

using namespace std;
using namespace std::chrono;

void Merge(int *A, int p, int q, int r) {
     int n1 = q - p + 1; //Length of LEFT subarray
     int n2 = r - q; // Length of RIGHT subarray
     int L[n1 + 1], R[n2 + 1]; //Create LEFT & RIGHT arrays

     L[n1] = INT_MAX; //Assign sentinel
     R[n2] = INT_MAX; //Assign sentinel

     for (int i = 0; i < n1; i++) // Copies the subarray A[p...q] into L[1...n1
         L[i] = A[p + i];
     for (int j = 0; j < n2; j++) // Copies the subarray A[q+1...r] into R[1...n2]
         R[j] = A[q + j + 1];

     int i = 0; // First index such that L[0] contains the smallest element that has not been copied back to A
     int j = 0; // First index such that R[0] contains the smallest element that has not been copied back to A

     for (int k = p; k <= r; k++) {
         if (L[i] <= R[j]) { // Compare the two elements at their respective indicies (both are intially at index 0)
             A[k] = L[i]; // Assign A[K] to the element at L[i] only if the condition above is true
             i++; // Increase the index i by 1 only if the condition above is true
         } else { // If the condtion above is false, then...
             A[k] = R[j]; // Assign A[k] to the value of R[j] if the condition above is false
             j++; // Increase the index i by 1 only if the condition above is false
         }
     }
 }

 void MergeSort(int *A, int p, int r) {
     if(p < r) {
         int result = (p+r)/2;
         int q = floor(result); // q is the mid index (where we partition the array)
         MergeSort(A, p, q);
         MergeSort(A, q + 1, r);
         Merge(A, p, q, r);
     }
 }
 
void printArray(int *A, int size) 
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
      A[i] = rand() % 1000;
  }
 
  int ArraySize = sizeof(A)/sizeof(A[0]);
  printArray(A, ArraySize);
  auto start = high_resolution_clock::now();
  MergeSort(A, 0, ArraySize - 1);
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Sorted Array via Mergesort: " << endl;
  printArray(A, ArraySize);
  cout << "\ntime taken by Mergesort: " << duration.count() << " microseconds." << endl;
  return 0;
}
