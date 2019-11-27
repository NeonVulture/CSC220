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
      A = (int*
      break;
    default:
      cout << "Invaild choice!" << endl;
      break;
  }
  return 0;
}

/******************************************INSERTION_SORT*************************************/
/*********************************************************************************************/
