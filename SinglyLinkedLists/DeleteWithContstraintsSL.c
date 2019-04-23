#include <stdio.h> 
#include <stdlib.h> 

/* structure of a linked list node */
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 

void deleteNode(struct Node *head, struct Node *n) 
{ 
	// When node to be deleted is head node 
	if(head == n) 
	{ 
		if(head->next == NULL) 
		{ 
			printf("There is only one node. The list can't be made empty "); 
			return; 
		} 

		/* Copy the data of next node to head */
		head->data = head->next->data; 

		// store address of next node 
		n = head->next; 

		// Remove the link of next node 
		head->next = head->next->next; 

		// free memory 
		free(n); 

		return; 
	} 


	// When not first node, follow the normal deletion process 

	// find the previous node 
	struct Node *prev = head; 
	while(prev->next != NULL && prev->next != n) 
		prev = prev->next; 

	// Check if node really exists in Linked List 
	if(prev->next == NULL) 
	{ 
		printf("\n Given node is not present in Linked List"); 
		return; 
	} 

	// Remove node from Linked List 
	prev->next = prev->next->next; 

	// Free memory 
	free(n); 

	return; 
} 

/* Utility function to insert a node at the begining */
void push(struct Node **head_ref, int new_data) 
{ 
	struct Node *new_node = 
		(struct Node *)malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = *head_ref; 
	*head_ref = new_node; 
} 

/* Utility function to print a linked list */
void printList(struct Node *head) 
{ 
	while(head!=NULL) 
	{ 
		printf("%d ",head->data); 
		head=head->next; 
	} 
	printf("\n"); 
} 

/* Driver program to test above functions */
int main() 
{ 
	struct Node *head = NULL; 

	/* Create following linked list 
	12->15->10->11->5->6->2->3 */
	push(&head,3); 
	push(&head,2); 
	push(&head,6); 
	push(&head,5); 
	push(&head,11); 
	push(&head,10); 
	push(&head,15); 
	push(&head,12); 

	printf("Given Linked List: "); 
	printList(head); 

	/* Let us delete the node with value 10 */
	printf("\nDeleting node %d: ", head->next->next->data); 
	deleteNode(head, head->next->next); 

	printf("\nModified Linked List: "); 
	printList(head); 

	/* Let us delete the the first node */
	printf("\nDeleting first node "); 
	deleteNode(head, head); 

	printf("\nModified Linked List: "); 
	printList(head); 

	getchar(); 
	return 0; 
} 

