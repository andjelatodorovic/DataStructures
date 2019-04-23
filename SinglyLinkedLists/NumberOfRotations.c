// Program for count number of rotations in 
// sorted linked list. 
#include <bits/stdc++.h> 
using namespace std; 
/* Linked list node */
struct Node { 
	int data; 
	struct Node* next; 
}; 

// Function that count number of 
// rotation in singly linked list. 
int countRotation(struct Node* head) 
{ 
	// declare count variable and assign it 1. 
	int count = 0; 

	// declare a min variable and assign to 
	// data of head node. 
	int min = head->data; 

	// check that while head not equal to NULL. 
	while (head != NULL) { 

		// if min value is greater then head->data 
		// then it breaks the while loop and 
		// return the value of count. 
		if (min > head->data) 
			break; 

		count++; 

		// head assign the next value of head. 
		head = head->next; 
	} 
	return count; 
} 

// Function to push element in linked list. 
void push(struct Node** head, int data) 
{ 
	// Allocate dynamic memory for newNode. 
	struct Node* newNode = new Node; 

	// Assign the data into newNode. 
	newNode->data = data; 

	// newNode->next assign the address of 
	// head node. 
	newNode->next = (*head); 

	// newNode become the headNode. 
	(*head) = newNode; 
} 

// Display linked list. 
void printList(struct Node* node) 
{ 
	while (node != NULL) { 
		printf("%d ", node->data); 
		node = node->next; 
	} 
} 

// Drier functions 
int main() 
{ 
	// Create a node and initialize with NULL 
	struct Node* head = NULL; 

	// push() insert node in linked list. 
	// 15 -> 18 -> 5 -> 8 -> 11 -> 12 
	push(&head, 12); 
	push(&head, 11); 
	push(&head, 8); 
	push(&head, 5); 
	push(&head, 18); 
	push(&head, 15); 

	printList(head); 
	cout << endl; 
	cout << "Linked list rotated elements: "; 

	// Function call countRotation() 
	cout << countRotation(head) << endl; 

	return 0; 
} 

