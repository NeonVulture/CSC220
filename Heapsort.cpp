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
          largest = i;
     }
     if (largest != i) {
          swap(A[i-1], A[largest - 1]);
          MAXHEAPIFY(A, largest, n);
     }
}

void BUILDMAXHEAP() {
     
}
