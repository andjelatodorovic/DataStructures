// C++ implementation for Sorted merge of two 
// sorted doubly circular linked list 
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int data; 
	Node *next, *prev; 
}; 

// A utility function to insert a new node at the 
// beginning of doubly circular linked list 
void insert(Node** head_ref, int data) 
{ 
	// allocate space 
	Node* new_node = new Node; 

	// put in the data 
	new_node->data = data; 

	// if list is empty 
	if (*head_ref == NULL) { 
		new_node->next = new_node; 
		new_node->prev = new_node; 
	} 

	else { 

		// pointer points to last Node 
		Node* last = (*head_ref)->prev; 

		// setting up previous and next of new node 
		new_node->next = *head_ref; 
		new_node->prev = last; 

		// update next and previous pointers of head_ref 
		// and last. 
		last->next = (*head_ref)->prev = new_node; 
	} 

	// update head_ref pointer 
	*head_ref = new_node; 
} 

// function for Sorted merge of two 
// sorted doubly linked list 
Node* merge(Node* first, Node* second) 
{ 
	// If first list is empty 
	if (!first) 
		return second; 

	// If second list is empty 
	if (!second) 
		return first; 

	// Pick the smaller value and adjust 
	// the links 
	if (first->data < second->data) { 
		first->next = merge(first->next, second); 
		first->next->prev = first; 
		first->prev = NULL; 
		return first; 
	} 
	else { 
		second->next = merge(first, second->next); 
		second->next->prev = second; 
		second->prev = NULL; 
		return second; 
	} 
} 

// function for Sorted merge of two sorted 
// doubly circular linked list 
Node* mergeUtil(Node* head1, Node* head2) 
{ 
	// if 1st list is empty 
	if (!head1) 
		return head2; 

	// if 2nd list is empty 
	if (!head2) 
		return head1; 

	// get pointer to the node which will be the 
	// last node of the final list 
	Node* last_node; 
	if (head1->prev->data < head2->prev->data) 
		last_node = head2->prev; 
	else
		last_node = head1->prev; 

	// store NULL to the 'next' link of the last nodes 
	// of the two lists 
	head1->prev->next = head2->prev->next = NULL; 

	// sorted merge of head1 and head2 
	Node* finalHead = merge(head1, head2); 

	// 'prev' of 1st node pointing the last node 
	// 'next' of last node pointing to 1st node 
	finalHead->prev = last_node; 
	last_node->next = finalHead; 

	return finalHead; 
} 

// function to print the list 
void printList(Node* head) 
{ 
	Node* temp = head; 

	while (temp->next != head) { 
		cout << temp->data << " "; 
		temp = temp->next; 
	} 
	cout << temp->data << " "; 
} 

// Driver program to test above 
int main() 
{ 
	Node *head1 = NULL, *head2 = NULL; 

	// list 1: 
	insert(&head1, 8); 
	insert(&head1, 5); 
	insert(&head1, 3); 
	insert(&head1, 1); 

	// list 2: 
	insert(&head2, 11); 
	insert(&head2, 9); 
	insert(&head2, 7); 
	insert(&head2, 2); 

	Node* newHead = mergeUtil(head1, head2); 

	cout << "Final Sorted List: "; 
	printList(newHead); 

	return 0; 
} 

