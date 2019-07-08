// C++ program to check if there exist an edge whose 
// removal creates two trees of same size 
#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}; 

// utility function to create a new node 
struct Node* newNode(int x) 
{ 
	struct Node* temp = new Node; 
	temp->data = x; 
	temp->left = temp->right = NULL; 
	return temp; 
}; 

// To calculate size of tree with given root 
int count(Node* root) 
{ 
	if (root==NULL) 
		return 0; 
	return count(root->left) + count(root->right) + 1; 
} 

// This function returns true if there is an edge 
// whose removal can divide the tree in two halves 
// n is size of tree 
bool checkRec(Node* root, int n) 
{ 
	// Base cases 
	if (root ==NULL) 
	return false; 

	// Check for root 
	if (count(root) == n-count(root)) 
		return true; 

	// Check for rest of the nodes 
	return checkRec(root->left, n) || 
		checkRec(root->right, n); 
} 

// This function mainly uses checkRec() 
bool check(Node *root) 
{ 
	// Count total nodes in given tree 
	int n = count(root); 

	// Now recursively check all nodes 
	return checkRec(root, n); 
} 

// Driver code 
int main() 
{ 
	struct Node* root = newNode(5); 
	root->left = newNode(1); 
	root->right = newNode(6); 
	root->left->left = newNode(3); 
	root->right->left = newNode(7); 
	root->right->right = newNode(4); 

	check(root)? printf("YES") : printf("NO"); 

	return 0; 
} 

