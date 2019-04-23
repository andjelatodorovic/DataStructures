// Cpp Program to Reverse a List using Data Swapping 

#include <iostream> 
using namespace std; 

struct Node { 
	int data; 
	struct Node *prev, *next; 
}; 

Node* newNode(int val) 
{ 
	Node* temp = new Node; 
	temp->data = val; 
	temp->prev = temp->next = nullptr; 
	return temp; 
} 

void printList(Node* head) 
{ 
	while (head->next != nullptr) { 
		cout << head->data << " <--> "; 
		head = head->next; 
	} 
	cout << head->data << endl; 
} 

// Insert a new node at the head of the list 
void insert(Node** head, int val) 
{ 
	Node* temp = newNode(val); 
	temp->next = *head; 
	(*head)->prev = temp; 
	(*head) = temp; 
} 

// Function to reverse the list 
void reverseList(Node** head) 
{ 
	Node* left = *head, * right = *head; 

	// Traverse the list and set right pointer to 
	// end of list 
	while (right->next != nullptr) 
		right = right->next; 

	// Swap data of left and right pointer and move 
	// them towards each other until they meet or 
	// cross each other 
	while (left != right && left->prev != right) { 

		// Swap data of left and right pointer 
		swap(left->data, right->data); 

		// Advance left pointer 
		left = left->next; 

		// Advance right pointer 
		right = right->prev; 
	} 
} 

// Driver code 
int main() 
{ 
	Node* head = newNode(5); 
	insert(&head, 4); 
	insert(&head, 3); 
	insert(&head, 2); 
	insert(&head, 1); 

	printList(head); 
	cout << "List After Reversing" << endl; 
	reverseList(&head); 
	printList(head); 

	return 0; 
} 

