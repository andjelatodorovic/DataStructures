// C++ program to rearrange a given list such that it 
// consists of alternating minimum maximum elements 
#include <bits/stdc++.h> 
using namespace std; 

// Function to rearrange a given list such that it 
// consists of alternating minimum maximum elements 
void alternateSort(list<int>& inp) 
{ 
	// sort the list in ascending order 
	inp.sort(); 

	// get iterator to first element of the list 
	list<int>::iterator it = inp.begin(); 
	it++; 

	for (int i=1; i<(inp.size() + 1)/2; i++) 
	{ 
		// pop last element (next greatest) 
		int val = inp.back(); 
		inp.pop_back(); 

		// insert it after next minimum element 
		inp.insert(it, val); 

		// increment the pointer for next pair 
		++it; 
	} 
} 

// Driver code 
int main() 
{ 
	// input list 
	list<int> inp({ 1, 3, 8, 2, 7, 5, 6, 4 }); 

	// rearrange the given list 
	alternateSort(inp); 

	// print the modified list 
	for (int i : inp) 
		cout << i << " "; 

	return 0; 
} 

