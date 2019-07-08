// C++ program to find if there is a subtree with 
// given sum 
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

// function to check if there exist any subtree with given sum 
// cur_sum --> sum of current subtree from ptr as root 
// sum_left --> sum of left subtree from ptr as root 
// sum_right --> sum of right subtree from ptr as root 
bool sumSubtreeUtil(struct Node *ptr, int *cur_sum, int sum) 
{ 
	// base condition 
	if (ptr == NULL) 
	{ 
		*cur_sum = 0; 
		return false; 
	} 

	// Here first we go to left sub-tree, then right subtree 
	// then first we calculate sum of all nodes of subtree 
	// having ptr as root and assign it as cur_sum 
	// cur_sum = sum_left + sum_right + ptr->data 
	// after that we check if cur_sum == sum 
	int sum_left = 0, sum_right = 0; 
	return ( sumSubtreeUtil(ptr->left, &sum_left, sum) || 
			sumSubtreeUtil(ptr->right, &sum_right, sum) || 
		((*cur_sum = sum_left + sum_right + ptr->data) == sum)); 
} 

// Wrapper over sumSubtreeUtil() 
bool sumSubtree(struct Node *root, int sum) 
{ 
	// Initialize sum of subtree with root 
	int cur_sum = 0; 

	return sumSubtreeUtil(root, &cur_sum, sum); 
} 

// driver program to run the case 
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
	int sum = 22; 

	if (sumSubtree(root, sum)) 
		cout << "Yes"; 
	else
		cout << "No"; 
	return 0; 
} 

