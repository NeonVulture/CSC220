// FILE: sort.cpp
// AUTHOR: ANTHONY RAMOS

#include <iostream> // For inputing and outputing to the console
#include <cstdlib> // For srand() and rand()
#include <ctime> // For implementing srand()
#include <chrono> // For calculating run-time
#include <cmath> // To utilize floor function (Used in Mergesort)
#include <climits> // To utilize Infinity (Specifically to assign the sentinels in Mergesort)

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
        A[i + 1] = key;
    }
}
/***************************************END_OF_INSERTION_SORT********************************/

/***************************************MERGESORT********************************************/
void Merge(int *A, int p, int q, int r) {
     int n1 = q - p + 1; //Length of LEFT subarray
     int n2 = r - q; // Length of RIGHT subarray
     int L[n1 + 1], R[n2 + 1]; //Create LEFT & RIGHT arrays

     L[n1] = INT_MAX; //Assign sentinel
     R[n2] = INT_MAX; //Assign sentinel

     for (int i = 0; i < n1; i++) // Copies the subarray A[p...q] into L[1...n1]
         L[i] = A[p + i];
     for (int j = 0; j < n2; j++) // Copies the subarray A[q+1...r] into R[1...n2]
         R[j] = A[q + j + 1];

     int i = 0; // First index such that L[0] contains the smallest element that has not been copied back to A
     int j = 0; // First index such that R[0] contains the smallest element that has not been copied back to A

     for (int k = p; k <= r; k++) {
         if (L[i] <= R[j]) { // Compare the two elements at their respective indicies (both are intially at index 0)
             A[k] = L[i]; // Assign A[K] to the element at L[i] only if the condition above is true
             i++; // Increase the index i by 1 only if the condition above is true
         } else { // If the condtion above is false, then...
             A[k] = R[j]; // Assign A[k] to the value of R[j] if the condition above is false
             j++; // Increase the index i by 1 only if the condition above is false
         }
     }
 }

 void Mergesort(int *A, int p, int r) {
     if(p < r) {
         int result = (p+r)/2;
         int q = floor(result); // q is the mid index (where we partition the array)
         Mergesort(A, p, q);
         Mergesort(A, q + 1, r);
         Merge(A, p, q, r);
     }
 }
/****************************************END_OF_MERGSORT*************************************/

/*******************************************HEAPSORT*****************************************/
int heapsize;

int PARENT(int i) { // Get Parent (This function is not actually used)
     return i/2;
}

int LEFT(int i) { // Get left child
    return (2*i);
}

int RIGHT(int i) { // Get right child
     return (2*i+1);
}

void MAXHEAPIFY(int *A, int i) { // Function to maintain Max-Heap Property
     int largest, l , r;
     l = LEFT(i);
     r = RIGHT(i); 
     /* We want to find the largest out of A[LEFT(i)], A[RIGHT(i)], and A[i]
      * If the largest is A[i], then the subtree rooted at node i is already a Max-HEAP and we're done.
      * If not, then either the left or right child contain the largest in which case we will swap that element (A[largest]) with A[i]
      * such that node i and its children satify the MAX-HEAP property. Note however, that after swapping the subtree rooted at node largest
      * may violate the MAX-HEAP property.
     */
    
     if (l < heapsize && A[l] > A[i]) { 
          largest = l;
     }     else {
          largest = i;
     }
     if (r < heapsize && A[r] > A[largest]) { 
          largest = r;
     }
     if (largest != i) {
          swap(A[i], A[largest]);
          MAXHEAPIFY(A, largest);
     }
}

void BUILDMAXHEAP(int *A, int n) { // Do MAXHEAPIFY for the remaining nodes of the tree to remedy a possible violation and GUARANTEE that each node satisfies the MAX-HEAP property
     heapsize = n;
      for(int i = n/2; i >= 0; i--) { // for n/2 down to 1
           MAXHEAPIFY(A,i);
      }
}

void Heapsort(int *A, int n) {
     BUILDMAXHEAP(A,n);
     for(int i = n-1; i > 0 ; i--) { // for i <- length[A] down to 2 
          swap(A[0],A[i]); 
          heapsize--;
          MAXHEAPIFY(A,0);
     }
}
/***************************************END_OF_HEAPSORT**************************************/

/******************************************QUICKSORT*****************************************/
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

void Quicksort(int *A, int p, int r) {
    if (p < r) { // Condition needed to prevent infinite recursion
        int q = Partition(A,p,r); // partition index 
        Quicksort(A,p,q-1); // 
        Quicksort(A,q+1,r);
    }
}

/***************************************END_OF_QUICKSORT*************************************/

/**************************************RANDOMIZED_QUICKSORT**********************************/
//NOTE: THIS ALGORITHM MAKES USE OF THE PARTITION FUNCTION USED IN QUICKSORT

int RandomizedParition (int *A, int p, int r) {
    srand(time(0));
    int i = p + (rand() % (r-p+1)); // Random pivot
    swap(A[r],A[i]);
    return Partition(A,p,r);
}

void RandomizedQuicksort(int *A, int p, int r) {
    if (p < r) { // Condition needed to prevent infinite recursion
        int q = RandomizedParition(A,p,r); // partition index 
        RandomizedQuicksort(A,p,q-1); // 
        RandomizedQuicksort(A,q+1,r);
    }
}
/***********************************END_OF_RANDOMIZED_QUICKSORT******************************/

/******************************************PrintArray****************************************/
void printArray(int *A, int size) {
   for(int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << "\n";
}
/*******************************************************************************************/


/******************************************************************************************/
void printMenu() {
    int *A, n;
    high_resolution_clock::time_point start;
    high_resolution_clock::time_point stop;
    duration<double> time_span;

    cout << "\t\t\t\t\t\t\t\t\t\t\t\t Welcome!" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t +++++++++++++++++++++++++++++++++++++" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t 1 - Insertion Sort" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t 2 - Merge Sort" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t 3 - Heapsort" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t 4 - Quicksort" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t 5 - Randomized Quicksort" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t 6 - All" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t +++++++++++++++++++++++++++++++++++++" << endl;

  int choice;
  cout << "\n\nSelect a sorting algorithm: ";
  cin >> choice;

  switch(choice) {
    case 1: // Insertion Sort
      cout << "Enter the number of elements: ";
      cin >> n;
      A = (int*)malloc(sizeof(int)*n);
      srand(time(0));
      for (int i = 0 ; i < n; i++) {
        A[i] = rand() % 1000; // random number from 0 to 999
      }
      cout << "Given Array: " << endl;
      printArray(A,n);
      start = high_resolution_clock::now();
      InsertionSort(A, n);
      stop = high_resolution_clock::now();
      time_span = duration_cast<duration<double>>(stop - start);
      cout << "Sorted Array via InsertionSort: " << endl;
      printArray(A, n);
      cout << "\nTime taken by Insertion-Sort: " << time_span.count()*1e6 << " microseconds." << endl;
      break;
    case 2: // Mergesort
      cout << "Enter the number of elements: ";
      cin >> n;
      A = (int*)malloc(sizeof(int)*n);
      srand(time(0));
      for(int i = 0; i < n; i++) {
          A[i] = rand() % 1000;
      }
      cout << "Given Array: " << endl;
      printArray(A,n);
      start = high_resolution_clock::now();
      Mergesort(A,0,n-1);
      stop = high_resolution_clock::now();
      time_span = duration_cast<duration<double>>(stop - start);
      cout << "Sorted Array via Mergesort: " << endl;
      printArray(A, n);
      cout << "\nTime taken by Mergesort: " << time_span.count()*1e6 << " microseconds." << endl;
      break;
    case 3: // Heapsort
      cout << "Enter the number of elements: ";
      cin >> n;
      A = (int*)malloc(sizeof(int)*n);
      srand(time(0));
      for (int i = 0 ; i < n; i++) {
        A[i] = rand() % 1000;
      }
      cout << "Given Array: " << endl;
      printArray(A,n);
      start = high_resolution_clock::now();
      Heapsort(A,n);
      stop = high_resolution_clock::now();
      time_span = duration_cast<duration<double>>(stop - start);
      cout << "Sorted Array via Heapsort: " << endl;
      printArray(A, n);
      cout << "\nTime taken by Heapsort: " << time_span.count()*1e6 << " microseconds." << endl;
      break;
    case 4: // Quicksort
      cout << "Enter the number of elements: ";
      cin >> n;
      A = (int*)malloc(sizeof(int)*n);
      srand(time(0));
      for (int i = 0 ; i < n; i++) {
        A[i] = rand() % 1000;
      }
      cout << "Given Array: " << endl;
      printArray(A,n);
      start = high_resolution_clock::now();
      Quicksort(A,0,n-1);
      stop = high_resolution_clock::now();
      time_span = duration_cast<duration<double>>(stop - start);
      cout << "Sorted Array via Quicksort: " << endl;
      printArray(A,n);
      cout << "\nTime taken by Quicksort: " << time_span.count()*1e6 << " microseconds." << endl;
      break;
    case 5: // Randomized Quicksort
      cout << "Enter the number of elements: ";
      cin >> n;
      A = (int*)malloc(sizeof(int)*n);
      srand(time(0));
      for (int i = 0 ; i < n; i++) {
        A[i] = rand() % 1000;
      }
      cout << "Given Array: " << endl;
      printArray(A,n);
      start = high_resolution_clock::now();
      RandomizedQuicksort(A,0,n-1);
      stop = high_resolution_clock::now();
      time_span = duration_cast<duration<double>>(stop - start);
      cout << "Sorted Array via Randomized Quicksort: " << endl;
      printArray(A,n);
      cout << "\nTime taken by Randomized Quicksort: " << time_span.count()*1e6 << " microseconds." << endl;
      break;
    case 6: // All algorithms
      cout << "Enter the number of elements: ";
      cin >> n;
      A = (int*)malloc(sizeof(int)*n);
      srand(time(0));
      for (int i = 0; i < n; i++) {
          A[i] = rand() % 1000;
      }
      cout << "Given Array: " << endl;
      printArray(A,n);

      start = high_resolution_clock::now();
      InsertionSort(A,n);
      stop = high_resolution_clock::now();
      time_span = duration_cast<duration<double>>(stop - start);
      cout << "\nSorted Array via Insertionsort: " << endl;
      printArray(A,n);
      cout << "\nTime taken by InsertionSort: " << time_span.count()*1e6 << " microseconds." << endl;
      
      start = high_resolution_clock::now();
      Mergesort(A,0,n-1);
      stop = high_resolution_clock::now();
      time_span = duration_cast<duration<double>>(stop - start);
      cout << "\nSorted Array via Mergesort: " << endl;
      printArray(A, n);
      cout << "\nTime taken by Mergesort: " << time_span.count()*1e6 << " microseconds." << endl;

      start = high_resolution_clock::now();
      Heapsort(A,n);
      stop = high_resolution_clock::now();
      time_span = duration_cast<duration<double>>(stop - start);
      cout << "Sorted Array via Heapsort: " << endl;
      printArray(A, n);
      cout << "\nTime taken by Heapsort: " << time_span.count()*1e6 << " microseconds." << endl;
      
      start = high_resolution_clock::now();
      Quicksort(A,0,n-1);
      stop = high_resolution_clock::now();
      time_span = duration_cast<duration<double>>(stop - start);
      cout << "Sorted Array via Quicksort: " << endl;
      printArray(A,n);
      cout << "\nTime taken by Quicksort: " << time_span.count()*1e6 << " microseconds." << endl;
      
      start = high_resolution_clock::now();
      RandomizedQuicksort(A,0,n-1);
      stop = high_resolution_clock::now();
      time_span = duration_cast<duration<double>>(stop - start);
      cout << "Sorted Array via Randomized Quicksort: " << endl;
      printArray(A,n);
      cout << "\nTime taken by Randomized Quicksort: " << time_span.count()*1e6 << " microseconds." << endl;

      break;
    default:
      cout << "Invaild choice!" << endl;
      break;
  }
}
/**************************************************************************************************************************/

int main() {
  bool quit = false;
  char leave;
  do {
      printMenu();
      cout << "\nWould you like to quit? Y/N ";
      cin >> leave;
      if (leave == 'y' || leave == 'Y') quit = true;
  } while (quit == false);
  cout << "\t\t\t\t\t\t\t\t\t\t\t\tGoodbye!" << endl;
  return 0;
}

