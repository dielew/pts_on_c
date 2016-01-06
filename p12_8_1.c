#include <stdio.h>
#include <stdlib.h>
#include "Sll_Node.h"


int node_count( Node *root_ptr ){
	
	int counter = 0;
	Node *current = root_ptr;
	while( current != NULL ){
		printf("value of current node: %d\n", current->value);
		current = current->link;
		counter += 1;
	}
	return counter;
}




int main( void ){

	int init_value = 5;
	Node *root_ptr;
	Node *current;
	Node *next;
	
	next = malloc(sizeof(Node));
	root_ptr = next;
	
	while( init_value <= 30 && ((current = next) != NULL )){
		current->value = init_value;
		init_value += 5;
		next = malloc(sizeof(Node));
		current->link = next;
	}
	current->link = NULL;

	printf("Node Number Count: %d\n", node_count(root_ptr));
	
	return 0;
}
