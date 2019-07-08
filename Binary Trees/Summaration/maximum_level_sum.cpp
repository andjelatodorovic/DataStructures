// A queue based C++ program to find maximum sum 
// of a level in Binary Tree 
#include<bits/stdc++.h> 
using namespace std ; 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node 
{ 
	int data ; 
	struct Node * left, * right ; 
}; 

// Function to find the maximum sum of a level in tree 
// using level order traversal 
int maxLevelSum(struct Node * root) 
{ 
	// Base case 
	if (root == NULL) 
		return 0; 

	// Initialize result 
	int result = root->data; 

	// Do Level order traversal keeping track of number 
	// of nodes at every level. 
	queue<Node*> q; 
	q.push(root); 
	while (!q.empty()) 
	{ 
		// Get the size of queue when the level order 
		// traversal for one level finishes 
		int count = q.size() ; 

		// Iterate for all the nodes in the queue currently 
		int sum = 0; 
		while (count--) 
		{ 
			// Dequeue an node from queue 
			Node *temp = q.front(); 
			q.pop(); 

			// Add this node's value to current sum. 
			sum = sum + temp->data; 

			// Enqueue left and right children of 
			// dequeued node 
			if (temp->left != NULL) 
				q.push(temp->left); 
			if (temp->right != NULL) 
				q.push(temp->right); 
		} 

		// Update the maximum node count value 
		result = max(sum, result); 
	} 

	return result; 
} 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
struct Node * newNode(int data) 
{ 
	struct Node * node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

int main() 
{ 
	struct Node *root = newNode(1); 
	root->left	 = newNode(2); 
	root->right	 = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 
	root->right->right = newNode(8); 
	root->right->right->left = newNode(6); 
	root->right->right->right = newNode(7); 

	/* Constructed Binary tree is: 
				1 
			/ \ 
			2	 3 
		/ \	 \ 
		4 5	 8 
					/ \ 
				6	 7 */
	cout << "Maximum level sum is "
		<< maxLevelSum(root) << endl; 
	return 0; 
} 

