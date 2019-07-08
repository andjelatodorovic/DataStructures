// CPP program to find sum of heights of all 
// nodes in a binary tree 
#include <stdio.h> 
#include <stdlib.h> 

/* A binary tree Node has data, pointer to 
	left child and a pointer to right child */
struct Node { 
	int data; 
	struct Node* left; 
	struct Node* right; 
}; 

/* Compute the "maxHeight" of a particular Node*/
int getHeight(struct Node* Node) 
{ 
	if (Node == NULL) 
		return 0; 
	else { 
		/* compute the height of each subtree */
		int lHeight = getHeight(Node->left); 
		int rHeight = getHeight(Node->right); 

		/* use the larger one */
		if (lHeight > rHeight) 
			return (lHeight + 1); 
		else
			return (rHeight + 1); 
	} 
} 

/* Helper function that allocates a new Node with the 
given data and NULL left and right pointers. */
struct Node* newNode(int data) 
{ 
	struct Node* Node = (struct Node*) 
		malloc(sizeof(struct Node)); 
	Node->data = data; 
	Node->left = NULL; 
	Node->right = NULL; 

	return (Node); 
} 

/* Function to sum of heights of individual Nodes 
Uses Inorder traversal */
int getTotalHeight(struct Node* root) 
{ 
	if (root == NULL) 
		return 0; 

	return getTotalHeight(root->left) + 
		getHeight(root) + 
		getTotalHeight(root->right); 
} 

// Driver code 
int main() 
{ 
	struct Node* root = newNode(1); 

	root->left = newNode(2); 
	root->right = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	printf("Sum of heights of all Nodes = %d",	 
						getTotalHeight(root)); 
	return 0; 
} 

