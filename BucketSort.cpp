#include <iostream> 
#include <algorithm> 
#include <vector> 
using namespace std; 
  

// Function to sort arr[] of size n using bucket sort 
void bucketSort(float A[]) 
{
    int n = 6;
    // 1) Create n empty buckets 
    vector<float> B[n]; 
     
    // 2) Put array elements in different buckets 
    for (int i = 0; i < n; i++) 
    { 
       int bi = n*A[i]; // Index in bucket 
       B[bi].push_back(A[i]); 
    } 
  
    // 3) Sort individual buckets 
    for (int i=0; i<n; i++) 
       sort(B[i].begin(), B[i].end()); 
  
    // 4) Concatenate all buckets into arr[] 
    int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < B[i].size(); j++) 
         A[index++] = B[i][j]; 
} 
  
/* Driver program to test above funtion */
int main() 
{ 
    float A[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434}; 
    int n = sizeof(A)/sizeof(A[0]); 
    //bucketSort(A, n); 
    bucketSort(A);
  
    cout << "Sorted array is \n"; 
    for (int i=0; i<n; i++) 
       cout << A[i] << " "; 
    return 0; 
} 
