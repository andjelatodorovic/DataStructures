// C++ implementation to check if the given array 
// can represent Level Order Traversal of Binary 
// Search Tree 
#include <bits/stdc++.h> 

using namespace std; 

// to store details of a node like 
// node's data, 'min' and 'max' to obtain the 
// range of values where node's left and 
// right child's should lie 
struct NodeDetails 
{ 
	int data; 
	int min, max; 
}; 

// function to check if the given array 
// can represent Level Order Traversal 
// of Binary Search Tree 
bool levelOrderIsOfBST(int arr[], int n) 
{ 
	// if tree is empty 
	if (n == 0) 
		return true; 
	
	// queue to store NodeDetails 
	queue<NodeDetails> q; 
	
	// index variable to access array elements 
	int i=0; 
	
	// node details for the 
	// root of the BST 
	NodeDetails newNode; 
	newNode.data = arr[i++]; 
	newNode.min = INT_MIN; 
	newNode.max = INT_MAX; 
	q.push(newNode); 
	
	// until there are no more elements 
	// in arr[] or queue is not empty 
	while (i != n && !q.empty())		 
	{ 
		// extracting NodeDetails of a 
		// node from the queue 
		NodeDetails temp = q.front(); 
		q.pop(); 
		
		// check whether there are more elements 
		// in the arr[] and arr[i] can be left child 
		// of 'temp.data' or not 
		if (i < n && (arr[i] < temp.data && 
					arr[i] > temp.min)) 
		{ 
			// Create NodeDetails for newNode 
			/// and add it to the queue 
			newNode.data = arr[i++]; 
			newNode.min = temp.min; 
			newNode.max = temp.data; 
			q.push(newNode);				 
		} 
		
		// check whether there are more elements 
		// in the arr[] and arr[i] can be right child 
		// of 'temp.data' or not 
		if (i < n && (arr[i] > temp.data && 
					arr[i] < temp.max)) 
		{ 
			// Create NodeDetails for newNode 
			/// and add it to the queue 
			newNode.data = arr[i++]; 
			newNode.min = temp.data; 
			newNode.max = temp.max; 
			q.push(newNode);			 
		}		 
	} 
	
	// given array represents level 
	// order traversal of BST 
	if (i == n) 
		return true; 
		
	// given array do not represent 
	// level order traversal of BST	 
	return false;		 
} 

// Driver program to test above 
int main() 
{ 
	int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};	 
	int n = sizeof(arr) / sizeof(arr[0]);	 
	if (levelOrderIsOfBST(arr, n)) 
		cout << "Yes"; 
	else
		cout << "No";		 
	return 0;	 
} 
