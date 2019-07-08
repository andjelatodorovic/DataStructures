// C++ program to see if there is a root to leaf path 
// with given sequence. 
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

// function to check given sequence of root to leaf path exist 
// in tree or not. 
// index represents current element in sequence of rooth to 
// leaf path 
bool existPath(struct Node *root, int arr[], int n, int index) 
{ 
	// If root is NULL, then there must not be any element 
	// in array. 
	if (root == NULL) 
		return (n == 0); 

// If this node is a leaf and matches with last entry 
// of array. 
if ((root->left == NULL && root->right == NULL) && 
	(root->data == arr[index]) && (index == n-1)) 
			return true; 

// If current node is equal to arr[index] this means 
// that till this level path has been matched and 
// remaining path can be either in left subtree or 
// right subtree. 
return ((index < n) && (root->data == arr[index]) && 
			(existPath(root->left, arr, n, index+1) || 
			existPath(root->right, arr, n, index+1) )); 
} 

// Driver function to run the case 
int main() 
{ 
	// arr[] --> sequence of root to leaf path 
	int arr[] = {5, 8, 6, 7}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	struct Node *root = newnode(5); 
	root->left = newnode(3); 
	root->right = newnode(8); 
	root->left->left = newnode(2); 
	root->left->right = newnode(4); 
	root->left->left->left = newnode(1); 
	root->right->left = newnode(6); 
	root->right->left->right = newnode(7); 

	existPath(root, arr, n, 0)? cout << "Path Exists" : 
								cout << "Path does not Exist"; 
	return 0; 
} 

