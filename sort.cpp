#include <iostream> // For inputing and outputing to the console
#include <cstdlib> // For srand() and rand()
#include <ctime> 
#include <chrono> // For calculating run-time

using namespace std;
using namespace std::chrono;

int main() {
  cout << "\t\t\t\t Welcome!" << endl;
  cout << "\t\t\t====================================" << endl;
  cout << "\t\t\t 1 - Insertion_Sort" << endl;
  cout << "\t\t\t 2 - Merge_Sort" << endl;
  cout << "\t\t\t 3 - Quicksort" << endl;
  cout << "\t\t\t 4 - Randomized Quicksort" << endl;
  cout << "\t\t\t 5 - Heapsort" << endl;
  
  int choice = 0;
  switch(choice) {
    case 1: // Insertion
      int n;
      cout << "Enter the number of elements: " << endl;
      cin >> n;
      int A[n];
      srand(time(0));
      for
      int ArraySize = sizeof(A)/sizeof(A[0]);
      printArray(A,ArraySize);

    auto start = high_resolution_clock::now();

    InsertionSort(A, ArraySize);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    printArray(A, ArraySize);

    cout << "\nTime taken by Insertion-Sort: " << duration.count() << " microseconds." << endl; 
      break:
    case 2: //Merge
      int n;
      cout << "Enter the number of elements: " << endl;
      cin >> n;
      int A[n];
      break;
    case 3: // Quicksort
      int n;
      cout << "Enter the number of elements: " << endl;
      cin >> n;
      int A[n];
      break;
    case 4: // Randomized
      int n;
      cout << "Enter the number of elements: " << endl;
      cin >> n;
      int A[n];
      break;
    case 5: // Heapsort
      int n, *A;
      cout << "Enter the number of elements: " << endl;
      cin >> n;
      A = (int*)malloc(sizeof(int)*n);
      break;
    default:
      cout << "Invaild choice!" << endl;
      break;
  }
  return 0;
}

/******************************************INSERTION_SORT*************************************/
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
/***************************************END_OF_INSERTION_SORT********************************/
void printArray(int *A, int size) {
   for(int i = 0; i < n; i++)
        cout << A[i] << " " << endl;
    cout << "\n";
}
