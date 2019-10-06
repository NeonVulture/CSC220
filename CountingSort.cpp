#include<iostream>
using namespace std;

int k = 0;

void Counting_Sort(int A[],int B[],int n)    
{
	int C[k]; //Initializating of a new array C which provides temporary storage  
	for(int i = 0; i < k+1; i++)
	{
		//Initialize the array C with zeroes
		C[i]=0;
	}
	for(int j = 1;j <= n; j++)
	{
		/*It will count the occurence of every element x in A 
		and increment it at position x in C*/
		C[A[j]]++;	
		// C[i] Now contains the number of elements equal to each i to k
	}
	for(int i = 1; i <= k; i++)
	{
		/*It will store the last 
		occurence of the element i */
		C[i] += C[i-1];
		//C[i] now contains the number of elements less than or equal to i
	}
	for(int j = n ; j>=1; j--)
	{
		/*It will place the elements at their 
		respective index*/
		B[C[A[j]]] = A[j];          
		/*It will help if an element occurs 
		more than one time*/
		C[A[j]] = C[A[j]] - 1;		  
	}
}

int main() {
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	
	//A is the input array which stores the elements input by user
	//B is the output array and holds the sorted array of A  	
	int A[n],B[n]; 
	
	for(int i = 1; i <= n; i++)        
	{
		cin >> A[i];
		if(A[i] > k)
		{
			/*It will modify k if an element 
			occurs whose value is greater than k*/
			k = A[i];              
		}
	}
	Counting_Sort(A,B,n);        
	/*It will print the sorted sequence on the 
	console*/ 
	for(int i = 1; i <= n; i++)       
	{
		cout << B[i] << " ";
	}
	
	cout << "\n";
	return 0;
}
