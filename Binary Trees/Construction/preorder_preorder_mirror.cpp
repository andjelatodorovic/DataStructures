// C++ program to construct full binary tree 
// using its preorder traversal and preorder 
// traversal of its mirror tree 

#include<bits/stdc++.h> 
using namespace std; 

// A Binary Tree Node 
struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// Utility function to create a new tree node 
Node* newNode(int data) 
{ 
	Node *temp = new Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to print inorder traversal 
// of a Binary Tree 
void printInorder(Node* node) 
{ 
	if (node == NULL) 
		return; 

	printInorder(node->left); 
	printf("%d ", node->data); 
	printInorder(node->right); 
} 

// A recursive function to construct Full binary tree 
// from pre[] and preM[]. preIndex is used to keep 
// track of index in pre[]. l is low index and h is high 
//index for the current subarray in preM[] 
Node* constructBinaryTreeUtil(int pre[], int preM[], 
					int &preIndex, int l,int h,int size) 
{	 
	// Base case 
	if (preIndex >= size || l > h) 
		return NULL; 

	// The first node in preorder traversal is root. 
	// So take the node at preIndex from preorder and 
	// make it root, and increment preIndex 
	Node* root = newNode(pre[preIndex]); 
		++(preIndex); 

	// If the current subarry has only one element, 
	// no need to recur 
	if (l == h) 
		return root; 
	
	// Search the next element of pre[] in preM[] 
	int i; 
	for (i = l; i <= h; ++i) 
		if (pre[preIndex] == preM[i]) 
			break; 

	// construct left and right subtrees recursively	 
	if (i <= h) 
	{ 
		root->left = constructBinaryTreeUtil (pre, preM, 
									preIndex, i, h, size); 
		root->right = constructBinaryTreeUtil (pre, preM, 
								preIndex, l+1, i-1, size); 
	} 

	// return root 
	return root;	 
} 

// function to construct full binary tree 
// using its preorder traversal and preorder 
// traversal of its mirror tree 
void constructBinaryTree(Node* root,int pre[], 
						int preMirror[], int size) 
{ 
	int preIndex = 0; 
	int preMIndex = 0; 

	root = constructBinaryTreeUtil(pre,preMirror, 
							preIndex,0,size-1,size); 

	printInorder(root); 
} 

// Driver program to test above functions 
int main() 
{ 
	int preOrder[] = {1,2,4,5,3,6,7}; 
	int preOrderMirror[] = {1,3,7,6,2,5,4}; 

	int size = sizeof(preOrder)/sizeof(preOrder[0]); 

	Node* root = new Node; 

	constructBinaryTree(root,preOrder,preOrderMirror,size); 

	return 0; 
} 

