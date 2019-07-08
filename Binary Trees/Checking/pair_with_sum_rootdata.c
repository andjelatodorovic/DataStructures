// C++ program to find if there is a pair in any root 
// to leaf path with sum equals to root's key. 
#include<bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}; 

/* utility that allocates a new node with the 
given data and NULL left and right pointers. */
struct Node* newnode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

// Function to print root to leaf path which satisfies the condition 
bool printPathUtil(Node *node, unordered_set<int> &s, int root_data) 
{ 
	// Base condition 
	if (node == NULL) 
		return false; 

	// Check if current node makes a pair with any of the 
	// existing elements in set. 
	int rem = root_data - node->data; 
	if (s.find(rem) != s.end()) 
		return true; 

	// Insert current node in set 
	s.insert(node->data); 

	// If result returned by either left or right child is 
	// true, return true. 
	bool res = printPathUtil(node->left, s, root_data) || 
			printPathUtil(node->right, s, root_data); 

	// Remove current node from hash table 
	s.erase(node->data); 

	return res; 
} 

// A wrapper over printPathUtil() 
bool isPathSum(Node *root) 
{ 
// create an empty hash table 
unordered_set<int> s; 

// Recursively check in left and right subtrees. 
return printPathUtil(root->left, s, root->data) || 
		printPathUtil(root->right, s, root->data); 
} 

// Driver program to run the case 
int main() 
{ 
	struct Node *root = newnode(8); 
	root->left = newnode(5); 
	root->right = newnode(4); 
	root->left->left = newnode(9); 
	root->left->right = newnode(7); 
	root->left->right->left = newnode(1); 
	root->left->right->right = newnode(12); 
	root->left->right->right->right = newnode(2); 
	root->right->right = newnode(11); 
	root->right->right->left = newnode(3); 
	isPathSum(root)? cout << "Yes" : cout << "No"; 
	return 0; 
} 

