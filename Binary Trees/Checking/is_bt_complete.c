// A program to check if a given binary tree is complete or not 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
#define MAX_Q_SIZE 500 

/* A binary tree node has data, a pointer to left child 
and a pointer to right child */
struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

/* function prototypes for functions needed for Queue data 
structure. A queue is needed for level order tarversal */
struct node** createQueue(int *, int *); 
void enQueue(struct node **, int *, struct node *); 
struct node *deQueue(struct node **, int *); 
bool isQueueEmpty(int *front, int *rear); 

/* Given a binary tree, return true if the tree is complete 
else false */
bool isCompleteBT(struct node* root) 
{ 
// Base Case: An empty tree is complete Binary Tree 
if (root == NULL) 
	return true; 

// Create an empty queue 
int rear, front; 
struct node **queue = createQueue(&front, &rear); 

// Create a flag variable which will be set true 
// when a non full node is seen 
bool flag = false; 

// Do level order traversal using queue. 
enQueue(queue, &rear, root); 
while(!isQueueEmpty(&front, &rear)) 
{ 
	struct node *temp_node = deQueue(queue, &front); 

	/* Check if left child is present*/
	if(temp_node->left) 
	{ 
	// If we have seen a non full node, and we see a node 
	// with non-empty left child, then the given tree is not 
	// a complete Binary Tree 
	if (flag == true) 
		return false; 

	enQueue(queue, &rear, temp_node->left); // Enqueue Left Child 
	} 
	else // If this a non-full node, set the flag as true 
	flag = true; 

	/* Check if right child is present*/
	if(temp_node->right) 
	{ 
	// If we have seen a non full node, and we see a node 
	// with non-empty right child, then the given tree is not 
	// a complete Binary Tree 
	if(flag == true) 
		return false; 

	enQueue(queue, &rear, temp_node->right); // Enqueue Right Child 
	} 
	else // If this a non-full node, set the flag as true 
	flag = true; 
} 

// If we reach here, then the tree is complete Binary Tree 
return true; 
} 


/*UTILITY FUNCTIONS*/
struct node** createQueue(int *front, int *rear) 
{ 
struct node **queue = 
(struct node **)malloc(sizeof(struct node*)*MAX_Q_SIZE); 

*front = *rear = 0; 
return queue; 
} 

void enQueue(struct node **queue, int *rear, struct node *new_node) 
{ 
queue[*rear] = new_node; 
(*rear)++; 
} 

struct node *deQueue(struct node **queue, int *front) 
{ 
(*front)++; 
return queue[*front - 1]; 
} 

bool isQueueEmpty(int *front, int *rear) 
{ 
return (*rear == *front); 
} 

/* Helper function that allocates a new node with the 
given data and NULL left and right pointers. */
struct node* newNode(int data) 
{ 
struct node* node = (struct node*) 
					malloc(sizeof(struct node)); 
node->data = data; 
node->left = NULL; 
node->right = NULL; 

return(node); 
} 

/* Driver program to test above functions*/
int main() 
{ 
/* Let us construct the following Binary Tree which 
	is not a complete Binary Tree 
			1 
		/ \ 
		2	 3 
		/ \	 \ 
	4 5	 6 
	*/

struct node *root = newNode(1); 
root->left		 = newNode(2); 
root->right	 = newNode(3); 
root->left->left = newNode(4); 
root->left->right = newNode(5); 
root->right->right = newNode(6); 

if ( isCompleteBT(root) == true ) 
	printf ("Complete Binary Tree"); 
else
	printf ("NOT Complete Binary Tree"); 

return 0; 
} 

