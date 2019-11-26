#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>

using namespace std;
using namespace std::chrono;


void InsertionSort(int *A,int n) {
    int i, j, key;
    for(j = 1; j < n; j++) {
        key = A[j];
        i = j - 1;
        while (i >= 0 && A[i] > key) {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1 ] = key;
    }
}

void printArray(int *A, int n) {
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int A[n];
    
    for(int i = 0; i < n;i++) {
        A[i] = rand() % 100;
    }
    int ArraySize = sizeof(A)/sizeof(A[0]);
    printArray(A,ArraySize);
    auto start = high_resolution_clock::now();
    InsertionSort(A, ArraySize);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    printArray(A, ArraySize);
    cout << "\nTime taken by Insertion-Sort: " << duration.count() << " microseconds." << endl; 
}
