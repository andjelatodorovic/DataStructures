// C++ Program to check duplicates 
// in Binary Tree 
#include <bits/stdc++.h> 
using namespace std; 

// A binary tree Node has data, 
// pointer to left child 
// and a pointer to right child 
struct Node { 
	int data; 
	struct Node* left; 
	struct Node* right; 
}; 

// Helper function that allocates 
// a new Node with the given data 
// and NULL left and right pointers. 
struct Node* newNode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

bool checkDupUtil(Node* root, unordered_set<int> &s) 
{ 
	// If tree is empty, there are no 
	// duplicates. 
	if (root == NULL) 
	return false; 

	// If current node's data is already present. 
	if (s.find(root->data) != s.end()) 
	return true; 

	// Insert current node 
	s.insert(root->data); 
	
	// Recursively check in left and right 
	// subtrees. 
	return checkDupUtil(root->left, s) || 
		checkDupUtil(root->right, s); 
} 

// To check if tree has duplicates 
bool checkDup(struct Node* root) 
{ 
	unordered_set<int> s; 
	return checkDupUtil(root, s); 
} 

// Driver program to test above functions 
int main() 
{ 
	struct Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(2); 
	root->left->left = newNode(3); 
	if (checkDup(root)) 
		printf("Yes"); 
	else
		printf("No"); 

	return 0; 
} 

