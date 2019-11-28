#include <iostream> // For inputing and outputing to the console
#include <cstdlib> // For srand() and rand()
#include <ctime> // For implementing srand()
#include <chrono> // For calculating run-time

using namespace std;
using namespace std::chrono;

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

/******************************************PrintArray****************************************/
void printArray(int *A, int size) {
   for(int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << "\n";
}
/*******************************************************************************************/

int main() {
  int *A, n;
  high_resolution_clock::time_point start;
  high_resolution_clock::time_point stop;
  duration<double> time_span;

  cout << "\t\t\t\t\t\t\t\t\t\t\t\t Welcome!" << endl;
  cout << "\t\t\t\t\t\t\t\t\t\t =====================================" << endl;
  cout << "\t\t\t\t\t\t\t\t\t\t 1 - Insertion_Sort" << endl;
  cout << "\t\t\t\t\t\t\t\t\t\t 2 - Merge_Sort" << endl;
  cout << "\t\t\t\t\t\t\t\t\t\t 3 - Quicksort" << endl;
  cout << "\t\t\t\t\t\t\t\t\t\t 4 - Randomized Quicksort" << endl;
  cout << "\t\t\t\t\t\t\t\t\t\t 5 - Heapsort" << endl;
  
  int choice;
  cout << "\n\nSelect a sorting algorithm: ";
  cin >> choice;

  switch(choice) {
    case 1: // Insertion
      cout << "Enter the number of elements: ";
      cin >> n;
      A = (int*)malloc(sizeof(int)*n);
      srand(time(0));
      for (int i = 0 ; i < n; i++) {
        A[i] = rand() % 1000; // random number from 0 to 999
      }
      //int ArraySize = sizeof(A)/sizeof(A[0]);
      cout << "Given Array: " << endl;
      printArray(A,n);
      start = high_resolution_clock::now();
      InsertionSort(A, n);
      stop = high_resolution_clock::now();
      time_span = duration_cast<microseconds>(stop - start);
      cout << "Sorted Array via InsertionSort: " << endl;
      printArray(A, n);
      cout << "\nTime taken by Insertion-Sort: " << time_span.count() << " microseconds." << endl; 
      break;
    case 2: //Merge
      cout << "Enter the number of elements: ";
      //cin >> n;
      //int A[n];
      break;
    case 3: // Quicksort
      //int n;
      cout << "Enter the number of elements: ";
      //cin >> n;
      break;
    case 4: // Randomized
      //int n;
      cout << "Enter the number of elements: ";
      //cin >> n;
      //int A[n];
      break;
    case 5: // Heapsort
      //int n, *A;
      cout << "Enter the number of elements: ";
      //A = (int*)malloc(sizeof(int)*n);
      break; 
    default:
      cout << "Invaild choice!" << endl;
      break;
  }
  return 0;
}

