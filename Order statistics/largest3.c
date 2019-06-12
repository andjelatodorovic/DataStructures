#include <stdio.h> 
#include <limits.h> /* For INT_MIN */ 

/* Function to print three largest elements */
void print3largest(int arr[], int arr_size) 
{ 
	int i, first, second, third; 

	/* There should be atleast three elements */
	if (arr_size < 3) 
	{ 
		printf(" Invalid Input "); 
		return; 
	} 

	third = first = second = INT_MIN; 
	for (i = 0; i < arr_size ; i ++) 
	{ 
		/* If current element is greater than first*/
		if (arr[i] > first) 
		{ 
			third = second; 
			second = first; 
			first = arr[i]; 
		} 

		/* If arr[i] is in between first and second then update second */
		else if (arr[i] > second) 
		{ 
			third = second; 
			second = arr[i]; 
		} 

		else if (arr[i] > third) 
			third = arr[i]; 
	} 

	printf("Three largest elements are %d %d %d\n", first, second, third); 
} 


/* Driver program to test above function */
int main() 
{ 
	int arr[] = {12, 13, 1, 10, 34, 1}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	print3largest(arr, n); 
	return 0; 
} 
/*This code is edited by Ayush Singla(@ayusin51)*/

