// C++ program to check if a given tree is 
// Binary Heap or not 
#include <bits/stdc++.h> 
using namespace std; 

// Returns true if given level order traversal 
// is Min Heap. 
bool isMinHeap(int level[], int n) 
{ 
	// First non leaf node is at index (n/2-1). 
	// Check whether each parent is greater than child 
	for (int i=(n/2-1) ; i>=0 ; i--) 
	{ 
		// Left child will be at index 2*i+1 
		// Right child will be at index 2*i+2 
		if (level[i] > level[2 * i + 1]) 
			return false; 

		if (2*i + 2 < n) 
		{ 
			// If parent is greater than right child 
			if (level[i] > level[2 * i + 2]) 
				return false; 
		} 
	} 
	return true; 
} 

// Driver code 
int main() 
{ 
	int level[] = {10, 15, 14, 25, 30}; 
	int n = sizeof(level)/sizeof(level[0]); 
	if (isMinHeap(level, n)) 
		cout << "True"; 
	else
		cout << "False"; 
	return 0; 
} 

