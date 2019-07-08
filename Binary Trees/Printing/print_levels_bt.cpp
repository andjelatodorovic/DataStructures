// An iterative C++ program to print levels 
// of all nodes 
#include <bits/stdc++.h> 
using namespace std; 

/* A tree node structure */
struct Node { 
	int data; 
	struct Node* left; 
	struct Node* right; 
}; 

void printLevel(struct Node* root) 
{ 
	if (!root) 
		return; 

	// queue to hold tree node with level 
	queue<pair<struct Node*, int> > q; 

	q.push({root, 1}); // let root node be at level 1 

	pair<struct Node*, int> p; 

	// Do level Order Traversal of tree 
	while (!q.empty()) { 
		p = q.front(); 
		q.pop(); 

		cout << "Level of " << p.first->data 
			<< " is " << p.second << "\n"; 

		if (p.first->left) 
			q.push({ p.first->left, p.second + 1 }); 
		if (p.first->right) 
			q.push({ p.first->right, p.second + 1 }); 
	} 
} 

/* Utility function to create a new Binary Tree node */
struct Node* newNode(int data) 
{ 
	struct Node* temp = new struct Node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

/* Driver function to test above functions */
int main() 
{ 
	struct Node* root = NULL; 

	/* Constructing tree given in the above figure */
	root = newNode(3); 
	root->left = newNode(2); 
	root->right = newNode(5); 
	root->left->left = newNode(1); 
	root->left->right = newNode(4); 

	printLevel(root); 
	return 0; 
} 

