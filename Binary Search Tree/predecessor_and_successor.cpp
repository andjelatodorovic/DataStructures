// C++ program to find predecessor 
// and successor in a BST 
#include <bits/stdc++.h> 
using namespace std; 

// BST Node 
struct Node { 
	int key; 
	struct Node *left, *right; 
}; 

// Function that finds predecessor and successor of key in BST. 
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) 
{ 
	if (root == NULL) 
		return; 

	// Search for given key in BST. 
	while (root != NULL) { 

		// If root is given key. 
		if (root->key == key) { 

			// the minimum value in right subtree 
			// is predecessor. 
			if (root->right) { 
				suc = root->right; 
				while (suc->left) 
					suc = suc->left; 
			} 

			// the maximum value in left subtree 
			// is successor. 
			if (root->left) { 
				pre = root->left; 
				while (pre->right) 
					pre = pre->right; 
			} 

			return; 
		} 

		// If key is greater than root, then 
		// key lies in right subtree. Root 
		// could be predecessor if left 
		// subtree of key is null. 
		else if (root->key < key) { 
			pre = root; 
			root = root->right; 
		} 

		// If key is smaller than root, then 
		// key lies in left subtree. Root 
		// could be successor if right 
		// subtree of key is null. 
		else { 
			suc = root; 
			root = root->left; 
		} 
	} 
} 

// A utility function to create a new BST node 
Node* newNode(int item) 
{ 
	Node* temp = new Node; 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// A utility function to insert 
// a new node with given key in BST 
Node* insert(Node* node, int key) 
{ 
	if (node == NULL) 
		return newNode(key); 
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else
		node->right = insert(node->right, key); 
	return node; 
} 

// Driver program to test above function 
int main() 
{ 
	int key = 65; // Key to be searched in BST 

	/* Let us create following BST 
				50 
				/ \ 
			/ \ 
			30	 70 
			/ \	 / \ 
			/ \ / \ 
		20 40 60 80 
*/
	Node* root = NULL; 
	root = insert(root, 50); 
	insert(root, 30); 
	insert(root, 20); 
	insert(root, 40); 
	insert(root, 70); 
	insert(root, 60); 
	insert(root, 80); 

	Node *pre = NULL, *suc = NULL; 

	findPreSuc(root, pre, suc, key); 
	if (pre != NULL) 
		cout << "Predecessor is " << pre->key << endl; 
	else
		cout << "-1"; 

	if (suc != NULL) 
		cout << "Successor is " << suc->key; 
	else
		cout << "-1"; 
	return 0; 
} 

