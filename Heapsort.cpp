#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namesapce std::

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

 
