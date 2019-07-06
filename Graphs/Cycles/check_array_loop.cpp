// C++ program to check if a given array is cyclic or not 
#include<bits/stdc++.h> 
using namespace std; 

// A simple Graph DFS based recursive function to check if 
// there is cycle in graph with vertex v as root of DFS. 
// Refer below article for details. 
// https://www.geeksforgeeks.org/detect-cycle-in-a-graph/ 
bool isCycleRec(int v, vector<int>adj[], 
			vector<bool> &visited, vector<bool> &recur) 
{ 
	visited[v] = true; 
	recur[v] = true; 
	for (int i=0; i<adj[v].size(); i++) 
	{ 
		if (visited[adj[v][i]] == false) 
		{ 
			if (isCycleRec(adj[v][i], adj, visited, recur)) 
				return true; 
		} 

		// There is a cycle if an adjacent is visited 
		// and present in recursion call stack recur[] 
		else if (visited[adj[v][i]] == true && 
				recur[adj[v][i]] == true) 
			return true; 
	} 

	recur[v] = false; 
	return false; 
} 

// Returns true if arr[] has cycle 
bool isCycle(int arr[], int n) 
{ 
	// Create a graph using given moves in arr[] 
	vector<int>adj[n]; 
	for (int i=0; i<n; i++) 
	if (i != (i+arr[i]+n)%n) 
		adj[i].push_back((i+arr[i]+n)%n); 

	// Do DFS traversal of graph to detect cycle 
	vector<bool> visited(n, false); 
	vector<bool> recur(n, false); 
	for (int i=0; i<n; i++) 
		if (visited[i]==false) 
			if (isCycleRec(i, adj, visited, recur)) 
				return true; 
	return true; 
} 

// Driver code 
int main(void) 
{ 
	int arr[] = {2, -1, 1, 2, 2}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	if (isCycle(arr, n)) 
		cout << "Yes"<<endl; 
	else
		cout << "No"<<endl; 
	return 0; 
} 

