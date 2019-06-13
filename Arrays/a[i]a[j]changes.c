// C++ program to sort an array according to given 
// indexes 
#include<iostream> 

using namespace std; 

// Function to reorder elements of arr[] according 
// to index[] 
void reorder(int arr[], int index[], int n) 
{ 
	int temp[n]; 

	// arr[i] should be present at index[i] index 
	for (int i=0; i<n; i++) 
		temp[index[i]] = arr[i]; 

	// Copy temp[] to arr[] 
	for (int i=0; i<n; i++) 
	{ 
	arr[i] = temp[i]; 
	index[i] = i; 
	} 
} 

// Driver program 
int main() 
{ 
	int arr[] = {50, 40, 70, 60, 90}; 
	int index[] = {3, 0, 4, 1, 2}; 
	int n = sizeof(arr)/sizeof(arr[0]); 

	reorder(arr, index, n); 

	cout << "Reordered array is: \n"; 
	for (int i=0; i<n; i++) 
		cout << arr[i] << " "; 

	cout << "\nModified Index array is: \n"; 
	for (int i=0; i<n; i++) 
		cout << index[i] << " "; 
	return 0; 
} 

