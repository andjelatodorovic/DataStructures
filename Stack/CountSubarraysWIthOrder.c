// C++ program to count number of distinct instance 
// where second highest number lie 
// before highest number in all subarrays. 
#include <bits/stdc++.h> 
#define MAXN 100005 
using namespace std; 

// Finding the next greater element of the array. 
void makeNext(int arr[], int n, int nextBig[]) 
{ 
	stack<pair<int, int> > s; 

	for (int i = n - 1; i >= 0; i--) { 

		nextBig[i] = i; 
		while (!s.empty() && s.top().first < arr[i]) 
			s.pop(); 

		if (!s.empty()) 
			nextBig[i] = s.top().second; 

		s.push(pair<int, int>(arr[i], i)); 
	} 
} 

// Finding the previous greater element of the array. 
void makePrev(int arr[], int n, int prevBig[]) 
{ 
	stack<pair<int, int> > s; 
	for (int i = 0; i < n; i++) { 

		prevBig[i] = -1; 
		while (!s.empty() && s.top().first < arr[i]) 
			s.pop(); 

		if (!s.empty()) 
			prevBig[i] = s.top().second; 

		s.push(pair<int, int>(arr[i], i)); 
	} 
} 

// Wrapper Function 
int wrapper(int arr[], int n) 
{ 
	int nextBig[MAXN]; 
	int prevBig[MAXN]; 
	int maxi[MAXN]; 
	int ans = 0; 

	// Finding previous largest element 
	makePrev(arr, n, prevBig); 

	// Finding next largest element 
	makeNext(arr, n, nextBig); 

	for (int i = 0; i < n; i++) 
		if (nextBig[i] != i) 
			maxi[nextBig[i] - i] = max(maxi[nextBig[i] - i], 
									i - prevBig[i]); 

	for (int i = 0; i < n; i++) 
		ans += maxi[i]; 

	return ans; 
} 

// Driven Program 
int main() 
{ 
	int arr[] = { 1, 3, 2, 4 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << wrapper(arr, n) << endl; 
	return 0; 
} 

