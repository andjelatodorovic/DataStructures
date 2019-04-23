/* This program swaps the nodes of 
linked list rather than swapping the 
field from the nodes. 
Imagine a case where a node contains 
many fields, there will be plenty 
of unnecessary swap calls. */

#include <bits/stdc++.h> 
using namespace std; 

/* A linked list node */
class node { 
public: 
	int data; 
	node* next; 
}; 

/* Function to pairwise swap elements 
of a linked list. It returns head of 
the modified list, so return value 
of this node must be assigned */
node* pairWiseSwap(node* head) 
{ 
	// Base Case: The list is empty or has only one node 
	if (head == NULL || head->next == NULL) 
		return head; 

	// Store head of list after two nodes 
	node* remaing = head->next->next; 

	// Change head 
	node* newhead = head->next; 

	// Change next of second node 
	head->next->next = head; 

	// Recur for remaining list and change next of head 
	head->next = pairWiseSwap(remaing); 

	// Return new head of modified list 
	return newhead; 
} 

/* Function to add a node at 
the begining of Linked List */
void push(node** head_ref, int new_data) 
{ 
	/* allocate node */
	node* new_node = new node(); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Function to print nodes 
in a given linked list */
void printList(node* node) 
{ 
	while (node != NULL) { 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

/* Driver code */
int main() 
{ 
	node* start = NULL; 

	/* The constructed linked list is: 
	1->2->3->4->5->6->7 */
	push(&start, 7); 
	push(&start, 6); 
	push(&start, 5); 
	push(&start, 4); 
	push(&start, 3); 
	push(&start, 2); 
	push(&start, 1); 

	cout << "Linked list before calling pairWiseSwap() "; 
	printList(start); 

	start = pairWiseSwap(start); // NOTE THIS CHANGE 

	cout << "\nLinked list after calling pairWiseSwap() "; 
	printList(start); 

	return 0; 
} 

// This code is contributed by rathbhupendra 
