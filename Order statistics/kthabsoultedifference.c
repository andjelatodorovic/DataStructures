// C++ program to find k-th absolute difference 
// between two elements 
#include<bits/stdc++.h> 
using namespace std; 

// returns number of pairs with absolute difference 
// less than or equal to mid. 
int countPairs(int *a, int n, int mid) 
{ 
	int res = 0; 
	for (int i = 0; i < n; ++i) 

		// Upper bound returns pointer to position 
		// of next higher number than a[i]+mid in 
		// a[i..n-1]. We subtract (a + i + 1) from 
		// this position to count 
		res += upper_bound(a+i, a+n, a[i] + mid) - 
									(a + i + 1); 
	return res; 
} 

// Returns k-th absolute difference 
int kthDiff(int a[], int n, int k) 
{ 
	// Sort array 
	sort(a, a+n); 

	// Minimum absolute difference 
	int low = a[1] - a[0]; 
	for (int i = 1; i <= n-2; ++i) 
		low = min(low, a[i+1] - a[i]); 

	// Maximum absolute difference 
	int high = a[n-1] - a[0]; 

	// Do binary search for k-th absolute difference 
	while (low < high) 
	{ 
		int mid = (low+high)>>1; 
		if (countPairs(a, n, mid) < k) 
			low = mid + 1; 
		else
			high = mid; 
	} 

	return low; 
} 

// Driver code 
int main() 
{ 
	int k = 3; 
	int a[] = {1, 2, 3, 4}; 
	int n = sizeof(a)/sizeof(a[0]); 
	cout << kthDiff(a, n, k); 
	return 0; 
} 

