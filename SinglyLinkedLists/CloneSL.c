// C++ program to clone a linked list with 
// random pointers 
#include<bits/stdc++.h> 
using namespace std; 


// Linked List Node 
class Node 
{ 
	public: 
	int data;//Node data 
	
	// Next and random reference 
	Node *next, *random; 

	Node(int data) 
	{ 
		this->data = data; 
		this->next = this->random = NULL; 
	} 
}; 

// linked list class 
class LinkedList 
{ 
	public: 
	Node *head;// Linked list head reference 

	LinkedList(Node *head) 
	{ 
		this->head = head; 
	} 

	// push method to put data always at 
	// the head in the linked list. 
	void push(int data) 
	{ 
		Node *node = new Node(data); 
		node->next = head; 
		head = node; 
	} 

	// Method to print the list. 
	void print() 
	{ 
		Node *temp = head; 
		while (temp != NULL) 
		{ 
			Node *random = temp->random; 
			int randomData = (random != NULL)? 
						random->data: -1; 
			cout << "Data = " << temp->data 
				<< ", "; 
			cout << "Random Data = " << 
				randomData << endl; 
			temp = temp->next; 
		} 
		cout << endl; 
	} 

	// Actual clone method which returns 
	// head reference of cloned linked 
	// list. 
	LinkedList* clone() 
	{ 
		// Initialize two references, 
		// one with original list's head. 
		Node *origCurr = head; 
		Node *cloneCurr = NULL; 

		// Hash map which contains node 
		// to node mapping of original 
		// and clone linked list. 
		unordered_map<Node*, Node*> mymap; 

		// Traverse the original list and 
		// make a copy of that in the 
		// clone linked list. 
		while (origCurr != NULL) 
		{ 
			cloneCurr = new Node(origCurr->data); 
			mymap[origCurr] = cloneCurr; 
			origCurr = origCurr->next; 
		} 

		// Adjusting the original list 
		// reference again. 
		origCurr = head; 

		// Traversal of original list again 
		// to adjust the next and random 
		// references of clone list using 
		// hash map. 
		while (origCurr != NULL) 
		{ 
			cloneCurr = mymap[origCurr]; 
			cloneCurr->next = mymap[origCurr->next]; 
			cloneCurr->random = mymap[origCurr->random]; 
			origCurr = origCurr->next; 
		} 

		// return the head reference of 
		// the clone list. 
		return new LinkedList(mymap[head]); 
	} 
}; 

// driver code 
int main() 
{ 
	// Pushing data in the linked list. 
	LinkedList *mylist = new LinkedList(new Node(5)); 
	mylist->push(4); 
	mylist->push(3); 
	mylist->push(2); 
	mylist->push(1); 

	// Setting up random references. 
	mylist->head->random = mylist->head->next->next; 

	mylist->head->next->random = 
		mylist->head->next->next->next; 

	mylist->head->next->next->random = 
		mylist->head->next->next->next->next; 

	mylist->head->next->next->next->random = 
		mylist->head->next->next->next->next->next; 

	mylist->head->next->next->next->next->random = 
		mylist->head->next; 

	// Making a clone of the original 
	// linked list. 
	LinkedList *clone = mylist->clone(); 

	// Print the original and cloned 
	// linked list. 
	cout << "Original linked list\n"; 
	mylist->print(); 
	cout << "\nCloned linked list\n"; 
	clone->print(); 
} 
// This code is contributed by Chhavi 

