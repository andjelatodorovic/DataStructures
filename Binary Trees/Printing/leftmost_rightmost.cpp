// C/C++ program to print corner node at each level 
// of binary tree 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has key, pointer to left 
child and a pointer to right child */
struct Node 
{ 
	int key; 
	struct Node* left, *right; 
}; 

/* To create a newNode of tree and return pointer */
struct Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return (temp); 
} 

/* Function to print corner node at each level */
void printCorner(Node *root) 
{ 
	//If the root is null then simply return 
	if(root == NULL) 
		return; 
	//Do level order traversal using queue 
	queue<Node*> q; 
	q.push(root); 
	
	//The vector would store the ans 
	//Note that you could simply print the corner values at each step 
	vector<int> ans; 
	
	while(!q.empty()) 
	{ 
		//n denotes the size of the current queue 
		int n = q.size(); 
		
		for(int i =0;i<n;i++) 
		{ 
			Node *temp = q.front(); 
			q.pop(); 
			
			// leftmost corner value 
			if(i==0) 
				ans.push_back(temp->key); 
		// rightmost corner value 
			else if(i==n-1) 
				ans.push_back(temp->key); 
			
				
			//push the left and right children of the temp node 
			if(temp->left) 
				q.push(temp->left); 
			if(temp->right) 
				q.push(temp->right); 
		} 
	} 
	//loop through the variable and print the answers 
	for(auto i : ans) 
		cout << i << " "; 
} 
// Driver program to test above function 
int main () 
{ 
	Node *root = newNode(15); 
	root->left = newNode(10); 
	root->right = newNode(20); 
	root->left->left = newNode(8); 
	root->left->right = newNode(12); 
	root->right->left = newNode(16); 
	root->right->right = newNode(25); 
	printCorner(root); 
	return 0; 
} 

