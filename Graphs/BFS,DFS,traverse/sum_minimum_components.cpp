// C++ program to find the sum 
// of the minimum elements in all 
// connected components of an undirected graph 
#include <bits/stdc++.h> 
using namespace std; 
const int N = 10000; 
vector<int> graph[N]; 

// Initially all nodes 
// marked as unvisited 
bool visited[N]; 

// DFS function that visits all 
// connected nodes from a given node 
void dfs(int node, int a[], int mini) 
{ 
	// Stores the minimum 
	mini = min(mini, a[node]); 

	// Marks node as visited 
	visited[node] = true; 

	// Traversed in all the connected nodes 
	for (int i : graph[node]) { 
		if (!visited[i]) 
			dfs(i, a, mini); 
	} 
} 

// Function to add the edges 
void addedge(int u, int v) 
{ 
	graph[u - 1].push_back(v - 1); 
	graph[v - 1].push_back(u - 1); 
} 

// Function that returns the sum of all minimums 
// of connected componenets of graph 
int minimumSumConnectedComponents(int a[], int n) 
{ 
	// Initially sum is 0 
	int sum = 0; 

	// Traverse for all nodes 
	for (int i = 0; i < n; i++) { 
		if (!visited[i]) { 
			int mini = a[i]; 
			dfs(i, a, mini); 
			sum += mini; 
		} 
	} 
	
	// Returns the answer 
	return sum; 
} 

// Driver Code 
int main() 
{ 
	int a[] = {1, 6, 2, 7, 3, 8, 4, 9, 5, 10}; 
	
	// Add edges 
	addedge(1, 2); 
	addedge(3, 4); 
	addedge(5, 6); 
	addedge(7, 8); 
	addedge(9, 10); 
	
	int n = sizeof(a) / sizeof(a[0]); 

	// Calling Function 
	cout << minimumSumConnectedComponents(a, n); 
	return 0; 
} 

