#include<stdio.h> 

/* A tree node structure */
struct node 
{ 
int data; 
struct node *left; 
struct node *right; 
}; 

// Convert a given tree to a tree where every node contains sum of values of 
// nodes in left and right subtrees in the original tree 
int toSumTree(struct node *node) 
{ 
	// Base case 
	if(node == NULL) 
	return 0; 

	// Store the old value 
	int old_val = node->data; 

	// Recursively call for left and right subtrees and store the sum as 
	// new value of this node 
	node->data = toSumTree(node->left) + toSumTree(node->right); 

	// Return the sum of values of nodes in left and right subtrees and 
	// old_value of this node 
	return node->data + old_val; 
} 

// A utility function to print inorder traversal of a Binary Tree 
void printInorder(struct node* node) 
{ 
	if (node == NULL) 
		return; 
	printInorder(node->left); 
	printf("%d ", node->data); 
	printInorder(node->right); 
} 

/* Utility function to create a new Binary Tree node */
struct node* newNode(int data) 
{ 
struct node *temp = new struct node; 
temp->data = data; 
temp->left = NULL; 
temp->right = NULL; 

return temp; 
} 

/* Driver function to test above functions */
int main() 
{ 
struct node *root = NULL; 
int x; 

/* Constructing tree given in the above figure */
root = newNode(10); 
root->left = newNode(-2); 
root->right = newNode(6); 
root->left->left = newNode(8); 
root->left->right = newNode(-4); 
root->right->left = newNode(7); 
root->right->right = newNode(5); 

toSumTree(root); 

// Print inorder traversal of the converted tree to test result of toSumTree() 
printf("Inorder Traversal of the resultant tree is: \n"); 
printInorder(root); 

getchar(); 
return 0; 
} 

