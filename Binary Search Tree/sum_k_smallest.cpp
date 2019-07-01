// c++ program to find Sum Of All Elements smaller 
// than or equal to Kth Smallest Element In BST 
#include <bits/stdc++.h> 
using namespace std; 

/* Binary tree Node */
struct Node 
{ 
	int data; 
	Node* left, * right; 
}; 

// utility function new Node of BST 
struct Node *createNode(int data) 
{ 
	Node * new_Node = new Node; 
	new_Node->left = NULL; 
	new_Node->right = NULL; 
	new_Node->data = data; 
	return new_Node; 
} 

// A utility function to insert a new Node 
// with given key in BST and also maintain lcount ,Sum 
struct Node * insert(Node *root, int key) 
{ 
	// If the tree is empty, return a new Node 
	if (root == NULL) 
		return createNode(key); 

	// Otherwise, recur down the tree 
	if (root->data > key) 
		root->left = insert(root->left, key); 

	else if (root->data < key) 
		root->right = insert(root->right, key); 

	// return the (unchanged) Node pointer 
	return root; 
} 

// function return sum of all element smaller than 
// and equal to Kth smallest element 
int ksmallestElementSumRec(Node *root, int k, int &count) 
{ 
	// Base cases 
	if (root == NULL) 
		return 0; 
	if (count > k) 
		return 0; 

	// Compute sum of elements in left subtree 
	int res = ksmallestElementSumRec(root->left, k, count); 
	if (count >= k) 
		return res; 

	// Add root's data 
	res += root->data; 

	// Add current Node 
	count++; 
	if (count >= k) 
	return res; 

	// If count is less than k, return right subtree Nodes 
	return res + ksmallestElementSumRec(root->right, k, count); 
} 

// Wrapper over ksmallestElementSumRec() 
int ksmallestElementSum(struct Node *root, int k) 
{ 
int count = 0; 
ksmallestElementSumRec(root, k, count); 
} 

/* Driver program to test above functions */
int main() 
{ 

	/* 20 
		/ \ 
	8	 22 
	/ \ 
	4	 12 
		/ \ 
		10 14 
		*/
	Node *root = NULL; 
	root = insert(root, 20); 
	root = insert(root, 8); 
	root = insert(root, 4); 
	root = insert(root, 12); 
	root = insert(root, 10); 
	root = insert(root, 14); 
	root = insert(root, 22); 

	int k = 3; 
	cout << ksmallestElementSum(root, k) <<endl; 
	return 0; 
} 

