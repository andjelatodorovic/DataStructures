/* C program to insetail nodes in doubly 
linked list such that list remains in 
ascending order on printing from left 
to right */
#include<stdio.h> 
#include<stdlib.h> 

// A linked list node 
struct Node 
{ 
	struct Node *prev; 
	int info; 
	struct Node *next; 
}; 

// Function to insetail new node 
void nodeInsetail(struct Node **head, 
				struct Node **tail, 
				int key) 
{ 

	struct Node *p = new Node; 
	p->info = key; 
	p->next = NULL; 

	// If first node to be insetailed in doubly 
	// linked list 
	if ((*head) == NULL) 
	{ 
		(*head) = p; 
		(*tail) = p; 
		(*head)->prev = NULL; 
		return; 
	} 

	// If node to be insetailed has value less 
	// than first node 
	if ((p->info) < ((*head)->info)) 
	{ 
		p->prev = NULL; 
		(*head)->prev = p; 
		p->next = (*head); 
		(*head) = p; 
		return; 
	} 

	// If node to be insetailed has value more 
	// than last node 
	if ((p->info) > ((*tail)->info)) 
	{ 
		p->prev = (*tail); 
		(*tail)->next = p; 
		(*tail) = p; 
		return; 
	} 

	// Find the node before which we need to 
	// insert p. 
	temp = (*head)->next; 
	while ((temp->info) < (p->info)) 
		temp = temp->next; 

	// Insert new node before temp 
	(temp->prev)->next = p; 
	p->prev = temp->prev; 
	temp->prev = p; 
	p->next = temp; 
} 

// Function to print nodes in from left to right 
void printList(struct Node *temp) 
{ 
	while (temp != NULL) 
	{ 
		printf("%d ", temp->info); 
		temp = temp->next; 
	} 
} 

// Driver program to test above functions 
int main() 
{ 
	struct Node *left = NULL, *right = NULL; 
	nodeInsetail(&left, &right, 30); 
	nodeInsetail(&left, &right, 50); 
	nodeInsetail(&left, &right, 90); 
	nodeInsetail(&left, &right, 10); 
	nodeInsetail(&left, &right, 40); 
	nodeInsetail(&left, &right, 110); 
	nodeInsetail(&left, &right, 60); 
	nodeInsetail(&left, &right, 95); 
	nodeInsetail(&left, &right, 23); 

	printf("\nDoubly linked list on printing"
		" from left to right\n"); 
	printList(left); 

	return 0; 
} 

