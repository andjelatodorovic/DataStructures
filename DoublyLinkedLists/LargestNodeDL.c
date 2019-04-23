/* Program to find the largest 
nodes in doubly linked list */
#include <stdio.h> 
#include <stdlib.h> 

// Create node of the doubly linked list 
struct Node { 
	int data; 
	struct Node* next; 
	struct Node* prev; 
}; 

/* UTILITY FUNCTIONS */
/* Function to insert a node at the 
beginging of the Doubly Linked List */
void push(struct Node** head_ref, int new_data) 
{ 
	/* allocate node */
	struct Node* new_node = 
	(struct Node*)malloc(sizeof(struct Node)); 

	/* put in the data */
	new_node->data = new_data; 

	/* since we are adding at the 
	begining, prev is always NULL */
	new_node->prev = NULL; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* change prev of head node to new node */
	if ((*head_ref) != NULL) 
		(*head_ref)->prev = new_node; 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Function to find the largest 
nodes in Doubly Linked List */
int LargestInDLL(struct Node** head_ref) 
{ 
	struct Node *max, *temp; 

	/* initialize two pointer temp 
	and max on the head node */
	temp = max = *head_ref; 

	// traverse the whole doubly linked list 
	while (temp != NULL) { 

		/* if temp's data is greater than 
		max's data, then put max = temp 
		and return max->data */		
		if (temp->data > max->data) 
			max = temp; 
		
		temp = temp->next; 
	} 
	return max->data; 
} 

int main() 
{ 
	// Start with the empty list 
	struct Node* head = NULL; 

	// Let us create a linked list 
	push(&head, 20); 
	push(&head, 14); 
	push(&head, 181); 
	push(&head, 100); 

	printf("%d", LargestInDLL(&head)); 
	return 0; 
} 

