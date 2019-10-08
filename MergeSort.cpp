#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

void Merge(int A[], int p, int q, int r) {
  int n1 = q - p + 1;
  int n2 = r - q;
  //int  L[n1 + 1], R[n2 + 1];

  int L[n1], R[n2];
  
  for(int i = 0; i < n1; i++) {
    L[i] = A[p + i];
    //[i] = A[p + i - 1];
    
  }
  for(int j = 0; j < n2; j++) {
    R[j] = A[q + j + 1];
    //R[j] = A[q + j];
  }
  //L[n1 + 1] = INT_MIN;
  //R[n2 + 1] = INT_MIN;
  

  int i = 0;
  int j = 0;

  /*for(int k = 1; p <= r; k++) {
    if (L[k] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++; 
    }
  }*/
  
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

 /* for(int k = p; p < r; k++) {
      if (i > n1) {
          A[k] = R[j];
          j++;
      } else if (j > n2) {
          A[k] = L[i];
          i++;
      } else if (L[i] <= R[j]) {
          A[k] = L[j];
          i++;
      } else {
          A[k] = R[j];
          j++;
      }
  }*/
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
  int A[] = {5,2,4,7,1,3,6};
  int ArraySize = sizeof(A)/sizeof(A[0]);
  //int ArraySize = 8;
  printArray(A, ArraySize);
  MergeSort(A, 0, ArraySize - 1);
  printArray(A, ArraySize);
  return 0;
}
