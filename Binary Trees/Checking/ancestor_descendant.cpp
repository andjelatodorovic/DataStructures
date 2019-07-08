// C/C++ program to query whether two node has 
// ancestor-descendant relationship or not 
#include <bits/stdc++.h> 
using namespace std; 

// Utility dfs method to assign in and out time 
// to each node 
void dfs(vector<int> g[], int u, int parent, 
		int timeIn[], int timeOut[], int& cnt) 
{ 
	// assign In-time to node u 
	timeIn[u] = cnt++; 

	// call dfs over all neighbors except parent 
	for (int i = 0; i < g[u].size(); i++) { 
		int v = g[u][i]; 
		if (v != parent) 
			dfs(g, v, u, timeIn, timeOut, cnt); 
	} 

	// assign Out-time to node u 
	timeOut[u] = cnt++; 
} 

// method to preprocess all nodes for assigning time 
void preProcess(int edges[][2], int V, int timeIn[], 
				int timeOut[]) 
{ 
	vector<int> g[V]; 

	// construct array of vector data structure 
	// for tree 
	for (int i = 0; i < V - 1; i++) { 
		int u = edges[i][0]; 
		int v = edges[i][1]; 

		g[u].push_back(v); 
		g[v].push_back(u); 
	} 

	int cnt = 0; 

	// call dfs method from root 
	dfs(g, 0, -1, timeIn, timeOut, cnt); 
} 

// method returns "yes" if u is a ancestor 
// node of v 
string isAncestor(int u, int v, int timeIn[], 
				int timeOut[]) 
{ 
	bool b = (timeIn[u] <= timeIn[v] && 
			timeOut[v] <= timeOut[u]); 
	return (b ? "yes" : "no"); 
} 

// Driver code to test abovea methods 
int main() 
{ 
	int edges[][2] = { 
		{ 0, 1 }, 
		{ 0, 2 }, 
		{ 1, 3 }, 
		{ 1, 4 }, 
		{ 2, 5 }, 
		{ 4, 6 }, 
		{ 5, 7 } 
	}; 

	int E = sizeof(edges) / sizeof(edges[0]); 
	int V = E + 1; 

	int timeIn[V], timeOut[V]; 
	preProcess(edges, V, timeIn, timeOut); 

	int u = 1; 
	int v = 6; 
	cout << isAncestor(u, v, timeIn, timeOut) << endl; 

	u = 1; 
	v = 7; 
	cout << isAncestor(u, v, timeIn, timeOut) << endl; 

	return 0; 
} 

