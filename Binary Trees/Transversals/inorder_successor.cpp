// CPP program to find inorder successor of a node 
#include<bits/stdc++.h> 
using namespace std; 

// A Binary Tree Node 
struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// Temporary node for case 2 
Node* temp = new Node; 

// Utility function to create a new tree node 
Node* newNode(int data) 
{ 
	Node *temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// function to find left most node in a tree 
Node* leftMostNode(Node* node) 
{ 
	while (node != NULL && node->left != NULL) 
		node = node->left; 
	return node; 
} 

// function to find right most node in a tree 
Node* rightMostNode(Node* node) 
{ 
	while (node != NULL && node->right != NULL) 
		node = node->right; 
	return node; 
} 

// recursive function to find the Inorder Scuccessor 
// when the right child of node x is NULL 
Node* findInorderRecursive(Node* root, Node* x ) 
{ 
	if (!root) 
		return NULL; 

	if (root==x || (temp = findInorderRecursive(root->left,x)) || 
				(temp = findInorderRecursive(root->right,x))) 
	{ 
		if (temp) 
		{ 
			if (root->left == temp) 
			{ 
				cout << "Inorder Successor of " << x->data; 
				cout << " is "<< root->data << "\n"; 
				return NULL; 
			} 
		} 

		return root; 
	} 

	return NULL; 
} 

// function to find inorder successor of 
// a node 
void inorderSuccesor(Node* root, Node* x) 
{ 
	// Case1: If right child is not NULL 
	if (x->right != NULL) 
	{ 
		Node* inorderSucc = leftMostNode(x->right); 
		cout<<"Inorder Successor of "<<x->data<<" is "; 
		cout<<inorderSucc->data<<"\n"; 
	} 

	// Case2: If right child is NULL 
	if (x->right == NULL) 
	{	 
		int f = 0; 
		
		Node* rightMost = rightMostNode(root); 

		// case3: If x is the right most node 
		if (rightMost == x) 
			cout << "No inorder successor! Right most node.\n"; 
		else
			findInorderRecursive(root, x); 
	} 
} 

// Driver program to test above functions 
int main() 
{ 
	// Let's construct the binary tree 
	// as shown in above diagram 

	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->right = newNode(6); 

	// Case 1 
	inorderSuccesor(root, root->right); 

	// case 2 
	inorderSuccesor(root, root->left->left); 

	// case 3 
	inorderSuccesor(root, root->right->right); 

	return 0; 
} 

