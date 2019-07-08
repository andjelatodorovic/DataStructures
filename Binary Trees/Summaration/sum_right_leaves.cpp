// CPP program to find total sum 
// of right leaf nodes 
#include <bits/stdc++.h> 
using namespace std; 

// struct node of binary tree 
struct Node{ 
	int data; 
	Node *left, *right; 
}; 

// return new node 
Node *addNode(int data){ 
	Node *temp = new Node(); 
	temp->data = data; 
	temp->left = temp->right = NULL; 
} 

// utility function to calculate sum 
// of right leaf nodes 
void rightLeafSum(Node *root, int *sum){ 
	if(!root) 
		return; 

	// check if the right child of root 
	// is leaf node 
	if(root->right) 
		if(!root->right->left && 
					!root->right->right) 
			*sum += root->right->data; 

	rightLeafSum(root->left, sum); 
	rightLeafSum(root->right, sum); 
} 

// driver program 
int main(){ 
	
		//contruct binary tree 
	Node *root = addNode(1); 
	root->left = addNode(2); 
	root->left->left = addNode(4); 
	root->left->right = addNode(5); 
	root->left->left->right = addNode(2); 
	root->right = addNode(3); 
	root->right->right = addNode(8); 
	root->right->right->left = addNode(6); 
	root->right->right->right = addNode(7); 

	// variable to store sum of right 
	// leaves 
	int sum = 0; 
	rightLeafSum(root, &sum); 
	cout << sum << endl; 
	return 0; 
} 

