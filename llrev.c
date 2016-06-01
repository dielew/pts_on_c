#include <stdio.h>
#include <stdlib.h>
#include "Sll_Node.h"




















Node* linkedlist_rev( Node* linkedlist )
{
	Node* root_ptr = linkedlist;
	Node* init_ptr = root_ptr;
	Node* start_ptr = root_ptr;
	Node* rev_ptr;
	int len;
	int i, j, k;
	int temp;

	for( len = 0; start_ptr != NULL; start_ptr = start_ptr->link ){
		len++;
	}

	int swap_len = len / 2;
	

	for( i = 0, j = len, start_ptr = init_ptr; i < swap_len && j > len - swap_len; i++, j-- ){ 
		for( k = 0, rev_ptr = init_ptr; k < j - 1; k++ ){
			rev_ptr = rev_ptr->link;
		}
		
		
		
		temp = start_ptr->value;

		start_ptr->value = rev_ptr->value;
		rev_ptr->value = temp;



		start_ptr = start_ptr->link;


	}
	
	return root_ptr;
			
}








int main( void )
{
	
	Node* start = (Node*)malloc(sizeof(Node));
	int n = 1;
	start->value = n;
	Node* root_ptr = start;
	
	Node* result;
		

	while( ++n < 11 ){
		printf("%d\n", start->value);
		Node* node = (Node*)malloc(sizeof(Node));
		start->link = node;
		
		start = node;
		start->value = n;
	}

	start->link = NULL;

	printf("\n");
	result = linkedlist_rev(root_ptr);

	for( start = result; start != NULL; start = start->link ){
		printf("reversed node value=%d\n", start->value);

	}





	return 0;
}
