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
     int largest, l , r;
     l = 2 * i; // left child
     r = (2 * i) + 1; // right child
     if (l <= n && A[l - 1] > A[i - 1]) {
          largest = l;
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

void BUILDMAXHEAP(int *A, int n) {
      
}



void Heapsort(int *A, int n) {
     BUILDMAXHEAP(A,n);
     for(int i = n/2; i >= 1 ; i--) { // for i <- length[A] down to 2
          swap(A[0],A[i-1]);
          //Something
          MAXHEAPIFY(A,0,n);
}
