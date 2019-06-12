// CPP program to find minimum product of 
// k elements in an array 
#include <bits/stdc++.h> 
using namespace std; 

int minProduct(int arr[], int n, int k) 
{ 
	priority_queue<int, vector<int>, greater<int> > pq; 
	for (int i = 0; i < n; i++) 
		pq.push(arr[i]); 

	int count = 0, ans = 1; 

	// One by one extract items from max heap 
	while (pq.empty() == false && count < k) { 
		ans = ans * pq.top(); 
		pq.pop(); 
		count++; 
	} 

	return ans; 
} 

// Driver code 
int main() 
{ 
	int arr[] = {198, 76, 544, 123, 154, 675}; 
	int k = 2; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Minimum product is "
		<< minProduct(arr, n, k); 
	return 0; 
} 

