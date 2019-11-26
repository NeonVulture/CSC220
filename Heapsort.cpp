#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>

using namespace std;
using namesapce std::chrono;

int getParent(int i) {
     return i/2;
}

int getLeftChild() {
    return (2*i+1);
}

int getRightChild() {
     return (2*i+2);
}

void MAXHEAPIFY(int *A, int i, int n) {
     int largest, left , right;
     left = getLeftChild(i); // left child
     right = getRightChild(i); // right child
     if (left <= n && A[left] > A[i]) { // Maybe try A[left-1] && A[i-1]
          largest = left;
     }
     else {
          largest = i;
     }
     if (r <= n && A[r - 1] > A[largest - 1]) { 
          largest = r;
     }
     if (largest != i) {
          swap(A[i-1], A[largest - 1]);
          MAXHEAPIFY(A, largest, n);
     }
}

void BUILDMAXHEAP(int *A, int h, int *n) {
      n = h - 1;
      for(int i = h/2; i>=0; i--) {
           MAXHEAPIFY(A,i,n);
      }
}


void Heapsort(int *A, int n) {
     BUILDMAXHEAP(A,h,n);
     for(int i = h-1; i > 0 ; i--) { // for i <- length[A] down to 2
          swap(A[0],A[i]); // Myabe try A[i-1]
          *n--;
          MAXHEAPIFY(A,0,n);
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
     srand(time(0));
     for (int i = 0; i < n; i++) {
          A = (int*) malloc(sizeog(int)*(rand()%100));
     }
    int arraySize = sizeof(A)/sizeof(A[0]);
    cout << "Given Array \n \n";
    printArray(A,arraySize);
    cout << "\nSorted Array \n \n";
    auto start = high_resolution_clock::now();
    Heapsort(A,n); 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
    for (int i = 0; i < arraySize ; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    cout << "Time taken by Heapsort: " << duration.count()  << " microseconds." << endl;
     return 0;
}

 
