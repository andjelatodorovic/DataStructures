// C++ implementation to find k numbers with most 
// occurrences in the given array 
#include <bits/stdc++.h> 

using namespace std; 

// comparison function to sort the 'freq_arr[]' 
bool compare(pair<int, int> p1, pair<int, int> p2) 
{ 
	// if frequencies of two elements are same 
	// then the larger number should come first 
	if (p1.second == p2.second) 
		return p1.first > p2.first; 
		
	// sort on the basis of decreasing order 
	// of frequencies	 
	return p1.second > p2.second;	 
} 

// funnction to print the k numbers with most occurrences 
void print_N_mostFrequentNumber(int arr[], int n, int k) 
{ 
	// unordered_map 'um' implemented as frequency hash table 
	unordered_map<int, int> um; 
	for (int i = 0; i<n; i++) 
		um[arr[i]]++; 
		
	// store the elements of 'um' in the vector 'freq_arr'	 
	vector<pair<int, int> > freq_arr(um.begin(), um.end()); 
	
	// sort the vector 'freq_arr' on the basis of the 
	// 'compare' function 
	sort(freq_arr.begin(), freq_arr.end(), compare); 
	
	// display the the top k numbers 
	cout << k << " numbers with most occurrences are:\n"; 
	for (int i = 0; i<k; i++) 
		cout << freq_arr[i].first << " "; 
} 

// Driver program to test above 
int main() 
{ 
	int arr[] = {3, 1, 4, 4, 5, 2, 6, 1}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	int k = 2; 
	print_N_mostFrequentNumber(arr, n, k); 
	return 0; 
} 



