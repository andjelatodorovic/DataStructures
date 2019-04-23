// C++ Program to find decimal value of 
// binary linked list 
#include <bits/stdc++.h> 
using namespace std; 

/* Link list Node */
class Node 
{ 
	public: 
	bool data; 
	Node* next; 
}; 

/* Returns decimal value of binary linked list */
int decimalValue(Node *head) 
{ 
	// Initialized result 
	int res = 0; 

	// Traverse linked list 
	while (head != NULL) 
	{ 
		// Multiply result by 2 and add 
		// head's data 
		res = (res << 1) + head->data; 

		// Move next 
		head = head->next; 
	} 
	return res; 
} 

// Utility function to create a new node. 
Node *newNode(bool data) 
{ 
	Node *temp = new Node; 
	temp->data = data; 
	temp->next = NULL; 
	return temp; 
} 

/* Drier program to test above function*/
int main() 
{ 
	/* Start with the empty list */
	Node* head = newNode(1); 
	head->next = newNode(0); 
	head->next->next = newNode(1); 
	head->next->next->next = newNode(1); 

	cout << "Decimal value is "
		<< decimalValue(head); 

	return 0; 
} 

// This is code is contributed by rathbhupendra 

