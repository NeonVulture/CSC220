#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace std::chrono;

int Partition (int *A, int p, int r) {
    int x = A[r]; // Set x equal to the pivot located at A[r] (i.e the last element in A)
    int i = p; // pivot index i 
    for (int j = p; j < r; j++) {
        if (A[j] <= x) { // if element at A[j] is <= the pivot
            swap(A[j],A[i]); // Exchange elements A[j] and A[i]
            i++; // increase the pivot index by 1
        }
    }
    // Executed after the for loop terminates
    swap(A[i],A[r]); // swap element at pivot index i with the pivot
    return i;
}

void QuickSort(int *A, int p, int r) {
    if (p < r) { // Condition needed to prevent infinite recursion
        int q = Partition(A,p,r); // partition index 
        QuickSort(A,p,q-1); // 
        QuickSort(A,q+1,r);
    }
}

void printArray(int *A, int size) {
    for (int i = 0; i < size; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int A[n];     //create an array with given number of elements
    srand(time(0));
    cout << "Enter elements:" << endl;
    for(int i = 0; i < n; i++) {
      A[i] = rand() % 1000;
    }
    //int A[] = {2,8,10,9,7,13,17,1,3,5,6,4};
    int arraySize = sizeof(A)/sizeof(A[0]);
    cout << "Given Array \n \n";
    printArray(A,arraySize);
    cout << "\nSorted Array \n \n";
    auto start = high_resolution_clock::now();
    QuickSort(A,0,arraySize-1); 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start); 
    for (int i = 0; i < arraySize ; i++) {
        cout << A[i] << " ";
    }
    cout << "\n";
    cout << "Time taken by Quicksort " << duration.count()  << " microseconds." << endl;
    return 0;
}
