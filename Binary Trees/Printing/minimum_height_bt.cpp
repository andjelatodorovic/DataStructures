// C++ program to find minimum depth of a given Binary Tree 
#include<bits/stdc++.h> 
using namespace std; 

// A BT Node 
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}; 

int minDepth(Node *root) 
{ 
	// Corner case. Should never be hit unless the code is 
	// called on root = NULL 
	if (root == NULL) 
		return 0; 

	// Base case : Leaf Node. This accounts for height = 1. 
	if (root->left == NULL && root->right == NULL) 
	return 1; 

	// If left subtree is NULL, recur for right subtree 
	if (!root->left) 
	return minDepth(root->right) + 1; 

	// If right subtree is NULL, recur for left subtree 
	if (!root->right) 
	return minDepth(root->left) + 1; 

	return min(minDepth(root->left), minDepth(root->right)) + 1; 
} 

// Utility function to create new Node 
Node *newNode(int data) 
{ 
	Node *temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return (temp); 
} 

// Driver program 
int main() 
{ 
	// Let us construct the Tree shown in the above figure 
	Node *root	 = newNode(1); 
	root->left	 = newNode(2); 
	root->right	 = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	cout <<"The minimum depth of binary tree is : "<< minDepth(root); 
	return 0; 
} 

