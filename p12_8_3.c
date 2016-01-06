#include <stdio.h>
#include <stdlib.h>
#include "Dll_Node.h"


int dll_insert( Node **head, Node **tail, int ins_value ){

	Node *current;
	Node *next;
	Node *newnode;

	for( current = *head; ((next = current->fwd) != NULL) && ((next->value) < ins_value); current = next ){
		;
	}

	if( current != NULL && next != NULL ){
		printf("current_value = %d\n", current->value);
		printf("next_value = %d\n", next->value);
		if( current->value == ins_value || next->value == ins_value ){
			return 0;
		}
		else{
			;
		}
	}
	else{
		;
	}



	newnode = (Node *)(malloc(sizeof(Node)));
	if( newnode == NULL ){
		return -1;
	}
	else{
		newnode->value = ins_value;
	}


	if( next != NULL ){
		if( current != *head || newnode->value > current->value){
			newnode->fwd = next;
			current->fwd = newnode;
			newnode->bwd = current;
			next->bwd = newnode;
		}// newnode is at neither head nor tail of the DLL.
		else{
			newnode->fwd = current;
			*head = newnode;
			newnode->bwd = NULL;
			current->bwd = newnode;
		}// newnode is at no tail of DLL, but at very start.
	}
	else{
		if( current != *head ){
			newnode->fwd = NULL;
			current->fwd = newnode;
			newnode->bwd = current;
			*tail = newnode;
		}// newnode is at very end of DLL, but the linked list is not empty.
		else{
			newnode->fwd = NULL;
			*head = newnode;
			newnode->bwd = NULL;
			*tail = newnode;
		}// newnode is at both start and end of the DLL, cuz DLL is empty.
	}
	
	return 1;
}



int main( void ){
	
	int value;
	int flag;
	int init_val;
	Node *show;
	Node *previous;
	Node *next;
	
	Node *current = malloc(sizeof(Node));
	Node *head = current;

	current->bwd = NULL;
	for(init_val = 2; init_val < 21; init_val += 2 ){
		current->value = init_val;
		next = malloc(sizeof(Node));
		current->fwd = next;
		next->bwd = current;
		previous = malloc(sizeof(Node));
		previous = current;
		printf("Value of each original node in DLL is %d\n", previous->value);
		current = next;
	}
	previous->fwd = NULL;
	Node *tail = previous;

	printf("value of first node is: %d\n", head->value);
	printf("value of last  node is: %d\n", tail->value);
	

	printf("Enter insertation value: ");
	scanf("%d", &value);

	flag = dll_insert(&head, &tail, value);

	printf("flag: %d\n", flag);	
	if( !flag ){
		printf("Insertion value is already exists, invalid input, try agian...\n");
	}
	else{
		if( flag == -1 ){
			printf("mem allocation failed\n");
		}
		else{
			if( flag == 1 ){
				for( show = head;  show != NULL; show = show->fwd ){
					printf("Value of each node in inserted DLL is: %d\n", show->value);
				}
			}
			else{
				printf("unexpected branch. Wrong return value of the calling function.\n");
			}

		}

	}

	return 0;
}


