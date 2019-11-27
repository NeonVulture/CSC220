#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

int heapsize;

int getParent(int i) {
     return i/2;
}

int getLeftChild(int i) {
    return (2*i);
}

int getRightChild(int i) {
     return (2*i+1);
}

void MAXHEAPIFY(int *A, int i) {
     int largest, left , right;
     left = getLeftChild(i); // left child
     right = getRightChild(i); // right child
     if (left < heapsize && A[left] > A[i]) { // Maybe try A[left-1] && A[i-1]
          largest = left;
     }     else {
          largest = i;
     }
     if (right < heapsize && A[right] > A[largest]) { 
          largest = right;
     }
     if (largest != i) {
          swap(A[i], A[largest]);
          MAXHEAPIFY(A, largest);
     }
}

void BUILDMAXHEAP(int *A, int n) {
     heapsize = n;
      for(int i = n/2; i >= 0; i--) {
           MAXHEAPIFY(A,i);
      }
}


void Heapsort(int *A, int n) {
     BUILDMAXHEAP(A,n);
     for(int i = n-1; i > 0 ; i--) { // for i <- length[A] down to 2 (also i >= 1)
          swap(A[0],A[i]); // Myabe try A[i-1]
          heapsize--;
          MAXHEAPIFY(A,0);
     }
}

void printArray(int *A, int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
}

int main() {
     int *A, n;
     cout << "Enter the number of elements: ";
     cin >> n;
     //A = (int*)malloc(sizeof(int)*n);
     A[n];
     srand(time(0));
     for (int i = 0; i < n; i++) {
          A[i] = rand() % 100;
     }
    int arraySize = sizeof(A) + 2;
    cout << "Given Array: \n \n";
    printArray(A,arraySize);
    cout << "\nSorted Array: \n \n";
    auto start = high_resolution_clock::now();
    Heapsort(A,n); 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    cout << "Time taken by Heapsort: " << duration.count()  << " microseconds." << endl;
    return 0;
}
